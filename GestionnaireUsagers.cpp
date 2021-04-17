/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ismaël Coulibaly et Simon ZHang
*******************************************/

#include "GestionnaireUsagers.h"

void GestionnaireUsagers::reinitialiser()
{
	for (auto i : conteneur_)

		i->reinitialiser();

}


void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (produit->obtenirPrix() < montant) 

		produit->mettreAJourEnchere(client, montant); 
}



double GestionnaireUsagers::obtenirChiffreAffaires() const
{
    double montant = 0;
	for (auto i : conteneur_) 

		montant+= i->obtenirTotalAPayer();

	return montant;

}

void GestionnaireUsagers::afficherProfils() const{


	cout << "PROFILS" << endl;

    //a finir 
}