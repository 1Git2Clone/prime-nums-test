# prime-nums-test

### IMPORTANT NOTE

**The SIMD solution (-se) doesn't actually work.**

### Setting up

Minimal compiling options (for g++ on the **ROOT** directory of the **REPOSITORY**):
- -ftemplate-depth=PRIME_UPPER_LIMIT+1 -> this needs to be the minimum value.

```
g++ src/main.cpp -o bin/test -march=native -mavx -ftemplate-depth=1001 -Ofast
```

The **-Ofast** flag for g++ is optional.

```
g++ src/main.cpp -o bin/test -march=native -mavx -ftemplate-depth=1001
```


No **-Ofast** variant.


Running variations:
- **-eval** (-e) flag runs the barebones unoptimized solution.
- **-sieve-of-eratosthenes** (-soe) flag runs a more optimized version using modulo math. ([wikipedia.org](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes))
- **-simd-eval** (-se) flag runs the same -soe flag but with AVX2 (**NOT WORKING FOR NOW!**).
- **-constexpr-eval** (-ce) flag is the reason why your compile times are slow. It runs on compile time instead of runtime. On runtime it just gets printed.

### Additional details

This project was just made as a test related to [this YouTube video](https://www.youtube.com/watch?v=8-VZoXn8f9U)

The **constexpr** data type is really interesting and I never used it before.
Basically its used for evaluations on compile time, saving runtime resources for specific predefined data.
This is useful but I do wonder which exact use cases are the best for it...
Aggressive GCC optimize flags tend to do the job just fine and usually you'd be looking at data caching evaluations for the flexibility of your app.
