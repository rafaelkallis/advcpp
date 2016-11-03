//
// Created by Rafael Kallis on 08.10.16.
//

#include <vector>
#include <sstream>
#include <iostream>
#include <sstream>

void pop_last(std::vector<double> &v, double &before_last, double &last) {
    typename std::vector<double>::iterator lst = v.end();
    last = *--lst;
    before_last = *--lst;
    lst = v.erase(lst);
    lst = v.erase(lst);
}

template<typename T>
T &pop(std::vector<T> &v) {
    T &pop = v.back();
    v.pop_back();
    return pop;
}

void start_rpn_calc() {
    std::vector<double> v;
    bool run = true;
    while (run) {
        double temp1, temp2;
        std::cout << "[ q, n ::double::, d, +, -, *, /])*" << std::endl;
        std::string line, token;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        while (iss.good()) {
            iss >> token;
            if (token == "q") {
                run = false;
                break;

            } else if (token == "n") {
                if (iss.bad()) throw std::runtime_error("no input");
                iss >> token;
                v.push_back(std::stoi(token));

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

            }
        }
    }
}

int main() {
    start_rpn_calc();
    return 0;
}