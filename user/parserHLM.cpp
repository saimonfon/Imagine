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
#include "ContrainteMurFenetre.cpp"
#include "ContrainteFenetreComplete.cpp"
#include "ContrainteClusterFenetre.cpp"
#include "CalculAttFenetreComplete.cpp"
class ParserHLM : public Parser {
public:
ParserHLM(){
vector<MembreDroit*> v0;
v0.push_back(new MembreStandard("polygone"));
Regle* r0 = new Regle("sol_balcon",v0);
ajouterRegle(r0);
class ConditionUnique0_1 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("horizontal")->boolValue()==true);}};
ConditionUnique0_1* c0_1 = new ConditionUnique0_1(); c0_1->indice = 0;
class ConditionUnique0_2 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.5);}};
ConditionUnique0_2* c0_2 = new ConditionUnique0_2(); c0_2->indice = 0;
class ConditionUnique0_3 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<3.0);}};
ConditionUnique0_3* c0_3 = new ConditionUnique0_3(); c0_3->indice = 0;
r0->condUnique.push_back(c0_1);
r0->condUnique.push_back(c0_2);
r0->condUnique.push_back(c0_3);
class Calcul3 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r0->calculAtt = new Calcul3();
vector<MembreDroit*> v1;
v1.push_back(new MembreStandard("polygone"));
Regle* r1 = new Regle("premur",v1);
ajouterRegle(r1);
class ConditionUnique1_5 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique1_5* c1_5 = new ConditionUnique1_5(); c1_5->indice = 0;
class ConditionUnique1_6 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>2.0);}};
ConditionUnique1_6* c1_6 = new ConditionUnique1_6(); c1_6->indice = 0;
r1->condUnique.push_back(c1_5);
r1->condUnique.push_back(c1_6);
class Calcul6 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r1->calculAtt = new Calcul6();
vector<MembreDroit*> v2;
v2.push_back(new MembreStandard("premur"));
OperateurCluster* op0= new OperateurCluster("balcon","OPE");
op0->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v2.push_back(op0);
Regle* r2 = new Regle("premur_avec_balcon",v2);
ajouterRegle(r2);
class Calcul7 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r2->calculAtt = new Calcul7();
vector<MembreDroit*> v3;
v3.push_back(new MembreStandard("polygone"));
Regle* r3 = new Regle("fenetre",v3);
ajouterRegle(r3);
class ConditionUnique3_9 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique3_9* c3_9 = new ConditionUnique3_9(); c3_9->indice = 0;
class ConditionUnique3_10 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.1);}};
ConditionUnique3_10* c3_10 = new ConditionUnique3_10(); c3_10->indice = 0;
class ConditionUnique3_11 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<2.0);}};
ConditionUnique3_11* c3_11 = new ConditionUnique3_11(); c3_11->indice = 0;
r3->condUnique.push_back(c3_9);
r3->condUnique.push_back(c3_10);
r3->condUnique.push_back(c3_11);
class Calcul11 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r3->calculAtt = new Calcul11();
vector<MembreDroit*> v4;
v4.push_back(new MembreStandard("polygone"));
Regle* r4 = new Regle("rebord_possible",v4);
ajouterRegle(r4);
class ConditionUnique4_13 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vert_or_hor")->boolValue()==true);}};
ConditionUnique4_13* c4_13 = new ConditionUnique4_13(); c4_13->indice = 0;
class ConditionUnique4_14 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("rectangle")->boolValue()==true);}};
ConditionUnique4_14* c4_14 = new ConditionUnique4_14(); c4_14->indice = 0;
class ConditionUnique4_15 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<0.5);}};
ConditionUnique4_15* c4_15 = new ConditionUnique4_15(); c4_15->indice = 0;
r4->condUnique.push_back(c4_13);
r4->condUnique.push_back(c4_14);
r4->condUnique.push_back(c4_15);
class Calcul15 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r4->calculAtt = new Calcul15();
vector<MembreDroit*> v5;
v5.push_back(new MembreStandard("fenetre"));
OperateurCycle* op1= new OperateurCycle("rebord_possible","OPE");
op1->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
op1->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op1->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul16 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
op1->calculAtt = new Calcul16();
v5.push_back(op1);
Regle* r5 = new Regle("fenetre_complete",v5);
ajouterRegle(r5);
class ConditionUnique5_18 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("size")->intValue()==4);}};
ConditionUnique5_18* c5_18 = new ConditionUnique5_18(); c5_18->indice = 1;
r5->condUnique.push_back(c5_18);
r5->condGen.push_back(new ContrainteFenetreComplete());
r5->calculAtt = new CalculAttFenetreComplete();
vector<MembreDroit*> v6;
v6.push_back(new MembreStandard("premur_avec_balcon"));
OperateurCluster* op2= new OperateurCluster("fenetre_complete","OPE");
op2->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v6.push_back(op2);
Regle* r6 = new Regle("mur",v6);
ajouterRegle(r6);
class Calcul18 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r6->calculAtt = new Calcul18();
vector<MembreDroit*> v7;
OperateurCycle* op3= new OperateurCycle("mur","OPE");
op3->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op3->condGen.push_back(new ContrainteAdjacenceExacte());
v7.push_back(op3);
Regle* r7 = new Regle("murs",v7);
ajouterRegle(r7);
class Calcul19 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r7->calculAtt = new Calcul19();
vector<MembreDroit*> v8;
v8.push_back(new MembreStandard("polygone"));
Regle* r8 = new Regle("rambarde",v8);
ajouterRegle(r8);
class ConditionUnique8_21 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique8_21* c8_21 = new ConditionUnique8_21(); c8_21->indice = 0;
class ConditionUnique8_22 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.2);}};
ConditionUnique8_22* c8_22 = new ConditionUnique8_22(); c8_22->indice = 0;
class ConditionUnique8_23 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<2.0);}};
ConditionUnique8_23* c8_23 = new ConditionUnique8_23(); c8_23->indice = 0;
r8->condUnique.push_back(c8_21);
r8->condUnique.push_back(c8_22);
r8->condUnique.push_back(c8_23);
class Calcul23 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r8->calculAtt = new Calcul23();
vector<MembreDroit*> v9;
v9.push_back(new MembreStandard("sol_balcon"));
OperateurSequence* op4= new OperateurSequence("rambarde","OPE");
op4->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
op4->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
v9.push_back(op4);
Regle* r9 = new Regle("balcon",v9);
ajouterRegle(r9);
class Calcul24 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r9->calculAtt = new Calcul24();
}};
