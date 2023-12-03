#include"Book.h"

Book::Book() {
    this->name = "";
    this->author = "";
    this->year = 0;
    this->count = 0;
    this->isAvailable = false;
}
Book::Book(const Book& book) {
    this->name = book.name;
    this->author = book.author;
    this->year = book.year;
    this->count = book.count;
    this->isAvailable = book.isAvailable;
}

Book::Book(std::string name, std::string author, int year, int count, bool isAvailable) {
    this->name = name;
    this->author = author;
    this->year = year;
    this->count = count;
    this->isAvailable = isAvailable;
}
Book::~Book() = default;

/*setters*/

void Book::setName(std::string name) {
    this->name = name;
}
void Book::setAuthor(std::string author) {
    this->author = author;
}
void Book::setYear(int year) {
    this->year = year;
}
void Book::setCount(int count) {
    this->count = count;
}
void Book::setAvailable() {
    this->count == 0 ? false : true;
}

/*getters */

std::string Book::getName() {
    return this->name;
}
std::string Book::getAuthor() {
    return this->author;
}
int Book::getYear() {
    return this->year;
}
int Book::getCount() {
    return this->count;
}
bool Book::getAvailable() {
    return this->isAvailable;
}

/*base output for instance of class*/

void Book::print() {
    std::cout << this->name << "\t" << this->author << "\t" << this->year << "\t" << this->count << "\t" << this->isAvailable << std::endl;
}