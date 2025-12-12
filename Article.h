#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
using namespace std;

class Article
{
private:
  int reference;
  string nom;
  double prixVente;
  int quantiteStock;

public:
  // Constructeur par défaut
  Article()
  {
    reference = 0;
    nom = "";
    prixVente = 0.0;
    quantiteStock = 0;
  }

  // Constructeur avec paramètres
  Article(int ref, string n, double prix, int qte)
  {
    reference = ref;
    nom = n;
    prixVente = prix;
    quantiteStock = qte;
  }

  // Accesseurs en lecture (getters)
  int getReference()
  {
    return reference;
  }

  string getNom()
  {
    return nom;
  }

  double getPrixVente()
  {
    return prixVente;
  }

  int getQuantiteStock()
  {
    return quantiteStock;
  }

  // Accesseurs en écriture (setters)
  void setReference(int ref)
  {
    reference = ref;
  }

  void setNom(string n)
  {
    nom = n;
  }

  void setPrixVente(double prix)
  {
    prixVente = prix;
  }

  void setQuantiteStock(int qte)
  {
    quantiteStock = qte;
  }

  // Méthode toString
  string toString()
  {
    return "Ref: " + to_string(reference) +
           " | Nom: " + nom +
           " | Prix: " + to_string(prixVente) + " DT" +
           " | Quantite: " + to_string(quantiteStock);
  }
};

#endif