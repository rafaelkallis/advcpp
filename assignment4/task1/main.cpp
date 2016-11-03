//
// Created by Rafael Kallis on 25.10.16.
//

#include <vector>
#include <iostream>
#include "container_merger.cpp"

template<typename T>
struct vector_control {
public:
    static void push(std::vector<T> &v, T &val) {
        v.push_back(val);
    }

    static T pop(std::vector<T> &v) {
        if (v.empty()) return (T) NULL;
        T val = v.back();
        v.pop_back();
        return val;
    }
};


int main() {

    std::vector<int> v1, v2, o;

    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);

    v2.push_back(6);
    v2.push_back(5);
    v2.push_back(4);


//    container_merger<int,
//            std::vector<int>,
//            vector_control<int>,
//            std::vector<int>,
//            vector_control<int>,
//            std::vector<int>,
//            vector_control<int>>::merge(v1, v2, o);

    container_merger<int,
            std::vector<int>,
            vector_control<int>>::merge(v1, v2, o);

    std::cout << o[0] << std::endl << o[1] << std::endl << o[2] << std::endl << o[3] << std::endl << o[4] << std::endl << o[5] << std::endl;
    return 0;
}