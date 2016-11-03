//
// Created by Rafael Kallis on 08.10.16.
//

#include <vector>
#include <sstream>
#include <iostream>
#include "../task1/pvector.h"
#include "../../assignment1/task2/fraction.h"

template<typename T>
class rpn {
public:
    rpn(std::string filename) : pv(pvector<T>(filename)) {}

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
                    pv.push(temp1);

                } else if (token == "d" && pv.size()) {
                    std::cout << pv.pop() << std::endl;

                } else if (token == "+") {
                    temp2 = pv.pop();
                    temp1 = pv.pop();
                    pv.push(temp1 + temp2);

                } else if (token == "-") {
                    temp2 = pv.pop();
                    temp1 = pv.pop();
                    pv.push(temp1 - temp2);

                } else if (token == "*") {
                    temp2 = pv.pop();
                    temp1 = pv.pop();
                    pv.push(temp1 * temp2);

                } else if (token == "/") {
                    temp2 = pv.pop();
                    temp1 = pv.pop();
                    pv.push(temp1 / temp2);

                } else if(token == "m") {
                    temp2 = pv.pop();
                    temp1 = pv.pop();
                    pv.push(temp1 < temp2 ? temp1 : temp2);
                }
            }
        }
    }

private:
    pvector<T> pv;
};

int main() {
    rpn<int> r("assignment2/task5/data_int");
//    rpn<fraction> r("assignment2/task5/data_fraction");
    r.start();
    return 0;
}