/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ismaël Coulibaly & Simon Zhang
*******************************************/


#pragma once
using namespace std;
// TODO : Cr�er la classe GestionnaireGenerique

template<typename T, typename C, typename A, typename S>
class GestionnaireGenerique{
public:
    GestionnaireGenerique() {};
    ~GestionnaireGenerique(){};

  C obtenirConteneur(){
    return conteneur_;
}; 
void ajouter(T*ptrT){
    A a(conteneur_);
    conteneur_=a(ptrT);

};

 void suppime(T*ptrT){
    S s(conteneur_);
    };

template<typename Predicate>
void pourChaqueElement(Predicate foncteur){
    for_each(conteneur_.begin(),conteneur_.end(), foncteur);

};




protected:
    C conteneur_;

};

