//
// Created by Rafael Kallis on 09.10.16.
//

#include "pvector.h"
#include "pset.h"
#include "trait_base.h"


int main(){
//    pvector<int, int_trait> pv("assignment3/task1/data");
//    pv.push(3);
    pset<int, int_trait> ps("assignment3/task1/data");
    ps.insert(4);

    return 0;
}