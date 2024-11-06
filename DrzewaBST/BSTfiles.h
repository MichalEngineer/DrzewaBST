#pragma once
#include <iostream>
#include <fstream>
#include "BST.h"

class FileManager {
public:
    static void saveToTextFile(const BST& tree, const std::string& filename);
    static void loadFromTextFile(BST& tree, const std::string& filename);
    static void saveToBinaryFile(const BST& tree, const std::string& filename);
    static void loadFromBinaryFile(BST& tree, const std::string& filename);
};
