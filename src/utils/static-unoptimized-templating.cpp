// /src/static-primes.cpp

#include <iostream>

// Static solution

// This can have quicker run times because
// constexpr values are evaluated on compile time

// Good thing is that it doesn't need any libraries i guess.
// allowing the program to just print out the result.

// ChatGPT solved it because I was completely clueless
// about template metaprogramming

template <int N, int D> struct is_prime_helper {
  static constexpr bool value =
      (N % D != 0) && is_prime_helper<N, D - 1>::value;
};

template <int N> struct is_prime_helper<N, 2> {
  static constexpr bool value = (N % 2 != 0);
};

template <int N> struct is_prime {
  static constexpr bool value = is_prime_helper<N, N / 2 + 1>::value;
};

template <int N, bool Prime> struct print_if_prime {
  static void print() {
    print_if_prime<N - 1, is_prime<N>::value>::print();
    if (Prime)
      std::cout << N << " ";
  }
};

template <int N> struct print_if_prime<N, true> {
  static void print() {
    print_if_prime<N - 1, is_prime<N>::value>::print();
    std::cout << N << " ";
  }
};

template <bool Prime> struct print_if_prime<1, Prime> {
  static void print() {}
};
