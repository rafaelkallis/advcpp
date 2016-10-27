//
// Created by Rafael Kallis on 08.10.16.
//

#include <vector>
#include <sstream>
#include <iostream>
#include "../task1/pvector.cpp"

template<typename T>
class rpn {
public:
    rpn(T (*parse)(char *), std::string filename) : parse(parse) {
        pv = new pvector<int>(filename);
    }

    ~rpn() {delete pv;}

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
                    pv->push(parse(token));

                } else if (!std::strcmp(token, "d") && pv->size()) {
                    std::cout << pv->pop() << std::endl;

                } else if (!std::strcmp(token, "+")) {
                    temp2 = pv->pop();
                    temp1 = pv->pop();
                    pv->push(temp1 + temp2);

                } else if (!std::strcmp(token, "-")) {
                    temp2 = pv->pop();
                    temp1 = pv->pop();
                    pv->push(temp1 - temp2);

                } else if (!std::strcmp(token, "*")) {
                    temp2 = pv->pop();
                    temp1 = pv->pop();
                    pv->push(temp1 * temp2);

                } else if (!std::strcmp(token, "/")) {
                    temp2 = pv->pop();
                    temp1 = pv->pop();
                    pv->push(temp1 / temp2);

                }else if(!std::strcmp(token, "m")) {
                    pop_last(v, temp1, temp2);
                    pv->push(temp1 < temp2 ? temp1 : temp2);
                    std::for_each(nums.begin(), nums.end(), [](int &n){ n++; });
                }
                token = std::strtok(NULL, " ");
            }
        }
    }

private:
    pvector<T> * pv;
    T (*parse)(char *);
};

int parse_int(char *string) {
    return std::stoi(string);
}

int main() {
    rpn<int> r(parse_int, "assignment2/task5/data");
    r.start();
    return 0;
}