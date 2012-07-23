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
Regle* r1 = new Regle("premur",v1);
ajouterRegle(r1);
class ConditionUnique1_2 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique1_2* c1_2 = new ConditionUnique1_2(); c1_2->indice = 0;
class ConditionUnique1_3 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.01);}};
ConditionUnique1_3* c1_3 = new ConditionUnique1_3(); c1_3->indice = 0;
r1->condUnique.push_back(c1_2);
r1->condUnique.push_back(c1_3);
class Calcul3 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r1->calculAtt = new Calcul3();
vector<MembreDroit*> v2;
v2.push_back(new MembreStandard("premur"));
OperateurEnsemble* op1= new OperateurEnsemble("fenetre_complete","OPE");
op1->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v2.push_back(op1);
Regle* r2 = new Regle("mur",v2);
ajouterRegle(r2);
class Calcul4 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r2->calculAtt = new Calcul4();
vector<MembreDroit*> v3;
v3.push_back(new MembreStandard("polygone"));
Regle* r3 = new Regle("fenetre",v3);
ajouterRegle(r3);
class ConditionUnique3_6 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique3_6* c3_6 = new ConditionUnique3_6(); c3_6->indice = 0;
class ConditionUnique3_7 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("area")->floatValue()>0.005);}};
ConditionUnique3_7* c3_7 = new ConditionUnique3_7(); c3_7->indice = 0;
r3->condUnique.push_back(c3_6);
r3->condUnique.push_back(c3_7);
class Calcul7 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r3->calculAtt = new Calcul7();
vector<MembreDroit*> v4;
v4.push_back(new MembreStandard("polygone"));
Regle* r4 = new Regle("rebord_possible",v4);
ajouterRegle(r4);
class ConditionUnique4_9 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vert_or_hor")->boolValue()==true);}};
ConditionUnique4_9* c4_9 = new ConditionUnique4_9(); c4_9->indice = 0;
class ConditionUnique4_10 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("rectangle")->boolValue()==true);}};
ConditionUnique4_10* c4_10 = new ConditionUnique4_10(); c4_10->indice = 0;
r4->condUnique.push_back(c4_9);
r4->condUnique.push_back(c4_10);
class Calcul10 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r4->calculAtt = new Calcul10();
vector<MembreDroit*> v5;
v5.push_back(new MembreStandard("fenetre"));
OperateurCycle* op2= new OperateurCycle("rebord_possible","OPE");
op2->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
op2->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op2->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul11 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
op2->calculAtt = new Calcul11();
v5.push_back(op2);
Regle* r5 = new Regle("fenetre_complete",v5);
ajouterRegle(r5);
class ConditionUnique5_13 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("size")->intValue()==4);}};
ConditionUnique5_13* c5_13 = new ConditionUnique5_13(); c5_13->indice = 1;
r5->condUnique.push_back(c5_13);
r5->condGen.push_back(new ContrainteFenetreComplete());
r5->calculAtt = new CalculAttFenetreComplete();
}};
