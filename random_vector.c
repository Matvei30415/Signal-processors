#include "dsp_lecture.h"

void random_vector(int n, int16_t *v)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = rand();
    }
}