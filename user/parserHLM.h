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
class ParserHLM : public Parser {
public:
ParserHLM(){
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
Regle* r1 = new Regle("sol_balcon",v1);
ajouterRegle(r1);
class ConditionUnique1_4 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("horizontal")->boolValue()==true);}};
ConditionUnique1_4* c1_4 = new ConditionUnique1_4(); c1_4->indice = 0;
class ConditionUnique1_5 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.5);}};
ConditionUnique1_5* c1_5 = new ConditionUnique1_5(); c1_5->indice = 0;
class ConditionUnique1_6 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<3.0);}};
ConditionUnique1_6* c1_6 = new ConditionUnique1_6(); c1_6->indice = 0;
r1->condUnique.push_back(c1_4);
r1->condUnique.push_back(c1_5);
r1->condUnique.push_back(c1_6);
class Calcul6 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r1->calculAtt = new Calcul6();
vector<MembreDroit*> v2;
v2.push_back(new MembreStandard("polygone"));
Regle* r2 = new Regle("fenetre",v2);
ajouterRegle(r2);
class ConditionUnique2_8 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique2_8* c2_8 = new ConditionUnique2_8(); c2_8->indice = 0;
class ConditionUnique2_9 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.1);}};
ConditionUnique2_9* c2_9 = new ConditionUnique2_9(); c2_9->indice = 0;
class ConditionUnique2_10 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<2.0);}};
ConditionUnique2_10* c2_10 = new ConditionUnique2_10(); c2_10->indice = 0;
r2->condUnique.push_back(c2_8);
r2->condUnique.push_back(c2_9);
r2->condUnique.push_back(c2_10);
class Calcul10 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r2->calculAtt = new Calcul10();
vector<MembreDroit*> v3;
v3.push_back(new MembreStandard("polygone"));
Regle* r3 = new Regle("rebord_possible",v3);
ajouterRegle(r3);
class ConditionUnique3_12 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vert_or_hor")->boolValue()==true);}};
ConditionUnique3_12* c3_12 = new ConditionUnique3_12(); c3_12->indice = 0;
class ConditionUnique3_13 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("rectangle")->boolValue()==true);}};
ConditionUnique3_13* c3_13 = new ConditionUnique3_13(); c3_13->indice = 0;
class ConditionUnique3_14 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<0.5);}};
ConditionUnique3_14* c3_14 = new ConditionUnique3_14(); c3_14->indice = 0;
r3->condUnique.push_back(c3_12);
r3->condUnique.push_back(c3_13);
r3->condUnique.push_back(c3_14);
class Calcul14 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r3->calculAtt = new Calcul14();
vector<MembreDroit*> v4;
v4.push_back(new MembreStandard("fenetre"));
OperateurCycle* op0= new OperateurCycle("rebord_possible","OPE");
op0->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
op0->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op0->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul15 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
op0->calculAtt = new Calcul15();
v4.push_back(op0);
Regle* r4 = new Regle("fenetre_complete",v4);
ajouterRegle(r4);
class ConditionUnique4_17 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("size")->intValue()==4);}};
ConditionUnique4_17* c4_17 = new ConditionUnique4_17(); c4_17->indice = 1;
r4->condUnique.push_back(c4_17);
r4->condGen.push_back(new ContrainteFenetreComplete());
r4->calculAtt = new CalculAttFenetreComplete();
vector<MembreDroit*> v5;
v5.push_back(new MembreStandard("polygone"));
Regle* r5 = new Regle("rambarde",v5);
ajouterRegle(r5);
class ConditionUnique5_18 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique5_18* c5_18 = new ConditionUnique5_18(); c5_18->indice = 0;
class ConditionUnique5_19 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.2);}};
ConditionUnique5_19* c5_19 = new ConditionUnique5_19(); c5_19->indice = 0;
class ConditionUnique5_20 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<2.0);}};
ConditionUnique5_20* c5_20 = new ConditionUnique5_20(); c5_20->indice = 0;
r5->condUnique.push_back(c5_18);
r5->condUnique.push_back(c5_19);
r5->condUnique.push_back(c5_20);
class Calcul20 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r5->calculAtt = new Calcul20();
vector<MembreDroit*> v6;
v6.push_back(new MembreStandard("sol_balcon"));
OperateurSequence* op1= new OperateurSequence("rambarde","OPE");
op1->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
op1->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
v6.push_back(op1);
Regle* r6 = new Regle("balcon",v6);
ajouterRegle(r6);
class Calcul21 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r6->calculAtt = new Calcul21();
vector<MembreDroit*> v7;
v7.push_back(new MembreStandard("premur"));
OperateurCluster* op2= new OperateurCluster("balcon","OPE");
op2->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v7.push_back(op2);
Regle* r7 = new Regle("premur_avec_balcon",v7);
ajouterRegle(r7);
class Calcul22 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r7->calculAtt = new Calcul22();
vector<MembreDroit*> v8;
v8.push_back(new MembreStandard("premur_avec_balcon"));
OperateurCluster* op3= new OperateurCluster("fenetre_complete","OPE");
op3->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v8.push_back(op3);
Regle* r8 = new Regle("mur",v8);
ajouterRegle(r8);
class Calcul23 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r8->calculAtt = new Calcul23();
vector<MembreDroit*> v9;
OperateurCycle* op4= new OperateurCycle("mur","OPE");
op4->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op4->condGen.push_back(new ContrainteAdjacenceExacte());
v9.push_back(op4);
Regle* r9 = new Regle("murs",v9);
ajouterRegle(r9);
class Calcul24 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r9->calculAtt = new Calcul24();
vector<MembreDroit*> v10;
OperateurCluster* op5= new OperateurCluster("murs","OPE");
v10.push_back(op5);
Regle* r10 = new Regle("hlm",v10);
ajouterRegle(r10);
}};
#endif
