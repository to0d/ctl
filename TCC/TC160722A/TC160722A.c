#include <stdio.h> 
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <setjmp.h>

/* ************************************************************ */
/*    SQL PARSER Macro                                          */
/*                                                              */
/* ************************************************************ */

#define MAX_TOKEN_LENGTH        152
#define MAX_CONTENT_LENGTH      (1024*4)  
#define MAX_TOKEN_COUNT         256

#define CT_CHAR         0           // character
#define CT_NUM          1           // number
#define CT_BLANK        2           // Symbol Space " " or \t
#define CT_STRING       3           // Symbol " or '
#define CT_SPECIAL      4           // Symbol _ @ $ #
#define CT_PERIOD       5           // Symbol .
#define CT_SINGLE       6           // Other Symbol
#define CT_END          7           // New line \r \n
#define CT_UNKNOWN      8           // unknown char

#define TT_BAD          0
#define TT_BLANK        1           // symbol blank space
#define TT_SYMBOL       2           // other symbol
#define TT_NAME         3           // simple string, ABC123, 12A, _123ABC 
#define TT_STRING       4           // in quotation marks, "abc123 " 
#define TT_INTEGER      5           // integer, 0123
#define TT_FLOAT        6           // float 123.5
#define TT_COMBINE      7           // Combine Symbols "%%"

#define CombinedSymbolSQLMAP        (ttCombinedSymbol[0])


#define ENABLE_TTSYMBOL_VARIANT     // use symbol variant for GetCharType
// #define ENABLE_TTSYMBOL_CONVERT  // Enable symbol char ccsid convert 
                                    // for GetCharType

#ifdef ENABLE_TTSYMBOL_VARIANT

/*-------------------------------------------------------------------*/
/* CCSID Translation                                                 */
/* Temp char array used for CCSID Translation                        */
/* If you add any new chars above, they must be added to this array  */
/*-------------------------------------------------------------------*/
static char SymbolVariant[11] = 
    {
        0xa1,                           /*Symbol ~    */
        0xba,                           /*Symbol [    */
        0xbb,                           /*Symbol ]    */
        0xc0,                           /*Symbol {    */
        0xd0,                           /*Symbol }    */
        0x7b,                           /*Symbol #    */
        0x4f,                           /*Symbol |    */
        0xe0,                           /*Symbol \    */
        0xb0,                           /*Symbol ^    */
        0x7c,                           /*Symbol @    */
        0x5B                            /*Symbol $    */
    };
  
#define CC_TILED     SymbolVariant[0]   /*Symbol ~    */
#define CC_LBRACKET  SymbolVariant[1]   /*Symbol [    */
#define CC_RBRACKET  SymbolVariant[2]   /*Symbol ]    */
#define CC_LBRACE    SymbolVariant[3]   /*Symbol {    */
#define CC_RBRACE    SymbolVariant[4]   /*Symbol }    */
#define CC_NUMSIGN   SymbolVariant[5]   /*Symbol #    */
#define CC_VBAR      SymbolVariant[6]   /*Symbol |    */
#define CC_BSLASH    SymbolVariant[7]   /*Symbol \    */
#define CC_HAT       SymbolVariant[8]   /*Symbol ^    */
#define CC_ATSIGN    SymbolVariant[9]   /*Symbol @    */
#define CC_CURRENCY  SymbolVariant[10]  /*Symbol $    */

static char CC_NEW_LINE = '\n'  ;
static char CC_RETURN   = '\r'  ;
static char CC_SPACE    = ' '   ;
static char CC_TAB      = '\t'  ;
static char CC_DQUOTE   = '"'   ;
static char CC_SQUOTE   = '\''  ;
static char CC_COLON    = ':'   ;
static char CC_SEMICOLON= ';'   ;
static char CC_COMMA    = ','   ;
static char CC_LPARETN  = '('   ;
static char CC_RPARETN  = ')'   ;
static char CC_EQUAL    = '='   ;
static char CC_SLASH    = '/'   ;
static char CC_PERIOD   = '.'   ;
static char CC_UNDERLINE= '_'   ;
static char CC_MINUS    = '-'   ;
static char CC_QUESTION = '?'   ;
static char CC_AMPERSAND= '&'   ;
static char CC_ASTERISK = '*'   ;
static char CC_PERCENT  = '%'   ;

#else 
    
#define CC_TILED                '~'
#define CC_LBRACKET             '['
#define CC_RBRACKET             ']'
#define CC_LBRACE               '{'
#define CC_RBRACE               '}'
#define CC_NUMSIGN              '#'
#define CC_VBAR                 '|'
#define CC_BSLASH               '\\'
#define CC_HAT                  '^'
#define CC_ATSIGN               '@'
#define CC_CURRENCY             '$'

#define CC_NEW_LINE             '\n'
#define CC_RETURN               '\r'
#define CC_SPACE                ' '
#define CC_TAB                  '\t'
#define CC_DQUOTE               '"'
#define CC_SQUOTE               '\''
#define CC_COLON                ':'
#define CC_SEMICOLON            ';'
#define CC_COMMA                ','
#define CC_LPARETN              '('
#define CC_RPARETN              ')'
#define CC_EQUAL                '='
#define CC_SLASH                '/'
#define CC_PERIOD               '.'
#define CC_UNDERLINE            '_'
#define CC_MINUS                '-'
#define CC_QUESTION             '?'
#define CC_AMPERSAND            '&'
#define CC_ASTERISK             '*'
#define CC_PERCENT              '%'

#endif


/* ************************************************************ */
/*    Token Parser:                                             */
/*          Token definition                                    */
/*          Global variables                                    */
/*          Paser functions                                     */
/*                                                              */
/* ************************************************************ */

/* token definition */
typedef struct 
{
    int  ntype;
    int  nLength;
    int  nEndPos;
    char tString[MAX_TOKEN_LENGTH];
    
} CTOKEN;

/* CombinedSymbol definition */
typedef struct {  

    int  Length;
    char *Name;  
    
} TT_CombinedSymbol;

static TT_CombinedSymbol ttCombinedSymbol[] =
{
   { 2, "%%"},                                      /* 0 */
}; /* reserved_token_info ttCombinedSymbol[] */


static const int CombineSymbolCount     = 1;
static const int MaxCombineSymbolLength = 2;    // Max length of combinedSymbol

static int  nCPaserPos = 0;
static int  nCPaserBufferLength = 0;
static char nCPaserBuffer [ MAX_CONTENT_LENGTH + 1];

#ifdef ENABLE_TTSYMBOL_CONVERT
static int  bCCSIDConvert = 0;
#endif

int isExtenderChar(char c) ;
int GetCharType(char c);
int InitCommonTokenParser(const char *input, int len);
int ScanToken(CTOKEN* pToken, int begPos);
int PeekToken(CTOKEN* pToken);
int NextToken(CTOKEN* pToken);

int isNameToken(CTOKEN* pToken, const char* name, int len);
int isIntegerToken(CTOKEN* pToken, int* num);
int isSpaceToken(CTOKEN* pToken);
int isSingleSymbol(CTOKEN* pToken, char c);
int isSupportedNameHeadSymbol(CTOKEN* pToken);
int isIntegerToken(CTOKEN* pToken, int* num);
int isStringToken(CTOKEN* pToken);

/* ************************************************************ */
/*    SQL Parser definition                                     */
/*                                                              */
/* ************************************************************ */

#define SQLDISPLAY_MODE_INVAILD    0 
#define SQLDISPLAY_MODE_AUTO       1
#define SQLDISPLAY_MODE_EBCDIC     2    // format 's', EBCDIC CCSID 65535
#define SQLDISPLAY_MODE_UNICODE    3    // format 'u', Unicode CCSID 13488
#define SQLDISPLAY_MODE_ASCII      4    // format 'a', ASCII related job CCSID
#define SQLDISPLAY_MODE_HEX        5    // format 'x', Hexadecimal formatting

#define SQLCMD_TYPE_INVAILD        0
#define SQLCMD_TYPE_DISPLAY        1    // EVAL %%VAR
#define SQLCMD_TYPE_LEFT_ASSIGN    2    // EVAL %%VAR = XYZ

#define SQLCMD_ERR_SUCC            0    // Succ
#define SQLCMD_ERR_PARA           -1    // Invaild parameter
#define SQLCMD_ERR_SYNTAX         -2    // Bad Syntax 
#define SQLCMD_ERR_TOKEN          -3    // Bad token
#define SQLCMD_ERR_LIMITAION      -4    // Beyond limitation
#define SQLCMD_ERR_UNKNOWN       -99    // Internal error

#define JUMP_ERROR_HAPPENED      -10
#define MAX_SQLCMD_STACK_DEPTH   256
#define MAX_SQLCMD_PARSE_COUNT 65535    // Max operation count
                                        // in case of recursion


typedef struct { 

    CTOKEN Tokens           [ MAX_TOKEN_COUNT + 1   ];       
    int    TokenCurPosStack [ MAX_SQLCMD_STACK_DEPTH + 1];
    int    TokenCount;
    
    char   OutputBuf        [ MAX_CONTENT_LENGTH * 2 + 1];
    int    OutputBufLenStack[ MAX_SQLCMD_STACK_DEPTH + 1];
    
    int    StackDepth;
    
    int    CommandType;
    int    DisplayFormatMode;
    int    DisplayFormatLength;         // 0: auto length
    int    DisplayFormatPosition;       // 0: default position
    int    OperationCount;
    
} SQLCmdContext;

jmp_buf         error_env_ttparser;
SQLCmdContext   ttContext;


/* internal functions  */
CTOKEN* getCurSQLToken();
int     getContextTokenPos();
int     getContextBufferLen();
int     getContextStackDepth();
int     hasMoreTokens();

void    appendContextBuffer(const char* v, int len);
void    updateStack(int addTokenCount, int addBufLen);
void    rollbackStack(int newDepth);
void    throwSQLBadSyntaxError();
void    checkRecursion();

int     ignoreBlank();
int     matchBlank();
int     matchBlankNotOutput();
int     matchNameNotOutput(const char* value, int length);
int     matchCombinedSymbol(const char* symbol, int len);
int     matchInteger(int* num );
int     matchSymbol(char symbol);

