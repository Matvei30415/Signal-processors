#include "dsp_lecture.h"

void mul_vector_a_cq15_ref(int n, cint32_t *dst, cint16_t *src1, cint16_t *src2)
{
    for (int i = 0; i < n; i++)
    {
        int32_t real_part = (int32_t)src1[i].real * src2[i].real - (int32_t)src1[i].imag * src2[i].imag;
        int32_t imag_part = (int32_t)src1[i].real * src2[i].imag + (int32_t)src1[i].imag * src2[i].real;

        dst[i].real = real_part;
        dst[i].imag = imag_part;
    }
}