%option noyywrap
%x COMMENT
%{
#include "grammar.tab.h"
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

%%
"/*"            { BEGIN(COMMENT); }
<COMMENT>"*/"   { BEGIN(INITIAL); }
<COMMENT>{ws}   { printf("inside comment ws\n"); }
<COMMENT>([^*]|\en)+|.
<COMMENT><<EOF>>    { printf("Unterminated comment\n"); return 0; }
"//"/*\n

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
"&"                                 { return(SIGNALAND); }
"&&"                                { return(AND); }
"||"                                { return(OR); }
"!"                                 { return(NOT); }
"="                                 { return(ASSIGNOP); }
"+"                                 { return(ADD); }
"-"                                 { return(MINUS); }
"*"                                 { return(STAR); }
"/"                                 { return(DIV); }
"%"                                 { return(MOD); }
"("                                 { return(LP); }
")"                                 { return(RP); }
"["                                 { return(LB); }
"]"                                 { return(RB); }
"{"                                 { return(LC); }
"}"                                 { return(RC); }
";"                                 { return(SEMI); }
","                                 { return(COMMA); }
{letter}({letter}|{digit})*         { yylval.str=strdup(yytext); return(ID); }
{digit}{letter}({letter}|{digit})*  { return(ERRORID); }
(([1-9]|-){digit}*)|0               { yylval.str=strdup(yytext); return(INT); }
[ \t\v\f\r\n]                       { }

%%
