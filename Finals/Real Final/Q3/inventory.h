#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>

using namespace std;

struct item
{
    string description;
    double price;
    string serialNumber;
    int quantity;
};

class inventory
{
    private:
        item * items;
        int size;
        int nElements;
    public:
        inventory(int);
        ~inventory();
        void addItem(const item &);
        void removeItem(const string &);
        void print();
        inventory(const inventory &);
        inventory & operator = (const inventory &);
};

#endif