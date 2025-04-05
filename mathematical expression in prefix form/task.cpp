#include <iostream>
#include <string>
using namespace std;

struct stack{
    int inf;
    stack *next;
};

void push(stack *&h, int x) {
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack *&h) {
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(string &str) {
    string str1;
    for (int i = str.length() - 1; i >= 0; i--) {
        str1.append(str.substr(i, 1));
    }
    str = str1;
}

void reverse_st(stack *&h) {
    stack *head1 = NULL;
    while(h) {
        push(head1, pop(h));
    }
    h = head1;
}

stack *oper(stack *&h, char t) {
    stack *h1 = NULL;
    int fst = pop(h);
    int snd = pop(h);
    while(h) {
        int temp = pop(h);
        push(h1, temp);
    }
    int new_num;
    switch(t) {
        case '+': new_num = fst + snd; break;
        case '-': new_num = fst - snd; break;
        case '*': new_num = fst * snd; break;
        case '/': new_num = fst / snd; break;
    }
    reverse_st(h1);
    push(h1, new_num);
    return h1;
}

int main() {
    stack *h = NULL;
    stack *h1 = NULL;
    string str;
    getline(cin, str);
    reverse(str);
    for (int i = 0; i < str.length(); i++) {
        string t = str.substr(i, 1);
        if (isdigit(str[i])) {
            int num = atoi(t.c_str());
            push(h, num);
        }
        else {
            h = oper(h, str[i]);
        }
    }
    cout << pop(h) << '\n';
}

