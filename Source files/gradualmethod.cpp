#include "gradualmethod.h"
#include <vector>
#include <QDebug>
using namespace std;

int GradualMethod :: Search(vector<int> A, int search_key) {
    comparisons = 0;
    for (int i = 0; i < A.size(); i++) {
        comparisons += 1;

        if (A[i] == search_key) {
            return i + 1;
        }
    }

    return -1;
}
