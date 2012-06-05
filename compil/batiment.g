grammar batiment;
@header{
import java.util.LinkedList;
}

@members{
int n=0;}
/* Règles du parser*/
//class batimentParser extends Parser;

grammaire 
	: {System.out.println("#include \"Parser.h\"");
System.out.println("#include <vector>");
System.out.println("#include <string>");
System.out.println("#include \"regles/RegleStandard.h\"");
System.out.println("#include \"regles/RegleSequence.h\"");
System.out.println("#include \"regles/RegleCycle.h\"");
System.out.println("#include \"condition/ConditionAdj.h\"");
System.out.println("#include \"condition/ConditionEgal.h\"");
System.out.println("#include \"regles/CalculAttributs.h\"");}

dinclude
dnom=def_nom {System.out.println("class Parser"+$dnom.nom+" : public Parser {");
System.out.println("public:");
	System.out.println("Parser"+$dnom.nom+"(){");}
	def_regles {
	System.out.println("}};");
	};
dinclude 
	: ('#' i=ID {System.out.println("#include \""+$i.text+".cpp\"");})*	;

def_nom	returns [String nom]:	'grammaire' id=ID {nom= $id.text;};//id.getText();};
def_regles 
	:	(regle_stand|regle_seq|regle_cycle)*;
	
	regle_stand : i1=ID '->' 
	{
	System.out.println("vector<string> v"+n+";");}
	i2=ID {System.out.println("v"+n+".push_back(\""+$i2.text+"\");");}
	(',' i3=ID  {System.out.println("v"+n+".push_back(\""+$i3.text+"\");");})* 
	{System.out.println("RegleStandard* r"+n+" = new RegleStandard(\""+$i1.text+"\",v"+n+");");System.out.println("ajouterRegle(r"+n+");");}
	 '{' liste_contraintes?'}'  '{' (liste_calcul {System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");})? '}' {n++;} ;
	
	regle_seq : i1=ID '->' 'sequence(' i2=ID {System.out.println("RegleSequence* r"+n+" = new RegleSequence(\""+$i1.text+"\",\""+$i2.text+"\");");System.out.println("ajouterRegle(r"+n+");");}
	',' '{' liste_contraintes?'}' ')' '{' (liste_calcul {System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");})? '}'  {n++;};
	
	regle_cycle : i1=ID '->' 'cycle(' i2=ID {System.out.println("RegleCycle* r"+n+" = new RegleCycle(\""+$i1.text+"\",\""+$i2.text+"\");");System.out.println("ajouterRegle(r"+n+");");}
	',' '{' liste_contraintes?'}' ')' '{' (liste_calcul {System.out.println("r"+n+"->calculAtt = new Calcul"+n+"();");})? '}' {n++;} ;

liste_contraintes/* returns [List<Contrainte> c]*/:
	contrainte ('^' contrainte)*;

liste_calcul 
	:
	{ System.out.
	
	println("class Calcul"+n+" : public CalculAttributs {");System.out.println("void calculAttrib(Noeud* nouveau){");}
	(expr_calcul ';')+ {System.out.println("}};");};
	
	contrainte/* returns [Contrainte c]*/:
	contrainte_egal|
	contrainte_adj|
	condition_unique|
	contrainte_generale|
	'(' contrainte')';
	
	contrainte_egal : '$' i=INT '.' att_i=ID '=' '$' j=INT '.' att_j=ID {System.out.println("r"+n+"->condEgal.push_back(new ConditionEgal("+$i.text+",\""+$att_i.text+"\","+$j.text+",\""+$att_j.text+"\"));");};
	contrainte_adj : ADJ '(' '$' i=INT '.' att_i=ID ',' '$' j=INT '.' att_j=ID ')' {System.out.println("r"+n+"->condAdj.push_back(new ConditionAdj("+$i.text+",\""+$att_i.text+"\","+$j.text+",\""+$att_j.text+"\"));");};
	
	condition_unique : {System.out.println("class ConditionUnique"+n+" : public ConditionUnique{");
	System.out.println("bool estVerifiee(Noeud* n){return (bool)(");}
	'$' i=INT '.' att_i=ID '==' val=CONST
		{System.out.print("n->getAttribut(\""+$att_i.text+"\"))=="+$val.text);
		System.out.println(";}};");
		System.out.println("ConditionUnique"+n+"* c"+n+" = new ConditionUnique"+n+"(); c"+n+"->indice = "+$i.text+";");
	System.out.println("r"+n+"->condUnique.push_back(c"+n+");");};
	
	contrainte_generale:'@' i=ID{System.out.println("r"+n+"->condGen.push_back(new "+$i.text+"());");};
	
	expr_calcul : att_i=ID '=' '$' j=INT '.' att_j=ID {System.out.println("nouveau->setAttribut(\""+$att_i.text+"\",nouveau->getEnfants()["+$j.text+"]->getAttribut(\""+$att_j.text+"\"));");};
/*Règles du lexer*/

CONST	:	'true'|'false';
ADJ 	: 'adj';
ID  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
    ;
    
INT 	:('0'..'9')+;

FLOAT
    :   ('0'..'9')+ '.' ('0'..'9')* EXPONENT?
    |   '.' ('0'..'9')+ EXPONENT?
    |   ('0'..'9')+ EXPONENT
    ;

WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;
    
fragment EXPONENT : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;