//
// Created by Rafael Kallis on 09.10.16.
//

#include "pvector.h"
#include "pset.h"
#include "trait_base.h"


int main(){
//    pvector<int, int_trait> pv("assignment3/task1/data_int");
//    pv.push(3);
    pset<int> ps("assignment3/task1/data_int");
    ps.insert(5);
    ps.insert(5);

    return 0;
}