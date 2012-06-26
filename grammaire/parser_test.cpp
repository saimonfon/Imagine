#include "Parser.h"
#include <vector>
#include <string>
#include "regles/RegleStandard.h"
#include "regles/RegleSequence.h"
#include "regles/RegleCycle.h"
#include "condition/ConditionAdj.h"
#include "condition/ConditionEgal.h"
#include "regles/CalculAttributs.h"
#include "ContrainteMurFenetre.cpp"
#include "ContrainteFenetreComplete.cpp"
#include "ContrainteAdjacenceExacte.cpp"
#include "ContrainteMaison.cpp"
class Parsermaison : public Parser {
public:
Parsermaison(){
vector<string> v0;
v0.push_back("murs");
v0.push_back("toit");
v0.push_back("sol");
RegleStandard* r0 = new RegleStandard("maison",v0);
ajouterRegle(r0);
r0->condGen.push_back(new ContrainteMaison());
RegleSequence* r1 = new RegleSequence("toit","toit_possible");
ajouterRegle(r1);
r1->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
class Calcul1 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r1->calculAtt = new Calcul1();
vector<string> v2;
v2.push_back("polygone");
RegleStandard* r2 = new RegleStandard("toit_possible",v2);
ajouterRegle(r2);
class ConditionUnique2 : public ConditionUnique{
bool estVerifiee(Noeud* n){return (bool)(
n->getAttribut("vertical"))==false;}};
ConditionUnique2* c2 = new ConditionUnique2(); c2->indice = 0;
r2->condUnique.push_back((ConditionUnique*)c2);
class Calcul2 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r2->calculAtt = new Calcul2();
RegleCycle* r3 = new RegleCycle("murs","mur");
ajouterRegle(r3);
r3->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
r3->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul3 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r3->calculAtt = new Calcul3();
vector<string> v4;
v4.push_back("polygone");
RegleStandard* r4 = new RegleStandard("sol",v4);
ajouterRegle(r4);
class ConditionUnique4 : public ConditionUnique{
bool estVerifiee(Noeud* n){return (bool)(
n->getAttribut("horizontal"))==true;}};
ConditionUnique4* c4 = new ConditionUnique4(); c4->indice = 0;
r4->condUnique.push_back((ConditionUnique*)c4);
class Calcul4 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r4->calculAtt = new Calcul4();
vector<string> v5;
v5.push_back("polygone");
RegleStandard* r5 = new RegleStandard("mur",v5);
ajouterRegle(r5);
class ConditionUnique5 : public ConditionUnique{
bool estVerifiee(Noeud* n){return (bool)(
n->getAttribut("vertical"))==true;}};
ConditionUnique5* c5 = new ConditionUnique5(); c5->indice = 0;
r5->condUnique.push_back(c5);
class Calcul5 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r5->calculAtt = new Calcul5();
vector<string> v6;
v6.push_back("mur");
v6.push_back("fenetre_complete");
RegleStandard* r6 = new RegleStandard("mur",v6);
ajouterRegle(r6);
r6->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
r6->condGen.push_back(new ContrainteMurFenetre());
class Calcul6 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r6->calculAtt = new Calcul6();
vector<string> v7;
v7.push_back("polygone");
RegleStandard* r7 = new RegleStandard("fenetre",v7);
ajouterRegle(r7);
class ConditionUnique7 : public ConditionUnique{
bool estVerifiee(Noeud* n){return (bool)(
n->getAttribut("vertical"))==true;}};
ConditionUnique7* c7 = new ConditionUnique7(); c7->indice = 0;
r7->condUnique.push_back(c7);
class Calcul7 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r7->calculAtt = new Calcul7();
RegleCycle* r8 = new RegleCycle("rebord","rebord_possible");
ajouterRegle(r8);
r8->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
r8->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul8 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r8->calculAtt = new Calcul8();
vector<string> v9;
v9.push_back("polygone");
RegleStandard* r9 = new RegleStandard("rebord_possible",v9);
ajouterRegle(r9);
class ConditionUnique9 : public ConditionUnique{
bool estVerifiee(Noeud* n){return (bool)(
n->getAttribut("vert_or_hor"))==true;}};
ConditionUnique9* c9 = new ConditionUnique9(); c9->indice = 0;
r9->condUnique.push_back(c9);
class Calcul9 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r9->calculAtt = new Calcul9();
vector<string> v10;
v10.push_back("fenetre");
v10.push_back("rebord");
RegleStandard* r10 = new RegleStandard("fenetre_complete",v10);
ajouterRegle(r10);
r10->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
r10->condGen.push_back(new ContrainteFenetreComplete());
class Calcul10 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r10->calculAtt = new Calcul10();
}};
