#ifndef S21_MATH
#define S21_MATH

#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NAN 0.0 / 0.0
#define S21_INF_POS 1.0 / 0.0L
#define S21_INF_NEG -1.0 / 0.0L
#define S21_PI 3.141592653589793238462643383279502884
#define S21_PI2 1.570796326794896619231321691639751442
#define S21_E 2.718281828459045235360287471352662498

int s21_abs(int x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_sqrt(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_factorial(long long int x);
long double s21_pow(double base, double exp);
long double pow_integer(double base, long long int exp);

#endif