# Stock Management System (Gestion de Stock)

A C++ command-line application for managing an inventory of articles/products.

## Description

This project implements a stock management system that allows users to:

- Add new articles to the inventory
- Search for articles by reference, name, or price range
- Modify article information
- Delete articles from stock
- Display all articles in the inventory
- Save the stock data to a file

## Project Structure

```
projet-stock/
├── Article.h       # Article class definition
├── Stock.h         # Stock management class
├── main.cpp        # Application entry point
└── README.md       # This file
```

## Classes

### Article

Represents a single product in the inventory.

**Attributes:**

- `reference` (int): Unique identifier for the article
- `nom` (string): Product name
- `prixVente` (double): Selling price
- `quantiteStock` (int): Quantity in stock

**Methods:**

- Getters: `getReference()`, `getNom()`, `getPrixVente()`, `getQuantiteStock()`
- `toString()`: Returns a formatted string representation of the article

### Stock

Manages the collection of articles and provides operations on them.

**Methods:**

- `rechercherParReference(int ref)`: Search article by reference number
- `ajouterArticle()`: Add a new article to stock
- `afficherArticles()`: Display all articles in stock
- `supprimerArticle()`: Remove an article by reference
- `modifierArticle()`: Modify article details
- `rechercherParNom()`: Search articles by name
- `rechercherParPrix()`: Search articles by price range
- `sauvegarder()`: Save stock data to file (D:\stock.txt)
- `executer()`: Run the interactive menu system

## Features

1. **Add Article** - Input article reference, name, price, and quantity
2. **Search by Reference** - Find a specific article using its reference number
3. **Search by Name** - Find articles matching a given name
4. **Search by Price** - Find articles within a price range
5. **View All** - Display complete list of articles in inventory
6. **Update** - Modify reference, name, price, or quantity of existing articles
7. **Delete** - Remove articles from inventory
8. **Save** - Export inventory data to a text file

## How to Build

```bash
g++ -o stock main.cpp
```

## How to Run

```bash
./stock
```

## Usage

When you run the application, you'll see an interactive menu with 9 options:

```
========== MENU GESTION DE STOCK ==========
1. Rechercher un article par reference
2. Ajouter un article au stock
3. Afficher les articles
4. Supprimer un article par reference
5. Modifier un article par reference
6. Rechercher un article par nom
7. Rechercher un article par intervalle de prix
8. Sauvegarder dans un fichier
9. Quitter
===========================================
```

Follow the on-screen prompts to perform operations. Enter `9` to exit the application.

## Notes

- Article references must be unique
- Stock data is saved to `D:\stock.txt` when option 8 is selected
- All user input is validated to prevent duplicate references
- The application runs until the user selects "Quitter" (Exit)
