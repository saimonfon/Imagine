#ifndef NOEUD_H
#define NOEUD_H
#include <Vector>
#include <string>
#include <Map>
using namespace std;
/** Classe décrivant un noeud (i.e. un non-terminal) reconnu.*/
class Noeud
{
	public:
	/** Retourne la liste des enfants du noeud.*/
	virtual vector<Noeud*> getEnfants() const = 0;
	/** Retourne le type du noeud.*/
	virtual string getType() const = 0;
	/** Retourne la valeur d'un attribut du nom.
	@param nom Le nom de l'attribut demandé.
	@return Un pointeur sur la valeur de l'attribut.*/
	void* getAttribut(string nom);
	/** Retourne les attributs du noeud.
	@return Les attributs du noeud, sous la forme d'un dictionnaire.*/
	map<string,void*> getAttributs();
	string nom_parser;
	/** Modifie la valeur d'un attribut du noeud.
	@param nom Le nom de l'attribut à modifier.
	@param val La nouvelle valeur de l'attribut.*/
	void setAttribut(string nom,void* val);
	
	/** Test d'égalité entre deux noeuds. Utilisé par le parser pour ne pas ajouter plusieurs fois le même noeud à la forêt.
	@param n2 Un pointeur sur le noeud à comparer.
	@return true si les deux noeuds sont identiques, false sinon.*/
	virtual bool equals(const Noeud* n2) const=0;
	float score;
	
	/**Accesseur sur les enfants du noeud.
	@param i Indice de l'élément à accéder.
	@return Un pointeur sur le i-ème enfant du noeud.*/
	Noeud*& operator[](int i);
	
	/** Accesseur sur les attributs du noeud.
	@param s Le nom de l'attribut demandé.
	@return La valeur de l'attribut (équivalent à getAttribut(s)).*/
	void* operator[](string s);
	
	vector<Noeud*> enfants;
	map<string,void*> attributs;
};
#endif