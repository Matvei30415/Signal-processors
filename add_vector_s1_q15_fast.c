#include "dsp_lecture.h"

void add_vector_s1_q15_fast(int n, int16_t* dst, int16_t* src1, int16_t* src2) {
    int vect_8_N_div = n - (n % 8);
    __m128i buf1, buf2, sumbuf;

    for (int vect_8_index = 0; vect_8_index < vect_8_N_div; vect_8_index += 8) {
        buf1 = _mm_loadu_si128((__m128i*)&src1[vect_8_index]);
        buf2 = _mm_loadu_si128((__m128i*)&src2[vect_8_index]);
        sumbuf = _mm_adds_epi16(buf1, buf2);

        sumbuf = _mm_srli_epi16(sumbuf, 1);

        _mm_storeu_si128((__m128i*)&dst[vect_8_index], sumbuf);
    }

    for (int i = 0; i < n; i++) {
        int sum = src1[i] + src2[i];

        if (sum > 32767) {
            sum = 32767;
            sum >>= 1;
            dst[i] = sum;
        } else if (sum < -32768) {
            sum = -32768;
            sum >>= 1;
            dst[i] = sum;
        } else {
            sum >>= 1;
            dst[i] = sum;
        }
    }
}