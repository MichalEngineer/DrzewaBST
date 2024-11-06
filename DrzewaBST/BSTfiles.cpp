#include "BSTfiles.h"
#include<fstream>

void Files::Load_from_text_file(BST& tree, const std::string& filename, bool clearTree) {

    int value;

    std::ifstream file(filename);

    if (!file) {

        std::cerr << "Nie mozna otworzyc pliku tekstowego: " << filename << std::endl;
        return;

    }

    while (file >> value) {

        tree.add(value);

    }

    file.close();

}

void Files::Save_to_text_file(std::ofstream& file, BST::Node* node) {
    if (node == nullptr) {
        return;
    }

    file << node->data << " "; 
    Save_to_text_file(file, node->left);
    Save_to_text_file(file, node->right);
}

void Files::Save_to_binary_file(BST& tree, const std::string& filename) {

    std::ofstream file(filename, std::ios::binary);

    if (!file) {

        std::cerr << "Nie mo¿na otworzyæ pliku do zapisu: " << filename << std::endl;
        return;

    }

    Save_to_text_file(file, tree.root);

    file.close();

}

void Files::Load_from_binary_file(BST& tree, const std::string& filename) {

    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Nie mo¿na otworzyæ pliku do wczytania: " << filename << std::endl;
        return;
    }

    int value;

    while (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        tree.add(value);
    }

    file.close();

}