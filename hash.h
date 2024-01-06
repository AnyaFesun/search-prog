#ifndef HASH_H
#define HASH_H
#include <list>
#include <vector>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>
using namespace std;

class Hash {
    int bucket;
    list<int>* table;

    int HashFunction(int x);
public:
    Hash(int a);
    void Insert(int key, int value);

    ~Hash();
    int SearchKey(int key, vector<int> A, int& comp) ;
};


#endif // HASH_H
