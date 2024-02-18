# prime-nums-test

### IMPORTANT NOTE

**The SIMD solution (-se) doesn't actually work.**

### Setting up

Minimal compiling options (for g++ -> -ftemplate-depth=PRIME_UPPER_LIMIT+1):

```
g++ src/main.cpp -o bin/test -march=native -Ofast -mavx -ftemplate-depth=1001
```

Running variations:
- 
- 
- 
- 

### Additional details

This project was just made as a test related to [this YouTube video](https://www.youtube.com/watch?v=8-VZoXn8f9U)

The **constexpr** data type is really interesting and I never used it before.
Basically its used for evaluations on compile time, saving runtime resources for specific predefined data.
This is useful but I do wonder which exact use cases are the best for it...
Aggressive GCC optimize flags tend to do the job just fine and usually you'd be looking at data caching evaluations for the flexibility of your app.