/* ************************************************************ */
/*     SQL Parser rules                                         */
/*                                                              */
/*    (1)   FormatOption        := :[S|U|A|X] (int) [int]       */
/*                                                              */
/*    (2)   OrdinaryIdentifier  := [A-Za-z@$#][A-Za-z0-9_@$#]*  */
/*                                                              */
/*    (3)   DelimitedIdentifier := {"}{String}{"}               */
/*                                      Drop trailing blanks    */
/*                                                              */
/*    (4)   SQLIdentifier       := {OrdinaryIdentifier}         */
/*                               | {DelimitedIdentifier}        */
/*                                                              */
/*    (5)   SQLLabel            := {OrdinaryIdentifier}         */
/*                                                              */
/*    (6)   SQLVariable         :=                              */
/*                         {%%}{SQLIdentifier}                  */
/*                        |{%%}{SQLLabel}{.}{SQLIdentifier}     */
/*                                                              */
/*    (7)   SQLExpression       :=  {SQLVariable}               */
/*                                                              */
/*    (8)   SQLDisplayComd      :=                              */
/*                    {EVAL}{ }{SQLExpression}{ }{FormatOption} */
/*                  | {EVAL}{ }{SQLExpression}                  */
/*                                                              */
/*    (9)   SQLAssignComd       := {EVAL}{SQLVariable} = *  @K4A*/
/*                                                              */
/* ************************************************************ */

int matchFormatOption(int* mode, int* len, int* pos);
                                           /* format option     */
int matchOrdinaryIdentifier();             /* Ordinary Identifie*/
int matchDelimitedIdentifier();            /* Delimited Identifi*/
int matchSQLIdentifier();                  /* SQL Identifier    */
int matchSQLLabel();                       /* SQL Label         */
int matchSQLVariable();                    /* SQL Variable      */
int matchSQLExpression();                  /* SQL Expression    */
int matchSQLDisplayCommand( int* mode, int* len, int* pos);

// The format eval command MUST be :
// EVAL %%[SQL-Variable] [: format option]
//     SQL-Variable  := [Lable.] SQL-identifier
//     SQL-identifier:= ABC123              --ordinary identifier
//                      "%^&*~!()<>? abc"   --delimited identifier                    
//     format option := [s|u|a] [Length]
//     
// Example:
//      EVAL TST.VAR
//      EVAL "%^&*~!()<>? abc "
//      EVAL VAR1 : s 10 
//
// Return: 
//      SQLCMD_ERR_SUCC      ( 0) : SUCC
//      SQLCMD_ERR_PARA      (-1) : Invaild parameter
//      SQLCMD_ERR_SYNTAX    (-2) : Bad Syntax 
//      SQLCMD_ERR_TOKEN     (-3) : Bad token
//      SQLCMD_ERR_LIMITAION (-4) : Beyond limitation
//      SQLCMD_ERR_UNKNOWN  (-99) : Internal error
int parseSQLCommand(const char* inputCmd, int inputCmdLen);

int parseSpeicalEvalArrayCommand
    ( const char  *inputCmd
    , int          inputCmdLen
    , int         *varBeginPos
    , int         *varLength
    );

/* ************************************************************ */
/*    Unit test definition                                      */
/*                                                              */
/* ************************************************************ */

void test_GetCharType();
void test_InitCommonTokenParser();
void test_TokenParser();   
void test_ParseSQLCommand();
void test_ParseSQLLeftAssignCommand();
void test_ParseSpeicalEvalArrayCommand();
//void test_IsSupportedSQLEvalCommand();   

void main(void)
{    
    test_GetCharType();    
    test_InitCommonTokenParser();
    test_TokenParser();
    test_ParseSQLCommand();
    test_ParseSQLLeftAssignCommand();
    test_ParseSpeicalEvalArrayCommand();
    
    printf("done!\n");
    return;
}

int InitCommonTokenParser(const char *input, int len)
{       
    /* check input is vaild*/
    if(input == NULL || len <= 0 || len > MAX_CONTENT_LENGTH )       
        return 0; 

#ifdef ENABLE_TTSYMBOL_CONVERT
    /* convert some special symbol char by ccsid */
    if( bCCSIDConvert != 1 )
    {
        // Some codes of CCSID Convert
        bCCSIDConvert = 1;
    }
#endif

    nCPaserPos = 0;
    nCPaserBufferLength = len;
    
    memcpy( nCPaserBuffer, input, len); 
    nCPaserBuffer[ len ] = '\0';
    
    /* nCPaserBuffer [ MAX_CONTENT_LENGTH + 1]  */
    if ( len < MAX_CONTENT_LENGTH )
    {
        memset( nCPaserBuffer + len + 1, 
                0,
                MAX_CONTENT_LENGTH - len);      
    }

    return 1;
}

// Return token type: 
//      (> 1): token type;
//         0 : TT_BAD 
//        -1 : scan end, no token found
//   -2 ~ -7 : internal errors
int ScanToken(CTOKEN* pToken, int begPos){

    #define SS_INI          0           // Init mode
    #define SS_SKI          1           // Skip mode
    #define SS_BLK          2           // Blank mode
    #define SS_NAM          3           // Name mode
    #define SS_INT          4           // Integer mode
    #define SS_FLO          5           // Float mode
    #define SS_STR          6           // String mode
    #define SS_OT1         -1           // output Token-Name
    #define SS_OT2         -2           // output Token-integer
    #define SS_OT3         -3           // output Token-float
    #define SS_OT4         -4           // output Token-Blank
    #define SS_OT5         -5           // output Single-Symbol
    #define SS_OT6         -8           // output Token-String
    #define SS_BAD        -99           // bad mode

    static int COMMON_SCAN_STATE[7][8] = {
        // -CHAR--NUMBER--BLANK---" " "---"_@$#"---" . "---SYMBOL--END
        { SS_NAM, SS_INT, SS_BLK, SS_STR, SS_NAM, SS_OT5, SS_OT5, SS_SKI }, // SS_INI
        { SS_NAM, SS_INT, SS_BLK, SS_STR, SS_NAM, SS_OT5, SS_OT5, SS_SKI }, // SS_SKI
        { SS_OT4, SS_OT4, SS_BLK, SS_OT4, SS_OT4, SS_OT4, SS_OT4, SS_OT4 }, // SS_BLK
        { SS_NAM, SS_NAM, SS_OT1, SS_OT1, SS_NAM, SS_OT1, SS_OT1, SS_OT1 }, // SS_NAM
        { SS_NAM, SS_INT, SS_OT2, SS_OT2, SS_NAM, SS_FLO, SS_OT2, SS_OT2 }, // SS_INT
        { SS_BAD, SS_FLO, SS_OT3, SS_OT3, SS_BAD, SS_BAD, SS_OT3, SS_OT3 }, // SS_FLO
        { SS_STR, SS_STR, SS_STR, SS_OT6, SS_STR, SS_STR, SS_STR, SS_BAD }, // SS_STR
    };

    int  scanPos;
    int  retPos;    
    int  lastState;
    int  curState;
    int  charType;
    int  findTokenType;
    
    char lastChar;
    char findStringHeadChar;     
    
    scanPos             = begPos;
    retPos              = -1;
    lastState           = SS_INI;
    curState            = SS_INI;
    findTokenType       = -1; 
    lastChar            = 0;
    findStringHeadChar  = 0;
    
    if (begPos >= nCPaserBufferLength) {
        return -1;
    }

    for ( ; findTokenType == -1 && scanPos < nCPaserBufferLength
          ; lastState = curState, scanPos++) 
    {
            
        lastChar = nCPaserBuffer[scanPos];    
        
        charType = GetCharType(lastChar);        
        if (charType == CT_UNKNOWN) {
            
            // skip some char in a string " abc??def "
            if ( lastState == SS_STR )
              continue;           
           
            //unsupport char found
            return -2;
        }
        
        if (  lastState  <  0 || lastState >= 7
            || charType  <  0 || charType  >= 8 )
        {
            return -3; //Invald DFA state
        }

        curState = COMMON_SCAN_STATE[lastState][charType];

        switch (curState) {
        case SS_BAD:            
            return -4;      //Invald DFA state       
            
        case SS_SKI:        
            ++begPos;
            break;
            
        // output Token-Name without curChar
        case SS_OT1:
        
            retPos        = scanPos;
            findTokenType = TT_NAME;
            break;
            
        // output Token-integer( without curChar)
        case SS_OT2:

            retPos        = scanPos ;
            findTokenType = TT_INTEGER;
            break;
            
        // output Token-float( without curChar)
        case SS_OT3:

            retPos        = scanPos ;
            findTokenType = TT_FLOAT;
            break;
            
        // output Token-Blank( without curChar)
        case SS_OT4:

            retPos        = scanPos ;
            findTokenType = TT_BLANK;
            break;  
            
        // output Single-Symbol (with curChar)
        case SS_OT5:
        
            retPos = scanPos + 1;
			if (retPos != (begPos + 1))
                 return -5;      //Invald DFA state 
             
			findTokenType = TT_SYMBOL;
            break;
            
        // output Token-String with curChar 
        case SS_OT6:
            
            if (findStringHeadChar == 0)
                return -6;          //Null String Char

            // Start with " and new the lastChar is '
            if (findStringHeadChar != lastChar) {

                // Continue scan to "StringBeginSymbol"
                curState = SS_STR;
                
            } else {
                
                retPos         = scanPos + 1;
                findTokenType  = TT_STRING;
            }
            
            break;
            
        case SS_STR:
        
            if (findStringHeadChar == 0) {
                findStringHeadChar = lastChar;
            }  
            
            break;            
        }// switch (curState)
        
    }//for
    
    if (findTokenType == -1) {

        switch (curState) 
        {
        case SS_SKI:
            return -1;      // String end in \n or \r
                            // NULL TOKEN
        case SS_NAM:
            findTokenType = TT_NAME;
            break;
        case SS_INT:
            findTokenType = TT_INTEGER;
            break;
        case SS_FLO:
            findTokenType = TT_FLOAT;
            break;
        case SS_BLK:
            findTokenType = TT_BLANK;
            break;
        default:
            findTokenType = TT_BAD;
        }
        
        retPos = nCPaserBufferLength;        
    }
        
    if( pToken != NULL )
    {  
        pToken->ntype   = findTokenType;
        pToken->nEndPos = retPos;  
        pToken->nLength = retPos - begPos;
        
        // Invaild length
        if( pToken->nLength <=0 )
            return -7;

        memcpy( pToken->tString, 
                nCPaserBuffer + begPos, 
                pToken->nLength); 
    }
    
    return findTokenType;
}

int isSingleSymbol(CTOKEN* pToken, char c) {
    return pToken != NULL  
            && pToken->ntype == TT_SYMBOL 
            && pToken->nLength == 1
            && pToken->tString[0] == c;
}

int isStringToken(CTOKEN* pToken) {
    
    return pToken != NULL  
            && pToken->ntype == TT_STRING;
}

int isExtenderChar(char c) {
        
    return ( CC_ATSIGN == c )       /*Symbol @    */
         ||( CC_CURRENCY == c )     /*Symbol $    */
         ||( CC_NUMSIGN  == c );    /*Symbol #    */ 
}

int isSupportedNameHeadSymbol(CTOKEN* pToken) {
    
    if( pToken != NULL  
            && pToken->ntype == TT_SYMBOL 
            && pToken->nLength == 1 
            && isExtenderChar(pToken->tString[0]))
    {
        return 1;
    }
    
    return 0;
}

