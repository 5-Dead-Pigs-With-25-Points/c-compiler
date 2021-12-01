%x COMMENT
%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *yytext;
extern int column;
extern FILE * yyin;
extern YYSTYPE yylval;
void yyerror(const char *str);
%}
%option yylineno
digit   [0-9]
letter  [A-Za-z_]
delim   [ \t\n]
ws  {delim}+
string \".*\"
%%
"/*"            { BEGIN(COMMENT); }
<COMMENT>"*/"   { BEGIN(INITIAL); }
<COMMENT>{ws}   { printf("inside comment ws\n"); }
<COMMENT>([^*]|\en)+|.
<COMMENT><<EOF>>    { printf("Unterminated comment\n"); return 0; }
"//".*\n
"int"                               { yylval.str=strdup(yytext); return(TYPE); }
"void"                              { yylval.str=strdup(yytext); return(TYPE); }
"main"                              { yylval.str=strdup(yytext); return(ID); }
"return"                            { return(RETURN); }
"for"                               { return(FOR); }
"while"                             { return(WHILE); }
"if"                                { return(IF); }
"else"                              { return(ELSE); }
"struct"                            { return(STRUCT); }
"."                                 { return(GETMEMBER); }
(>=)|(<=)|(==)|(!=)|<|>             { yylval.str=strdup(yytext); return(RELOP); }
"&"                                 { return('&'); }
"&&"                                { return(AND); }
"||"                                { return(OR); }
"!"                                 { return('!'); }
"="                                 { return('='); }
"+"                                 { return('+'); }
"-"                                 { return('-'); }
"*"                                 { return('*'); }
"/"                                 { return('/'); }
"%"                                 { return('%'); }
"("                                 { return('('); }
")"                                 { return(')'); }
"["                                 { return('['); }
"]"                                 { return(']'); }
"{"                                 { return('{'); }
"}"                                 { return('}'); }
";"                                 { return(';'); }
","                                 { return(','); }
{letter}({letter}|{digit})*         { yylval.str=strdup(yytext); return(ID); }
{digit}{letter}({letter}|{digit})*  { return(ERRORID); }
(([1-9]|-){digit}*)|0               { yylval.str=strdup(yytext); return(INT); }
{string}	          	    { yylval.str=strdup(yytext); return(STR); }
[ \t\v\f\r\n]                       { }

%%
int yywrap(){
	return 1;
}
