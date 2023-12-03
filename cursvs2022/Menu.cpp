#include "Menu.h"
#include <string>

void Menu::menu() {

    int ch;
    do {
        std::cout << "Menu" << std::endl <<
            "1 - add new book" << std::endl <<
            "2 - delete book" << std::endl <<
            "3 - sort by all parameters" << std::endl <<
            "4 - order book" << std::endl <<
            "5 - output all data" << std::endl <<
            "6 - save data to file" << std::endl <<
            "7 - load data from file" << std::endl <<
            "8 - change data" << std::endl <<
            "9 - delete all data from file" << std::endl <<
            "0 - exit" << std::endl;
        "-> ";

        std::cin >> ch;

        switch (ch) {
        case 1:
            addBook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            sortingBy();
            break;
        case 4:
            bookOrder();
            break;
        case 5:
            printAll();
            break;
        case 6:
            save();
            break;
        case 7:
            load();
            break;
        case 8:
            changeData();
        case 9: 
            clearData();
        default:
            break;
        }
    } while (ch != 0);

}

void Menu::addBook() {
    std::string name, author;
    int year, count;
    bool isAvailable;

    std::cout << "input title of the book: " << std::endl; getchar();
    std::getline(std::cin, name);

    std::cout << "input the author's name: " << std::endl;
    std::getline(std::cin, author);

    std::cout << "input the year of publishing: " << std::endl;
    std::cin >> year;

    std::cout << "input the total count of these books: " << std::endl;
    std::cin >> count;

    isAvailable = count > 0 ? true : false;

    Book b = Book(name, author, year, count, isAvailable);
    booksList.push_back(b);
}


void Menu::printAll() {
    for (size_t i = 0; i < booksList.size(); i++) {
        booksList[i].print();
    }

}

void Menu::deleteBook() {
    if (booksList.empty()) {
        std::cout << "your book list is empty";
        return;
    }

    int ch;
    std::cout << "1 - delete by index" << std::endl << "2 - delete by name" << std::endl << "-> ";
    std::cin >> ch;

    switch (ch) {
    case 1:
        int index;

        printAll();
        std::cout << "input index of Book" << std::endl << "-> ";
        std::cin >> index;

        deleteAtIndex(index);
        break;
    case 2:
        deleteByName();
        break;

    default:
        std::cout << "deleting canceled" << std::endl;
        break;
    }
}


void Menu::deleteAtIndex(int index) {
    if (index < 0 || index > booksList.size())
        return;

    booksList.erase(booksList.begin() + index);
    printAll();
}

void Menu::deleteByName() {
    std::string title;
    printAll();
    std::cout << "input book's title" << std::endl;
    getchar();
    std::getline(std::cin, title);
    int index;
    for (size_t i = 0; i < booksList.size(); i++) {
        if (booksList[i].getName() == title) {
            index = i;
            break;
        }
    }
    deleteAtIndex(index);

}

void Menu::sortingBy() {
    Book tmp;
    int ch;
    std::cout << "1 - by title" <<
        std::endl << "2 - by author" <<
        std::endl << "3 - by year" <<
        std::endl << "4 - by count" <<
        std::endl << "-> ";
    std::cin >> ch;

    switch (ch)
    {
    case 1:
        for (size_t i = 1; i < booksList.size(); i++)
            for (size_t j = 0; j < booksList.size() - i; j++) {

                if (booksList[j].getName() > booksList[j + 1].getName()) {
                    tmp = booksList[j];
                    booksList[j] = booksList[j + 1];
                    booksList[j + 1] = tmp;
                }

            }
        printAll();
        break;
    case 2:
        for (size_t i = 1; i < booksList.size(); i++)
            for (size_t j = 0; j < booksList.size() - i; j++) {
                if (booksList[j].getAuthor() > booksList[j + 1].getAuthor()) {
                    tmp = booksList[j];
                    booksList[j] = booksList[j + 1];
                    booksList[j + 1] = tmp;
                }

            }
        printAll();
        break;
    case 3:
        for (size_t i = 1; i < booksList.size(); i++)
            for (size_t j = 0; j < booksList.size() - i; j++) {

                if (booksList[j].getYear() > booksList[j + 1].getYear()) {
                    tmp = booksList[j];
                    booksList[j] = booksList[j + 1];
                    booksList[j + 1] = tmp;
                }

            }
        printAll();
        break;
    case 4:
        for (size_t i = 1; i < booksList.size(); i++)
            for (size_t j = 0; j < booksList.size() - i; j++) {

                if (booksList[j].getCount() > booksList[j + 1].getCount()) {
                    tmp = booksList[j];
                    booksList[j] = booksList[j + 1];
                    booksList[j + 1] = tmp;
                }

            }
        printAll();

        break;
    default:
        break;
    }

}