int PeekToken(CTOKEN* pToken) {
    
    int     thisTokenType;
    int     nextTokenType;
    CTOKEN  nextToken;
    CTOKEN* pNextToken;
    int     lastTokenEndPos;
    
    static char buffer [ MAX_CONTENT_LENGTH ];
    int         bufPos;
    
    static TT_CombinedSymbol** hittingSymbols = NULL;
    
    TT_CombinedSymbol* pHittingSymbol;
    int    hittingSymbolCount;
    int    count;
    int    hitCount;
    int    lastEmptySlot;
    char   c;
    int    i;
    
    /* none token found or internal errors               */
    if( (thisTokenType = ScanToken(pToken, nCPaserPos)) < 0 )
        return thisTokenType;
    
    /* 
    // @ABC or ABC@
    if( (isSupportedNameHeadSymbol(pToken) 
        && ( nextTokenType = ScanToken(&nextToken, pToken->nEndPos )) >= 0 
        && ( pToken->nEndPos + nextToken.nLength) == nextToken.nEndPos ) 
    {
        //init buffer                                       
        bufPos = 0;
        count = 0;
        
        //Append this token content to buffer                
        //Update last token position                         
        buffer[ bufPos++ ] = pToken->tString[0];
        lastTokenEndPos = pToken->nEndPos;
        
        while ( nextTokenType >= 0
             && ( isSupportedNameHeadSymbol(&nextToken )
                || isSingleSymbol(&nextToken, CC_UNDERLINE)
                || nextToken.ntype == TT_NAME 
                || nextToken.ntype == TT_INTEGER )
             && ( lastTokenEndPos + nextToken.nLength) == nextToken.nEndPos ) 
        {
            
            //Append nextToken content to buffer
            memcpy( buffer+bufPos, nextToken.tString, nextToken.nLength);
            bufPos += nextToken.nLength;
            
            if(  nextToken.ntype == TT_NAME || nextToken.ntype == TT_INTEGER )
            {   count++;                
            }
            
            lastTokenEndPos = nextToken.nEndPos;            
            nextTokenType   = ScanToken(&nextToken, nextToken.nEndPos );
        }

        if ( count > 0 ) // has one string at least
        { 
            //update token
            pToken->ntype   = TT_NAME;
            pToken->nEndPos = lastTokenEndPos;  
            pToken->nLength = bufPos;  
            
            memcpy( pToken->tString, buffer, bufPos );
            pToken->tString[pToken->nLength] = '\0';            
            return pToken->ntype;
        }
    }
    */
    
    // "ABC""DEF" should be a single String
    if(( isStringToken( pToken )) 
        && ( nextTokenType = ScanToken(&nextToken, pToken->nEndPos )) >= 0 
        && ( pToken->nEndPos + nextToken.nLength ) == nextToken.nEndPos
        && ( nextToken.ntype == TT_STRING )) 
    {
        //init buffer                                       
        bufPos = 0;
        
        //Append this token content to buffer 
        memcpy( buffer+bufPos, pToken->tString, pToken->nLength);
        bufPos += pToken->nLength;  
        
        //Update last token position   
        lastTokenEndPos = pToken->nEndPos;
        
        while( nextTokenType == TT_STRING             
           &&( lastTokenEndPos + nextToken.nLength) == nextToken.nEndPos ) 
        {
            
            //Append nextToken content to buffer
            memcpy( buffer+bufPos, nextToken.tString, nextToken.nLength);
            bufPos += nextToken.nLength;            
            lastTokenEndPos = nextToken.nEndPos;
            nextTokenType = ScanToken(&nextToken, nextToken.nEndPos );
        }
        
        //update token
        pToken->ntype   = TT_STRING;
        pToken->nEndPos = lastTokenEndPos;  
        pToken->nLength = bufPos;             
        memcpy( pToken->tString, buffer, bufPos );
        pToken->tString[pToken->nLength] = '\0';   
        return pToken->ntype;
    }
    
    // -123 or -1.5
    if (isSingleSymbol(pToken, CC_MINUS) 
        && ( nextTokenType = ScanToken(&nextToken, pToken->nEndPos )) >= 0 
        && ( pToken->nEndPos + nextToken.nLength ) == nextToken.nEndPos
        && ( nextToken.ntype == TT_FLOAT || nextToken.ntype == TT_INTEGER) ) 
    {

        /*Append nextToken content to thisToken            */
        memcpy( pToken->tString + pToken->nLength, 
                nextToken.tString, 
                nextToken.nLength);
                
        pToken->nLength += nextToken.nLength;
        pToken->ntype    = nextToken.ntype;
        pToken->nEndPos  = nextToken.nEndPos;          
        pToken->tString[pToken->nLength] = '\0';
        
        return pToken->ntype;
    }
    
    // Combined Symbols "%%"
    if (pToken->ntype == TT_SYMBOL && pToken->nLength == 1) 
    {
        
        hittingSymbolCount = CombineSymbolCount;   /*init hittingSymbolCount*/
        bufPos             = 0;                    /*init buffer            */
        count              = 0;
        pNextToken         = pToken;
        lastTokenEndPos    = pToken->nEndPos - 1;  /* pToken->nLength == 1  */
        
        /*Init hitting symbols memory */
        if( hittingSymbols == NULL )
            hittingSymbols = (TT_CombinedSymbol**)
                malloc( sizeof(TT_CombinedSymbol*) * CombineSymbolCount);
        
        /*copy combined symbol pointers */  
        i = 0;     
        for (; i < CombineSymbolCount; ++i )            
            hittingSymbols[i] = &(ttCombinedSymbol[i]);

        while (count < MaxCombineSymbolLength 
                && hittingSymbolCount > 0 
                && pNextToken != NULL
                && pNextToken->ntype == TT_SYMBOL 
                && pNextToken->nLength == 1                 // Is single symbol             
                && (lastTokenEndPos + 1) == pNextToken->nEndPos// need continue
               ) 
        {

            c               = pNextToken->tString[0];
            hitCount        = 0;
            lastEmptySlot   = -1;
            i               = 0;
            for (; i < hittingSymbolCount; ++i) 
            {
                pHittingSymbol = hittingSymbols[i];

                // hit char
                if ( count < pHittingSymbol->Length 
                    && pHittingSymbol-> Name[count] == c )    
                 {
                    if (lastEmptySlot != -1) 
                        hittingSymbols[lastEmptySlot++] = pHittingSymbol;

                    ++hitCount;

                } else {
                    
                    if (lastEmptySlot == -1) 
                        lastEmptySlot = i;
                }
            }

            hittingSymbolCount = hitCount;
            if (hitCount == 0) {
                break; // break while
            }

            buffer[ bufPos++ ] = c;
            lastTokenEndPos = pNextToken->nEndPos;
            ++count;
            
            if ( ScanToken(&nextToken, lastTokenEndPos) >= 0 )
                pNextToken = &nextToken;
            else 
                pNextToken = NULL; 
        }

        if (count > 0 && bufPos > 0 ) 
        {
            i = 0;     
            for (; i < CombineSymbolCount; ++i )   
            {
                if( ttCombinedSymbol[i].Length == bufPos 
                  && memcmp( ttCombinedSymbol[i].Name,
                             buffer,
                             bufPos) == 0)
                {
                    pToken->nLength  = bufPos;
                    pToken->ntype    = TT_COMBINE;
                    pToken->nEndPos  = lastTokenEndPos;
                    
                    /*Append buffer content to thisToken            */
                    memcpy( pToken->tString, buffer, bufPos);        
                    pToken->tString[pToken->nLength] = '\0';
                    
                    return pToken->ntype;
                }
            }//for         
        }//if
    }//Combined Symbols "%%"   

    return thisTokenType;
}

int isNameToken(CTOKEN* pToken, const char* name, int len) {
    
    if( ( pToken == NULL            )
      ||( pToken->ntype != TT_NAME  )
      ||( pToken->nLength != len    )
      )
    {   return 0;
    }
    
    return ( name == NULL                           )   // match any characters
      ||   ( memcmp(pToken->tString, name, len) == 0);  // match input characters
}


int isIntegerToken(CTOKEN* pToken, int* num) {
    
    if(pToken == NULL 
        || pToken->ntype != TT_INTEGER 
        || pToken->nLength <= 0)
        return 0;
    
    if (num != NULL)
    {
        pToken->tString[pToken->nLength] = '\0';
        sscanf(pToken->tString, "%d", num );
    }
     
    return 1;
}


int isSpaceToken(CTOKEN* pToken) 
{     
    return pToken != NULL && pToken->ntype == TT_BLANK;
}


int NextToken(CTOKEN* pToken) 
{
    int tokenType;
    
    tokenType = PeekToken(pToken);
    if( tokenType >= 0 )
        nCPaserPos = pToken->nEndPos;
    else
        nCPaserPos = nCPaserBufferLength;
    
    return tokenType;
}

int GetCharType(char c)
{
    if( isalpha(c)        ) return CT_CHAR;    
    if( isdigit(c)        ) return CT_NUM; 
    if( CC_NEW_LINE  == c ) return CT_END;    
    if( CC_RETURN    == c ) return CT_END; 
    if( CC_SPACE     == c ) return CT_BLANK;  
    if( CC_TAB       == c ) return CT_BLANK; 
    if( CC_DQUOTE    == c ) return CT_STRING; 
    if( CC_SQUOTE    == c ) return CT_STRING; 
    if( CC_UNDERLINE == c ) return CT_SPECIAL; 
    if( CC_ATSIGN    == c ) return CT_SPECIAL;      /*Symbol @    */
    if( CC_CURRENCY  == c ) return CT_SPECIAL;      /*Symbol $    */
    if( CC_NUMSIGN   == c ) return CT_SPECIAL;      /*Symbol #    */ 
    if( CC_COLON     == c ) return CT_SINGLE; 
    if( CC_SEMICOLON == c ) return CT_SINGLE;    
    if( CC_COMMA     == c ) return CT_SINGLE; 
    if( CC_LBRACKET  == c ) return CT_SINGLE;  
    if( CC_RBRACKET  == c ) return CT_SINGLE;  
    if( CC_LBRACE    == c ) return CT_SINGLE; 
    if( CC_RBRACE    == c ) return CT_SINGLE; 
    if( CC_LPARETN   == c ) return CT_SINGLE; 
    if( CC_RPARETN   == c ) return CT_SINGLE; 
    if( CC_EQUAL     == c ) return CT_SINGLE; 
    if( CC_SLASH     == c ) return CT_SINGLE; 
    if( CC_MINUS     == c ) return CT_SINGLE; 
    if( CC_QUESTION  == c ) return CT_SINGLE;  
    if( CC_AMPERSAND == c ) return CT_SINGLE;   
    if( CC_ASTERISK  == c ) return CT_SINGLE;  
    if( CC_PERCENT   == c ) return CT_SINGLE;    
    if( CC_TILED     == c ) return CT_SINGLE; 
    if( CC_VBAR      == c ) return CT_SINGLE; 
    if( CC_BSLASH    == c ) return CT_SINGLE; 
    if( CC_HAT       == c ) return CT_SINGLE;    
    if( CC_PERIOD    == c ) return CT_PERIOD; 

    return CT_UNKNOWN; //  default: 
}


