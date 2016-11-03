//
// Created by Rafael Kallis on 09.10.16.
//

#ifndef TRAIT_BASE
#define TRAIT_BASE

template<typename T>
class default_trait {
public:
    static void write(std::ofstream &ofs, const T &out) {
        ofs << out << std::endl;
    }
    static T read(std::ifstream &ifs) {
        T in;
        ifs >> in;
        return in;
    }
};

class int_trait {
public:
    static void write(std::ofstream &ofs, const int &out) {
        ofs << out << std::endl;
    }
    static int read(std::ifstream &ifs) {
        int in;
        ifs >> in;
        return in;
    }
};

#endif