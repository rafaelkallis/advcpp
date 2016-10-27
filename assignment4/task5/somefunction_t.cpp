//
// Created by Rafael Kallis on 25.10.16.
//

#include <functional>
#include <iostream>

template<class BinOp, class Op1, class Op2>
class somefunction_t :
        public std::unary_function<typename Op1::argument_type,
                typename BinOp::result_type> {
protected:
    BinOp o;
    Op1 o1;
    Op2 o2;
public:
    somefunction_t(BinOp binop, Op1 op1, Op2 op2)
            : o(binop), o1(op1), o2(op2) {}

    typename BinOp::result_type
    operator()(const typename Op1::argument_type &x) {
        return o(o1(x), o2(x));
    }
};

template<typename T>
struct multiplication {
public:
    T operator()(T arg0, T arg1) {
        return arg0 * arg1;
    }
};

template<typename T>
struct divide_by_2 {
public:
    T operator()(T arg) {
        return arg / 2;
    }
};

int main() {
    multiplication mult;
    divide_by_2 div_2;
    somefunction_t<multiplication, divide_by_2, divide_by_2> func(mult, div_2, div_2);

    std::cout << func(8) << std::endl;

    return 0;
}