void throwSQLBadSyntaxError()
{
    longjmp( error_env_ttparser, JUMP_ERROR_HAPPENED );
}

void checkRecursion()
{
    if( ttContext.OperationCount++ >= MAX_SQLCMD_PARSE_COUNT )
       throwSQLBadSyntaxError(); 
}

int hasMoreTokens()
{
    return getContextTokenPos() < ttContext.TokenCount;
}

CTOKEN* getCurSQLToken()
{
    if( getContextTokenPos() >= ttContext.TokenCount)
        return NULL;
        
    return &(ttContext.Tokens[getContextTokenPos()]);
}

int getContextTokenPos()
{
    return ttContext.TokenCurPosStack[getContextStackDepth()];
}

int getContextBufferLen( )
{
    return ttContext.OutputBufLenStack[getContextStackDepth()];
}

int getContextStackDepth( )
{
    if( ttContext.StackDepth >= MAX_SQLCMD_STACK_DEPTH )
       throwSQLBadSyntaxError(); 

    return ttContext.StackDepth;
}

void appendContextBuffer(const char* v, int len)
{
    if(v == NULL || len <= 0 
      // not enough output buffer
     || (getContextBufferLen() + len ) >= MAX_CONTENT_LENGTH * 2 )
       throwSQLBadSyntaxError();  
    
    memcpy( ttContext.OutputBuf + getContextBufferLen(), v, len);
}  

void updateStack(int addTokenCount, int addBufferLength)
{
    int pos;
    int len;
    
    if(ttContext.StackDepth >= ( MAX_SQLCMD_STACK_DEPTH - 1) 
      || addTokenCount < 0 
      || addBufferLength < 0 )
      throwSQLBadSyntaxError(); 

    pos = getContextTokenPos()  + addTokenCount;
    len = getContextBufferLen() + addBufferLength;
    
    if( pos >= MAX_SQLCMD_STACK_DEPTH 
        || len >= MAX_SQLCMD_STACK_DEPTH )
       throwSQLBadSyntaxError();     // beyond buffer 
     
    ttContext.StackDepth++;
    ttContext.TokenCurPosStack [ttContext.StackDepth] = pos;
    ttContext.OutputBufLenStack[ttContext.StackDepth] = len;
}

void rollbackStack(int newDepth)
{
    if( newDepth < 0 || newDepth > getContextStackDepth() )
       throwSQLBadSyntaxError();  
  
    ttContext.StackDepth = newDepth;    
}

int ignoreBlank()
{
    CTOKEN* pToken;
    
    checkRecursion();
    
    if((pToken = getCurSQLToken()) != NULL
       && isSpaceToken(pToken)) 
    {
        updateStack(1, 0);
    }
    
    return 1;
}

int matchBlank()
{   
    CTOKEN* pToken;
    
    checkRecursion();
    
    if((pToken = getCurSQLToken()) != NULL
       && isSpaceToken(pToken)) 
    {
        /* output: a blank character " "               */
        appendContextBuffer(pToken->tString,1 );
        updateStack(1, 1);
        return 1;
    }
    
    return 0;
}

int matchBlankNotOutput()
{   
    CTOKEN* pToken;
    
    checkRecursion();
    
    if((pToken = getCurSQLToken()) != NULL
       && isSpaceToken(pToken)) 
    {
        updateStack(1, 0);
        return 1;
    }
    
    return 0;
}

int matchCombinedSymbol(const char* symbol, int len)
{
    CTOKEN* pToken;
    
    checkRecursion();
    
    if(symbol != NULL && len > 0
       && (pToken = getCurSQLToken())!= NULL 
       && pToken->ntype   == TT_COMBINE
       && pToken->nLength == len
       && ( memcmp(pToken->tString, symbol, len) == 0)) 
    {        
        /* output token */
        appendContextBuffer(pToken->tString, pToken->nLength);
        updateStack(1, pToken->nLength);
        return 1;
    }
    
    return 0;
}

int matchInteger(int* num )
{
    CTOKEN* pToken;

    checkRecursion();
    
    if( num != NULL 
        && (pToken = getCurSQLToken() )!= NULL 
        && isIntegerToken( pToken, num))
    {
        /* output token */
        appendContextBuffer(pToken->tString, pToken->nLength);
        updateStack(1, pToken->nLength);
        return 1;
    }
    
    return 0;
}

int matchNameNotOutput(const char* value, int length)
{
    CTOKEN* pToken;
    
    checkRecursion();
    
    if( ( length > 0                          )
     && ( (pToken = getCurSQLToken())!= NULL  )
     && ( isNameToken( pToken, value, length) )
      )
    {
        updateStack(1, 0);        
        return 1;
    }
    
    return 0;
}

int matchSymbol(char symbol)
{
    CTOKEN* pToken;
    
    checkRecursion();
    
    if((pToken = getCurSQLToken())!= NULL 
        && pToken->ntype   == TT_SYMBOL
        && pToken->nLength == 1
        && pToken->tString[0] == symbol)
    {
        /* output symbol */
        appendContextBuffer(pToken->tString, 1);
        updateStack(1, 1);
        return 1;
    }
    
    return 0;
}

/* FormatOption := :[S|U|A|X] (int) [int] */
int matchFormatOption(int* mode, int* len, int* pos)
{
    int depth;
    int num;
    
    checkRecursion();
    
    /* save depth of option */
    depth = getContextStackDepth();
    
    *mode = SQLDISPLAY_MODE_INVAILD;
    *len = 0;                           // auto length
    *pos = 0;                           // default position
    
    /* example ": s 10" */
    if( ignoreBlank() 
     && matchSymbol(CC_COLON) 
     && ignoreBlank())
    {
        /* format 's', EBCDIC CCSID 65535          */
        if( matchNameNotOutput("s",1)
         || matchNameNotOutput("S",1) )
        {   *mode = SQLDISPLAY_MODE_EBCDIC; 
        }        
        /* format 'u', Unicode CCSID 13488         */
        else if( matchNameNotOutput("u",1)
             || matchNameNotOutput("U",1) )
        {   *mode = SQLDISPLAY_MODE_UNICODE;
        }        
        /* format 'a', ASCII related job CCSID     */
        else if( matchNameNotOutput("a",1)
              || matchNameNotOutput("A",1) )
        {   *mode = SQLDISPLAY_MODE_ASCII;
        }        
        /* format 'x', Hexadecimal formatting      */
        else if( matchNameNotOutput("x",1)
              || matchNameNotOutput("X",1) )
        {   *mode = SQLDISPLAY_MODE_HEX;
        }        
        /* Invaild formatting                      */
        else if( matchNameNotOutput(NULL,1) )
        {    *mode = SQLDISPLAY_MODE_INVAILD;
        }
        /* match failed */
        else
        {
            rollbackStack(depth);
            return 0;
        }
        
        /* match succ               */
        /* update depth of option   */
        depth = getContextStackDepth();
        
        if( matchBlank() 
          && matchSymbol('(') 
          && ignoreBlank()
          && matchInteger(&num)
          && ignoreBlank()
          && matchSymbol(')'))
        {
            *pos  = num;
            depth = getContextStackDepth();
        }
        else
            rollbackStack(depth);
        
        if( matchBlank() && matchInteger(&num))
            *len = num;
        else
            rollbackStack(depth);
        
        return 1;
    }
  
    /* match failed */
    rollbackStack(depth);
    return 0;
}


/*   OrdinaryIdentifier  := [A-Za-z]{NAME}          */
int matchOrdinaryIdentifier()
{
    CTOKEN* pToken;
    
    checkRecursion();
    
    if((pToken = getCurSQLToken())!= NULL 
        && pToken->ntype == TT_NAME
        && pToken->nLength > 0
        && (GetCharType(pToken->tString[0]) == CT_CHAR 
         || isExtenderChar(pToken->tString[0])))
    {
        /* output token */
        appendContextBuffer(pToken->tString, pToken->nLength);
        updateStack(1, pToken->nLength);
        return 1;
    }
    
    return 0;
}

/*    DelimitedIdentifier := {\"String\"}             */
int matchDelimitedIdentifier()
{
    CTOKEN* pToken;
    
    checkRecursion();
    
    static char tmpBuf [ MAX_CONTENT_LENGTH + 1];
    int pos;
    
    if((pToken = getCurSQLToken())!= NULL 
        && pToken->ntype == TT_STRING
        && pToken->nLength > 2            // ""  is invaild identifier
        && pToken->tString[0] == '\"')    // "a" At least
    {
        // The blank in the tail should be dropped
        memcpy( tmpBuf, pToken->tString, pToken->nLength);
        
        // 012345 ( Len == 6)
        // "abc "
        //     |
        //   pos = 4 => n - 2;
        pos = pToken->nLength - 2;
        
        while( pos > 0 && tmpBuf[pos] == CC_SPACE)
            --pos;
                
        // ( pos == 0 ) ==> ""  ; is invaild identifier
        if( pos > 0 )
        {
            // add a " at tail
            tmpBuf[ pos + 1 ] = '\"';
            
            // output token
            // length = pos + 2
            appendContextBuffer(tmpBuf, pos + 2);
            updateStack(1, pos + 2);
            return 1;         
        }
    }
  
    return 0;
}

/* SQLIdentifier := {OrdinaryIdentifier}         */
/*                | {DelimitedIdentifier}        */
int matchSQLIdentifier()
{
    int depth;
    
    checkRecursion();
    
    /* save depth of option                      */
    depth = getContextStackDepth();
    
    if( matchOrdinaryIdentifier() 
     || matchDelimitedIdentifier())
    {
        return 1;
    }
    
    rollbackStack(depth);
    return 0;
}

/*  SQLLabel := {OrdinaryIdentifier}         */
int matchSQLLabel()
{
    int depth;
    
    checkRecursion();
    
    /* save depth of option                  */
    depth = getContextStackDepth();
    
    if( matchOrdinaryIdentifier())
    {
        return 1;
    } 
    
    rollbackStack(depth);
    return 0;
}

/*  SQLVariable := %%{SQLIdentifier}            */
/*              |  %%{SQLLabel}.{SQLIdentifier}  */
int matchSQLVariable()
{
    int depth;
    
    checkRecursion();
    
    /* save depth of option */
    depth = getContextStackDepth();
    
    /* %%TST.VAR */
    if( matchCombinedSymbol(CombinedSymbolSQLMAP.Name, 
                            CombinedSymbolSQLMAP.Length) 
        && ignoreBlank()
        && matchSQLLabel()
        && ignoreBlank()
        && matchSymbol('.')
        && ignoreBlank()
        && matchSQLIdentifier())
    {
        return 1;
    }
    
    rollbackStack(depth);
    
    /* %%VAR */
    if( matchCombinedSymbol(CombinedSymbolSQLMAP.Name, 
                            CombinedSymbolSQLMAP.Length) 
        && ignoreBlank()
        && matchSQLIdentifier() ) 
    {
        return 1;
    }   
    
    rollbackStack(depth);
    return 0;
}

