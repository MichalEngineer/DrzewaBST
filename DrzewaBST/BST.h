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
    Node* root; // <--- Wska�nik na 
    void addNode(Node*& node, int value);
    Node* deleteNode(Node* node, int value);
    void deleteTree(Node* node);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    void findPath(Node* node, int value, std::string path);
    void saveInOrder(Node* node, std::ofstream& outFile);

public:
    BST();
    ~BST();
    void add(int value);
    void remove(int value);
    void clear();
    void searchPath(int value);
    void displayInorder();
    void displayPreorder();
    void displayPostorder();
    void saveToFile();

    friend class Files;
};
