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
#include "CalculAttFenetreCompleteReel.cpp"
class ParserReel : public Parser {
public:
ParserReel(){
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
(n->getAttribut("area")->floatValue()>0.2);}};
ConditionUnique1_5* c1_5 = new ConditionUnique1_5(); c1_5->indice = 0;
class ConditionUnique1_6 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()<1.0);}};
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
(n->getAttribut("area")->floatValue()<0.1);}};
ConditionUnique2_9* c2_9 = new ConditionUnique2_9(); c2_9->indice = 0;
r2->condUnique.push_back(c2_8);
r2->condUnique.push_back(c2_9);
class Calcul9 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r2->calculAtt = new Calcul9();
vector<MembreDroit*> v3;
v3.push_back(new MembreStandard("fenetre"));
OperateurCluster* op0= new OperateurCluster("rebord_possible","OPE");
op0->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v3.push_back(op0);
Regle* r3 = new Regle("fenetre_complete",v3);
ajouterRegle(r3);
class ConditionUnique3_11 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("size")->intValue()>=1);}};
ConditionUnique3_11* c3_11 = new ConditionUnique3_11(); c3_11->indice = 1;
r3->condUnique.push_back(c3_11);
r3->calculAtt = new CalculAttFenetreCompleteReel();
vector<MembreDroit*> v4;
v4.push_back(new MembreStandard("premur"));
OperateurCluster* op1= new OperateurCluster("fenetre_complete","OPE");
op1->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v4.push_back(op1);
Regle* r4 = new Regle("mur",v4);
ajouterRegle(r4);
class Calcul11 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r4->calculAtt = new Calcul11();
vector<MembreDroit*> v5;
OperateurSequence* op2= new OperateurSequence("mur","OPE");
op2->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op2->condGen.push_back(new ContrainteAdjacenceExacte());
v5.push_back(op2);
Regle* r5 = new Regle("murs",v5);
ajouterRegle(r5);
class Calcul12 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r5->calculAtt = new Calcul12();
}};
