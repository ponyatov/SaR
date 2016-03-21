#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }
int main() { return yyparse(); }

Sym::Sym(string T, string V) { tag=T; val=V; }
Sym::Sym(string V):Sym("",V) {}

string Sym::dump() { return "<"+tag+":"+val+">"; }

Sym* Sym::at(Sym*o) { return new Sym(val+"@"+o->val); }

Op::Op(string V):Sym("op",V) {}
