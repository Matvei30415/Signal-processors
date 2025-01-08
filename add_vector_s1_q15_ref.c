#include "dsp_lecture.h"

void add_vector_s1_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2)
{
    for (int i = 0; i < n; i++)
    {
        int sum = src1[i] + src2[i];

        if (sum > 32767)
        {
            sum = 32767;
            sum >>= 1;
            dst[i] = sum;
        }
        else if (sum < -32768)
        {
            sum = -32768;
            sum >>= 1;
            dst[i] = sum;
        }
        else
        {
            sum >>= 1;
            dst[i] = sum;
        }
    }
}
