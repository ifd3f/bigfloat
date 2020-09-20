//
// Created by astrid on 9/19/20.
//

#ifndef BIGFLOAT_BENCH_SIMD_H
#define BIGFLOAT_BENCH_SIMD_H


#include <benchmark/benchmark.h>
#include "shared.hpp"
#include "../simd_vec4.hpp"

using namespace bigfloat::simd;

static void bigfloatx4_multiplication(benchmark::State &state) {
    simd_vec4 vec(bf(91234), bf(83.3123789), bf(1728781.1237), bf(134289));
    for (auto _ : state) {
        vec *= vec;
    }
}

#endif //BIGFLOAT_BENCH_SIMD_H