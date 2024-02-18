// /src/main.cpp

#include "./definitions/definitions.hpp"

#include "./utils/simd-vector-primes.cpp"
#include "./utils/static-unoptimized-templating.cpp"
#include "./utils/vector-primes.cpp"

#include <chrono>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0]
              << "-eval (-e) | -simd-eval (-se) | -constexpr-eval (-ce)\n";
    return 1;
  }

  auto start = std::chrono::high_resolution_clock::now();

  std::string option(argv[1]);

  if (option == "-eval" || option == "-e") {
    printEvalPrimes(PRIME_UPPER_LIMIT);
  } else if (option == "-simd-eval" || option == "-se") {
    printEvalPrimesVectorized(PRIME_UPPER_LIMIT);
  } else if (option == "-constexpr-eval" || option == "-ce") {
    std::cout << "Prime numbers from 1 to " << PRIME_UPPER_LIMIT << ": ";
    print_if_prime<PRIME_UPPER_LIMIT, false>::print();
    std::cout << std::endl;
  } else {
    std::cerr << "Invalid argument. Usage: " << argv[0]
              << " [eval | simd-eval | constexpr-eval]\n";
    return 1;
  }

  auto end = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();

  std::cout << "Program finished in " << duration << " microseconds."
            << std::endl;
  return 0;
}
