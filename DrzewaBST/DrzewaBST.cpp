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

void BST::preorder(Node* node) {
    
}

void BST::displayPreorder() {
    
}

void BST::postorder(Node* node) {
    
}

void BST::displayPostorder() {
    
}

void BST::saveToFile() {
    
}

void BST::saveInOrder() {
}
