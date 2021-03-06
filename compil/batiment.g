grammar batiment;
@header{
import java.util.LinkedList;
}

@members{
int n=0; //compteur pour les regles
int n2=0; //compteur pour les membres droits
int n3 = 0; //compteur pour les conditions et regles de calcul
int n4=0; //compteur pour les op�rateurs imbriqu�s
}
/* Regles du parser*/
//class batimentParser extends Parser;

grammaire 
	: {
System.out.println("#ifndef "+$dnom.nom+"_header");
System.out.println("#define "+$dnom.nom+"_header");
System.out.println("#include \"../grammaire/Parser.h\"");
System.out.println("#include <vector>");
System.out.println("#include <string>");
System.out.println("#include \"../grammaire/Regle.h\"");
System.out.println("#include \"../grammaire/OperateurCycle.h\"");
System.out.println("#include \"../grammaire/MembreStandard.h\"");
System.out.println("#include \"../grammaire/OperateurSequence.h\"");
System.out.println("#include \"../grammaire/OperateurCluster.h\"");
System.out.println("#include \"../grammaire/OperateurEnsemble.h\"");
System.out.println("#include \"../grammaire/OperateurPartieConnexe.h\"");
System.out.println("#include \"../grammaire/condition/ConditionAdj.h\"");
System.out.println("#include \"../grammaire/condition/ConditionAdj_Ext.h\"");
System.out.println("#include \"../grammaire/condition/ConditionAdj_Int.h\"");
System.out.println("#include \"../grammaire/condition/ConditionEgal.h\"");
System.out.println("#include \"../grammaire/regles/CalculAttributs.h\"");
System.out.println("#include \"../grammaire/attributs/Attribut.h\"");
}


dinclude
dnom=def_nom {System.out.println("class Parser"+$dnom.nom+" : public Parser {");
System.out.println("public:");
	System.out.println("Parser"+$dnom.nom+"(){");}
	def_regles {
	System.out.println("}};");
	System.out.println("#endif");
	};
dinclude 
	: ('#' i=ID {System.out.println("#include \""+$i.text+".h\"");})*	;

def_nom	returns [String nom]:	'grammaire' id=ID {nom= $id.text;};//id.getText();};
def_regles 
	:	regle*;
	
regle	:	i1=ID '->' 
		{System.out.println("vector<MembreDroit*> v"+n+";");}
		membre_droit (',' membre_droit)*
		{System.out.println("Regle* r"+n+" = new Regle(\""+$i1.text+"\",v"+n+");");System.out.println("ajouterRegle(r"+n+");");}
		'{' (lc = liste_contraintes {for(String s:$lc.liste) System.out.println("r"+n+"->"+s);})?'}'
		('{' (liste_calcul {System.out.println("r"+n+"->calculAtt = new Calcul"+n3+"();");n3++;}
	 	|'@' c=ID {System.out.println("r"+n+"->calculAtt = new "+$c.text+"();");}) '}')?  {n++;};
	 	
membre_droit 
	:	 membreStandard | operateur
	;
	
membreStandard 
	:	 i2=ID {System.out.println("v"+n+".push_back(new MembreStandard(\""+$i2.text+"\"));");}; 
	
operateur 
	:	{String opType="";}('sequence' {opType="OperateurSequence";}
		| 'cycle' {opType="OperateurCycle";}
		|'cluster' {opType="OperateurCluster";}
		|'ensemble' {opType="OperateurEnsemble";}
		| 'partieConnexe' {opType="OperateurPartieConnexe";})
		'(' 
		(i2 = ID {System.out.println(opType+"* op"+n2+"= new "+opType+"(\""+$i2.text+"\",\"OPE\");");} ('{' contrainte_op_membres '}')?
		|operateur_imbrique {System.out.println(opType+"* op"+n2+"= new "+opType+"(opi"+n4+",\"OPE_IMBRIQUE\");");n4++;})
		',' '{' (lc = liste_contraintes {for(String s:$lc.liste) System.out.println("op"+n2+"->"+s);})?'}'
		 (',' ('{' liste_calcul {System.out.println("op"+n2+"->calculAtt = new Calcul"+n3+"();");n3++;}
		|'@' c=ID {System.out.println("op"+n2+"->calculAtt = new "+$c.text+"();");}) '}' )? ')' {System.out.println("v"+n+".push_back(op"+n2+");");n2++;};
		
		operateur_imbrique 
	:	{String opType="";}('sequence' {opType="OperateurSequence";}
		| 'cycle' {opType="OperateurCycle";}
		|'cluster' {opType="OperateurCluster";}
		|'ensemble' {opType="OperateurEnsemble";}
		| 'partieConnexe' {opType="OperateurPartieConnexe";})
		'(' i2 = ID {System.out.println(opType+"* opi"+n4+"= new "+opType+"(\""+$i2.text+"\",\"OPE\");");} ('{' contrainte_op_membres_imbrique '}')?
		',' '{' (lc = liste_contraintes {for(String s:$lc.liste) System.out.println("opi"+n4+"->"+s);})?'}'
		 (',' ('{' liste_calcul {System.out.println("opi"+n4+"->calculAtt = new Calcul"+n3+"();");n3++;}
		|'@' c=ID {System.out.println("opi"+n4+"->calculAtt = new "+$c.text+"();");}) '}' )? ')';

