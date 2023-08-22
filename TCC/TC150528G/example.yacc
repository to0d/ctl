%{
#include <stdio.h>
#include <string.h>

static char* heater;

    int yywrap()
    {
        return  1;
    }

    void yyerror()
    {
         printf(" parse error\n");
    }

    main()
    {
        yyparse();
    }
%}


%token  NUMBER TOKHEAT STATE TOKTARGET TOKTEMPERATURE TOKHEATER
%union
{
    int number;
    char *string;
}

%token <number> STATE
%token <number> NUMBER
%token <string> WORD

%%

commands
    : /* empty */
    | commands command
;

command
    : heat_switch
    | target_set 
    | heater_select
;

heat_switch
    : TOKHEAT STATE
        {
            printf("\tHeat turned on or off\n");
        }
;

heater_select :
        TOKHEATER WORD
        {

           printf("\tSelected heater '%s'\n", $2);
           heater = $2;
        }
;

target_set:
    TOKTARGET TOKTEMPERATURE NUMBER
    {
       printf("\tHeater '%s' temperature set to %d\n", heater, $3);
    }
;

%%