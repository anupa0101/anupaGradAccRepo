/**
 * Demo for using Benchmarking using Google's benchmark platform:
 * Run:
         bazel run src/benchmark/main_benchmark -c opt -- --benchmark_format=csv | \
         tee src/benchmark/outputs/main_benchmark.csv
         python3 src/benchmark/plot.py src/benchmark/outputs/main_benchmark.csv
 */


// JUST USE bazel run src/benchmark/main_benchmark -c opt   THIS IS ENOUGH

//THIS GIVES INFORMATION OF THE SYSTEM AS WELL LIKE CPU CORES AND THE CPU CACHE INFORMATION
// Run on (4 X 2712 MHz CPU s)
// CPU Caches:
//   L1 Data 32 KiB (x2)
//   L1 Instruction 32 KiB (x2)
//   L2 Unified 256 KiB (x2)
//   L3 Unified 3072 KiB (x1)

//LOOK AT THE CPU TIME.

#include "benchmark/benchmark.h" //FOR BENCHMARKING

#include <string>

void SomeFunction(size_t size) { //FUNCTION TO BE BENCHMARKED
  std::string s1(size, '-');
  std::string s2(size, '-');
  benchmark::DoNotOptimize(s1.compare(s2));  // this prevents optimization
}

static void BM_SomeFunction(benchmark::State& state) {  //WRAPPER FOR BENCHMARKING- REMEMBER SYNTAX static void BM_SomeFucntion(benchmark::State& state)
  // Perform setup here
  for (auto _ : state) {      //THE FUNCTION WILL BE EXECUTED AS MANY TIMES AS NECESSARY UNTILL A STABLE VALUE IS OBTAINED FOR RUNTIME
    // This code gets timed         auto _ is a variable called _ , but not used in the loop
    SomeFunction(state.range(0)); //(bad naming) STATE.RANGE(0) IS THE first parameter IN THE ->Arg(param1  ). instead we can just add SomeFunction(10000);// will ouput just for 10000. also when registering use BENCHMARK(BM_StringComparison) without ->Arg
// if theres multiple input parameters SomeFunction(state.range(0),state.range(1)); // BENCHMARK(BM_SomeFunction)->Args({100000,299})->Args({1000,29900})->Args({10090,29999}); // use s not Arg here.
  }
}

//##############################################################

// Register the function as a benchmark
// BENCHMARK(BM_SomeFunction)->Arg(100000)->Arg(200000)->Arg(400000); // GIVING MULTIPLE INPUT VALUES. THIS APPROACH IS ALSO GOD

BENCHMARK(BM_SomeFunction)->RangeMultiplier(2)->Range(1 << 10, 1 << 20)->Complexity();// REGISTER THE WRAPPER AS A BENCHMARK. here sweep the first argument from 2 to the power 10 to 2 to the power 20.

//BENCHMARK(BM_SomeFunction)->RangeMultiplier(2)-Ranges({{1<<8,1<<10},{1,5}})// when theres multiple input values use ranges, first argument from 2 to the power 10 to 2 to the power 20. and second from 1 to 5 multiplied by 2.


//##########################################################
// Run the benchmark
BENCHMARK_MAIN();// REPLACES THE MAIN FUNCTION- no  need main function