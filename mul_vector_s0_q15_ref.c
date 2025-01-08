#include "dsp_lecture.h"

void mul_vector_s0_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2)
{
    for (int i = 0; i < n; i++)
    {
        int32_t result = (int32_t)src1[i] * (int32_t)src2[i];

        int16_t lower_16_bits = (int16_t)(result & 0xFFFF);

        if (lower_16_bits > 32767)
        {
            dst[i] = 32767;
        }
        else if (lower_16_bits < -32768)
        {
            dst[i] = -32768;
        }
        else
        {
            dst[i] = lower_16_bits;
        }
    }
}
