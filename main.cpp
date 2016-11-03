#include <iostream>
#include "assignment2/task1/pvector.h"

template <typename T>
void foo(pvector<T> & p){
    p.push(4);
}

int main() {
    pvector<int> p("assignment2/task1/data_int");
    foo(p);

    return 0;
}