%{
    #include <stdio.h>
    #include "y.tab.h"
    #define YYSTYPE  char*
    YYSTYPE yylval;  
%}
%%

zone                    return  ZONETOK;
file                    return  FILETOK;
[a-zA-Z][a-zA-Z0-9]*    yylval = strdup(yytext);  return WORD;
[a-zA-Z0-9\/.-]+        yylval = strdup(yytext);  return FILENAME;
\"                      return  QUOTE;
\{                      return  OBRACE;
\}                      return  EBRACE;
;                       return  SEMICOLON;
[ \t]+                  /* ignore whitespace */;
\n                      /* ignore EOL */;
%%