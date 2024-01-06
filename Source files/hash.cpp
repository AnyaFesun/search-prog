#include "hash.h"
#include <list>
#include <vector>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>
using namespace std;

Hash::Hash(int a) {
    bucket = a;
    table = new list<int>[bucket];
}
void Hash::Insert(int key, int value) {
    int index =  HashFunction(key);
    table[index].push_back(value);
}

Hash::~Hash() {
    delete[] table;
}

int Hash::SearchKey(int key, vector<int> A, int& comp) {
    int index = HashFunction(key);

    std::list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        comp +=1;
        if (key == A[*i]){
            return *i+1;
        }
    }

    return -1;
}

int Hash::HashFunction(int x) {
    return x % bucket;
}
