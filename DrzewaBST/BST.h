#pragma once
#include <iostream>
#include <fstream>
#include <string>
/**
 * @class BST
 * @brief Klasa implementuj�ca binarne drzewo poszukiwa� (BST).
 */
class BST {
private:
    /**
    * @class Node
    * @brief W�ze� drzewa BST przechowuj�cy warto�� oraz wska�niki do lewego i prawego dziecka.
    */
    class Node {
    public:
        int data; // <--- Warto�� przechowywane w w�le
        Node* left;  // <--- Wska�nik na lewy korzen
        Node* right;  // <--- Wska�nik na prawy korzen
        Node(int value) : data(value), left(nullptr), right(nullptr) {}  // <--- Konstruktor tworz�cy wezel z podana wartoscia
    };
    Node* root; // <--- Wska�nik na korzen drzewa
    /**
    * @brief Dodanie nowego w�z�a do drzewa
    * @param value Wartosc nowego wezla
    * @param node referencja do wska�nika w�z�a
    */
    void addNode(Node*& node, int value);
    /**
    * @brief Usuniecie wezla z dana wartoscia
    * @param value wartosc wezla ktory ma byc usuniety
    * @param node wska�nika w�z�a od ktorego szukamy
    */
    Node* deleteNode(Node* node, int value);
    /**
    * @brief Usuniecie calego drzewa
    * @param node wska�nika w�z�a od ktorego usuwamy
    */
    void deleteTree(Node* node);
    /**
    * @brief Wypisanie drzewa inorder
    * @param node wska�nika w�z�a w tym przypadku root
    */
    void inorder(Node* node);
    /**
    * @brief Wypisanie drzewa preorder
    * @param node wska�nika w�z�a w tym przypadku root
    */
    void preorder(Node* node);
    /**
    * @brief Wypisanie drzewa postorder
    * @param node wska�nika w�z�a w tym przypadku root
    */
    void postorder(Node* node);
    /**
    * @brief Znalezienie �cie�ki do danego w�z�a
    * @param node wska�nika w�z�a w tym przypadku root
    * @param value wartosc wezla do ktorego chcemy znalezc droge
    * @param path �a�cuch znak�w kt�ry przechowuje �cie�k�
    */
    void findPath(Node* node, int value, std::string path);
    /**
    * @brief Zapisanie drzewa do pliku in order
    * @param node wska�nik na w�ze�, od kt�rego zaczynamy zapisywanie
    * @param outfile referencja do strumienia wyjsciowego pliku ktory jest otwarty
    */
    void saveInOrder(Node* node, std::ofstream& outFile);

public:

    BST(); // <--- Konstruktor drzewa
    ~BST(); // <--- Destruktor drzewa drzewa
    void add(int value); // <--- Wywo�anie poprzez referencje fukcji addNode
    void remove(int value); // <--- Wywo�anie poprzez referencje fukcji deleteNode
    void clear(); // <--- Wywo�anie poprzez referencje fukcji deleteTree
    void searchPath(int value); // <--- Wywo�anie poprzez referencje fukcji findPath
    void displayInorder(); // <--- Wywo�anie poprzez referencje fukcji Inorder
    void displayPreorder(); // <--- Wywo�anie poprzez referencje fukcji Preorder
    void displayPostorder(); // <--- Wywo�anie poprzez referencje fukcji Postorder
    void saveToFile(); // <--- Wywo�anie poprzez referencje fukcji saveInOrder

    friend class Files; // <--- ustawienie friend class �eby klasa Files �eby metody tej klasy mog�y korzysta� z prywatnej klasy node
};
