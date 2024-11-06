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

bool BST::findPath() {
    return 1;
}

bool BST::searchPath() {
    return 1;
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
