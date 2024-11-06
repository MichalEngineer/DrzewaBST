#pragma once
#include <iostream>
#include <fstream>
#include "BST.h"
/**
 * @class Files
 * @brief Klasa statyczna do obs³ugi operacji plikowych na drzewie BST.
 *
 * Klasa Files udostêpnia metody do zapisu i odczytu drzewa BST z plików tekstowych i binarnych.
 * Wszystkie metody s¹ statyczne i operuj¹ na podanym drzewie BST.
 */
class Files {
public:
        /**
        * @brief Wczytuje drzewo BST z pliku tekstowego.
        *
        * Metoda odczytuje wartoœci z podanego pliku tekstowego i dodaje je do drzewa BST.
        * Jeœli parametr `clearTree` jest ustawiony na `true`, metoda wyczyœci drzewo przed wczytaniem nowych danych.
        *
        * @param tree Referencja do drzewa BST, do którego zostan¹ dodane wczytane wartoœci.
        * @param filename Nazwa pliku tekstowego z liczbami.
        * @param clearTree Flaga okreœlaj¹ca, czy drzewo ma zostaæ wyczyszczone przed wczytaniem danych.
        */
        static void Load_from_text_file(BST& tree, const std::string& filename, bool clearTree);
        /**
        * @brief Zapisuje drzewo BST do pliku tekstowego w kolejnoœci in-order.
        *
        * Metoda zapisuje wartoœci wêz³ów drzewa BST do pliku tekstowego w kolejnoœci in-order.
        *
        * @param file Obiekt pliku wyjœciowego, do którego zapisywane s¹ wartoœci.
        * @param node WskaŸnik do bie¿¹cego wêz³a BST do zapisania.
        */
        static void Save_to_text_file(std::ofstream& file,BST::Node* node);
        /**
        * @brief Zapisuje drzewo BST do pliku binarnego.
        *
        * Metoda zapisuje strukturê drzewa BST do pliku binarnego, umo¿liwiaj¹c póŸniejsze
        * wczytanie drzewa w tej samej strukturze.
        *
        * @param tree Referencja do drzewa BST, które ma zostaæ zapisane do pliku.
        * @param filename Nazwa pliku binarnego, do którego zostanie zapisane drzewo.
        */
        static void Save_to_binary_file(BST& tree, const std::string& filename);
        /**
        * @brief Wczytuje drzewo BST z pliku binarnego.
        *
        * Metoda odczytuje dane z pliku binarnego i odbudowuje drzewo BST w tej samej strukturze.
        *
        * @param tree Referencja do drzewa BST, do którego zostan¹ dodane wczytane wartoœci.
        * @param filename Nazwa pliku binarnego z zapisanym drzewem BST.
         */
        static void Load_from_binary_file(BST& tree, const std::string& filename);
    };
