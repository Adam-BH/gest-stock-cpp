#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Article.h"
using namespace std;

class Stock
{
private:
  vector<Article> articles;

public:
  // Rechercher un article par référence
  int rechercherParReference(int ref)
  {
    for (int i = 0; i < articles.size(); i++)
    {
      if (articles[i].getReference() == ref)
      {
        return i;
      }
    }
    return -1;
  }

  // Ajouter un article
  void ajouterArticle()
  {
    int ref, qte;
    string nom;
    double prix;

    cout << "\n=== Ajouter un article ===" << endl;
    cout << "Reference: ";
    cin >> ref;

    // Vérifier l'unicité
    if (rechercherParReference(ref) != -1)
    {
      cout << "Erreur: Cette reference existe deja!" << endl;
      return;
    }

    cout << "Nom: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Prix de vente: ";
    cin >> prix;
    cout << "Quantite en stock: ";
    cin >> qte;

    Article a(ref, nom, prix, qte);
    articles.push_back(a);
    cout << "Article ajoute avec succes!" << endl;
  }

  // Afficher les articles
  void afficherArticles()
  {
    cout << "\n=== Liste des articles ===" << endl;
    if (articles.size() == 0)
    {
      cout << "Le stock est vide." << endl;
      return;
    }

    for (int i = 0; i < articles.size(); i++)
    {
      cout << articles[i].toString() << endl;
    }
  }

  // Supprimer un article
  void supprimerArticle()
  {
    int ref;
    cout << "\n=== Supprimer un article ===" << endl;
    cout << "Reference de l'article a supprimer: ";
    cin >> ref;

    int pos = rechercherParReference(ref);
    if (pos == -1)
    {
      cout << "Article non trouve!" << endl;
      return;
    }

    articles.erase(articles.begin() + pos);
    cout << "Article supprime avec succes!" << endl;
  }

  // Modifier un article
  void modifierArticle()
  {
    int ref;
    cout << "\n=== Modifier un article ===" << endl;
    cout << "Reference de l'article a modifier: ";
    cin >> ref;

    int pos = rechercherParReference(ref);
    if (pos == -1)
    {
      cout << "Article non trouve!" << endl;
      return;
    }

    string nom;
    double prix;
    int qte;

    cout << "Nouveau nom: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Nouveau prix: ";
    cin >> prix;
    cout << "Nouvelle quantite: ";
    cin >> qte;

    articles[pos].setNom(nom);
    articles[pos].setPrixVente(prix);
    articles[pos].setQuantiteStock(qte);

    cout << "Article modifie avec succes!" << endl;
  }

  // Rechercher par nom
  void rechercherParNom()
  {
    string nom;
    cout << "\n=== Rechercher par nom ===" << endl;
    cout << "Nom de l'article: ";
    cin.ignore();
    getline(cin, nom);

    bool trouve = false;
    for (int i = 0; i < articles.size(); i++)
    {
      if (articles[i].getNom() == nom)
      {
        cout << articles[i].toString() << endl;
        trouve = true;
      }
    }

    if (!trouve)
    {
      cout << "Aucun article trouve avec ce nom." << endl;
    }
  }

  // Rechercher par intervalle de prix
  void rechercherParPrix()
  {
    double prixMin, prixMax;
    cout << "\n=== Rechercher par prix ===" << endl;
    cout << "Prix minimum: ";
    cin >> prixMin;
    cout << "Prix maximum: ";
    cin >> prixMax;

    bool trouve = false;
    for (int i = 0; i < articles.size(); i++)
    {
      double prix = articles[i].getPrixVente();
      if (prix >= prixMin && prix <= prixMax)
      {
        cout << articles[i].toString() << endl;
        trouve = true;
      }
    }

    if (!trouve)
    {
      cout << "Aucun article trouve dans cet intervalle." << endl;
    }
  }

  // Sauvegarder dans un fichier
  void sauvegarder()
  {
    ofstream fichier("D:\\stock.txt");

    if (!fichier)
    {
      cout << "Erreur: Impossible d'ouvrir le fichier!" << endl;
      return;
    }

    for (int i = 0; i < articles.size(); i++)
    {
      fichier << articles[i].getReference() << endl;
      fichier << articles[i].getNom() << endl;
      fichier << articles[i].getPrixVente() << endl;
      fichier << articles[i].getQuantiteStock() << endl;
    }

    fichier.close();
    cout << "Stock sauvegarde avec succes dans D:\\stock.txt" << endl;
  }

  // Afficher le menu
  void afficherMenu()
  {
    cout << "\n========== MENU GESTION DE STOCK ==========" << endl;
    cout << "1. Rechercher un article par reference" << endl;
    cout << "2. Ajouter un article au stock" << endl;
    cout << "3. Afficher les articles" << endl;
    cout << "4. Supprimer un article par reference" << endl;
    cout << "5. Modifier un article par reference" << endl;
    cout << "6. Rechercher un article par nom" << endl;
    cout << "7. Rechercher un article par intervalle de prix" << endl;
    cout << "8. Sauvegarder dans un fichier" << endl;
    cout << "9. Quitter" << endl;
    cout << "===========================================" << endl;
    cout << "Votre choix: ";
  }

  // Exécuter le menu
  void executer()
  {
    int choix;
    int ref;
    int pos;

    do
    {
      afficherMenu();
      cin >> choix;

      switch (choix)
      {
      case 1:
        cout << "\n=== Rechercher par reference ===" << endl;
        cout << "Reference: ";
        cin >> ref;
        pos = rechercherParReference(ref);
        if (pos != -1)
        {
          cout << articles[pos].toString() << endl;
        }
        else
        {
          cout << "Article non trouve!" << endl;
        }
        break;

      case 2:
        ajouterArticle();
        break;

      case 3:
        afficherArticles();
        break;

      case 4:
        supprimerArticle();
        break;

      case 5:
        modifierArticle();
        break;

      case 6:
        rechercherParNom();
        break;

      case 7:
        rechercherParPrix();
        break;

      case 8:
        sauvegarder();
        break;

      case 9:
        cout << "Au revoir!" << endl;
        break;

      default:
        cout << "Choix invalide!" << endl;
      }

    } while (choix != 9);
  }
};

#endif