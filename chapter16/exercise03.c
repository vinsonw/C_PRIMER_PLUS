#include <stdio.h>
#include <math.h>
#include "ex01.h"

struct vector_r *p_to_r(struct vector_p *pp, struct vector_r *pr);

int main(void)
{
    struct vector_p vectors_p[3] = {
        {1, 30},
        {1, 60},
        {1, 90},
    };

    struct vector_r  vectors_r[3];



    for (int i=0; i<3; i++)
    {
        p_to_r(&vectors_p[i], &vectors_r[i]);
        printf("(%.2lf, %.2lf) => (%.2lf, %.2lf)\n",
        vectors_p[i].magnitude, vectors_p[i].angle,
        vectors_r[i].x, vectors_r[i].y
        );
    }
}

struct vector_r *p_to_r(struct vector_p *pp, struct vector_r *pr)
{
    pr->x = pp->magnitude * cos(pp->angle / 180 * 3.141592653);
    pr->y = pp->magnitude * sin(pp->angle / 180 * 3.141592653);
    return pr;
}