%{
	/*definições de constantes manifestas*/
%}

delim	[ \t\n]
ws		{delim}+
letra	[A-Za-z]
digito	[0-9]
id		{letra}({letra}|{digito})*
numero	{digito}+(\.{digito}+)?(E[+-]?{digito}+)?

%%

{ws}
if			{return(IF);}
then		{return(THEN);}
else		{return(ELSE);}
{id}		{yylval = (int) installID(); return(ID);}
{numero}	{yylval = (int) installNUM(); return(NUMERO);}
"<"			{yylval = LT; return(OPREL);}
"<="		{yylval = LE; return(OPREL);}
"="			{yylval = EQ; return(OPREL);}
"<>"		{yylval = NE; return(OPREL);}
">"			{yylval = GT; return(OPREL);}
">="		{yylval = GE; return(OPREL);}

%%

int installID(){
}

int installNUM(){
}