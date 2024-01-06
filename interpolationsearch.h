#ifndef INTERPOLATIONSEARCH_H
#define INTERPOLATIONSEARCH_H
#include "searchmethods.h"
#include <vector>
using namespace std;

class InterpolationSearch : public SearchMethods {
public:
    int Search(vector<int> A, int search_key)override;

};
#endif // INTERPOLATIONSEARCH_H
