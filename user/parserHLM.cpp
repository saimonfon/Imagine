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
class Calcul1 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r0->calculAtt = new Calcul1();
vector<MembreDroit*> v1;
v1.push_back(new MembreStandard("polygone"));
Regle* r1 = new Regle("premur",v1);
ajouterRegle(r1);
class ConditionUnique1_3 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique1_3* c1_3 = new ConditionUnique1_3(); c1_3->indice = 0;
r1->condUnique.push_back(c1_3);
class Calcul3 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r1->calculAtt = new Calcul3();
vector<MembreDroit*> v2;
v2.push_back(new MembreStandard("premur"));
OperateurEnsemble* op4= new OperateurEnsemble("fenetre_complete","OPE");
op4->condAdjExt.push_back(new ConditionAdj(0,"primitive",0,"primitive"));
v2.push_back(op4);
Regle* r2 = new Regle("mur",v2);
ajouterRegle(r2);
class Calcul5 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
nouveau->setAttribut("plan",nouveau->getEnfants()[0]->getAttribut("plan"));
}};
r2->calculAtt = new Calcul5();
vector<MembreDroit*> v3;
v3.push_back(new MembreStandard("polygone"));
Regle* r3 = new Regle("fenetre",v3);
ajouterRegle(r3);
class ConditionUnique3_7 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vertical")->boolValue()==true);}};
ConditionUnique3_7* c3_7 = new ConditionUnique3_7(); c3_7->indice = 0;
r3->condUnique.push_back(c3_7);
class Calcul7 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r3->calculAtt = new Calcul7();
vector<MembreDroit*> v4;
OperateurCycle* op8= new OperateurCycle("rebord_possible","OPE");
op8->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
op8->condGen.push_back(new ContrainteAdjacenceExacte());
class Calcul8 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
op8->calculAtt = new Calcul8();
v4.push_back(op8);
Regle* r4 = new Regle("rebord",v4);
ajouterRegle(r4);
class ConditionUnique4_10 : public ConditionUnique{
bool estVerifiee(Noeud* n){
cout<<"On vérifie la condition Sur le rebord"<<" : "<<n->getAttribut("size")->intValue()<<endl;
return 
(n->getAttribut("size")->intValue()==4);}};
ConditionUnique4_10* c4_10 = new ConditionUnique4_10(); c4_10->indice = 0;
r4->condUnique.push_back(c4_10);
cout<<r4<<" : "<<r4->condUnique.size()<<endl;
class Calcul10 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r4->calculAtt = new Calcul10();
vector<MembreDroit*> v5;
v5.push_back(new MembreStandard("polygone"));
Regle* r5 = new Regle("rebord_possible",v5);
ajouterRegle(r5);
class ConditionUnique5_12 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("vert_or_hor")->boolValue()==true);}};
ConditionUnique5_12* c5_12 = new ConditionUnique5_12(); c5_12->indice = 0;
class ConditionUnique5_13 : public ConditionUnique{
bool estVerifiee(Noeud* n){return 
(n->getAttribut("rectangle")->boolValue()==true);}};
ConditionUnique5_13* c5_13 = new ConditionUnique5_13(); c5_13->indice = 0;
r5->condUnique.push_back(c5_12);
r5->condUnique.push_back(c5_13);
class Calcul13 : public CalculAttributs {
void calculAttrib(Noeud* nouveau){
nouveau->setAttribut("primitive",nouveau->getEnfants()[0]->getAttribut("primitive"));
}};
r5->calculAtt = new Calcul13();
vector<MembreDroit*> v6;
v6.push_back(new MembreStandard("fenetre"));
v6.push_back(new MembreStandard("rebord"));
Regle* r6 = new Regle("fenetre_complete",v6);
ajouterRegle(r6);
r6->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
r6->condGen.push_back(new ContrainteFenetreComplete());
r6->calculAtt = new CalculAttFenetreComplete();
}};
