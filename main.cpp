#include <cstddef>
#include <iostream>
#include <vector>

// Returns all primes in [2, n] using the Sieve of Eratosthenes.
static std::vector<std::size_t> sieve(std::size_t n) {
    std::vector<std::size_t> primes;
    if (n < 2) {
        return primes;
    }

    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (std::size_t i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (std::size_t j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (std::size_t i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    long long n = 0;
    if (!(std::cin >> n)) {
        std::cerr << "error: expected an integer on stdin\n";
        return 1;
    }
    if (n < 0) {
        std::cerr << "error: N must be non-negative\n";
        return 1;
    }

    std::vector<std::size_t> primes = sieve(static_cast<std::size_t>(n));
    std::cout << "Pocet prvocisel je " << primes.size() << '\n';
    for (std::size_t p : primes) {
        std::cout << p << '\n';
    }
    return 0;
}
