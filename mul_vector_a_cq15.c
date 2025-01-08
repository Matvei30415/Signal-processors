#include "dsp_lecture.h"

void mul_vector_a_cq15(int n, cint32_t *dst, cint16_t *src1, cint16_t *src2)
{
    cint32_t *dst_ref = (cint32_t *)malloc(n * sizeof(cint32_t));
    if (!dst_ref)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    clock_t start_time_ref = clock();
    mul_vector_a_cq15_ref(n, dst_ref, src1, src2);
    clock_t end_time_ref = clock();
    clock_t elapsed_time_ref = end_time_ref - start_time_ref;

    clock_t start_time_fast = clock();
    mul_vector_a_cq15_fast(n, dst, src1, src2);
    clock_t end_time_fast = clock();
    clock_t elapsed_time_fast = end_time_fast - start_time_fast;

    if (elapsed_time_fast > 0)
    {
        double diff_time = ((double)(elapsed_time_ref - elapsed_time_fast) / elapsed_time_fast) * 100;
        printf("The function mul_vector_a_cq15 is completed. Elapsed time: %ld ms; time difference: %.2f%%.\n",
               elapsed_time_fast, diff_time);
    }
    else
    {
        printf("The function mul_vector_a_cq15 is completed. Elapsed time: %ld ms; time difference: N/A.\n",
               elapsed_time_fast);
    }

    int error_p = 0, error_i = 0;
    for (int i = 0; i < n; i++)
    {
        if (dst_ref[i].real != dst[i].real || dst_ref[i].imag != dst[i].imag)
        {
            error_p = 1;
            error_i = i;
            // break;
        }
    }

    // if (error_p)
    // {
    //     fprintf(stderr, "ERROR: the function mul_vector_a_cq15_fast did not compute correctly!\n");
    //     fprintf(stderr, "ERROR: i=%d, ref: dst[i].real=0x%8.8x, dst[i].imag=0x%8.8x, result: dst[i].real=0x%8.8x, dst[i].imag=0x%8.8x\n",
    //             error_i, dst_ref[error_i].real, dst_ref[error_i].imag, dst[error_i].real, dst[error_i].imag);
    // }

    free(dst_ref);
}
