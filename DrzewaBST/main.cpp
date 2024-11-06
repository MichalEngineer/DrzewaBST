#include <iostream>
#include "BST.h"

void displayMenu() {
    std::cout << "\nBST Menu:\n";
    std::cout << "1. Dodaj element\n";
    std::cout << "2. Usu� element\n";
    std::cout << "3. Usu� ca�e drzewo\n";
    std::cout << "4. Szukaj drogi do elementu\n";
    std::cout << "5. Wy�wietl drzewo (1. Inorder, 2. Preorder, 3. Postorder)\n";
    std::cout << "6. Zapisz drzewo do pliku\n";
    std::cout << "7. Wczytaj drzewo z pliku binarnego\n";
    std::cout << "8. Wczytaj drzewo z pliku tekstowego\n";
    std::cout << "0. Wyjd�\n";
}

int main() {
    //By�a by�a by�a moim idea�em dok�adnie naprawde by�a ziomu�
    displayMenu();
    BST bst;
    bst.add(5);
    bst.add(9);
    bst.add(2);
    bst.add(3);
    bst.displayInorder();
}
