//
// Created by Rafael Kallis on 29.09.16.
//

#include "pvector.h"

template<typename T>
void push_back(const T &el) {
    v.push_back(el);
}

void pop_back() {
    v.pop_back();
}
void readvector() {
    ifstream ifs(filename);
    while(true) {
        T x;
        ifs >> x;
        if (!ifs.good()) break;
        v.push_back(x);
    }
}
void writevector() {
    ofstream ofs(filename);
    typename vector<T>::iterator fst = v.begin(), lst = v.end();
    while (fst != lst) ofs << *fst++ << endl;
}