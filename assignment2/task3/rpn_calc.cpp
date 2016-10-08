//
// Created by Rafael Kallis on 08.10.16.
//

#include <vector>
#include <sstream>
#include <iostream>

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
        char line[256];
        std::cout << "[ q, n[0-9]*, d, +, -, *, /]*" << std::endl;
        std::cin.getline(line, 256);
        char * token = std::strtok(line, " ");
        while (token) {
            if (!std::strcmp(token, "q")) {
                run = false;
                break;

            } else if (!std::strcmp(token, "n")) {
                token = std::strtok(NULL, " ");
                v.push_back(std::stoi(token));

            } else if (!std::strcmp(token, "d") && v.size()) {
                std::cout << pop(v) << std::endl;

            } else if (!std::strcmp(token, "+")) {
                pop_last(v, temp1, temp2);
                v.push_back(temp1 + temp2);

            } else if (!std::strcmp(token, "-")) {
                pop_last(v, temp1, temp2);
                v.push_back(temp1 - temp2);

            } else if (!std::strcmp(token, "*")) {
                pop_last(v, temp1, temp2);
                v.push_back(temp1 * temp2);

            } else if (!std::strcmp(token, "/")) {
                pop_last(v, temp1, temp2);
                v.push_back(temp1 / temp2);

            }
            token = std::strtok(NULL, " ");
        }
    }
}

int main() {
    start_rpn_calc();
    return 0;
}