/* SQLExpression       :=  {SQLVariable}          */
int matchSQLExpression()
{
    int depth;
    
    checkRecursion();
    
    /* save depth of option                  */
    depth = getContextStackDepth();
    
    if( matchSQLVariable() )
    {
        return 1;
    }    
    
    rollbackStack(depth);
    return 0;
}

/* *********************************************** */
/*  SQLDisplayComd :=                              */
/*              {EVAL}{SQLExpression}{FormatOption}*/
/*            | {EVAL}{SQLExpression}              */
/*  NFA match algorithm                            */
/* *********************************************** */
int matchSQLDisplayCommand( int* mode, int* len, int* pos)
{
    int depth;
    int depthOfSQLExpression;
       
    checkRecursion();
    
    /* save depth of option                  */
    depth = getContextStackDepth();
    
    /*  match "EVAL " */
    if(  (matchNameNotOutput( "EVAL",4) || matchNameNotOutput("eval",4) )
       && matchBlankNotOutput()
       && matchSQLExpression())
    {
          /* Save SQL expression depth                   */
          depthOfSQLExpression = getContextStackDepth();
          
          /*  match "EVAL {SQL-Expression}"              */
          if( !hasMoreTokens())
          {
              *mode = SQLDISPLAY_MODE_AUTO;
              *len  = 0;              
              *pos  = 0;
              
              return 1;   
          }

          /*  match "EVAL {SQL-Expression} {Format}"      */
          if( matchFormatOption(mode, len, pos)
             && !hasMoreTokens()) 
          {
              
             /* ignore content after "depthOfSQLExpression" */
             rollbackStack( depthOfSQLExpression);              
             return 1;                      
          }// matchSQLFormatOption            
    }// End of match "EVAL "

    rollbackStack(depth);
    return 0;
}


/* *********************************************** */
/*  SQLDisplayComd := {EVAL}{SQLVariable} = *      */
/* *********************************************** */
int matchSQLLeftAssignCommand()
{
    int depth;
    int depthOfSQLVariable;
       
    checkRecursion();
    
    /* save depth of option                  */
    depth = getContextStackDepth();
    
    /*  match "EVAL " */
    if( (matchNameNotOutput( "EVAL",4) || matchNameNotOutput("eval",4) )
       && matchBlankNotOutput()
       && matchSQLVariable())
    {
          /* Save SQL Variable depth                   */
          depthOfSQLVariable = getContextStackDepth();
          
          if( ignoreBlank()  
           && matchSymbol(CC_EQUAL) 
           && ignoreBlank() 
           && hasMoreTokens())
          {
             /* ignore content after "depthOfSQLVariable" */
             rollbackStack( depthOfSQLVariable); 
             return 1; 
          }
    }
    
    rollbackStack(depth);
    return 0;
}

int parseSQLCommand(const char* inputCmd, int inputCmdLen) 
{  
    int tokenType;
    int begin;
    
    int depth;    
    int formatMode;
    int formatLength;
    int formatPosition;
    int CmdType;
 
    /* ------------- main rountine ------------- */    
    if ( inputCmd == NULL || inputCmdLen <= 0)
        return SQLCMD_ERR_PARA;     //invaild parameter
        
    if ( inputCmdLen > MAX_CONTENT_LENGTH )
        return SQLCMD_ERR_LIMITAION; //Out of space
    
    /* ----------- init local vars ------------ */ 
    tokenType                     = -1;
    begin                         = 0;
    
    /* ----------- init global vars ------------ */   
    ttContext.TokenCount          = 0 ; 
    ttContext.StackDepth          = 0 ;
    ttContext.OperationCount      = 0 ;
   
    ttContext.CommandType         = SQLCMD_TYPE_INVAILD;
    ttContext.DisplayFormatMode   = SQLDISPLAY_MODE_INVAILD;
    ttContext.DisplayFormatLength = 0;   // 0: auto length     
    ttContext.DisplayFormatPosition = 0; // 0: default position    
    
    // reset output buffer 
    memset( ttContext.OutputBuf, 0, MAX_CONTENT_LENGTH * 2 + 1);
    
    // reset parser stack 
    memset( ttContext.TokenCurPosStack, 
                0, 
                sizeof(int) *(MAX_SQLCMD_STACK_DEPTH + 1));
                
    memset( ttContext.OutputBufLenStack, 
                0,
                sizeof(int) *(MAX_SQLCMD_STACK_DEPTH + 1));     
    
    /* ----------- init token parser ---------- */ 
    if(!InitCommonTokenParser(inputCmd, inputCmdLen))
        return SQLCMD_ERR_UNKNOWN ; // Unknown error     
    
    /* set Jump content                          */ 
    if ( setjmp(error_env_ttparser) == JUMP_ERROR_HAPPENED )           
        return SQLCMD_ERR_SYNTAX ; // Bad Syntax
    
   
    /* Scan all tokens                           */
    while( ttContext.TokenCount <= MAX_TOKEN_COUNT )
    {     
        tokenType = NextToken(&(ttContext.Tokens[ttContext.TokenCount]));
        
        if( tokenType == 0 )
            return SQLCMD_ERR_TOKEN;        // Bad token
        else if( tokenType < -1)
            return SQLCMD_ERR_UNKNOWN;      // internal error
        else if( tokenType == -1)
            // scan token end, 
            break;      // break while  
        else if( ttContext.TokenCount == MAX_TOKEN_COUNT )
            return SQLCMD_ERR_LIMITAION;    // Out of space        
       
        ++ttContext.TokenCount;
    }
    
    /* drop tail space in */
    while( ttContext.TokenCount > 0 
        && isSpaceToken(&( ttContext.Tokens[ttContext.TokenCount - 1])))
        --ttContext.TokenCount;
    
    /* Skip space in the head */     
    begin = 0;
    while ( begin < ttContext.TokenCount 
        && isSpaceToken(&(ttContext.Tokens[begin])))
        ++begin;      
 
    /* all tokens are dropped */
    if ( begin >= ttContext.TokenCount )
        return SQLCMD_ERR_SYNTAX ; // Bad Syntax
    
    /* current depth position */
    depth = getContextStackDepth();
    
    /* update token position*/
    ttContext.TokenCurPosStack[depth] = begin;
    
    /* ******************************************* */
    /* Try SQL Display Command                     */
    /* ******************************************* */
    if( matchSQLDisplayCommand( &formatMode, 
                                &formatLength, 
                                &formatPosition) )
    {
        ttContext.CommandType         = SQLCMD_TYPE_DISPLAY;
        ttContext.DisplayFormatMode   = formatMode;
        ttContext.DisplayFormatLength = formatLength;
        ttContext.DisplayFormatPosition = formatPosition;
        
        goto SUCC;
    }
    
    /* ******************************************* */
    /* Try SQL Left Assign Command                 */
    /* ******************************************* */
    
    /* roll back old depth */
    rollbackStack( depth );
    
    if( matchSQLLeftAssignCommand() )
    {        
        ttContext.CommandType = SQLCMD_TYPE_LEFT_ASSIGN;  
        goto SUCC;
    }
    
    /* ******************************************* */
    /* Fail:                                       */
    /* ******************************************* */

    /* roll back old depth */
    rollbackStack( depth );  
    
    /* no match rules */
    return SQLCMD_ERR_SYNTAX; // Bad Syntax 
    
SUCC:
    
    /* clear garbage content */ 
    if( getContextBufferLen() < MAX_CONTENT_LENGTH * 2 )
    {
        memset( ttContext.OutputBuf + getContextBufferLen(), 
                0, 
                MAX_CONTENT_LENGTH*2- getContextBufferLen());      
    }
    
    return SQLCMD_ERR_SUCC;
}


int parseSpeicalEvalArrayCommand
    ( const char  *inputCmd
    , int          inputCmdLen
    , int         *varBeginPos
    , int         *varLength
    ) 
{  
    int begin = 0;
    int end   = inputCmdLen-1;

    while( begin <= end && *(inputCmd+begin) == CC_SPACE )
        ++begin;

    // Start with "EVAL "
    if( begin >= (end - 5) || 
        ( memcmp(inputCmd+begin, "eval ", 5) != 0 
      && memcmp(inputCmd+begin, "EVAL ", 5) != 0 ))
        return SQLCMD_ERR_SYNTAX;
    else
        begin += 5;
    
    // Skip head blanks
    while( begin <= end && *(inputCmd+begin) == CC_SPACE )
        ++begin;
    
    // Skip tail blanks
    while( begin <= end && *(inputCmd+end) == CC_SPACE )
        --end;

    // End with ")"
    if( begin >= (end - 1) || *(inputCmd+end) != CC_RPARETN)
        return SQLCMD_ERR_SYNTAX;
    else
        --end;

    // Skip tail blanks
    while( begin <= end && *(inputCmd+end) == CC_SPACE )
        --end;

    // End with "*"
    if( begin >= (end - 1) || *(inputCmd+end) != CC_ASTERISK)
        return SQLCMD_ERR_SYNTAX;
    else
        --end;

    // Skip tail blanks
    while( begin <= end && *(inputCmd+end) == CC_SPACE )
        --end;

    // End with "("
    if( begin >= (end - 1) || *(inputCmd+end) != CC_LPARETN)
        return SQLCMD_ERR_SYNTAX;
    else
        --end;

    // Skip tail blanks
    while( begin <= end && *(inputCmd+end) == CC_SPACE )
        --end;
    
    
    if( begin > end )
        return SQLCMD_ERR_SYNTAX;


    *varBeginPos = begin;
    *varLength   = end - begin + 1;
 
    return SQLCMD_ERR_SUCC;
}

/* ************************************************************ */
/*    Unit test definition                                      */
/*                                                              */
/* ************************************************************ */

void test_GetCharType_1(const char* input, const char* expect)
{     
    char    input_char;
    int     output_type;
    int     i; 
    
    int input_len;
    int expect_len;
    int output_len;
    
    char output[256];   
    
    input_len  = strlen(input);
    expect_len = strlen(expect);
    output_len = 0;
    
    for(i = 0;i < input_len ; ++i )
    {
        input_char  = *(input + i);
        output_type = GetCharType(input_char);        
        output_len += sprintf(output+output_len, 
                              "%d", 
                              output_type);     
    }
    
    output[output_len] = '\0';
    
    if(  output_len != expect_len 
      || strcmp(output, expect) != 0 )
    {
        printf("not-match: in=[%s], out=[%s], [expect]=%s\n",                     
                    input, 
                    output, 
                    expect); 
                    
        assert(0);
    } 
}

