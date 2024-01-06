#include "hashsearch.h"
#include <vector>
#include "hash.h"
using namespace std;

int HashSearch :: Search(vector<int> A, int search_key) {
    comparisons = 0;
    int size = A.size();
    Hash hashTable(size);
    for (int i = 0; i < A.size(); i++) {
        hashTable.Insert(A[i], i);
    }

    return hashTable.SearchKey(search_key, A, comparisons);

}
