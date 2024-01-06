#include "interpolationsearch.h"
#include <vector>
#include <QDebug>
using namespace std;

int InterpolationSearch::Search(vector<int> A, int search_key) {
    comparisons = 0;
    int low = 0;
    int high = A.size() - 1;
    int mid;

    while ((A[high] != A[low]) && (search_key >= A[low]) && (search_key <= A[high])) {
        mid = low + ((search_key - A[low]) * (high - low) / (A[high] - A[low]));

        comparisons += 1;
        if (A[mid] < search_key) {
            low = mid + 1;
        }
        else if (search_key < A[mid]) {
            high = mid - 1;
        }
        else {
            return mid+1;
        }
    }


    comparisons += 1;
    if (search_key == A[low]) {
        return low+1;
    }
    else {
        return -1;
    }


}
