//
// Created by Rafael Kallis on 09.10.16.
//

#include <vector>
#include <fstream>
#include <iostream>
#include "trait_base.h"

template<typename T, typename P>
class pvector {
public:
    pvector(std::string filename) : filename(filename) {
        if (!exists_file()) { std::cout << "file doesn't exist" << std::endl; }
        read_vector();
    }

    ~pvector() {
        write_vector();
    }

    void push(const T &arg) {
        v.push_back(arg);
    }

    T &pop() {
        T pop = v.back();
        v.pop_back();
        return pop;
    }

    size_t size() const {
        return v.size();
    }

private:
    std::string filename;
    std::vector<T> v;

    bool exists_file() {
        std::ifstream ifs(filename);
        return ifs.good();
    }

    void read_vector() {
        std::ifstream ifs(filename);
        while (true) {
            T in = P::read(ifs);
            if (!ifs.good()) break;
            v.push_back(in);
        }
    }

    void write_vector() {
        std::ofstream ofs(filename);
        typename std::vector<T>::iterator fst = v.begin(), lst = v.end();
        while (fst != lst) P::write(ofs, *fst++);
    }
};