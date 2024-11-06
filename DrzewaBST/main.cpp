#include <iostream>
#include "BST.h"
#include "BSTfiles.h"

void displayMenu() {
    std::cout << "\nBST Menu:\n";
    std::cout << "1. Dodaj element\n";
    std::cout << "2. Usuñ element\n";
    std::cout << "3. Wyœwietl drzewo preorder\n";
    std::cout << "4. Wyœwietl drzewo inorder\n";
    std::cout << "5. Wyœwietl drzewo postorder\n";
    std::cout << "6. Szukaj drogi do elementu\n";
    std::cout << "7. Usuñ ca³e drzewo\n";
    std::cout << "8. Zapisz drzewo do pliku\n";
    std::cout << "9. Wczytaj drzewo z pliku tekstowego\n";
    std::cout << "10. Zapisz drzewo z pliku binarnego\n";
    std::cout << "11. Wczytaj drzewo z pliku binarnego\n";
    std::cout << "12. WyjdŸ\n";
}

int main() {
  
    char choice = 'n';
    int option;
    int value;
    BST tree;

    Files file;

    do {
        displayMenu(); 
        std::cin >> option;

    switch (option) {
    case 1:
        do {
            std::cout << "Podaj wartosc nowego elementu drzewa BST: "; // dodawanie elementu
            std::cin >> value;

            tree.addNode(value);

            std::cout << "Czy dodac nastepny element ? (t/n): ";
            std::cin >> choice;

        } while (choice == 't' || choice == 'T');
        break;
    case 2:

        std::cout << "Podaj wartosc elementu drzewa BST, ktora chcesz usunac: ";
        std::cin >> value;

        tree.remove(value);

        break;
    case 3:
        tree.displayPreorder();
        std::cout << std::endl;
        break;

    case 4:
        tree.displayPostorders();
        std::cout << std::endl;
        break;

    case 5:
        tree.displayPostorder();
        std::cout << std::endl;
        break;
    case 6:
        do {
            std::cout << "Podaj wartosc elementu drzewa BST, ktora chcesz znalezc: ";
            std::cin >> value;

            tree.searchPath(value);

            std::cout << "Czy chcesz znalezc inny element ? (t/n): ";
            std::cin >> choice;

        } while (choice == 't' || choice == 'T');
        break;
    case 7:
        tree.clear();
        std::cout << "Cale drzewo zostalo usuniete" << std::endl;
        break;

    case 8:
        tree.saveToFile();
        std::cout << "Drzewo zapisano do plik.txt" << std::endl;
        break;

    case 9:
    {
        std::string filename = "Wczytanie z pliku tekstowego";
        file.Load_from_text_file(tree, filename, true);
    }
    break;


    case 10:
    {
        std::string binFilename = "tree.bin";
        file.Save_to_binary_file(tree, binFilename);
        std::cout << "Konczenie programu..." << std::endl;
    }
    break;

    case 11:
    {
        std::string binFilename = "tree.bin";
        file.Load_from_binary_file(tree, binFilename);
        std::cout << "Wczytano tree z pliku binarnego: " << binFilename << std::endl;
    }
    break;

    }

} while (option != 12);

}
