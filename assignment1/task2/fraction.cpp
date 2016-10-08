//
// Created by Rafael Kallis on 07.10.16.
//

#include <iostream>

class fraction {
public:
    fraction(int nom = 1, int denom = 1) : nom(nom / gcd(nom, denom)), denom(denom / gcd(nom, denom)) {}

    ~fraction() {}

    bool operator==(const fraction &arg) {
        return this->nom == arg.nom && this->denom == arg.denom;
    }

    bool operator!=(const fraction &arg) {
        return !(*this == arg);
    }

    fraction &operator+(const fraction &arg) {
        int common_denom = this->denom * arg.denom;
        int this_mult = common_denom / this->denom;
        int arg_mult = common_denom / arg.denom;
        int nom = this->nom * this_mult + arg.nom * arg_mult;
        int g = gcd(nom, common_denom);
        return *(new fraction(nom / g, common_denom / g));
    }

    fraction &operator-(const fraction &arg) {
        int common_denom = this->denom * arg.denom;
        int this_mult = common_denom / this->denom;
        int arg_mult = common_denom / arg.denom;
        int nom = this->nom * this_mult - arg.nom * arg_mult;
        int g = gcd(nom, common_denom);
        return *(new fraction(nom / g, common_denom / g));
    }

    fraction &operator*(const fraction &arg) {
        int nom = this->nom * arg.nom;
        int denom = this->denom * arg.denom;
        int g = gcd(nom, denom);
        return *(new fraction(nom / g, denom / g));
    }

    fraction &operator*(const int &arg) {
        return *(new fraction(this->nom / arg, this->denom));
    }

    fraction &operator/(const fraction &arg) {
        int nom = this->nom * arg.denom;
        int denom = this->denom * arg.nom;
        int g = gcd(nom, denom);
        return *(new fraction(nom / g, denom / g));
    }

    friend std::ostream &operator<<(std::ostream &, const fraction &);

    friend std::istream &operator>>(std::istream &, fraction &);

private:
    int nom;
    int denom;

    int gcd(const int arg0, const int arg1) {
        return arg1 == 0 ? arg0 : gcd(arg1, arg0 % arg1);
    }
};

std::ostream &operator<<(std::ostream &out, const fraction &arg) {
    return out << arg.nom << '/' << arg.denom;
}

std::istream &operator>>(std::istream &in, fraction &arg) {
    return in >> arg.nom >> arg.denom;
}