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
class ParserHLMSimple : public Parser {
public:
ParserHLMSimple(){
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
Regle* r1 = new Regle("fenetre",v1);
ajouterRegle(r1);
class ConditionUnique1_4 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique1_4* c1_4 = new ConditionUnique1_4(); c1_4->indice = 0;
class ConditionUnique1_5 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.1);}};
ConditionUnique1_5* c1_5 = new ConditionUnique1_5(); c1_5->indice = 0;
class ConditionUnique1_6 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<2.0);}};
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
Regle* r2 = new Regle("rebord_possible",v2);
ajouterRegle(r2);
class ConditionUnique2_8 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vert_or_hor")->boolValue()==true);}};
ConditionUnique2_8* c2_8 = new ConditionUnique2_8(); c2_8->indice = 0;
class ConditionUnique2_9 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("rectangle")->boolValue()==true);}};
ConditionUnique2_9* c2_9 = new ConditionUnique2_9(); c2_9->indice = 0;
class ConditionUnique2_10 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<0.5);}};
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
v3.push_back(new MembreStandard("fenetre"));
OperateurCycle* op0= new OperateurCycle("rebord_possible","OPE");
op0->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
op0->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op0->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul11 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
op0->calculAtt = new Calcul11();
v3.push_back(op0);
Regle* r3 = new Regle("fenetre_complete",v3);
ajouterRegle(r3);
class ConditionUnique3_13 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("size")->intValue()==4);}};
ConditionUnique3_13* c3_13 = new ConditionUnique3_13(); c3_13->indice = 1;
r3->condUnique.push_back(c3_13);
r3->condGen.push_back(new ContrainteFenetreComplete());
r3->calculAtt = new CalculAttFenetreComplete();
vector<MembreDroit*> v4;
v4.push_back(new MembreStandard("premur"));
OperateurCluster* op1= new OperateurCluster("fenetre_complete","OPE");
op1->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v4.push_back(op1);
Regle* r4 = new Regle("mur",v4);
ajouterRegle(r4);
class Calcul13 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r4->calculAtt = new Calcul13();
vector<MembreDroit*> v5;
OperateurCycle* op2= new OperateurCycle("mur","OPE");
op2->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op2->condGen.push_back(new ContrainteAdjacenceExacte());
v5.push_back(op2);
Regle* r5 = new Regle("murs",v5);
ajouterRegle(r5);
class Calcul14 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r5->calculAtt = new Calcul14();
}};
