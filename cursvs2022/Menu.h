#pragma once
#include"Book.h"
#include<vector>
#include <fstream>


class Menu {

private:

    std::vector<Book> booksList;

    void addBook();
    void printAll();
    void deleteBook();
    void deleteAtIndex(int index);
    void deleteByName();

    void sortingBy();
    void bookOrder();
    void load();
    static void clearData();
    void save();
    void changeData();
    bool fileIsEmpty(std::ifstream& pFile);

    void changeTitle(int index);
    void changeAuthor(int index);
    void changeYear(int index);
    void changeCount(int index);
public:
    void menu();
};