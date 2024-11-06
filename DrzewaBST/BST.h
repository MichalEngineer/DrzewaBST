#pragma once
#include <iostream>
#include <fstream>
#include <string>
/**
 * @class BST
 * @brief Klasa implementuj¹ca binarne drzewo poszukiwañ (BST).
 */
class BST {
private:
    /**
    * @class Node
    * @brief Wêze³ drzewa BST przechowuj¹cy wartoœæ oraz wskaŸniki do lewego i prawego dziecka.
    */
    class Node {
    public:
        int data; // <--- Wartoœæ przechowywane w wêŸle
        Node* left;  // <--- WskaŸnik na lewy korzen
        Node* right;  // <--- WskaŸnik na prawy korzen
        Node(int value) : data(value), left(nullptr), right(nullptr) {}  // <--- Konstruktor tworz¹cy wezel z podana wartoscia
    };
    Node* root; // <--- WskaŸnik na 
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
