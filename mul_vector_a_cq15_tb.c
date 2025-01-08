#include "dsp_lecture.h"

void mul_vector_a_cq15_tb(int16_t seed, int num_runs)
{
    int i, n;
    cint32_t *dst = NULL;
    cint16_t *src1 = NULL;
    cint16_t *src2 = NULL;
    srand(seed);
    for (i = 0; i < num_runs; i++)
    {
        n = N_MAX;
        dst = (cint32_t *)realloc(dst, n * sizeof(cint32_t));
        src1 = (cint16_t *)realloc(src1, n * sizeof(cint16_t));
        src2 = (cint16_t *)realloc(src2, n * sizeof(cint16_t));
        random_cvector(n, src1);
        random_cvector(n, src2);
        mul_vector_a_cq15(n, dst, src1, src2);
    }
    printf("The function mul_vector_a_cq15_tb is completed.\n");
    free(dst);
    free(src1);
    free(src2);
}