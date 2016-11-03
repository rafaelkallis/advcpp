//
// Created by Rafael Kallis on 08.10.16.
//

#include <vector>
#include <sstream>
#include <iostream>
#include "../../assignment1/task2/fraction.h"

template<typename T>
class rpn {
public:
    rpn() {}

    ~rpn() {}

    void start() {
        bool run = true;
        while (run) {
            T temp1, temp2;
            std::cout << "[ q, n ::input::, d, +, -, *, /, m]*" << std::endl;
            std::string token, line;
            std::getline(std::cin, line);
            std::istringstream iss(line);
            while (iss.good()) {
                iss >> token;
                if (token == "q") {
                    run = false;
                    break;

                } else if (token == "n") {
                    if (iss.bad()) throw std::runtime_error("no input");
                    iss >> temp1;
                    v.push_back(temp1);

                } else if (token == "d" && v.size()) {
                    std::cout << pop(v) << std::endl;

                } else if (token == "+") {
                    pop_last(v, temp1, temp2);
                    v.push_back(temp1 + temp2);

                } else if (token == "-") {
                    pop_last(v, temp1, temp2);
                    v.push_back(temp1 - temp2);

                } else if (token == "*") {
                    pop_last(v, temp1, temp2);
                    v.push_back(temp1 * temp2);

                } else if (token == "/") {
                    pop_last(v, temp1, temp2);
                    v.push_back(temp1 / temp2);

                } else if (token == "m") {
                    T _min = v.back();
                    std::for_each(v.begin(), v.end(), [&](T &cur){ _min = _min < cur ? _min : cur; });
                    v.clear();
                    v.push_back(_min);
                }
            }
        }
    }

private:
    std::vector<T> v;

    void pop_last(std::vector<T> &v, T &before_last, T &last) {
        typename std::vector<T>::iterator lst = v.end();
        last = *--lst;
        before_last = *--lst;
        lst = v.erase(lst);
    }

    template<typename C>
    C &pop(std::vector<C> &v) {
        C &pop = v.back();
        v.pop_back();
        return pop;
    }
};

int main() {
//    rpn<int> r;
    rpn<fraction> r;
    r.start();
    return 0;
}




