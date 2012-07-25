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
#include "ContrainteAdjacenceExacte.cpp"
class Parsermurs : public Parser {
public:
Parsermurs(){
vector<MembreDroit*> v0;
OperateurCycle* op0= new OperateurCycle("mur","OPE");
op0->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op0->condGen.push_back(new ContrainteAdjacenceExacte());
v0.push_back(op0);
Regle* r0 = new Regle("murs",v0);
ajouterRegle(r0);
class Calcul0 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r0->calculAtt = new Calcul0();
vector<MembreDroit*> v1;
v1.push_back(new MembreStandard("polygone"));
Regle* r1 = new Regle("mur",v1);
ajouterRegle(r1);
class ConditionUnique1_2 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique1_2* c1_2 = new ConditionUnique1_2(); c1_2->indice = 0;
class ConditionUnique1_3 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.0005);}};
ConditionUnique1_3* c1_3 = new ConditionUnique1_3(); c1_3->indice = 0;
r1->condUnique.push_back(c1_2);
r1->condUnique.push_back(c1_3);
class Calcul3 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r1->calculAtt = new Calcul3();
}};
