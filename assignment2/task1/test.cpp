//
// Created by Rafael Kallis on 03.11.16.
//
#include <iostream>
#include <assert.h>
#include <math.h>
#include "pvector.h"

int main() {
    pvector<int> pv_int("assignment2/task1/data_int");
    pvector<float> pv_float("assignment2/task1/data_float");
    pvector<std::string> pv_string("assignment2/task1/data_string");
    pv_int.push(1);
    pv_int.push(2);
    pv_float.push(1.1);
    pv_float.push(1.2);
    pv_string.push("hello");
    pv_string.push("world");

    assert(pv_int.pop() == 2);
    assert(fabsf(pv_float.pop() - 1.2) < std::numeric_limits<float>::epsilon());
    assert(pv_string.pop() == "world");
    return 0;
}