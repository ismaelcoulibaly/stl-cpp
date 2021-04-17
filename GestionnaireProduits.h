/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ismaël Coulibaly et Simon Zhang
*******************************************/
#ifndef GESTIONNAIREPRODUIT_H
#define GESTIONNAIREPRODUIT_H

#pragma once




#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
#include "GestionnaireGenerique.h"
#include <map>



using namespace std;

// TODO : Cr�er la classe GestionnaireProduits  

class GestionnaireProduit : public GestionnaireGenerique<pair<int, Produit*>, Produit, AjouterProduit, SupprimerProduit>
{
    public:
    GestionnaireProduit();
    ~GestionnaireProduit();

    void reinitialiserClient();
    void reinitialiserFournisseur();
    void afficher();
    double obtenirTotalAPayer();
    double obtenirTotalApayerPremium();
    Produit* trouverProduitPlusCher() const;
    vector< pair<int, Produit*>> obtenirProduitsEntre(double borneInferieure, double borneSuperieure);
    Produit * obtenirProduitsSuivant(Produit* prod);
    private:
};
#endif 
// TODO : M�thodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/
