//
// Created by Rafael Kallis on 10.10.16.
//

#ifndef ADVCPP_PSET_H
#define ADVCPP_PSET_H

#include <set>
#include <fstream>
#include "trait_base.h"


template<typename T,
        typename Serialiser = default_trait<T>,
        typename _Compare = std::less <T>,
        typename _Allocator = std::allocator <T> >
class pset {
public:
    pset(std::string filename) : filename(filename) { read_set(); }

    ~pset() { write_set(); }

    void insert(const T &arg) {
        s.insert(arg);
    }

    T &find(const T &arg) {
        return s.find(arg);
    }

    int count(const T &arg) {
        return s.count(arg);
    }

private:
    std::string filename;
    std::set<T, _Compare, _Allocator> s;

    void read_set() {
        std::ifstream ifs(filename);
        while (true) {
            T in = Serialiser::read(ifs);
            if (!ifs.good()) break;
            s.insert(in);
        }
    }

    void write_set() {
        std::ofstream ofs(filename);
        typename std::set<T>::iterator fst = s.begin(), lst = s.end();
        while (fst != lst) Serialiser::write(ofs, *fst++);
    }
};


#endif //ADVCPP_PSET_H
