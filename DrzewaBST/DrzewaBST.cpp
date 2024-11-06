#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {

}

void BST::addNode(Node*& node, int value) {
     if (!node) { node = new Node(value); }
     else if (value < node->data) { addNode(node->left, value); }
     else { addNode(node->right, value); }
 }


void BST::add(int value) {
        addNode(root, value);
}

BST::Node* BST::deleteNode(Node* node, int value) {
        if (!node) return nullptr;
        if (value < node->data) { node->left = deleteNode(node->left, value); }
        else if (value > node->data) { node->right = deleteNode(node->right, value); }
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = node->right;
                while (temp->left) temp = temp->left;
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
}


void BST::remove(int value) {
    root = deleteNode(root, value);
}

void BST::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    
}

void BST::clear() {
    deleteTree(root);
    root = nullptr;
}

void BST::findPath(Node* node, int value, std::string path = ""){
    if (!node) {
        std::cout << "Brak elementu w drzewie." << std::endl;
        return;
    }
    path += std::to_string(node->data) + " ";
    if (node->data == value) {
        std::cout << "Sciezka do " << value << " : " << path << std::endl;
        return;
    }
    if (value < node->data) { findPath(node->left, value, path); }
    else { findPath(node->right, value, path); }
}

void BST::searchPath(int value) {
    findPath(root, value);
}

void BST::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void BST::displayInorder() {
    inorder(root);
    std::cout << std::endl;
}

void BST::preorder(Node* node) { 
    if (node) {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BST::displayPreorder() { 
    preorder(root);
    std::cout << std::endl;
}

void BST::postorder(Node* node) { 
    if (node) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}

void BST::displayPostorder() { 
    postorder(root);
    std::cout << std::endl;
}

void BST::saveToFile() {
    std::ofstream outFile("plik.txt");
    if (outFile.is_open()) {
        saveInOrder(root, outFile);
        outFile.close();
        std::cout << "Drzewo zapisane w plik.txt" << std::endl;
    }
    else {
        std::cerr << "Brak mozliwosci otwarcia pliku." << std::endl;
    }
}

void BST::saveInOrder(Node* node, std::ofstream& outFile) {
    if (node) {
        saveInOrder(node->left, outFile);
        outFile << node->data << " ";
        saveInOrder(node->right, outFile);
    }
}
