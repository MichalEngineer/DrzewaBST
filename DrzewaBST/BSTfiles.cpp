#include "BSTfiles.h"
#include<fstream>

void Files::Load_from_text_file(BST& tree, const std::string& filename, bool clearTree) {

    int value;  // <--- Zmienna przechowuj�ca warto�� odczytan� z pliku

    std::ifstream file(filename); // <---  Otwarcie podanego pliku do odczytu

    if (!file) {  // <--- Sprawdzanie czy plik zosta� poprawnie otwarty

        std::cout << "Nie mozna otworzyc pliku tekstowego: " << filename << std::endl;
        return;

    }

    while (file >> value) { // <--- P�tla odczytuj�ca liczby z pliku

        tree.add(value);  // <--- Przekazywanie liczb do drzewa

    }

    file.close(); // <--- Zamykanie pliku

}

void Files::Save_to_text_file(std::ofstream& file, BST::Node* node) {
    if (node == nullptr) {  // <--- Sprawdzanie czy istnieje w�ze�
        return;
    }

    file << node->data << " ";  // <--- Zapisywanie warto�ci bie��cego w�z�a
    Save_to_text_file(file, node->left);  // <--- Wywo�anie funkcji dla lewego korzenia
    Save_to_text_file(file, node->right); // <--- Wywo�anie funkcji dla prawego korzenia
}

void Files::Save_to_binary_file(BST& tree, const std::string& filename) {

    std::ofstream file(filename, std::ios::binary); // <--- Otwiera plik do zapisu w trybie binarnym

    if (!file) { // <--- Sprawdzanie czy plik zosta� poprawnie otwarty

        std::cout << "Nie mo�na otworzy� pliku do zapisu: " << filename << std::endl;
        return;

    }

    Save_to_text_file(file, tree.root); // <--- Wywo�uje funkcj� aby zapisa� warto�ci

    file.close(); // <--- Zamykanie pliku

}

void Files::Load_from_binary_file(BST& tree, const std::string& filename) {

    std::ifstream file(filename, std::ios::binary); // <---  Otwarcie podanego pliku do odczytu

    if (!file) { // <--- Sprawdzanie czy plik zosta� poprawnie otwarty
        std::cout << "Nie mo�na otworzy� pliku do wczytania: " << filename << std::endl;
        return;
    }

    int value;

    while (file.read(reinterpret_cast<char*>(&value), sizeof(value))) { // <--- Odczytywanie funkcj� read w p�tli while i zapisanie do zmiennej value. Rzutuje wska�nik do value na char* poniewa� funkcja read tego wymaga
        tree.add(value); // <--- Dodanie wartosci do drzewa
    }

    file.close();// <--- Zamykanie pliku

}