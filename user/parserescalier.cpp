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
#include "ContrainteOrtho.cpp"
#include "ContrainteOrtho2.cpp"
#include "ContrainteAdjacenceExacte.cpp"
class Parserescalier : public Parser {
public:
Parserescalier(){
vector<MembreDroit*> v0;
OperateurSequence* op0= new OperateurSequence("marche","OPE");
op0->condAdj.push_back(new ConditionAdj(0,"top",1,"front"));
op0->condGen.push_back(new ContrainteOrtho2());
v0.push_back(op0);
Regle* r0 = new Regle("escalier",v0);
ajouterRegle(r0);
class ConditionUnique0_1 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("size")->intValue()>2);}};
ConditionUnique0_1* c0_1 = new ConditionUnique0_1(); c0_1->indice = 0;
r0->condUnique.push_back(c0_1);
vector<MembreDroit*> v1;
v1.push_back(new MembreStandard("rect"));
v1.push_back(new MembreStandard("rect"));
Regle* r1 = new Regle("marche",v1);
ajouterRegle(r1);
class ConditionUnique1_2 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("horizontal")->boolValue()==true);}};
ConditionUnique1_2* c1_2 = new ConditionUnique1_2(); c1_2->indice = 0;
class ConditionUnique1_3 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique1_3* c1_3 = new ConditionUnique1_3(); c1_3->indice = 1;
r1->condUnique.push_back(c1_2);
r1->condUnique.push_back(c1_3);
r1->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
r1->condGen.push_back(new ContrainteOrtho());
r1->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul3 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("top",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("front",nouveau->getEnfants()[1]->getAttribut("primitive"));
}};
r1->calculAtt = new Calcul3();
vector<MembreDroit*> v2;
v2.push_back(new MembreStandard("polygone"));
Regle* r2 = new Regle("rect",v2);
ajouterRegle(r2);
class ConditionUnique2_5 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("rectangle")->boolValue()==true);}};
ConditionUnique2_5* c2_5 = new ConditionUnique2_5(); c2_5->indice = 0;
r2->condUnique.push_back(c2_5);
class Calcul5 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("horizontal",nouveau->getEnfants()[0]->getAttribut("horizontal"));
nouveau->setAttribut("vertical",nouveau->getEnfants()[0]->getAttribut("vertical"));
}};
r2->calculAtt = new Calcul5();
}};
