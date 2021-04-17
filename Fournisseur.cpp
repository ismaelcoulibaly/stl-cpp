#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
	// TODO : � modifier
    catalogue_=new GestionnaireProduit;
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
	// TODO : � modifier
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	// TODO : � modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
   
        catalogue_->afficher();
    cout << endl;
}

void Fournisseur::afficher() const
{
	// TODO : � modifier
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	// TODO : � modifier
    catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : � modifier
   return catalogue_->trouverProduitPlusCher();
}

void Fournisseur::enleverProduit(Produit *produit)
{
	// TODO : � modifier
    catalogue_->supprimer(produit);
}

Produit* Fournisseur::trouverProduitPlusCher() const {
	
    return catalogue_->trouverProduitPlusCher();
}

void Fournisseur::DiminuerPrix(int pourcent) const {
	FoncteurDiminuerPourcent predicat(pourcent); 

	catalogue_->pourChaqueElement(predicat);
}//ask