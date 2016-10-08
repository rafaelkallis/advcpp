#include <iostream>
#include "assignment2/task1/pvector.cpp"

template <typename T>
void foo(pvector<T> & p){
    p.push(4);
}

int main() {
    pvector<int> p("assignment2/task1/data");
    foo(p);

    return 0;
}