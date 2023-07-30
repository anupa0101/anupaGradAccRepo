/**
RUNNNING WITH OPTIMIZER FLAGS

// JUST USE bazel run src/benchmark/main_benchmark_adder -c opt    HERE  -c -opt wll cause =O2 optimizer flags to be added in bazel
// to be specific use -c -opt -copt=O3     to specify the optimizer flag
//times may become zero because of optimization- may be done in compile time. to confirm use a combination of assembly code viewing
 */
#include "benchmark/benchmark.h"

#include <iostream>
#include <string>
// benchmark::DoNotOptimize(sum++);// DESPITE THE OPTIMZER FLAGS- THIS WILL PREVENT OPTIMIZATION- forces the rresult to be stored in registerr or memory
// benchmark::ClobberMemory();// forces compiler to perform all pending writes to global memory- prevents goin to cache


/**
 * Increments n times and returns the value
 */
unsigned long Increment(unsigned long n) {
  unsigned long sum = 0;
  for (unsigned long i = 0; i < n; i++) {
    benchmark::DoNotOptimize(sum++);// prevents optimization or else will do it in compiletime
    benchmark::ClobberMemory();// forces to global main memory
  }
  return sum;
}
/**
 * A Benchmark for Increment
 */
static void BM_Increment(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    Increment(state.range(0));
  }
}

// Register the function as a benchmark
BENCHMARK(BM_Increment)->RangeMultiplier(2)->Range(1 << 8, 1 << 10);

// Run the benchmark
BENCHMARK_MAIN();

//#################PAUSE TIMING

/**
 * Adds value n times and returns the result
 */
unsigned long AddByValue(unsigned long n, unsigned long value) {
      state.PauseTiming();
      unsigned long sum = 0; // TIME TAKEN FOR THIS WILL NOT BE COUNTED-
    state.ResumeTiming();

  for (unsigned long i = 0; i < n; i++) {
    sum += value; // can add benchmark::DoNotOptimize(sum+=value); to prevent optimization here- or else might give zero if done in compile tiime
  }    // can add benchmark::ClobberMemory(); to force to use global memory
  return sum;
}

/**
 * A Benchmark for AddByValue
 */
static void BM_AddByValue(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    AddByValue(state.range(0), state.range(1));
  }
}

// Register the function as a benchmark
BENCHMARK(BM_Increment)->Args({100,200})->Args({300,500});

// Run the benchmark
BENCHMARK_MAIN();
