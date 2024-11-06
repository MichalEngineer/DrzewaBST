#pragma once
#include <iostream>
#include <fstream>

class BST {
private:
    class Node {
    public:
        int data;         
        Node* left;       
        Node* right;      
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };
    Node* root;           
    void addNode(Node*& node, int value);
    Node* deleteNode(Node* node, int value);
    void deleteTree(Node* node);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    bool findPath();
    void saveInOrder(Node* node, std::ofstream& outFile);

public:
    BST();
    ~BST();
    void add(int value);
    void remove(int value);
    void clear();
    bool searchPath();
    void displayInorder();
    void displayPreorder();
    void displayPostorder();
    void saveToFile();
};
