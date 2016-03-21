#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }
int main() { return yyparse(); }

Sym::Sym(string T, string V) { tag=T; val=V; }
Sym::Sym(string V):Sym("",V) {}

void Sym::push(Sym*o) { nest.push_back(o); }
void Sym::par(Sym*o) { pars[o->val]=o; }

string Sym::dump() { string S = "<"+tag+":"+val+">";
	for (auto pr=pars.begin(),e=pars.end();pr!=e;pr++) S+= ","+pr->first;
	for (auto it=nest.begin(),e=nest.end();it!=e;it++) S+= (*it)->dump();
	return S; }

Sym* Sym::at(Sym*o) { return new Sym(val+"@"+o->val); }

Op::Op(string V):Sym("op",V) {}


Lambda::Lambda():Sym("^","^") {}
