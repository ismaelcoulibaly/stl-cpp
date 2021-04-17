/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Isma34l Coulibaly et Simon Zhang
*******************************************/

#pragma once
#include <algorithm>  
#include <set>
#include <map>

// TODO : Cr�er le FoncteurEgal
template<typename T>
class FoncteurEgal {
	public:
	FoncteurEgal(T* t) : t_(t) {};
	 bool operator()(pair<int,T*>){ return pair.second == t_;}
	}
	private:
	T* t_;
};
// TODO : Cr�er le FoncteurGenerateurId
/*
Attributs :
- id_;
M�thodes :
- operator(); Incr�menter id_ � chaque appel
*/
class FoncteurGenerateurId {
	public:
		FoncteurGenerateurId() : id_(0) {};
	
		int operator()() { return id_++; }; //Incr�menter id_
	
	private:
		int id_;
};


// TODO : Cr�er le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
M�thodes :
- operator(); Calule le nouveau prix du Produit de la pair pass� en param�tre et le modifie
*/

class FoncteurDiminuerPourcent {
	public:

		FoncteurDiminuerPourcent(int pourcentage) :  pourcentage_(pourcentage) {};

	void operator()(pair<int, Produit*> pair) { 

		pair.second->modifierPrix(
		pair.second->Produit::obtenirPrix() - (pair.second->Produit::obtenirPrix() * pourcentage_ / 100));
		};

	private:
		int pourcentage_;
};
// TODO : Cr�er le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
M�thodes :
- operator(); V�rifie que le Produit associ� � la pair pass� en param�tre est compris entre les bornes borneInf_ et borneSup_ (retourne un bool�en)
*/

class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double& borneInf, double& borneSup) :borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<int, Produit*> donnee) {
		if (donnee.second->obtenirPrix() < borneSup_ && donnee.second->obtenirPrix() > borneInf_)
			return true;
		else
			return false;
	};
private:
	double borneInf_;
	double borneSup_;
}

// TODO : Cr�er le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Ajoute dans la multimap la pair pass� par param�tre et retourne la multimap_;
*/

class AjouterProduit
{
	public:
		AjouterProduit(multimap<int, Produit*> & multimap) :multimap_(multimap) {};
		multimap<int, Produit*> operator()(Produit* ptrProduit) 
		{
			multimap_.insert(pair<int, Produit*>(ptrProduit->obtenirReference(),ptrProduit));
			return multimap_;
		};

	private:
		multimap<int, Produit*>& multimap_;

};

// TODO : Cr�er le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
M�thodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'�l�ment.
*/

class SupprimerProduit
{
	public:
		SupprimerProduit(multimap<int, Produit*>& multimap):multimap_(multimap) {};
		multimap<int, Produit*> operator()(Produit* ptrProduit) {
			FoncteurEgal<Produit> foncteur(ptrProduit);
			for (multimap<int, Produit*>::iterator it = multimap_.begin(); it != multimap_.end(); it++) {
				auto iterateurDeLobjetASoustraire = find_if(multimap_.begin(), multimap_.end(), foncteur);  //bind(FoncteurEgal, ptrProduit)
				if(iterateurDeLobjetASoustraire != multimap_.end())
					multimap_.erase(it);
			}
	};

	private:
		multimap<int, Produit*>& multimap_;
};
//louche

//TODO : Cr�er le Foncteur AjouterUsager
/*
Attributs :
- &set;
M�thodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/


class AjouterUsager
{
public:
	AjouterUsager(set<Usager*>& set) :set_(set) {};
	void operator()(Usager* usager)
	{
		set_.insert(usager);
	}
private:
	set<Usager*>& set_;
};