#include <iostream>
#include <chrono>
#include "primelib.h"

int main() {

	primelib* pl = new primelib();

	uint64_t n = 100000000ULL; // 100 million

	auto start = std::chrono::high_resolution_clock::now();

	pl->atkins(n);

	std::chrono::nanoseconds elapsed = std::chrono::high_resolution_clock::now() - start;
    const long long seconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed).count();
    std::cout << "Sieve of Atkins Generation took " << seconds << "s" << " Size: " << n << std::endl; //microsecond symbol \xC2\xB5

	system("pause");

	pl->calc_bruns_constant();
	std::cout << "\n";

	return 0;
}