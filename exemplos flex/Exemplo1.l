%option main
	#include <stdio.h>
	

%%
[0-9]+	 puts (yytext);
[a-z]*	 puts (yytext);

