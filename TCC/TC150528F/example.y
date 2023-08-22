%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int yywrap()
    {
        return  1;
    }

    void yyerror()
    {
         printf("parse error\n");
    }

    main()
    {
        yyparse();
    }

%}

%token  SEMICOLON ZONETOK OBRACE EBRACE QUOTE FILENAME WORD FILETOK

%%

commands        :
                | commands command SEMICOLON
;

command         : zone_set
;

zone_set        : ZONETOK quotedname zonecontent
                    {
                        printf("Complete zone for '%s' found\n", $2);
                    }
;

zonecontent     : OBRACE zonestatements EBRACE
;

quotedname      : QUOTE FILENAME QUOTE
                   {                    
                      $$ = $2;
                      //printf("QUOTE name '%s' was encountered\n", $2);
                   }
;
                   
zonestatements  : 
                |zonestatements  zonestatement  SEMICOLON
;

zonestatement   : statements 
                | FILETOK quotedname
                  {
                      printf("A zonefile name '%s' was encountered\n", $2);
                  }
; 

block           : OBRACE  zonestatements EBRACE  SEMICOLON
;

statements      : 
                |statements  statement
;

statement       : WORD | block | quotedname
;

%%