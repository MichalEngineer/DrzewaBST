#pragma once
#include <iostream>
#include <fstream>
#include "BST.h"

class Files {

    public:
       
        static void Load_from_text_file(BST& tree, const std::string& filename, bool clearTree);
       
        static void Save_to_text_file(std::ofstream& file, Node* node);

        static void Save_to_binary_file(BST& tree, const std::string& filename);

        static void Load_from_binary_file(BST& tree, const std::string& filename);
    };
