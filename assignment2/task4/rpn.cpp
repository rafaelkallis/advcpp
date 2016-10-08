//
// Created by Rafael Kallis on 08.10.16.
//

#include <vector>
#include <sstream>
#include <iostream>
#include "../../assignment1/task2/fraction.cpp"

template<typename T>
class rpn {
public:
    rpn(T (*parse)(char *)) : parse(parse) {}

    ~rpn() {}

    void start() {
        bool run = true;
        while (run) {
            T temp1, temp2;
            char line[256];
            std::cout << "[ q, n[0-9]*, d, +, -, *, /]*" << std::endl;
            std::cin.getline(line, 256);
            char *token = std::strtok(line, " ");
            while (token) {
                if (!std::strcmp(token, "q")) {
                    run = false;
                    break;

                } else if (!std::strcmp(token, "n")) {
                    token = std::strtok(NULL, " ");
                    v.push_back(parse(token));

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

private:
    std::vector<T> v;

    T (*parse)(char *);

    void pop_last(std::vector<T> &v, T &before_last, T &last) {
        typename std::vector<T>::iterator lst = v.end();
        last = *--lst;
        before_last = *--lst;
        lst = v.erase(lst);
        lst = v.erase(lst);
    }

    template<typename C>
    C &pop(std::vector<C> &v) {
        C &pop = v.back();
        v.pop_back();
        return pop;
    }
};

int parse_int(char *string) {
    return std::stoi(string);
}

/**
 * Fraction in the form of <int>/<int>, e.g 1/3, 4/3, ...
 * @param string
 * @return
 */
fraction parse_fraction(char *string) {
    int del_index = std::strcspn(string, "/");
    int end_index = std::strlen(string);
    char nom_string[del_index + 1];
    char denom_string[end_index - del_index];

    std::strncpy(nom_string, string, del_index + 1);
    nom_string[del_index] = '\0';

    std::strncpy(denom_string, string + del_index + 1, end_index - del_index);
    denom_string[end_index - del_index - 1] = '\0';

    int nom = std::stoi(nom_string);
    int denom = std::stoi(denom_string);
    fraction f(nom, denom);
    return f;
}

int main() {
    rpn<int> r(parse_int);
//    rpn<fraction> r(parse_fraction);
    r.start();
    return 0;
}