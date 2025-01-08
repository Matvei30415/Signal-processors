#include "dsp_lecture.h"

void mul_vector_s15_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2)
{
    int vect_8_N_div = n - (n % 8);
    __m128i buf1, buf2, mulbuf;

    for (int vect_8_index = 0; vect_8_index < vect_8_N_div; vect_8_index += 8)
    {

        buf1 = _mm_loadu_si128((__m128i *)&src1[vect_8_index]);
        buf2 = _mm_loadu_si128((__m128i *)&src2[vect_8_index]);

        mulbuf = _mm_mulhi_epi16(buf1, buf2);

        _mm_storeu_si128((__m128i *)&dst[vect_8_index], mulbuf);
    }

    for (int i = 0; i < n; i++)
    {
        int32_t result = (int32_t)src1[i] * (int32_t)src2[i];

        int16_t higher_16_bits = (int16_t)(result >> 16);

        if (higher_16_bits > 32767)
        {
            dst[i] = 32767;
        }
        else if (higher_16_bits < -32768)
        {
            dst[i] = -32768;
        }
        else
        {
            dst[i] = higher_16_bits;
        }
    }
}
