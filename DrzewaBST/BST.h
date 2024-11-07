#pragma once
#include <iostream>
#include <fstream>
#include <string>
/**
 * @class BST
 * @brief Klasa implementuj¹ca binarne drzewo poszukiwañ (BST).
 */
class BST {
private:
    /**
    * @class Node
    * @brief Wêze³ drzewa BST przechowuj¹cy wartoœæ oraz wskaŸniki do lewego i prawego dziecka.
    */
    class Node {
    public:
        int data; // <--- Wartoœæ przechowywane w wêŸle
        Node* left;  // <--- WskaŸnik na lewy korzen
        Node* right;  // <--- WskaŸnik na prawy korzen
        Node(int value) : data(value), left(nullptr), right(nullptr) {}  // <--- Konstruktor tworz¹cy wezel z podana wartoscia
    };
    Node* root; // <--- WskaŸnik na korzen drzewa
    /**
    * @brief Dodanie nowego wêz³a do drzewa
    * @param value Wartosc nowego wezla
    * @param node referencja do wskaŸnika wêz³a
    */
    void addNode(Node*& node, int value);
    /**
    * @brief Usuniecie wezla z dana wartoscia
    * @param value wartosc wezla ktory ma byc usuniety
    * @param node wskaŸnika wêz³a od ktorego szukamy
    */
    Node* deleteNode(Node* node, int value);
    /**
    * @brief Usuniecie calego drzewa
    * @param node wskaŸnika wêz³a od ktorego usuwamy
    */
    void deleteTree(Node* node);
    /**
    * @brief Wypisanie drzewa inorder
    * @param node wskaŸnika wêz³a w tym przypadku root
    */
    void inorder(Node* node);
    /**
    * @brief Wypisanie drzewa preorder
    * @param node wskaŸnika wêz³a w tym przypadku root
    */
    void preorder(Node* node);
    /**
    * @brief Wypisanie drzewa postorder
    * @param node wskaŸnika wêz³a w tym przypadku root
    */
    void postorder(Node* node);
    /**
    * @brief Znalezienie œcie¿ki do danego wêz³a
    * @param node wskaŸnika wêz³a w tym przypadku root
    * @param value wartosc wezla do ktorego chcemy znalezc droge
    * @param path ³añcuch znaków który przechowuje œcie¿kê
    */
    void findPath(Node* node, int value, std::string path);
    /**
    * @brief Zapisanie drzewa do pliku in order
    * @param node wskaŸnik na wêze³, od którego zaczynamy zapisywanie
    * @param outfile referencja do strumienia wyjsciowego pliku ktory jest otwarty
    */
    void saveInOrder(Node* node, std::ofstream& outFile);

public:

    BST(); // <--- Konstruktor drzewa
    ~BST(); // <--- Destruktor drzewa drzewa
    void add(int value); // <--- Wywo³anie poprzez referencje fukcji addNode
    void remove(int value); // <--- Wywo³anie poprzez referencje fukcji deleteNode
    void clear(); // <--- Wywo³anie poprzez referencje fukcji deleteTree
    void searchPath(int value); // <--- Wywo³anie poprzez referencje fukcji findPath
    void displayInorder(); // <--- Wywo³anie poprzez referencje fukcji Inorder
    void displayPreorder(); // <--- Wywo³anie poprzez referencje fukcji Preorder
    void displayPostorder(); // <--- Wywo³anie poprzez referencje fukcji Postorder
    void saveToFile(); // <--- Wywo³anie poprzez referencje fukcji saveInOrder

    friend class Files; // <--- ustawienie friend class ¿eby klasa Files ¿eby metody tej klasy mog³y korzystaæ z prywatnej klasy node
};
