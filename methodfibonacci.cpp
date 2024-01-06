#include "methodfibonacci.h"
#include <vector>
#include <algorithm>
#include <QDebug>
using namespace std;


int MethodFibonacci::Search(vector<int> A, int search_key) {
    comparisons = 0;
    int Fib_2 = 0;
    int Fib_1 = 1;
    int Fib = Fib_2 + Fib_1;

    while (Fib < A.size()) {
        Fib_2 = Fib_1;
        Fib_1 = Fib;
        Fib = Fib_2 + Fib_1;
    }
    int offset = -1;

    while (Fib > 1) {
        comparisons += 1;
        int i = std::min(offset + Fib_2, static_cast<int>(A.size()) - 1);

        if (A[i] < search_key) {
            Fib = Fib_1;
            Fib_1 = Fib_2;
            Fib_2 = Fib - Fib_1;
            offset = i;
        }

        else if (A[i] > search_key) {
            Fib = Fib_2;
            Fib_1 = Fib_1 - Fib_2;
            Fib_2 = Fib - Fib_1;
        }

        else
            return i+1;
    }

    comparisons += 1;
    if (Fib_1 && A[offset + 1] == search_key)
        return offset + 2;

    return -1;
}
