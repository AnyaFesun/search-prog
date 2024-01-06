#ifndef HASHSEARCH_H
#define HASHSEARCH_H
#include "searchmethods.h"
#include <vector>
using namespace std;

class HashSearch :public SearchMethods {
public:
    int Search(vector<int> A, int search_key)override;
};

#endif // HASHSEARCH_H
