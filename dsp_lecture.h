#ifndef DSP_LECTURE_H
#define DSP_LECTURE_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <emmintrin.h>
#include <smmintrin.h>

#define N_MAX 20000000

typedef struct
{
    int16_t real;
    int16_t imag;
} cint16_t;

typedef struct
{
    int32_t real;
    int32_t imag;
} cint32_t;

void add_vector_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_q15_tb(int16_t seed, int num_runs);

void add_vector_s0_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_s0_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_s0_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_s0_q15_tb(int16_t seed, int num_runs);

void mul_vector_s0_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s0_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s0_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s0_q15_tb(int16_t seed, int num_runs);

void add_vector_s1_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_s1_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_s1_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void add_vector_s1_q15_tb(int16_t seed, int num_runs);

void mul_vector_s15_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s15_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s15_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s15_q15_tb(int16_t seed, int num_runs);

void mul_vector_a_q15(int n, int32_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_a_q15_ref(int n, int32_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_a_q15_fast(int n, int32_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_a_q15_tb(int16_t seed, int num_runs);

void mul_vector_a_cq15(int n, cint32_t *dst, cint16_t *src1, cint16_t *src2);
void mul_vector_a_cq15_ref(int n, cint32_t *dst, cint16_t *src1, cint16_t *src2);
void mul_vector_a_cq15_fast(int n, cint32_t *dst, cint16_t *src1, cint16_t *src2);
void mul_vector_a_cq15_tb(int16_t seed, int num_runs);

void random_vector(int n, int16_t *v);
void random_cvector(int n, cint16_t *v);
#endif