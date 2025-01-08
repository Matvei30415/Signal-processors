#include "dsp_lecture.h"
void add_vector_q15_ref(int n, int16_t * dst, int16_t * src1, int16_t * src2)
{
for (int i = 0; i != n; ++i) {
dst[i] = src1[i] + src2[i];
}
}