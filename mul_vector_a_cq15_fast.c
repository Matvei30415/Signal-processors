#include "dsp_lecture.h"

void mul_vector_a_cq15_fast(int n, cint32_t *dst, cint16_t *src1, cint16_t *src2)
{
    int vect_8_N_div = n - (n % 8);  // индекс до последнего элемента, кратного 8

    __m128i buf1_real, buf1_imag, buf2_real, buf2_imag;
    __m128i mul_real_lo, mul_imag_lo, mul_real_hi, mul_imag_hi;
    __m128i mul_real_imag_lo, mul_real_imag_hi, mul_imag_real_lo, mul_imag_real_hi;

    for (int vect_8_index = 0; vect_8_index < vect_8_N_div; vect_8_index += 8)
    {
        buf1_real = _mm_loadu_si128((__m128i *)&src1[vect_8_index].real);
        buf1_imag = _mm_loadu_si128((__m128i *)&src1[vect_8_index].imag);
        buf2_real = _mm_loadu_si128((__m128i *)&src2[vect_8_index].real);
        buf2_imag = _mm_loadu_si128((__m128i *)&src2[vect_8_index].imag);

        // Реальная часть: (real1 * real2 - imag1 * imag2)
        mul_real_lo = _mm_mullo_epi16(buf1_real, buf2_real);
        mul_real_hi = _mm_mulhi_epi16(buf1_real, buf2_real);

        __m128i mul_real_res_lo = _mm_unpacklo_epi16(mul_real_lo, mul_real_hi);
        __m128i mul_real_res_hi = _mm_unpackhi_epi16(mul_real_lo, mul_real_hi);

        mul_imag_lo = _mm_mullo_epi16(buf1_imag, buf2_imag);
        mul_imag_hi = _mm_mulhi_epi16(buf1_imag, buf2_imag);

        __m128i mul_imag_res_lo = _mm_unpacklo_epi16(mul_imag_lo, mul_imag_hi);
        __m128i mul_imag_res_hi = _mm_unpackhi_epi16(mul_imag_lo, mul_imag_hi);

        __m128i real_part_lo = _mm_sub_epi32(mul_real_res_lo, mul_imag_res_lo);
        __m128i real_part_hi = _mm_sub_epi32(mul_real_res_hi, mul_imag_res_hi); 

        // Мнимая часть: (real1 * imag2 + imag1 * real2)
        mul_real_imag_lo = _mm_mullo_epi16(buf1_real, buf2_imag);
        mul_real_imag_hi = _mm_mulhi_epi16(buf1_real, buf2_imag);

        __m128i mul_real_imag_res_lo = _mm_unpacklo_epi16(mul_real_imag_lo, mul_real_imag_hi);
        __m128i mul_real_imag_res_hi = _mm_unpackhi_epi16(mul_real_imag_lo, mul_real_imag_hi);

        mul_imag_real_lo = _mm_mullo_epi16(buf1_imag, buf2_real);
        mul_imag_real_hi = _mm_mulhi_epi16(buf1_imag, buf2_real);

        __m128i mul_imag_real_res_lo = _mm_unpacklo_epi16(mul_imag_real_lo, mul_imag_real_hi);
        __m128i mul_imag_real_res_hi = _mm_unpackhi_epi16(mul_imag_real_lo, mul_imag_real_hi);

        __m128i imag_part_lo = _mm_add_epi32(mul_real_imag_res_lo, mul_imag_real_res_lo);
        __m128i imag_part_hi = _mm_add_epi32(mul_real_imag_res_hi, mul_imag_real_res_hi);

        _mm_storeu_si128((__m128i *)&dst[vect_8_index].real, real_part_lo);
        _mm_storeu_si128((__m128i *)&dst[vect_8_index].imag, imag_part_lo);
        _mm_storeu_si128((__m128i *)&dst[vect_8_index + 2].real, real_part_hi);
        _mm_storeu_si128((__m128i *)&dst[vect_8_index + 2].imag, imag_part_hi);
    }

    // Остаточные элементы
    for (int i = vect_8_N_div; i < n; i++)
    {
        int32_t real_part = (int32_t)src1[i].real * src2[i].real - (int32_t)src1[i].imag * src2[i].imag;
        int32_t imag_part = (int32_t)src1[i].real * src2[i].imag + (int32_t)src1[i].imag * src2[i].real;

        dst[i].real = real_part;
        dst[i].imag = imag_part;
    }
}
