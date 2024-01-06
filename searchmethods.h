#ifndef SEARCHMETHODS_H
#define SEARCHMETHODS_H
#include <vector>
using namespace std;

class SearchMethods {
protected:
    int comparisons;
public:
    virtual int Search(vector<int> A, int search_key) = 0;
    int GetComparisons();
};

#endif // SEARCHMETHODS_H
