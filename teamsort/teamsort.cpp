#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compute_minrun(int n) {
    int r = 0;
    while(n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

void insertion_sort(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 && a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

vector<int> merge(vector<int> &a, vector<int> &b) {
    
}

vector<int> timsort(vector<int> a) {
    
}

int main() {

}
