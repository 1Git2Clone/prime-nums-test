#include <iostream>
#include <vector>

// Solution 3:
// Sieve of Eratosthenes
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// O(n log log n)

std::vector<int> sieveOfEratosthenes(int n) {
  std::vector<bool> primes(n + 1, true);
  primes[0] = primes[1] = false;

  for (int p = 2; p * p <= n; ++p) {
    if (primes[p]) {
      for (int i = p * p; i <= n; i += p) {
        primes[i] = false;
      }
    }
  }

  std::vector<int> prime_numbers;
  for (int i = 2; i <= n; ++i) {
    if (primes[i]) {
      prime_numbers.push_back(i);
    }
  }

  return prime_numbers;
}

void printSieveOfEratosthenes(int n) {
  std::cout << "Prime numbers from 1 to " << n << ": ";
  std::vector<int> resVectorized = sieveOfEratosthenes(n);
  for (const auto &element : resVectorized) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}
