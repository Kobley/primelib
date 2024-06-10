#include "primelib.h"

void primelib::output() {
    for (auto& prime : primelib::oprimes) {
        std::cout << prime << std::endl;
    }
}

void primelib::calc_bruns_constant() {
    long double b2{};
    for (auto& prime : primelib::oprimes) {
        uint64_t twin = prime + 2;
        if (primelib::oprimes.find(twin) != primelib::oprimes.end()) {
            b2 += (1.0 / prime) + (1.0 / twin);
            std::cout << b2 << "\r";
        }
    }
}

void primelib::atkins(uint64_t limit) {

    if (limit < 2) return;

    bool* sieve = new bool[limit + 1];
    for (uint64_t i = 0; i <= limit; ++i) {
        sieve[i] = false;
    }

    uint64_t sqrtLimit = static_cast<uint64_t>(std::sqrt(limit));
    for (uint64_t x = 1; x <= sqrtLimit; ++x) {
        for (uint64_t y = 1; y <= sqrtLimit; ++y) {
            uint64_t n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
                sieve[n] = !sieve[n];
            }
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7) {
                sieve[n] = !sieve[n];
            }
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11) {
                sieve[n] = !sieve[n];
            }
        }
    }

    for (uint64_t n = 5; n <= sqrtLimit; ++n) {
        if (sieve[n]) {
            uint64_t x = n * n;
            for (uint64_t k = x; k <= limit; k += x) {
                sieve[k] = false;
            }
        }
    }

    for (uint64_t n = 5; n <= limit; ++n) {
        if (sieve[n]) {
            primelib::oprimes.insert(n);
        }
    }

    delete[] sieve;
}

template <typename T>
void primelib::eratosthenes(uint64_t limit, const T& container) {

    static_assert(
        std::is_same<T, std::set<typename T::key_type>>::value || 
        std::is_same<T, std::unordered_set<typename T::key_type>>::value, 
        "T must be std::set or std::unordered_set"
    );

    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (uint64_t p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            container.insert(p);
            for (uint64_t i = p * 2; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
}