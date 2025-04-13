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
    int len = a.size() + b.size();
    vector<int> c(len);
    int i = 0;
    int j = 0;
    int curr = 0;
    while((i + j) <= len - 1) {
        if (j >= b.size()) {
            while(i < a.size()) {
                c[curr] = a[i];
                curr++;
                i++;
            }
        }
        else if (i >= a.size()) {
            while(j < b.size()) {
                c[curr] = b[j];
                curr++;
                j++;
            }
        }
        else if (a[i] < b[j] && i < a.size() && j < b.size()) {
            c[curr] = a[i];
            curr++;
            i++;
        }
        else if (a[i] > b[j] && i < a.size() && j < b.size()) {
            c[curr] = b[j];
            curr++;
            j++;
        }
        else if (i < a.size() && j < b.size()) {
            c[curr] = a[i];
            curr++;
            c[curr] = b[j];
            curr++;
            i++;
            j++;
        }
    }
    return c;
}

vector<int> timsort(vector<int> a) {
    
}

int main() {

}
