#include <fstream>
#include <iostream>
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


worker str_to_worker(string str) {
    worker human;
    size_t k = 0; size_t k1 = str.find_first_of(',');
    human.surname = str.substr(k, k1);
    k = k1 + 2; k1 = str.find_first_of(',', k);
    human.experience = stoi(str.substr(k, k1 - k));
    k = k1 + 2; k1 = str.find_first_of(',', k);
    size_t i = k; size_t i1 = str.find_first_of('.', k);
    human.date_of_birthday.day = stoi(str.substr(i, i1 - i));
    i = i1 + 1; i1 = str.find_first_of('.', i);
    human.date_of_birthday.month = stoi(str.substr(i, i1 - i));
    i = i1 + 1; i1 = str.find_first_of('.', i);
    human.date_of_birthday.year = stoi(str.substr(i, i1 - i));
    k = k1 + 2; k1 = str.find_first_of(',', k);
    human.post = str.substr(k, k1 - k);
    k = k1 + 2; k1 = str.find_first_of(',', k);
    human.pay = stoi(str.substr(k, k1 - k));
    return human;
}