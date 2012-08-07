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
OperateurCluster* op0= new OperateurCluster("escalier","OPE");
v0.push_back(op0);
Regle* r0 = new Regle("escaliers",v0);
ajouterRegle(r0);
vector<MembreDroit*> v1;
OperateurSequence* op1= new OperateurSequence("marche","OPE");
op1->condAdj.push_back(new ConditionAdj(0,"top",1,"front"));
op1->condGen.push_back(new ContrainteOrtho2());
v1.push_back(op1);
Regle* r1 = new Regle("escalier",v1);
ajouterRegle(r1);
class ConditionUnique1_1 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("size")->intValue()>4);}};
ConditionUnique1_1* c1_1 = new ConditionUnique1_1(); c1_1->indice = 0;
r1->condUnique.push_back(c1_1);
vector<MembreDroit*> v2;
v2.push_back(new MembreStandard("rect"));
v2.push_back(new MembreStandard("rect"));
Regle* r2 = new Regle("marche",v2);
ajouterRegle(r2);
class ConditionUnique2_2 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("horizontal")->boolValue()==true);}};
ConditionUnique2_2* c2_2 = new ConditionUnique2_2(); c2_2->indice = 0;
class ConditionUnique2_3 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique2_3* c2_3 = new ConditionUnique2_3(); c2_3->indice = 1;
r2->condUnique.push_back(c2_2);
r2->condUnique.push_back(c2_3);
r2->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
r2->condGen.push_back(new ContrainteOrtho());
r2->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul3 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("top",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("front",nouveau->getEnfants()[1]->getAttribut("primitive"));
}};
r2->calculAtt = new Calcul3();
vector<MembreDroit*> v3;
v3.push_back(new MembreStandard("polygone"));
Regle* r3 = new Regle("rect",v3);
ajouterRegle(r3);
class ConditionUnique3_5 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("rectangle")->boolValue()==true);}};
ConditionUnique3_5* c3_5 = new ConditionUnique3_5(); c3_5->indice = 0;
r3->condUnique.push_back(c3_5);
class Calcul5 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("horizontal",nouveau->getEnfants()[0]->getAttribut("horizontal"));
nouveau->setAttribut("vertical",nouveau->getEnfants()[0]->getAttribut("vertical"));
}};
r3->calculAtt = new Calcul5();
}};
