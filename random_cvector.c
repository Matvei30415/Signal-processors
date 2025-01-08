#include "dsp_lecture.h"

void random_cvector(int n, cint16_t *vec)
{
    for (int i = 0; i < n; i++)
    {
        vec[i].real = rand();
        vec[i].imag = rand();
    }
}