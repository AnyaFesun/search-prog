#ifndef METHODFIBONACCI_H
#define METHODFIBONACCI_H
#include "searchmethods.h"
#include <vector>
using namespace std;

class MethodFibonacci : public SearchMethods {
public:
    int Search(vector<int> A, int search_key)override;

};

#endif // METHODFIBONACCI_H
