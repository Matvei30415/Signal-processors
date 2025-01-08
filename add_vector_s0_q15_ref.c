#include "dsp_lecture.h"
void add_vector_s0_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2)
{
    for (int i = 0; i < n; i++)
    {
        int sum = src1[i] + src2[i];

        if (sum > 32767)
        {
            dst[i] = 32767;
        }
        else if (sum < -32768)
        {
            dst[i] = -32768;
        }
        else
        {
            dst[i] = sum;
        }
    }
}