//
// Created by Rafael Kallis on 10.10.16.
//

#ifndef ADVCPP_PSET_H
#define ADVCPP_PSET_H

#include <set>

template<typename T,
        typename Serialiser,
        typename _Compare = std::less <T>,
        typename _Allocator = std::allocator <T> >
class pset {
public:
    pset(char *filename) : filename(filename) { read_set(); }

    ~pset() { write_set(); }

    void insert(const T &arg) {
        s.insert(arg);
    }

    T &find(const T &arg) {
        s.find(arg);
    }

private:
    char *filename;
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
