//
// Created by Rafael Kallis on 29.09.16.
//

#ifndef ADVCPP_PVECTOR_H
#define ADVCPP_PVECTOR_H

template<typename T>
class Pvector {
public:
    Pvector(string fname);
    ~Pvector();
private:
    string filename;
    vector <T> v;

    void read_vector();
    void write_vector();
};

#endif //ADVCPP_PVECTOR_H
