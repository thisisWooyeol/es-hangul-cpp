#include "josa/josa.hpp"
#include <benchmark/benchmark.h>

static void BENCHMARK_josaPicker(benchmark::State& state)
{
    for (auto _ : state) {
        EsHangul::Josa::josaPicker(L"단어", EsHangul::Josa::JosaOption::이_가);
    }
}

BENCHMARK(BENCHMARK_josaPicker);
BENCHMARK_MAIN();