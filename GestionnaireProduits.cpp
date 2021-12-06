/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ismaël Coulibaly
*******************************************/


#include "GestionnaireGenerique.h"
#include "ProduitAuxEncheres.h"
#include "GestionnaireProduits.h"
#include <functional>

 GestionnaireProduit::GestionnaireProduit()
	 {
	 }

	 GestionnaireProduit::~GestionnaireProduit()
	 {
	 }

	 void GestionnaireProduit::reinitialiserClient()
	 {
		 for (auto i : conteneur_){
		 }


		 conteneur_.clear();
	 }

	 void GestionnaireProduit::reinitialiserFournisseur()
	 {
		 for (auto i : conteneur_)
			 i.second->modifierFournisseur(nullptr);
		 conteneur_.clear();
	 }

	 void GestionnaireProduit::afficher()
	 {
		 for (auto i : conteneur_) {
			 i.second->afficher();
			 cout << "t\t exemplaires :\t" << conteneur_.count(i.first) << endl;
		 }
	 }

	 double GestionnaireProduit::obtenirTotalAPayer()
	 {
		 double montant = 0;
		 for (auto i : conteneur_) 
			 montant += i.second->obtenirPrix();
		 
		 return montant;
	 }

	 double GestionnaireProduit::obtenirTotalApayerPremium()
	 {
		 double montant = 0;
		 for (auto i : conteneur_) {
			 if (i.second->obtenirPrix() > 5) {
				 montant -= 5;
			 }
			 else
				montant += i.second->obtenirPrix();

		 }
		 return montant;
	 }

	 Produit * GestionnaireProduit::trouverProduitPlusCher() const
	 {
		 auto ProduitPlusCher= max_element(conteneur_.begin(), conteneur_.end(),[](pair<int,Produit*> gauche, pair<int, Produit*> droite)){
			 return (gauche.second->obtenirPrix() < droite.second->obtenirPrix()); }
		 
		 
		 
	if (produitPlusCher != conteneur_.end())
		return produitPlusCher->second;
	else
		return nullptr;
		}
	 }


vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borneInf, double borneSup) {
	