contrainte_op_membres 
	:	(ADJ '(' att=ID ',' '#' j=INT '.' att_j=ID ')' {System.out.println("op"+n2+"->condAdjExt.push_back(new ConditionAdj(0,\""+$att.text+"\","+$j.text+",\""+$att_j.text+"\"));");})*;


contrainte_op_membres_imbrique 
	:	(ADJ '(' att=ID ',' '#' j=INT '.' att_j=ID ')' {System.out.println("opi"+n4+"->condAdjExt.push_back(new ConditionAdj(0,\""+$att.text+"\","+$j.text+",\""+$att_j.text+"\"));");})*;

liste_contraintes returns [List<String> liste]:	
	{liste = new LinkedList<String>();} c=contrainte {liste.add($c.toString);}('^' c2=contrainte {liste.add($c2.toString);})*;

liste_calcul 
	:
	{ System.out.println("class Calcul"+n3+" : public CalculAttributs {");System.out.println("void calculAttrib(Noeud* nouveau){");}
	(expr_calcul ';')+ {System.out.println("}};");};
	
	contrainte returns [String toString]:
	c=contrainte_egal {toString = $c.toString;}|
	c=contrainte_adj {toString = $c.toString;}|
	c=contrainte_adj_ext{toString = $c.toString;}|
	c=contrainte_adj_int{toString = $c.toString;}|
	c=condition_unique {toString = $c.toString;}|
	c=contrainte_generale {toString = $c.toString;}|
	'(' c=contrainte {toString = $c.toString;}')';
	
	contrainte_egal returns [String toString]: '$' i=INT '.' att_i=ID '=' '$' j=INT '.' att_j=ID {toString="condEgal.push_back(new ConditionEgal("+$i.text+",\""+$att_i.text+"\","+$j.text+",\""+$att_j.text+"\"));";};
	contrainte_adj returns [String toString] : ADJ '(' '$' i=INT '.' att_i=ID ',' '$' j=INT '.' att_j=ID ')' {toString="condAdj.push_back(new ConditionAdj("+$i.text+",\""+$att_i.text+"\","+$j.text+",\""+$att_j.text+"\"));";};
	contrainte_adj_ext returns [String toString] : ADJEXT '(' '$' i=INT '.' att_i=ID ',' '$' j=INT '.' att_j=ID ')' {toString="condAdj_ext.push_back(new ConditionAdj_Ext("+$i.text+",\""+$att_i.text+"\","+$j.text+",\""+$att_j.text+"\"));";};
	contrainte_adj_int returns [String toString] : ADJINT '(' '$' i=INT '.' att_i=ID ',' '$' j=INT '.' att_j=ID ')' {toString="condAdj_int.push_back(new ConditionAdj_Int("+$i.text+",\""+$att_i.text+"\","+$j.text+",\""+$att_j.text+"\"));";};
	
	condition_unique  returns [String toString] : {System.out.println("class ConditionUnique"+n+"_"+(++n3)+" : public ConditionUnique{");
	System.out.println("bool estVerifiee(Noeud* n){return ");}
	'$' i=INT '.' att_i=ID op=OP_COMP {System.out.print("(n->getAttribut(\""+$att_i.text+"\")->");}
	(val=INT {System.out.print("intValue()"+$op.text+$val.text);} | val=BOOL {System.out.print("boolValue()"+$op.text+$val.text);} | val=FLOAT {System.out.print("floatValue()"+$op.text+$val.text);})
		{System.out.println(");}};");
		System.out.println("ConditionUnique"+n+"_"+n3+"* c"+n+"_"+n3+" = new ConditionUnique"+n+"_"+n3+"(); c"+n+"_"+n3+"->indice = "+$i.text+";");
	toString = "condUnique.push_back(c"+n+"_"+n3+");";};
	
	contrainte_generale returns [String toString]:'@' i=ID{toString="condGen.push_back(new "+$i.text+"());";};
	
	expr_calcul : att_i=ID '=' '$' j=INT '.' att_j=ID {System.out.println("nouveau->setAttribut(\""+$att_i.text+"\",nouveau->getEnfants()["+$j.text+"]->getAttribut(\""+$att_j.text+"\"));");};
/*R�gles du lexer*/

BOOL 	:	 'true'|'false';
OP_COMP :'=='|'>'|'<'|'>='|'<='|'!=';
ADJ 	: 'adj';
ADJEXT	: 'adj_ext';
ADJINT	: 'adj_int';
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
