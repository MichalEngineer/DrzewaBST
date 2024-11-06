#pragma once
#include <iostream>
#include <fstream>
#include "BST.h"
/**
 * @class Files
 * @brief Klasa statyczna do obs�ugi operacji plikowych na drzewie BST.
 *
 * Klasa Files udost�pnia metody do zapisu i odczytu drzewa BST z plik�w tekstowych i binarnych.
 * Wszystkie metody s� statyczne i operuj� na podanym drzewie BST.
 */
class Files {
public:
        /**
        * @brief Wczytuje drzewo BST z pliku tekstowego.
        *
        * Metoda odczytuje warto�ci z podanego pliku tekstowego i dodaje je do drzewa BST.
        * Je�li parametr `clearTree` jest ustawiony na `true`, metoda wyczy�ci drzewo przed wczytaniem nowych danych.
        *
        * @param tree Referencja do drzewa BST, do kt�rego zostan� dodane wczytane warto�ci.
        * @param filename Nazwa pliku tekstowego z liczbami.
        * @param clearTree Flaga okre�laj�ca, czy drzewo ma zosta� wyczyszczone przed wczytaniem danych.
        */
        static void Load_from_text_file(BST& tree, const std::string& filename, bool clearTree);
        /**
        * @brief Zapisuje drzewo BST do pliku tekstowego w kolejno�ci in-order.
        *
        * Metoda zapisuje warto�ci w�z��w drzewa BST do pliku tekstowego w kolejno�ci in-order.
        *
        * @param file Obiekt pliku wyj�ciowego, do kt�rego zapisywane s� warto�ci.
        * @param node Wska�nik do bie��cego w�z�a BST do zapisania.
        */
        static void Save_to_text_file(std::ofstream& file,BST::Node* node);
        /**
        * @brief Zapisuje drzewo BST do pliku binarnego.
        *
        * Metoda zapisuje struktur� drzewa BST do pliku binarnego, umo�liwiaj�c p�niejsze
        * wczytanie drzewa w tej samej strukturze.
        *
        * @param tree Referencja do drzewa BST, kt�re ma zosta� zapisane do pliku.
        * @param filename Nazwa pliku binarnego, do kt�rego zostanie zapisane drzewo.
        */
        static void Save_to_binary_file(BST& tree, const std::string& filename);
        /**
        * @brief Wczytuje drzewo BST z pliku binarnego.
        *
        * Metoda odczytuje dane z pliku binarnego i odbudowuje drzewo BST w tej samej strukturze.
        *
        * @param tree Referencja do drzewa BST, do kt�rego zostan� dodane wczytane warto�ci.
        * @param filename Nazwa pliku binarnego z zapisanym drzewem BST.
         */
        static void Load_from_binary_file(BST& tree, const std::string& filename);
    };
