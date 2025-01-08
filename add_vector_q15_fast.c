#include "dsp_lecture.h"
void add_vector_q15_fast(int n, int16_t* dst, int16_t* src1, int16_t* src2) {
    int vect_8_N_div = n - (n % 8);
    __m128i buf1, buf2, sumbuf;

    for (int vect_8_index = 0; vect_8_index < vect_8_N_div; vect_8_index += 8) {
        buf1 = _mm_loadu_si128((__m128i*)&src1[vect_8_index]);
        buf2 = _mm_loadu_si128((__m128i*)&src2[vect_8_index]);
        sumbuf = _mm_add_epi16(buf1, buf2);
        _mm_storeu_si128((__m128i*)&dst[vect_8_index], sumbuf);
    }

    for (int i = vect_8_N_div; i < n; i++) {
        dst[i] = src1[i] + src2[i];
    }
}