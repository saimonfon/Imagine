#ifndef null_header
#define null_header
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
#include "ContrainteAdjacenceExacte.h"
#include "ContrainteMurFenetre.h"
#include "ContrainteFenetreComplete.h"
#include "ContrainteClusterFenetre.h"
#include "CalculAttFenetreComplete.h"
class Parsertest : public Parser {
public:
Parsertest(){
vector<MembreDroit*> v0;
v0.push_back(new MembreStandard("polygone"));
Regle* r0 = new Regle("premur0",v0);
ajouterRegle(r0);
class ConditionUnique0_1 : public ConditionUnique{
bool estVerifiee(Noeud* n){return
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique0_1* c0_1 = new ConditionUnique0_1(); c0_1->indice = 0;
class ConditionUnique0_2 : public ConditionUnique{
bool estVerifiee(Noeud* n){return
(n->getAttribut("bbz")->floatValue()>2.0);}};
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
OperateurCycle* op0= new OperateurCycle("premur0","OPE");
op0->condAdj_ext.push_back(new ConditionAdj_Ext(0,"primitive",1,"primitive"));
op0->condAdj_ext.push_back(new ConditionAdj_Ext(1,"primitive",0,"primitive"));
v1.push_back(op0);
Regle* r1 = new Regle("murs",v1);
ajouterRegle(r1);
class Calcul3 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r1->calculAtt = new Calcul3();
}};
#endif
