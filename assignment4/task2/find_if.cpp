//
// Created by Rafael Kallis on 25.10.16.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sys/time.h>
#include <cmath>

bool matches(int i) {
    return i == 94;
}

bool matches_random(int i) {
    return i == std::floor(rand());
}

int main() {
    srand(time(NULL));

    int match = 94;

    std::vector<int> v;
    std::vector<long> deltas;

    const int max_n = 10000000;

    for (int i = 0; i < max_n; i++) {
        int random = rand() % max_n;
        v.push_back(random);
    }

    struct timeval tp_start;
    for (int i = 0; i < 500; ++i) {
        int random_int = std::floor(rand() % max_n);
        auto matches_bench = ([&] (const int& s) { return s == random_int; });

        gettimeofday(&tp_start, NULL);
        long int start = tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000;
        std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), matches_bench);
        struct timeval tp_end;
        gettimeofday(&tp_end, NULL);
        long int end = tp_end.tv_sec * 1000 + tp_end.tv_usec / 1000;
        if (it != v.end()) deltas.push_back(end - start);
    }

    int mean = 0;
    int size = deltas.size();
    while(!deltas.empty()){
        mean += deltas.back();
        deltas.pop_back();
    }
    std::cout << "mean = " << (double) mean / size << " ms" << std::endl;
}