#ifndef bb
#define bb
#include "../grammaire/Parser.h"
#include <vector>
#include <string>
#include "../grammaire/Regle.h"
#include "../grammaire/OperateurCycle.h"
#include "../grammaire/MembreStandard.h"
#include "../grammaire/OperateurSequence.h"
#include "../grammaire/OperateurCluster.h"
#include "../grammaire/OperateurEnsemble.h"
#include "../grammaire/OperateurPartieConnexe.h"
#include "../grammaire/condition/ConditionAdj.h"
#include "../grammaire/condition/ConditionAdj_Ext.h"
#include "../grammaire/condition/ConditionAdj_Int.h"
#include "../grammaire/condition/ConditionEgal.h"
#include "../grammaire/regles/CalculAttributs.h"
#include "../grammaire/attributs/Attribut.h"
class ParserImbrique : public Parser {
public:
ParserImbrique(){
vector<MembreDroit*> v0;
v0.push_back(new MembreStandard("polygone"));
Regle* r0 = new Regle("premur",v0);
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
v1.push_back(new MembreStandard("polygone"));
Regle* r1 = new Regle("rebord_possible",v1);
ajouterRegle(r1);
class ConditionUnique1_4 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vert_or_hor")->boolValue()==true);}};
ConditionUnique1_4* c1_4 = new ConditionUnique1_4(); c1_4->indice = 0;
class ConditionUnique1_5 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<0.5);}};
ConditionUnique1_5* c1_5 = new ConditionUnique1_5(); c1_5->indice = 0;
r1->condUnique.push_back(c1_4);
r1->condUnique.push_back(c1_5);
class Calcul5 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r1->calculAtt = new Calcul5();
vector<MembreDroit*> v2;
v2.push_back(new MembreStandard("premur"));
OperateurCluster* opi0= new OperateurCluster("rebord_possible","OPE");
opi0->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
opi0->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
class Calcul6 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
opi0->calculAtt = new Calcul6();
OperateurCluster* op0= new OperateurCluster(opi0,"OPE_IMBRIQUE");
v2.push_back(op0);
Regle* r2 = new Regle("mur",v2);
ajouterRegle(r2);
class Calcul7 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r2->calculAtt = new Calcul7();
}};
#endif
