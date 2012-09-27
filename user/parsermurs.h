#ifndef parsermurs_header
#define parsermurs_header

#include "../grammaire/Parser.h"
#include <vector>
#include <string>
#include "../grammaire/Regle.h"
#include "../grammaire/OperateurCycle.h"
#include "../grammaire/MembreStandard.h"
#include "../grammaire/OperateurSequence.h"
#include "../grammaire/OperateurCluster.h"
#include "../grammaire/OperateurEnsemble.h"
#include "../grammaire/condition/ConditionAdj.h"
#include "../grammaire/condition/ConditionEgal.h"
#include "../grammaire/regles/CalculAttributs.h"
#include "../grammaire/attributs/Attribut.h"
#include "ContrainteAdjacenceExacte.h"
class Parsermurs : public Parser {
public:
	Parsermurs(){
		vector<MembreDroit*> v0;
		v0.push_back(new MembreStandard("polygone"));
		Regle* r0 = new Regle("mur",v0);
		ajouterRegle(r0);
		class ConditionUnique0_1 : public ConditionUnique{
			bool estVerifiee(Noeud* n){return
					(n->getAttribut("vertical")->boolValue()==true);}};
		ConditionUnique0_1* c0_1 = new ConditionUnique0_1(); c0_1->indice = 0;
		class ConditionUnique0_2 : public ConditionUnique{
			bool estVerifiee(Noeud* n){return
					(n->getAttribut("area")->floatValue()>2.0);}};
		ConditionUnique0_2* c0_2 = new ConditionUnique0_2(); c0_2->indice = 0;
		r0->condUnique.push_back(c0_1);
		r0->condUnique.push_back(c0_2);
		class Calcul2 : public CalculAttributs {
			void calculAttrib(Noeud* nouveau){
				nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
				nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
			}};
		r0->calculAtt = new Calcul2();
		vector<MembreDroit*> v1;
		OperateurCycle* op0= new OperateurCycle("mur","OPE");
		op0->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
		op0->condGen.push_back(new ContrainteAdjacenceExacte());
		v1.push_back(op0);
		Regle* r1 = new Regle("murs",v1);
		ajouterRegle(r1);
		class Calcul3 : public CalculAttributs {
			void calculAttrib(Noeud* nouveau){
				nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
			}};
		r1->calculAtt = new Calcul3();
	}
};

#endif
