#ifndef _EX01_H

#define HARMONIC_MEAN(X,Y) \
(2./((1./(X)) + (1./(Y))))

struct vector_p {
    double magnitude;
    double angle;
};

struct vector_r {
    double x;
    double y;
};

#endif