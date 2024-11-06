#include "BSTfiles.h"

void Files::Load_from_text_file(BST& tree, const std::string& filename, bool clearTree) {

    int v;  

    std::ifstream file(filename);  

    if (!file) {  

        std::cerr << "Nie mozna otworzyc pliku tekstowego: " << filename << std::endl;
        return;

    }

    while (file >> v) {   

        tree.BST_dodanie_elementu(v);  

    }

    file.close(); 

}

void Files::Save_to_text_file(std::ofstream& file, Node* node) {

    if (node == nullptr) { 

        return;

    }

    file.write(reinterpret_cast<char*>(&node->data), sizeof(node->data)); 

    Pliki_Zapisanie_wezla(file, node->left);   
    Pliki_Zapisanie_wezla(file, node->right);

}

void Files::Save_to_binary_file(BST& tree, const std::string& filename) {

    std::ofstream file(filename, std::ios::binary);   

    if (!file) {        

        std::cerr << "Nie mo¿na otworzyæ pliku do zapisu: " << filename << std::endl;
        return;

    }

    Pliki_Zapisanie_wezla(file, tree.root); 

    file.close();

}