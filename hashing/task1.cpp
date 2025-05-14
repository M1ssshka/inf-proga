#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

struct worker {
    string post;
    string surname;
    date date_of_birthday;
    int experience;
    int pay;
};

struct list {
    worker inf;
    list *prev;
    list *next;
};

struct List {
    list *h;
    list *t;
};
