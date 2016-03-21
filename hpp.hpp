#ifndef _H_SAR
#define _H_SAR

#include <iostream>
#include <cstdlib>
using namespace std;

struct Sym {
	string tag,val;
	Sym(string,string); Sym(string);
	virtual string dump();
	virtual Sym* at(Sym*);
};

struct Op: Sym { Op(string); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_SAR
