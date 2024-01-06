#ifndef GRADUALMETHOD_H
#define GRADUALMETHOD_H
#include "searchmethods.h"
#include <vector>
using namespace std;

class GradualMethod : public SearchMethods {
public:
    int Search(vector<int> A, int search_key)override;
};

#endif // GRADUALMETHOD_H
