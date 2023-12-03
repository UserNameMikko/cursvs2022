#pragma once
#include<iostream>

class Book {

private:
    std::string name;
    std::string author;
    int year;
    int count;
    bool isAvailable;

public:
    /*constructors*/

    Book();
    Book(const Book& book);

    Book(std::string name, std::string author, int year, int count, bool isAvailable);
    ~Book();

    /*setters*/

    void setName(std::string name);
    void setAuthor(std::string author);
    void setYear(int year);
    void setCount(int count);
    void setAvailable();
    /*getters */

    std::string getName();
    std::string getAuthor();
    int getYear();
    int getCount();
    bool getAvailable();

    /*base output for instance of class*/

    void print();
};