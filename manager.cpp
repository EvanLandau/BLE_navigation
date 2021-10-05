#include "laterate.cpp"
//#include "bluetooth_manage.cpp"

#include <iostream>

float fastInvSqrt(float x) 
{
    //Fast inverse square root (see https://en.wikipedia.org/wiki/Fast_inverse_square_root#Aliasing_to_an_integer_as_an_approximate_logarithm)
    unsigned long i;
    float x2, y;
    const float threehalfs = 1.5F;
    x2 = x * 0.5F;
    y = x;
    i = * ( unsigned long * ) &y;
    i = 0x5F1FFFF9ul - (i >> 1); //See "Subsequent improvements", ibid.
    y = * ( float * ) &i;
    y *= 0.703952253f * (2.38924456f - x * y * y);
    return y;
}

float calcRadius(float s, float k) 
{
    return k * fastInvSqrt(s);
}

void getRadii(float *s1, float *s2, float *s3, float *r1, float *r2, float *r3, float k1, float k2, float k3) 
{
    r1* = calcRadius(s1*, k1);
    r2* = calcRadius(s2*, k2);
    r3* = calcRadius(s3*, k3);
}