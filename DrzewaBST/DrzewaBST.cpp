#include "BST.h"

BST::BST() : root(nullptr) {} // <--- Przekazywanie nullptr do root oznacza że tworzymy drzewo ale jest puste

BST::~BST() {
    this->clear(); // <--- Destruktor wywołanie funkcji clear która usuwa drzewo
}

void BST::addNode(Node*& node, int value) {
     if (!node) { node = new Node(value); } // <--- Sprawdzanie czy istnieje jakikolwiek węzeł jeżeli nie isntieje to tworzenie nowego węzła z wartością value
     else if (value < node->data) { addNode(node->left, value); } // <--- jeżeli wartość nowego wezła jest mniejsza od wartosci obecnego to wywoływane jest znowu ta funkcja ale od lewego dziecka węzła
     else { addNode(node->right, value); } // <--- jeżeli wartość nowego wezła jest większa od wartosci obecnego to wywoływane jest znowu ta funkcja ale od prawego dziecka węzła
 }


void BST::add(int value) {
        addNode(root, value); // <--- Referencyjne wywołane addNode
}

BST::Node* BST::deleteNode(Node* node, int value) {
        if (!node) return nullptr;  // <--- Sprawdzanie czy istnieje jakikolwiek węzeł jeżeli nie to zwracany jest nullptr
        if (value < node->data) { node->left = deleteNode(node->left, value); } // <--- jeżeli wartość nowego wezła jest mniejsza od root to wywoływane jest znowu ta funkcja ale od lewego dziecka węzła
        else if (value > node->data) { node->right = deleteNode(node->right, value); }// <--- jeżeli wartość nowego wezła jest większa od root to wywoływane jest znowu ta funkcja ale od prawego dziecka węzła
        else {
            if (!node->left) { // <--- Jeżeli węzeł nie ma lewego dziecka, zastępujemy go jego prawym dzieckiem.
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) { // <--- Jeżeli węzeł nie ma prawego dziecka, zastępujemy go jego lewym dzieckiem.
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = node->right;
                while (temp->left) temp = temp->left; // <--- Znajdujemy najmniejszy węzeł w prawym poddrzewie 
                node->data = temp->data;  // <--- Zastępujemy dane bieżącego węzła danymi węzła najmniejszego 
                node->right = deleteNode(node->right, temp->data);  // <--- Rekurencyjnie usuwamy najmniejszy węzeł prawego poddrzewia
            }
        }
        return node;  // <--- zwracamy węzeł
}


void BST::remove(int value) {
    root = deleteNode(root, value);  // <--- Referencyjne wywołanie deleteNode
}

void BST::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);    // <--- Rekurencyjne wywołanie deleteTree w lewym dziecku
        deleteTree(node->right);   // <--- Rekurencyjne wywołanie deleteTree w prawym dziecku
        delete node;
    }
    
}

void BST::clear() {
    deleteTree(root);  // <--- Referencyjne wywołanie deleteTree
    root = nullptr;
}

void BST::findPath(Node* node, int value, std::string path = ""){
    if (!node) {   // <--- Sprawdzanie czy isntieje jakikolwiek węzeł w drzewie
        std::cout << "Brak elementu w drzewie." << std::endl;
        return;
    }
    path += std::to_string(node->data) + " ";   // <--- Dodanie do łańcucha znaków wartości obecnego węzła i spacji
    if (node->data == value) { // <--- Jeżeli trafiliśmy na dobry węzeł wypisywana jest wartość do niego
        std::cout << "Sciezka do " << value << " : " << path << std::endl;
        return;
    }
    if (value < node->data) { findPath(node->left, value, path); } // <--- Rekurencyjne wywołanie tej samej funkcji ale od lewego dziecka
    else { findPath(node->right, value, path); } // <--- Rekurencyjne wywołanie tej samej funkcji ale od prawego dziecka
}

void BST::searchPath(int value) {
    findPath(root, value);   // <--- Referencyjne wywołanie findPath
}

void BST::inorder(Node* node) {
    if (node) { // <--- Jeżeli isntieje jakikolwiek węzeł w drzewie
        inorder(node->left); // <--- Rekurencyjne wywołanie tej samej funkcji ale od lewego dziecka
        std::cout << node->data << " "; // <--- wypisanie wartości obecnego węzła
        inorder(node->right); // <--- Rekurencyjne wywołanie tej samej funkcji ale od prawego dziecka
    }
}

void BST::displayInorder() {
    inorder(root);   // <--- Referencyjne wywołanie inorder
    std::cout << std::endl;
}

void BST::preorder(Node* node) { 
    if (node) { // <--- Jeżeli isntieje jakikolwiek węzeł w drzewie
        std::cout << node->data << " ";// <--- wypisanie wartości obecnego węzła
        preorder(node->left); // <--- Rekurencyjne wywołanie tej samej funkcji ale od lewego dziecka
        preorder(node->right); // <--- Rekurencyjne wywołanie tej samej funkcji ale od prawego dziecka
    }
}

void BST::displayPreorder() { 
    preorder(root);   // <--- Referencyjne wywołanie preorder
    std::cout << std::endl;
}

void BST::postorder(Node* node) { 
    if (node) {
        postorder(node->left); // <--- Rekurencyjne wywołanie tej samej funkcji ale od lewego dziecka
        postorder(node->right);// <--- Rekurencyjne wywołanie tej samej funkcji ale od prawego dziecka
        std::cout << node->data << " ";// <--- wypisanie wartości obecnego węzła
    }
}

void BST::displayPostorder() { 
    postorder(root);  // <--- Referencyjne wywołanie postorder
    std::cout << std::endl;
}

void BST::saveToFile() {
    std::ofstream outFile("plik.txt"); // <--- Otwarcie pliku
    if (outFile.is_open()) { // <--- sprawdzanie czy plik się otwarł poprawnie
        saveInOrder(root, outFile); // <--- Referencyjne wywołanie saveInorder
        outFile.close(); // <--- Zamknięcie pliku
        std::cout << "Drzewo zapisane w plik.txt" << std::endl;
    }
    else { // <--- przypadek gdy plik się nie otwarł
        std::cerr << "Brak mozliwosci otwarcia pliku." << std::endl;
    }
}

void BST::saveInOrder(Node* node, std::ofstream& outFile) {
    if (node) {
        saveInOrder(node->left, outFile);// <--- Rekurencyjne wywołanie tej samej funkcji ale od lewego dziecka
        outFile << node->data << " "; // <--- zapisanie wartości obecnego węzła do pliku
        saveInOrder(node->right, outFile);// <--- Rekurencyjne wywołanie tej samej funkcji ale od prawego dziecka
    }
}
