#ifndef NOEUD_H
#define NOEUD_H
#include <vector>
#include <string>
#include <map>
#include "../attributs/Attribut.h"


using namespace std;
/** Classe d�crivant un noeud (i.e. un non-terminal) reconnu.*/
class Noeud
{
	public:
	/** Retourne la liste des enfants du noeud.*/
	virtual vector<Noeud*> getEnfants() const = 0;

	/** Retourne le type du noeud.*/
	virtual string getType() const = 0;

	/** Retourne la valeur d'un attribut du nom.
	@param nom Le nom de l'attribut demand�.
	@return Un pointeur sur la valeur de l'attribut.*/
	Attribut* getAttribut(string nom);

	/** Retourne les attributs du noeud.
	@return Les attributs du noeud, sous la forme d'un dictionnaire.*/
	map<string,Attribut*> getAttributs();
	string nom_parser;

	/** Modifie la valeur d'un attribut du noeud.
	@param nom Le nom de l'attribut � modifier.
	@param val La nouvelle valeur de l'attribut.*/
	void setAttribut(string nom,Attribut* val);
	
	/** Test d'�galit� entre deux noeuds. Utilis� par le parser pour ne pas ajouter plusieurs fois le m�me noeud � la for�t.
	@param n2 Un pointeur sur le noeud � comparer.
	@return true si les deux noeuds sont identiques, false sinon.*/
	virtual bool equals(const Noeud* n2) const=0;

	float score;
	
	/**Accesseur sur les enfants du noeud.
	@param i Indice de l'�l�ment � acc�der.
	@return Un pointeur sur le i-�me enfant du noeud.*/
	Noeud*& operator[](int i);
	
	/** Accesseur sur les attributs du noeud.
	@param s Le nom de l'attribut demand�.
	@return La valeur de l'attribut (�quivalent � getAttribut(s)).*/
	Attribut* operator[](string s);
	
	vector<Noeud*> enfants;
	map<string,Attribut*> attributs;


};
#endif