void test_GetCharType()
{  
    printf("test_GetCharType: ");
    
    test_GetCharType_1("abc123\'\"  %?\n\r~|\\^","000111332266778488");
    test_GetCharType_1("@$#","888");
    printf("succ!\n");
}

void test_InitCommonTokenParser()
{
    printf("test_InitCommonTokenParser: ");
    
    assert(InitCommonTokenParser(NULL, 0) == 0);
    assert(InitCommonTokenParser(NULL, 1) == 0);
    assert(InitCommonTokenParser("test",4) == 1);
    assert(nCPaserPos == 0);
    assert(nCPaserBufferLength == 4);
    assert(strlen(nCPaserBuffer) == 4);
    assert(memcmp(nCPaserBuffer,"test",4) == 0);
    printf("succ!\n");
}

char toTokenType(int t) {
    switch (t) {
    case TT_BAD:
        return 'B';
    case TT_BLANK:
        return 'X';
    case TT_SYMBOL:
        return 'S';
    case TT_COMBINE:
        return 'C';
    case TT_NAME:
        return 'N';
    case TT_STRING:
        return 'T';
    case TT_INTEGER:
        return 'I';
    case TT_FLOAT:
        return 'F';
    default:
        return 'U';
    }
}
        
void _testTokenParser(
        const char*  input, 
        const char*  expect)
{   
    int     type;
    int     index;
    CTOKEN  token; 
    
    int  bufPos = 0;
    char buffer [ 4096 ];  
    
    assert( input != NULL);
    assert( expect != NULL);
    
    assert( InitCommonTokenParser(input, strlen(input)) );
    
    bufPos  = 0; 
    memset( buffer, 4096, 0 );
    
    while ((type = NextToken(&token)) >= 0) 
    {
        //assert( ++index <= expect_len ); 
        buffer[bufPos++] = '[';        
        bufPos += sprintf(buffer+bufPos, "%c:", toTokenType(token.ntype) );
        bufPos += sprintf(buffer+bufPos, "%d:", token.nLength );
        bufPos += sprintf(buffer+bufPos, "%d:", token.nEndPos );        
        memcpy (buffer+bufPos, token.tString, token.nLength );
        bufPos += token.nLength;
        buffer[bufPos++] = ']'; 
        buffer[bufPos++] = ';';
        buffer[bufPos++] = ' ';
	}
    
    assert( bufPos > 0  );
    buffer[--bufPos] = '\0';

    if( strcmp(buffer,expect) != 0 )
    {
        printf("input : {%s}\n", input); 
        printf("output: {%s}\n", buffer);
        printf("expect: {%s}\n", expect);
        
        assert(0);
    }
}

