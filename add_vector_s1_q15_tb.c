#include "dsp_lecture.h"
void add_vector_s1_q15_tb(int16_t seed, int num_runs)
{
int i, n;
int16_t* dst = NULL;
int16_t* src1 = NULL;
int16_t* src2 = NULL;
srand(seed);
for (i = 0; i < num_runs; i++) {
n = ((long long)rand() * RAND_MAX + rand()) % N_MAX;
dst = (int16_t*)realloc(dst, n * sizeof(int16_t));
src1 = (int16_t*)realloc(src1, n * sizeof(int16_t));
src2 = (int16_t*)realloc(src2, n * sizeof(int16_t));
random_vector(n, src1);
random_vector(n, src2);
add_vector_s1_q15(n, dst, src1, src2);
}
printf("The function add_vector_s1_q15_tb is completed.\n");
free(dst);
free(src1);
free(src2);
}