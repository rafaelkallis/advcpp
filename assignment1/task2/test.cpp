//
// Created by Rafael Kallis on 07.10.16.
//

#include <assert.h>
#include "fraction.cpp"

int main() {
    Fraction fraction1(1, 2);
    Fraction fraction2(2, 3);
    assert((fraction1 + fraction2) == *(new Fraction(7, 6)));
    assert(fraction2 - fraction1 == *(new Fraction(1, 6)));
    assert(fraction1 - fraction2 == *(new Fraction(-1, 6)));
    assert(fraction1 * fraction2 == *(new Fraction(2, 6)));
    assert(fraction1 / fraction2 == *(new Fraction(3, 4)));
    std::cout << "You had a very hard day, had no sleep recently, can't wait for the weekend, but theres one thing you have to do..." << std::endl;
    std::cout << "Fraction operations!!!!!" << std::endl;
    while (true) {
        Fraction f1, f2, f3;
        char oper, option;
        std::cout << "Type your first fraction: nominator <return> denominator" << std::endl;
        std::cin >> f1;
        std::cout << "Type your second fraction: nominator <return> denominator" << std::endl;
        std::cin >> f2;
        std::cout << "Type your operator: {+, -, *, /}" << std::endl;
        std::cin >> oper;
        switch (oper) {
            case '+':
                f3 = f1 + f2;
                break;
            case '-':
                f3 = f1 - f2;
                break;
            case '*':
                f3 = f1 * f2;
                break;
            case '/':
                f3 = f1 / f2;
                break;
        }
        std::cout << "The result is " << f3 << std::endl;
        std::cout << "Did you have enough? (y/n)" << std::endl;
        std::cin >> option;
        if (option != 'n') break;
    }
    return 0;
}