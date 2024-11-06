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
  
}

void BST::remove(int value) {

}

void BST::deleteTree(Node* node) {

    
}

void BST::clear() {

}

bool BST::findPath() {

}

bool BST::searchPath() {

}

void BST::inorder(Node* node) {

}

void BST::displayInorder() { 
    
}

void BST::preorder(Node* node) { //tu
    if (node) {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BST::displayPreorder() { //tu
    preorder(root);
    std::cout << std::endl;
}

void BST::postorder(Node* node) { //tu
    if (node) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}

void BST::displayPostorder() { //tu
    postorder(root);
    std::cout << std::endl;
}

void BST::saveToFile() {
    
}

void BST::saveInOrder() {
}
