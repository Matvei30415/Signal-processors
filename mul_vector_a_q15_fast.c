#include "dsp_lecture.h"

void mul_vector_a_q15_fast(int n, int32_t *dst, int16_t *src1, int16_t *src2)
{
    int vect_8_N_div = n - (n % 8);
    __m128i buf1, buf2, mullo, mulhi;

    for (int vect_8_index = 0; vect_8_index < vect_8_N_div; vect_8_index += 8)
    {
        buf1 = _mm_loadu_si128((__m128i *)&src1[vect_8_index]);
        buf2 = _mm_loadu_si128((__m128i *)&src2[vect_8_index]);

        mullo = _mm_mullo_epi16(buf1, buf2);
        mulhi = _mm_mulhi_epi16(buf1, buf2);

        __m128i result_lo = _mm_unpacklo_epi16(mullo, mulhi);
        __m128i result_hi = _mm_unpackhi_epi16(mullo, mulhi);

        _mm_storeu_si128((__m128i *)&dst[vect_8_index], result_lo);
        _mm_storeu_si128((__m128i *)&dst[vect_8_index + 4], result_hi);
    }

    for (int i = vect_8_N_div; i < n; i++)
    {
        int32_t result = (int32_t)src1[i] * (int32_t)src2[i];
        dst[i] = result;
    }
}