void Menu::bookOrder() {
    int index = -1;
    std::string title;
    int ch;

    std::cout << "which book you want to order?" << std::endl;
    getchar();
    std::getline(std::cin, title);

    for (size_t i = 0; i < booksList.size(); i++)
        if (booksList[i].getName() == title) {
            index = i;
            break;
        }
    if (index == -1) {
        std::cout << "we don't have any copies of this book in library :( " << std::endl;
        return;
    }

    if (booksList[index].getCount() > 0) {
        std::cout << booksList[index].getCount() << " books are available now" <<
            std::endl << "Do you want to order one of them?" << std::endl <<
            "1 - Yes" << std::endl << "2 - No" << std::endl << "-> ";
        std::cin >> ch;
        switch (ch) {
        case 1:
            std::cout << "congratulations! your book is waiting for you!" << std::endl;
            booksList[index].setCount(booksList[index].getCount() - 1);
            break;
        case 2:
            std::cout << ":(" << std::endl;
            break;
        default:
            break;
        }

    }
    else {
        std::cout << "we can't find this book in library :( " << std::endl;
    }

}

bool Menu::fileIsEmpty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void Menu::load() {
    std::ifstream fileIn;
    std::string initFile = "db.txt";

    std::string name;
    std::string author;
    int year;
    int count;
    bool isAvailable;
    int sizeOfList;
    if (!booksList.empty())
        booksList.clear();

    fileIn.open(initFile, std::ios_base::in);
    if (!fileIn) {
        throw "No file";
        return;
    } else if (fileIsEmpty(fileIn)) {
        std::cout << "file is empty" << std::endl;
        return;
    }

    else {
        fileIn >> sizeOfList;
    }

    for (size_t i = 0; i < sizeOfList; i++) {

        fileIn >> name >> author >> year >> count >> isAvailable;

        Book b = Book(name, author, year, count, isAvailable);
        booksList.push_back(b);
        fileIn.ignore(32767, '\n');
    }

}
void Menu::clearData() {
    std::ofstream file;
    std::string initFile = "db.txt";

    file.open(initFile, std::ofstream::out | std::ofstream::trunc);
    file.close();
}

void Menu::save() {
    clearData();
    std::ofstream fileOut;
    std::string initFile = "db.txt";

    fileOut.open(initFile, std::ios_base::app);

    if (!fileOut) {
        throw "no such file or directory";
    }
    else {
        fileOut << booksList.size() << std::endl;

    }
    for (size_t i = 0; i < booksList.size(); i++) {
        fileOut << std::endl <<
            booksList[i].getName() << std::endl <<
            booksList[i].getAuthor() << std::endl <<
            booksList[i].getYear() << std::endl <<
            booksList[i].getCount() << std::endl <<
            booksList[i].getAvailable() << std::endl;
    }

    fileOut.close();
}

void Menu::changeData() {
    printAll();
    int index, ch;

    std::cout << "select the item that needs to be changed" << std::endl << "-> ";
    std::cin >> index;

    std::cout << "which parameter do you want to change?" << std::endl
        << "1 - title" << std::endl << "2 - author" << std::endl << "3 - year" << std::endl <<
        "4 - count of books" << std::endl << "5 - all parameters" << std::endl << "-> ";
    std::cin >> ch;

    switch (ch) {
    case 1:
        changeTitle(index);
        break;
    case 2:
        changeAuthor(index);
        break;
    case 3:
        changeYear(index);
        break;
    case 4:
        changeCount(index);
        break;
    case 5:
        changeTitle(index);
        changeAuthor(index);
        changeYear(index);
        changeCount(index);
        break;

    default:
        break;
    }
}

void Menu::changeTitle(int index) {
    std::string title;
    std::cout << "old value: " << booksList[index].getName() << std::endl;
    std::cout << "enter new data for the 'title' field:" << std::endl;
    std::cin >> title;
    booksList[index].setName(title);
}
void Menu::changeAuthor(int index) {
    std::string author;
    std::cout << "old value: " << booksList[index].getAuthor() << std::endl;
    std::cout << "enter new data for the 'author' field:" << std::endl;
    std::cin >> author;
    booksList[index].setAuthor(author);
}
void Menu::changeYear(int index) {
    int year;
    std::cout << "old value: " << booksList[index].getYear() << std::endl;
    std::cout << "enter new data for the 'year' field:" << std::endl;
    std::cin >> year;
    booksList[index].setYear(year);
}
void Menu::changeCount(int index) {
    int count;
    std::cout << "old value: " << booksList[index].getCount() << std::endl;
    std::cout << "enter new data for the 'year' field:" << std::endl;
    std::cin >> count;
    booksList[index].setCount(count);
    booksList[index].setAvailable();
}