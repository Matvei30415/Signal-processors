#include "dsp_lecture.h"

void add_vector_s0_q15_fast(int n, int16_t* dst, int16_t* src1, int16_t* src2) {
    int vect_8_N_div = n - (n % 8);
    __m128i buf1, buf2, sumbuf;
    __m128i saturate_max = _mm_set1_epi16(32767);
    __m128i saturate_min = _mm_set1_epi16(-32768);

    for (int vect_8_index = 0; vect_8_index < vect_8_N_div; vect_8_index += 8) {

        buf1 = _mm_loadu_si128((__m128i*)&src1[vect_8_index]);
        buf2 = _mm_loadu_si128((__m128i*)&src2[vect_8_index]);
        sumbuf = _mm_adds_epi16(buf1, buf2);
        _mm_storeu_si128((__m128i*)&dst[vect_8_index], sumbuf);
    }

    for (int i = vect_8_N_div; i < n; i++) {
        int sum = src1[i] + src2[i];

        if (sum > 32767) {
            dst[i] = 32767;
        } else if (sum < -32768) {
            dst[i] = -32768;
        } else {
            dst[i] = sum;
        }
    }
}
