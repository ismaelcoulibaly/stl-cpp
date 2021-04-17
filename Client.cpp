#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
	// TODO : � modifier
    panier_=new GestionnaireProduit;
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
	// TODO : � modifier
    panier_=new GestionnaireProduit;
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

GestionnaireProduit* Client::obtenirPanier() const
{
	// TODO : � modifier
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	// TODO : � modifier
   return panier_->obtenirTotalAPayer();
}

void Client::afficherPanier() const
{
	// TODO : � modifier
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    panier_.->afficherPanier();
}

void Client::afficher() const
{
	// TODO : � modifier
    Usager::afficher();
    cout << "\t\tcode client:\t" << codeClient_ << endl << "\t\tpanier:\t\t" << panier_->obtenirConteneur().size() << " element" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
	// TODO : � modifier
   oanier_->supprimer(produit);
}

void Client::ajouterProduit(Produit *produit)
{
	// TODO : � modifier
   panier_->ajouter(produit);
}

void Client::reinitialiser()
{
	// TODO : � modifier
   panier_->reinitialiserClient();
    }
  

Produit* Client::trouverProduitPlusCher() const {
	return panier_->trouverProduitPlusCher(); }