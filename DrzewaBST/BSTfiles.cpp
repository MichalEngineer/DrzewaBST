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