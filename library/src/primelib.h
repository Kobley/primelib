#pragma once

#include <iostream>
#include <set> //slower, but ordered.
#include <unordered_set> //faster, but unordered.
#include <vector>
#include <algorithm>
//#include <iomanip> //previously for std::setprecision. i dont think ill need it but its useful sometimes.
//#include "gmp.h" //for arbitrary precision and extra math, not in use for now. but 100% will be coming soon

/*
AUTHOR: Kobley @ github
*/

class primelib {
public:
    std::unordered_set<uint64_t> uprimes;
    std::set<uint64_t> oprimes;

    //all probably temp for now. just getting things going.

    //output/formatting
    void output();

    //misc/fun
    void calc_bruns_constant();

    //gen
    void atkins(uint64_t);

    template <typename T>
    void eratosthenes(uint64_t, const T&);
};
