// /src/utils/simd-vector-primes.cpp

#include <immintrin.h> // SIMD extensions
                       // AVX2 included.
#include <iostream>
#include <vector>

// Dynamic solution #2

// Using AVX2 (With the help of ChatGPT)

std::vector<int> evalPrimesVectorized(int n) {
  std::vector<int> res;
  // 1 isn't a prime number by definition
  // that's why we start from 2
  for (int i = 2; i <= n; i++) {
    res.push_back(i);
  }

  // Convert vector to array to make use of SIMD instructions
  int size = res.size();
  int *arr = res.data();

  // Perform the sieve of Eratosthenes algorithm using AVX2
  for (int i = 2; i * i <= n; i++) {
    if (arr[i - 2] != 0) { // Check if the number is not marked as composite
      __m256i prime = _mm256_set1_epi32(i);
      for (int j = i * i; j <= n; j += i) {
        if (j >= 2 && arr[j - 2] != 0) { // Check if j is within array bounds
                                         // and not marked as composite
          if (j % 8 == 0) {              // Check alignment for AVX2
            __m256i *addr = (__m256i *)(arr + j - 2);
            _mm256_storeu_si256(addr, _mm256_setzero_si256());
          } else {
            arr[j - 2] = 0; // Mark as composite
          }
        }
      }
    }
  }

  // Construct the result vector from the marked primes
  res.clear();
  for (int i = 0; i < size; i++) {
    if (arr[i] != 0) {
      res.push_back(arr[i]);
    }
  }

  return res;
}

void printEvalPrimesVectorized(int n) {
  std::cout << "Prime numbers from 1 to " << n << ": ";
  std::vector<int> resVectorized = evalPrimesVectorized(n);
  for (const auto &element : resVectorized) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}
