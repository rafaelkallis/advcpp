//
// Created by Rafael Kallis on 07.10.16.
//

#include <iostream>

class fraction {
public:
    fraction(int nom = 1, int denom = 1) : nom(nom), denom(denom) { simplify(); }

    ~fraction() {}

    bool operator==(const fraction &arg) {
        return this->nom == arg.nom && this->denom == arg.denom;
    }

    bool operator<(const fraction &arg) {
        return this->nom * arg.denom < this->denom * arg.nom;
    }

    fraction operator+(const fraction &arg) {
        fraction sum(this->nom * arg.denom + arg.nom * this->denom, this->denom * arg.denom);
        sum.simplify();
        return sum;
    }

    fraction operator-(const fraction &arg) {
        fraction difference(this->nom * arg.denom - arg.nom * this->denom, this->denom * arg.denom);
        difference.simplify();
        return difference;
    }

    fraction operator*(const fraction &arg) {
        fraction product(this->nom * arg.nom, this->denom * arg.denom);
        product.simplify();
        return product;
    }

    fraction operator*(const int &arg) {
        fraction product(this->nom * arg, denom);
        product.simplify();
        return product;
    }

    fraction operator/(const fraction &arg) {
        fraction quotient(this->nom * arg.denom, this->denom * arg.nom);
        quotient.simplify();
        return quotient;
    }

    fraction operator/(const int &arg) {
        fraction quotient(this->nom, this->denom * arg);
        quotient.simplify();
        return quotient;
    }


    friend std::ostream &operator<<(std::ostream &, const fraction &);

    friend std::istream &operator>>(std::istream &, fraction &);

private:
    int nom;
    int denom;

    static int gcd(const int arg0, const int arg1) {
        return arg1 == 0 ? arg0 : gcd(arg1, arg0 % arg1);
    }

    void simplify() {
        int gcd_memo = gcd(this->nom, this->denom);
        this->nom = this->nom / gcd_memo;
        this->denom = this->denom / gcd_memo;
    }
};

std::ostream &operator<<(std::ostream &out, const fraction &arg) {
    return out << arg.nom << "/" << arg.denom;
}

std::istream &operator>>(std::istream &in, fraction &arg) {
    std::string nom_string, denom_string;
    std::getline(in, nom_string, '/');
    if (!std::getline(in, denom_string, ' '))
        std::getline(in, denom_string);

    arg.nom = std::stoi(nom_string);
    arg.denom = std::stoi(denom_string);
    return in;
}