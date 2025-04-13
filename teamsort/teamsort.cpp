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
    int n = a.size();
    int minrun = compute_minrun(n);
    vector<vector<int>> runs;
    int i = 0;
    while(i < n) {
        if (i == n - 1) {
            vector<int> temp = {a[i]};
            runs.push_back(temp);
            break;
        }
        vector<int> run;
        if (a[i] <= a[i + 1]) {
            run = {a[i], a[i + 1]};
            i += 2;
            while (i < n && a[i] >= run[run.size() - 1]) {
                run.push_back(a[i]);
                i++;
            }
        }
        else {
            run = {a[i], a[i + 1]}; 
            i += 2;
            while (i < n && a[i] <= run[run.size() - 1]) {
                run.push_back(a[i]);
                i++;
            }
            reverse(run.begin(), run.end());
        }
        if (run.size() < minrun) {
            int t = i + minrun - run.size();
            int end = min(t, n);
            for (int j = i; j < end; j++) {
                run.push_back(a[j]);
            }
            insertion_sort(run);
            i = end;
        }
        runs.push_back(run);
    }
    while(runs.size() > 1) {
        vector<int> A;
        if (runs.size()) {
            A = runs[runs.size() - 1];
            runs.pop_back();
        }
        vector<int> B;
        if (runs.size()) {
            B = runs[runs.size() - 1];
            runs.pop_back();
        }
        vector<int> C;
        if (runs.size()) {
            C = runs[runs.size() - 1];
            runs.pop_back();
        }
        vector<int> merged;
        if (C.size() && (A.size() <= B.size() + C.size())) {
            merged = merge(B, C);
            runs.push_back(merged);
            runs.push_back(A);
        }
        else if (B.size() && (A.size() <= B.size())) {
            merged = merge(A, B);
            runs.push_back(merged);
            if (C.size()) {
                runs.push_back(C);
            }
        }
        else {
            if (C.size()) {
                runs.push_back(C);
            }
            if (B.size()) {
                runs.push_back(B);
            }
            runs.push_back(A);
            break;
        }
    }
    vector<int> sort_arr;
    if (runs.size() == 1) {
        sort_arr = runs[0];
    }
    return sort_arr;
}

int main() {

}
