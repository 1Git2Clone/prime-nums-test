// /src/utils/vector-primes.cpp

#include <iostream>
#include <vector>

// Dynamic solution

// This can't be solved on compile time
// because std::vector requires runtime memory sequence handling.
// - "It's not a bug, it's a feature."
std::vector<int> evalPrimes(int n) {
  std::vector<int> res;
  // 1 isn't a prime number by definition
  // that's why we start from 2
  for (int i = 2; i <= n; i++) {
    res.push_back(i);
  }

  for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
    // it+1 to avoid erasing the same element twice
    for (std::vector<int>::iterator prime_it = it + 1; prime_it != res.end();) {
      if (*prime_it % *it == 0) {
        // update for the erased element
        prime_it = res.erase(prime_it);
      } else {
        ++prime_it;
      }
    }
  }

  return res;
}

void printEvalPrimes(int n) {
  std::cout << "Prime numbers from 1 to " << n << ": ";
  std::vector<int> res = evalPrimes(n);
  for (const auto &element : res) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}