void test_TokenParser()
{
    printf("test_TokenParser: ");
    
    _testTokenParser("NBR(*)", "[N:3:3:NBR]; [S:1:4:(]; [S:1:5:*]; [S:1:6:)];");

    _testTokenParser("ABC123", "[N:6:6:ABC123];");

    _testTokenParser("123ABC", "[N:6:6:123ABC];");

    _testTokenParser("ABC 123", "[N:3:3:ABC]; [X:1:4: ]; [I:3:7:123];");

    _testTokenParser("ABC -123", "[N:3:3:ABC]; [X:1:4: ]; [I:4:8:-123];");

    _testTokenParser("ABC -123.5", "[N:3:3:ABC]; [X:1:4: ]; [F:6:10:-123.5];");

    _testTokenParser("123 ABC", "[I:3:3:123]; [X:1:4: ]; [N:3:7:ABC];");

    _testTokenParser("123_ABC", "[N:7:7:123_ABC];");

    _testTokenParser("ABC_123", "[N:7:7:ABC_123];");

    _testTokenParser("ABC_123___", "[N:10:10:ABC_123___];");

    _testTokenParser("_ABC123", "[N:7:7:_ABC123];");

    _testTokenParser("____ABC123", "[N:10:10:____ABC123];");

    _testTokenParser("____ABC123___", "[N:13:13:____ABC123___];");

    _testTokenParser("__", "[N:2:2:__];");

    _testTokenParser("_123ABC", "[N:7:7:_123ABC];");

    _testTokenParser("XXX 123ABC", 
"[N:3:3:XXX]; [X:1:4: ]; [N:6:10:123ABC];");

    _testTokenParser("XXX 123 ABC", 
"[N:3:3:XXX]; [X:1:4: ]; [I:3:7:123]; [X:1:8: ]; [N:3:11:ABC];");

    _testTokenParser("XXX 123.5 ABC", 
"[N:3:3:XXX]; [X:1:4: ]; [F:5:9:123.5]; [X:1:10: ]; [N:3:13:ABC];");

    _testTokenParser(".2 A", 
"[S:1:1:.]; [I:1:2:2]; [X:1:3: ]; [N:1:4:A];");

    _testTokenParser("ABC%%D", 
"[N:3:3:ABC]; [C:2:5:%%]; [N:1:6:D];");

    _testTokenParser("alt='yyy'  xx='yyy'",
"[N:3:3:alt]; [S:1:4:=]; [T:5:9:'yyy']; [X:2:11:  ]; [N:2:13:xx]; \
[S:1:14:=]; [T:5:19:'yyy'];");

    _testTokenParser("ABC%%1.5 ", 
"[N:3:3:ABC]; [C:2:5:%%]; [F:3:8:1.5]; [X:1:9: ];");

    _testTokenParser("ABC \" ' 12\" ", 
"[N:3:3:ABC]; [X:1:4: ]; [T:7:11:\" ' 12\"]; [X:1:12: ];");

    _testTokenParser("ABC  ' 12\"' ", 
"[N:3:3:ABC]; [X:2:5:  ]; [T:6:11:' 12\"']; [X:1:12: ];");

    _testTokenParser(" EVAL VAR", 
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [N:3:9:VAR];");

    _testTokenParser(" EVAL %%VAR", 
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [N:3:11:VAR];");

    _testTokenParser(" EVAL TST.VAR", 
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [N:3:9:TST]; [S:1:10:.]; [N:3:13:VAR];");

    _testTokenParser(" EVAL   %%TST.VAR",
"[X:1:1: ]; [N:4:5:EVAL]; [X:3:8:   ]; [C:2:10:%%]; [N:3:13:TST]; \
[S:1:14:.]; [N:3:17:VAR];");

    _testTokenParser(" EVAL %%\" abc \"", 
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [T:7:15:\" abc \"];");

    _testTokenParser(" EVAL %%TST.\" abc \"",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [N:3:11:TST]; \
[S:1:12:.]; [T:7:19:\" abc \"];");

    _testTokenParser(" EVAL VAR : c ",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [N:3:9:VAR]; [X:1:10: ]; \
[S:1:11::]; [X:1:12: ]; [N:1:13:c]; [X:1:14: ];");

    _testTokenParser(" EVAL %%VAR : c ",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [N:3:11:VAR]; \
[X:1:12: ]; [S:1:13::]; [X:1:14: ]; [N:1:15:c]; [X:1:16: ];");

    _testTokenParser("EVAL TST.VAR : c ",
"[N:4:4:EVAL]; [X:1:5: ]; [N:3:8:TST]; [S:1:9:.]; [N:3:12:VAR]; \
[X:1:13: ]; [S:1:14::]; [X:1:15: ]; [N:1:16:c]; [X:1:17: ];");

    _testTokenParser("EVAL %%TST.VAR : u ",
            "[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:3:10:TST]; \
[S:1:11:.]; [N:3:14:VAR]; [X:1:15: ]; [S:1:16::]; [X:1:17: ]; \
[N:1:18:u]; [X:1:19: ];");

    _testTokenParser("EVAL %%\" abc \" : x",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [T:7:14:\" abc \"]; [X:1:15: ]; \
[S:1:16::]; [X:1:17: ]; [N:1:18:x];");

    _testTokenParser("EVAL %%TST.\" abc \" : u",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:3:10:TST]; [S:1:11:.]; \
[T:7:18:\" abc \"]; [X:1:19: ]; [S:1:20::]; [X:1:21: ]; [N:1:22:u];");

    _testTokenParser(" EVAL VAR : c 10",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [N:3:9:VAR]; [X:1:10: ]; \
[S:1:11::]; [X:1:12: ]; [N:1:13:c]; [X:1:14: ]; [I:2:16:10];");

    _testTokenParser(" EVAL %% VAR : c 1",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [X:1:9: ]; [N:3:12:VAR]; \
[X:1:13: ]; [S:1:14::]; [X:1:15: ]; [N:1:16:c]; [X:1:17: ]; [I:1:18:1];");

    _testTokenParser(" EVAL TST . VAR : a 1",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [N:3:9:TST]; [X:1:10: ]; [S:1:11:.]; \
[X:1:12: ]; [N:3:15:VAR]; [X:1:16: ]; [S:1:17::]; [X:1:18: ]; [N:1:19:a]; \
[X:1:20: ]; [I:1:21:1];");

    _testTokenParser(" EVAL %% TST.VAR : a 6",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [X:1:9: ]; [N:3:12:TST]; \
[S:1:13:.]; [N:3:16:VAR]; [X:1:17: ]; [S:1:18::]; [X:1:19: ]; [N:1:20:a]; \
[X:1:21: ]; [I:1:22:6];");

    _testTokenParser(" EVAL %% \" abc \" : x 1000",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [X:1:9: ]; \
[T:7:16:\" abc \"]; [X:1:17: ]; [S:1:18::]; [X:1:19: ]; [N:1:20:x]; \
[X:1:21: ]; [I:4:25:1000];");

    _testTokenParser(" EVAL %%  TST.\" abc \" : u 1000  ",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [X:2:10:  ]; \
[N:3:13:TST]; [S:1:14:.]; [T:7:21:\" abc \"]; [X:1:22: ]; [S:1:23::]; \
[X:1:24: ]; [N:1:25:u]; [X:1:26: ]; [I:4:30:1000]; [X:2:32:  ];");

    _testTokenParser("{}", "[S:1:1:{]; [S:1:2:}];");

    _testTokenParser("{};", "[S:1:1:{]; [S:1:2:}]; [S:1:3:;];");

    _testTokenParser("eval %%VAR", 
"[N:4:4:eval]; [X:1:5: ]; [C:2:7:%%]; [N:3:10:VAR];");

    _testTokenParser("eval %%VAR123", 
"[N:4:4:eval]; [X:1:5: ]; [C:2:7:%%]; [N:6:13:VAR123];");

    _testTokenParser("eval %%V_1_2_", 
"[N:4:4:eval]; [X:1:5: ]; [C:2:7:%%]; [N:6:13:V_1_2_];");

    _testTokenParser("eval %%123VAR", 
"[N:4:4:eval]; [X:1:5: ]; [C:2:7:%%]; [N:6:13:123VAR];");

    _testTokenParser("EVAL %%VAR", 
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:3:10:VAR];");

    _testTokenParser(" EVAL %%VAR ", 
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [N:3:11:VAR]; [X:1:12: ];");

    _testTokenParser(" EVAL    %%VAR ",
"[X:1:1: ]; [N:4:5:EVAL]; [X:4:9:    ]; [C:2:11:%%]; [N:3:14:VAR]; \
[X:1:15: ];");

    _testTokenParser("EVAL %%TST.VAR",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:3:10:TST]; [S:1:11:.]; \
[N:3:14:VAR];");

    _testTokenParser("EVAL %%TST.VAR ",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:3:10:TST]; [S:1:11:.]; \
[N:3:14:VAR]; [X:1:15: ];");

    _testTokenParser(" EVAL %%TST.VAR",
"[X:1:1: ]; [N:4:5:EVAL]; [X:1:6: ]; [C:2:8:%%]; [N:3:11:TST]; \
[S:1:12:.]; [N:3:15:VAR];");

    _testTokenParser(" EVAL   %%TST.VAR ",
"[X:1:1: ]; [N:4:5:EVAL]; [X:3:8:   ]; [C:2:10:%%]; [N:3:13:TST]; \
[S:1:14:.]; [N:3:17:VAR]; [X:1:18: ];");

    _testTokenParser("    EVAL       %%TST.VAR      ",
"[X:4:4:    ]; [N:4:8:EVAL]; [X:7:15:       ]; [C:2:17:%%]; \
[N:3:20:TST]; [S:1:21:.]; [N:3:24:VAR]; [X:6:30:      ];");

    _testTokenParser("EVAL A10=10", 
"[N:4:4:EVAL]; [X:1:5: ]; [N:3:8:A10]; [S:1:9:=]; [I:2:11:10];");

    _testTokenParser("EVAL TST.\" abc\"", 
"[N:4:4:EVAL]; [X:1:5: ]; [N:3:8:TST]; [S:1:9:.]; [T:6:15:\" abc\"];");

    _testTokenParser("EVAL TST.\" abc \"", 
"[N:4:4:EVAL]; [X:1:5: ]; [N:3:8:TST]; [S:1:9:.]; [T:7:16:\" abc \"];");

    _testTokenParser("EVAL TST.\"%^&*~!()<>?./,{}||-=var7\"",
"[N:4:4:EVAL]; [X:1:5: ]; [N:3:8:TST]; [S:1:9:.]; \
[T:26:35:\"%^&*~!()<>?./,{}||-=var7\"];");
    
    _testTokenParser("EVAL %%VAR: x ( 5 ) 9",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:3:10:VAR]; [S:1:11::]; \
[X:1:12: ]; [N:1:13:x]; [X:1:14: ]; [S:1:15:(]; [X:1:16: ]; \
[I:1:17:5]; [X:1:18: ]; [S:1:19:)]; [X:1:20: ]; [I:1:21:9];");

    _testTokenParser("EVAL %%@ VSN01",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:1:8:@]; [X:1:9: ]; [N:5:14:VSN01];");

    _testTokenParser("EVAL %%@VSN01",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:6:13:@VSN01];");

    _testTokenParser("EVAL %%$VSN01",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:6:13:$VSN01];");

    _testTokenParser("EVAL %%#VSN01",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:6:13:#VSN01];");

    _testTokenParser("EVAL %%$A#_@4",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:6:13:$A#_@4];");

    _testTokenParser("EVAL %%$#_5",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:4:11:$#_5];");

    _testTokenParser("EVAL %%VAR@",
"[N:4:4:EVAL]; [X:1:5: ]; [C:2:7:%%]; [N:4:11:VAR@];");

    _testTokenParser("eval %%\"ABC@\"\"$\"\"#_''123@'123'\" = 'abc' ",
"[N:4:4:eval]; [X:1:5: ]; [C:2:7:%%]; [T:24:31:\"ABC@\"\"$\"\"#_''123@'123'\"];\
 [X:1:32: ]; [S:1:33:=]; [X:1:34: ]; [T:5:39:'abc']; [X:1:40: ];");

    printf("succ!\n");
}

void _testParseDisplayCommand(
        const char*  input, 
        int          expectRC,
        const char*  expectOutput,
        int          expectFormatMode,
        int          expectFormatLength,
        int          expectFormatPosition)
{    
    int inputLen;
    int rc;
    
    if( input == NULL )
        inputLen = 0;
    else 
        inputLen = strlen(input);
    
    rc = parseSQLCommand(input, inputLen);
    if ( rc != expectRC )
    {
        printf("input : {%s}\n", input);
        printf("rc not match: rc=%d, expect=%d \n", rc, expectRC);
        assert(rc == expectRC);                
    }   
    
    if( rc == SQLCMD_ERR_SUCC )
    {  
        assert( expectOutput != NULL); 
        assert( ttContext.CommandType == SQLCMD_TYPE_DISPLAY );
        assert( ttContext.DisplayFormatMode == expectFormatMode );
        assert( ttContext.DisplayFormatLength == expectFormatLength );
        assert( ttContext.DisplayFormatPosition == expectFormatPosition );
        
        if( strcmp(ttContext.OutputBuf,expectOutput) != 0 )
        {
            printf("output not match: \n"); 
            printf("input : {%s}\n", input); 
            printf("output: {%s}\n", ttContext.OutputBuf);
            printf("expect: {%s}\n", expectOutput);

            assert(0);         
        }
    }
}

void _testParseLeftAssignCommand(
        const char*  input, 
        int          expectRC,
        const char*  expectOutput)
{    
    int inputLen;
    int rc;
    
    if( input == NULL )
        inputLen = 0;
    else 
        inputLen = strlen(input);
    
    rc = parseSQLCommand(input, inputLen);
    if ( rc != expectRC )
    {
        printf("input : {%s}\n", input);
        printf("rc not match: rc=%d, expect=%d \n", rc, expectRC);
        assert(rc == expectRC);                
    }   
    
    if( rc == SQLCMD_ERR_SUCC )
    {  
        assert( expectOutput != NULL); 
        assert( ttContext.CommandType == SQLCMD_TYPE_LEFT_ASSIGN );
        
        if( strcmp(ttContext.OutputBuf,expectOutput) != 0 )
        {
            printf("output not match: \n"); 
            printf("input : {%s}\n", input); 
            printf("output: {%s}\n", ttContext.OutputBuf);
            printf("expect: {%s}\n", expectOutput);

            assert(0);         
        }
    }
}

void _testParseSpeicalEvalArrayCommand(
        const char*  input, 
        int          expectRC,
        const char*  expectOutput)
{    
    int inputLen;
    int varBeginPos = 0;
    int varLength = 0;
    int expectLen = 0;
    int rc;
    char var[256];
    
    if( input == NULL )
        inputLen = 0;
    else 
        inputLen = strlen(input);
    
    rc = parseSpeicalEvalArrayCommand
        ( input
        , inputLen
        ,&varBeginPos
        ,&varLength
        );
    if ( rc != expectRC )
    {
        printf("input : {%s}\n", input);
        printf("rc not match: rc=%d, expect=%d \n", rc, expectRC);
        assert(rc == expectRC);                
    }   
    
    if( rc == SQLCMD_ERR_SUCC )
    {  
        assert( expectOutput != NULL); 
        assert( varBeginPos > 0); 
        assert( varLength > 0); 
        
        expectLen = strlen(expectOutput);

        if( expectLen!= varLength ||
           memcmp(input+varBeginPos,expectOutput,varLength) != 0 )
        {            
            memcpy(var, input+varBeginPos, varLength);
            var[varLength] = '\0';
            
            printf("output not match: \n"); 
            printf("input : {%s}\n", input); 
            printf("output: {%s}\n", var);
            printf("expect: {%s}\n", expectOutput);

            assert(0);         
        }
    }
}
        
        
void test_ParseSQLCommand()
{
    printf("test_ParseSQLCommand: ");
    
    _testParseDisplayCommand(
                NULL, 
                SQLCMD_ERR_PARA, NULL, 0, 0, 0);    
                
    _testParseDisplayCommand(
                "", 
                SQLCMD_ERR_PARA, NULL, 0, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%VAR",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);
                
    _testParseDisplayCommand(
                "EVAL%%VAR",
                SQLCMD_ERR_SYNTAX,NULL, 0, 0, 0);   
                
    _testParseDisplayCommand(
                "eval %%VAR",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);
                
    _testParseDisplayCommand(
                "EVAL %%VAR   ",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0); 
                
    _testParseDisplayCommand(
                "    EVAL %%VAR",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);
                
    _testParseDisplayCommand(
                "    EVAL    %%VAR   ",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  
                
    _testParseDisplayCommand(
                "eval %%TST.VAR",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  

    _testParseDisplayCommand(
                "   EVAL %%TST.VAR",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR   ",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  

    _testParseDisplayCommand(
                "EVAL %%  TST.VAR",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  

    _testParseDisplayCommand(
                "EVAL %%TST  .VAR",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  

    _testParseDisplayCommand(
                "EVAL %%TST.  VAR",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  

    _testParseDisplayCommand(
                "EVAL %%TST.VAR  ",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  

    _testParseDisplayCommand(
                "  EVAL   %%  TST  .  VAR  ",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_AUTO, 0, 0);    

    _testParseDisplayCommand(
                "EVAL %%ABCabc___abc",
                SQLCMD_ERR_SUCC,
                "%%ABCabc___abc", 
                SQLDISPLAY_MODE_AUTO, 0, 0); 
                
    _testParseDisplayCommand(
                "EVAL %%V_",
                SQLCMD_ERR_SUCC,
                "%%V_", 
                SQLDISPLAY_MODE_AUTO, 0, 0); 
                
    _testParseDisplayCommand(
                "EVAL %%V_1",
                SQLCMD_ERR_SUCC,
                "%%V_1", 
                SQLDISPLAY_MODE_AUTO, 0, 0);   
                
    _testParseDisplayCommand(
                "EVAL %%V_1_",
                SQLCMD_ERR_SUCC,
                "%%V_1_", 
                SQLDISPLAY_MODE_AUTO, 0, 0); 

    _testParseDisplayCommand(
                "EVAL %%TT_.VA1_",
                SQLCMD_ERR_SUCC,
                "%%TT_.VA1_", 
                SQLDISPLAY_MODE_AUTO, 0, 0); 

    _testParseDisplayCommand(
                "EVAL %%T_.V_",
                SQLCMD_ERR_SUCC,
                "%%T_.V_", 
                SQLDISPLAY_MODE_AUTO, 0, 0); 

    _testParseDisplayCommand(
                "EVAL %%T_.V_5",
                SQLCMD_ERR_SUCC,
                "%%T_.V_5", 
                SQLDISPLAY_MODE_AUTO, 0, 0); 

    _testParseDisplayCommand(
                "EVAL %%T_.V_.5",
                SQLCMD_ERR_SYNTAX,
                NULL, 0, 0, 0); 
                
    _testParseDisplayCommand(
                "EVAL %%\"abc \"",
                SQLCMD_ERR_SUCC,
                "%%\"abc\"", 
                SQLDISPLAY_MODE_AUTO, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%\" abc \"",
                SQLCMD_ERR_SUCC,
                "%%\" abc\"", 
                SQLDISPLAY_MODE_AUTO, 0, 0);          

    _testParseDisplayCommand(
                "  EVAL   %%TST . \" abc \"  ",
                SQLCMD_ERR_SUCC,
                "%%TST.\" abc\"", 
                SQLDISPLAY_MODE_AUTO, 0, 0); 
                
    _testParseDisplayCommand(
                "EVAL %%TST.\"\"",
                SQLCMD_ERR_SYNTAX,
                NULL, 0, 0, 0); 
                
    _testParseDisplayCommand(
                "EVAL %%VAR : s",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_EBCDIC, 0, 0);
                
    _testParseDisplayCommand(
                "EVAL %%VAR : a",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_ASCII, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%VAR : u",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_UNICODE, 0, 0);  
                
     // Support upper case S/A/U format option 
    _testParseDisplayCommand(
                "EVAL %%VAR : S",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_EBCDIC, 0, 0);
                
    _testParseDisplayCommand(
                "EVAL %%VAR : A",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_ASCII, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%VAR : U",
                SQLCMD_ERR_SUCC,
                "%%VAR", 
                SQLDISPLAY_MODE_UNICODE, 0, 0); 
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : s",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_EBCDIC, 0, 0);
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : a",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_ASCII, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : u",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_UNICODE, 0, 0);  
                
    _testParseDisplayCommand(
                "%%TST.VAR : aa",
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : u a",
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0); 
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : s 1.5",
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0);   

    _testParseDisplayCommand(
                "EVAL %%TST.VAR : s 100",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_EBCDIC, 100, 0);
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : a 0",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_ASCII, 0, 0);  
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : u -1",
                SQLCMD_ERR_SUCC,
                "%%TST.VAR", 
                SQLDISPLAY_MODE_UNICODE, -1, 0); 
                
    _testParseDisplayCommand("EVAL %%VAR: s", 
                SQLCMD_ERR_SUCC, 
                "%%VAR",
                SQLDISPLAY_MODE_EBCDIC, 
                0, 0);

    _testParseDisplayCommand("EVAL %%VAR: a", 
                SQLCMD_ERR_SUCC, 
                "%%VAR",
                SQLDISPLAY_MODE_ASCII,
                0, 0);

    _testParseDisplayCommand("EVAL %%VAR: u", 
                SQLCMD_ERR_SUCC, 
                "%%VAR",
                SQLDISPLAY_MODE_UNICODE, 
                0, 0);

    _testParseDisplayCommand("EVAL %%VAR :s", 
                SQLCMD_ERR_SUCC, 
                "%%VAR",
                SQLDISPLAY_MODE_EBCDIC, 
                0, 0);

    _testParseDisplayCommand("EVAL %%VAR :a", 
                SQLCMD_ERR_SUCC, 
                "%%VAR",
                SQLDISPLAY_MODE_ASCII, 
                0, 0);

    _testParseDisplayCommand("EVAL %%VAR :u", 
                SQLCMD_ERR_SUCC, 
                "%%VAR",
                SQLDISPLAY_MODE_UNICODE,
                0, 0);

    _testParseDisplayCommand("EVAL %%VAR:s", 
                SQLCMD_ERR_SUCC, 
                "%%VAR",
                SQLDISPLAY_MODE_EBCDIC, 
                0, 0);

    _testParseDisplayCommand("EVAL %%VAR:a",
                SQLCMD_ERR_SUCC, 
                "%%VAR",
                SQLDISPLAY_MODE_ASCII, 
                0, 0);

    _testParseDisplayCommand("EVAL %%VAR:u", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_UNICODE, 
                0, 0);
                
     _testParseDisplayCommand("EVAL %%VAR:x", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_HEX, 
                0, 0);
       
     _testParseDisplayCommand("EVAL %%VAR:x 10", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_HEX, 
                10, 0);
                
     _testParseDisplayCommand("EVAL %%VAR: x 9", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_HEX, 
                9, 0);
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : x 1.5",
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0);   
                
    _testParseDisplayCommand(
                "EVAL %%TST.VAR : x (1.5)",
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0);   
                
     _testParseDisplayCommand("EVAL %%VAR: x (5) 9", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_HEX, 
                9, 5); 
                
     _testParseDisplayCommand("EVAL %%VAR: x (4) ", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_HEX, 
                0, 4); 
                
     _testParseDisplayCommand("EVAL %%VAR: x ( 5) 9", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_HEX, 
                9, 5); 
                
     _testParseDisplayCommand("EVAL %%VAR: x (5 ) 9", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_HEX, 
                9, 5); 
                
     _testParseDisplayCommand("EVAL %%VAR: x ( 5 ) 9", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_HEX, 
                9, 5); 
                
     _testParseDisplayCommand("EVAL %%VAR: x(1) 9", 
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0); 
                
     _testParseDisplayCommand("EVAL %%VAR: x (1)9", 
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0); 
                
     _testParseDisplayCommand("EVAL %%VAR: x (1 9", 
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0);  

     _testParseDisplayCommand("EVAL %%VAR: x  1) 9", 
                SQLCMD_ERR_SYNTAX, NULL, 0, 0, 0); 
             
             
     _testParseDisplayCommand("EVAL %%@VSN01", 
                SQLCMD_ERR_SUCC,
                "%%@VSN01",
                SQLDISPLAY_MODE_AUTO, 
                0, 0); 
                   
     _testParseDisplayCommand("EVAL %%#VSN02", 
                SQLCMD_ERR_SUCC,
                "%%#VSN02",
                SQLDISPLAY_MODE_AUTO, 
                0, 0); 
                   
     _testParseDisplayCommand("EVAL %%$VSN03", 
                SQLCMD_ERR_SUCC,
                "%%$VSN03",
                SQLDISPLAY_MODE_AUTO, 
                0, 0); 
                
     _testParseDisplayCommand("EVAL %%$A#_@4", 
                SQLCMD_ERR_SUCC,
                "%%$A#_@4",
                SQLDISPLAY_MODE_AUTO, 
                0, 0);  
                
     _testParseDisplayCommand("EVAL %%#A#_@4", 
                SQLCMD_ERR_SUCC,
                "%%#A#_@4",
                SQLDISPLAY_MODE_AUTO, 
                0, 0);  
 
     _testParseDisplayCommand("EVAL %%@A#_@4", 
                SQLCMD_ERR_SUCC,
                "%%@A#_@4",
                SQLDISPLAY_MODE_AUTO, 
                0, 0);
                
     _testParseDisplayCommand("EVAL %%$#_5", 
                SQLCMD_ERR_SUCC,
                "%%$#_5",
                SQLDISPLAY_MODE_AUTO, 
                0, 0); 
                
     _testParseDisplayCommand("EVAL %%TST.$#_5", 
                SQLCMD_ERR_SUCC,
                "%%TST.$#_5",
                SQLDISPLAY_MODE_AUTO, 
                0, 0);  
   
     _testParseDisplayCommand("EVAL %%TST.$A#_@4", 
                SQLCMD_ERR_SUCC,
                "%%TST.$A#_@4",
                SQLDISPLAY_MODE_AUTO, 
                0, 0);  
                
     _testParseDisplayCommand("EVAL %%VAR: f", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_INVAILD, 
                0, 0);  
    
     _testParseDisplayCommand("EVAL %%VAR: w", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_INVAILD, 
                0, 0);  
                
     _testParseDisplayCommand("EVAL %%VAR: w 10", 
                SQLCMD_ERR_SUCC,
                "%%VAR",
                SQLDISPLAY_MODE_INVAILD, 
                10, 0);  
                
     printf("succ!\n");
}

void test_ParseSQLLeftAssignCommand()
{
     printf("test_ParseSQLLeftAssignCommand: ");  
     
     _testParseLeftAssignCommand("EVAL %%VAR = 1", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%VAR =1", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%VAR=1", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%VAR= 1", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%VAR= 1      ", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%VAR  =     abc      ", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%VAR = %%VAR2", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%VAR =%%VAR2   ", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%VAR = \"ABC\"", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%VAR"); 
                                 
     _testParseLeftAssignCommand("EVAL %%\" abc \" = abc ", 
                                 SQLCMD_ERR_SUCC, 
                                 "%%\" abc\"");    

     _testParseLeftAssignCommand("EVAL %%VAR =", 
                                 SQLCMD_ERR_SYNTAX, 
                                 NULL);   
                                 
     _testParseLeftAssignCommand("EVAL %%VAR = ", 
                                 SQLCMD_ERR_SYNTAX, 
                                 NULL);                      
     
     _testParseLeftAssignCommand("EVAL %%VAR =   ", 
                                 SQLCMD_ERR_SYNTAX, 
                                 NULL);  
                                 
     _testParseLeftAssignCommand("EVAL VAR = abc", 
                                 SQLCMD_ERR_SYNTAX, 
                                 NULL); 
                                 
     printf("succ!\n");
}

void test_ParseSpeicalEvalArrayCommand()
{
     printf("test_ParseSpeicalEvalArrayCommand: ");  
     
     _testParseSpeicalEvalArrayCommand( "EVAL ABC"
                                      , SQLCMD_ERR_SYNTAX
                                      , NULL );
        
     _testParseSpeicalEvalArrayCommand( "EVAL ABC(*)"
                                      , SQLCMD_ERR_SUCC
                                      , "ABC" );

     _testParseSpeicalEvalArrayCommand( "eval ABC(*)"
                                      , SQLCMD_ERR_SUCC
                                      , "ABC" );

     _testParseSpeicalEvalArrayCommand( "eval  ABC(*)"
                                      , SQLCMD_ERR_SUCC
                                      , "ABC" );

     _testParseSpeicalEvalArrayCommand( "eval ABC(*) "
                                      , SQLCMD_ERR_SUCC
                                      , "ABC" );

     _testParseSpeicalEvalArrayCommand( "eval ABC( *)"
                                      , SQLCMD_ERR_SUCC
                                      , "ABC" );
                                      
     _testParseSpeicalEvalArrayCommand( "eval ABC( * )"
                                      , SQLCMD_ERR_SUCC
                                      , "ABC" );

     _testParseSpeicalEvalArrayCommand( "eval ABC(*   )"
                                      , SQLCMD_ERR_SUCC
                                      , "ABC" );

     _testParseSpeicalEvalArrayCommand( "EVAL *IN(*)"
                                      , SQLCMD_ERR_SUCC
                                      , "*IN" );
                                      
     printf("succ!\n");
}
