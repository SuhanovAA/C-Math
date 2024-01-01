#include <check.h>
#include <math.h>

#include "./s21_math.h"

// ABS TEST
START_TEST(s21_test_abs_check_1) { ck_assert_int_eq(s21_abs(-5), abs(-5)); }
END_TEST

START_TEST(s21_test_abs_check_2) { ck_assert_int_eq(s21_abs(5), abs(5)); }
END_TEST

START_TEST(s21_test_abs_check_3) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

// ACOS TEST
START_TEST(s21_test_acos_check_1) {
  double val1 = 1;
  double val2 = -1;
  double val3 = 0;
  double val4 = -0.554578;
  double val5 = 0.455635442;
  ck_assert_ldouble_eq_tol(s21_acos(val1), acos(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(val2), acos(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(val3), acos(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(val4), acos(val4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(val5), acos(val5), 1e-6);
}
END_TEST

START_TEST(s21_test_acos_check_2) {
  for (double i = -1; i <= 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_acos(i), acos(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_acos_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  double val4 = 4.5487;
  double val5 = -1.00005;
  ck_assert_double_nan(s21_acos(val1));
  ck_assert_double_nan(s21_acos(val2));
  ck_assert_double_nan(s21_acos(val3));
  ck_assert_double_nan(s21_acos(val4));
  ck_assert_double_nan(s21_acos(val5));
}
END_TEST

// ASIN TEST
START_TEST(s21_test_asin_check_1) {
  double val1 = 1;
  double val2 = 1;
  double val3 = 0;
  double val4 = -0.554578;
  double val5 = 0.455635442;
  ck_assert_ldouble_eq_tol(s21_asin(val1), asin(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(val2), asin(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(val3), asin(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(val4), asin(val4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(val5), asin(val5), 1e-6);
}
END_TEST

START_TEST(s21_test_asin_check_2) {
  for (double i = -1; i <= 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_asin_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  double val4 = 4.5487;
  double val5 = -1.00005;
  ck_assert_double_nan(s21_asin(val1));
  ck_assert_double_nan(s21_asin(val2));
  ck_assert_double_nan(s21_asin(val3));
  ck_assert_double_nan(s21_asin(val4));
  ck_assert_double_nan(s21_asin(val5));
}
END_TEST

// ATAN TEST
START_TEST(s21_test_atan_check_1) {
  double val1 = 1;
  double val2 = -1;
  double val3 = 0;
  double val4 = 2587.548675;
  double val5 = -24.548544;
  double val6 = INFINITY;
  double val7 = -INFINITY;

  ck_assert_ldouble_eq_tol(s21_atan(val1), atan(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(val2), atan(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(val3), atan(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(val4), atan(val4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(val5), atan(val5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(val6), atan(val6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(val7), atan(val7), 1e-6);
}
END_TEST

START_TEST(s21_test_atan_check_2) {
  for (double i = -1.05; i <= 1.05; i += 0.02) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 1e-6);
  }
}
END_TEST

// CEIL TEST
START_TEST(s21_test_ceil_check_1) {
  double val1 = -5.495414;
  double val2 = 4.957778;
  ck_assert_ldouble_eq_tol(s21_ceil(val1), ceil(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(val2), ceil(val2), 1e-6);
}
END_TEST

START_TEST(s21_test_ceil_check_2) {
  for (double i = -1.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_ceil(i), ceil(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_ceil_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  ck_assert_double_infinite(s21_ceil(val1));
  ck_assert_double_infinite(s21_ceil(val2));
  ck_assert_double_nan(s21_ceil(val3));
}
END_TEST

// COS TEST
START_TEST(s21_test_cos_check_1) {
  double val1 = 5.5487964;
  double val2 = 0;
  double val3 = 4e-10;
  double val4 = 1e10;
  ck_assert_ldouble_eq_tol(s21_cos(val1), cos(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(val2), cos(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(val3), cos(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(val4), cos(val4), 1e-6);
}
END_TEST

START_TEST(s21_test_cos_check_2) {
  for (double i = -S21_PI * 5; i <= S21_PI * 5; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_cos_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  ck_assert_double_nan(s21_cos(val1));
  ck_assert_double_nan(s21_cos(val2));
  ck_assert_double_nan(s21_cos(val3));
}
END_TEST

// EXP TEST
START_TEST(s21_test_exp_check_1) {
  double val1 = 22;
  double val2 = 0;
  double val3 = -1;
  double val4 = -14;
  ck_assert_ldouble_eq_tol(s21_exp(val1), expl(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(val2), expl(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(val3), expl(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(val4), expl(val4), 1e-6);
}
END_TEST

START_TEST(s21_test_exp_check_2) {
  for (double i = -2; i < 2; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_exp_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  double val4 = 1e5;
  ck_assert_ldouble_eq_tol(s21_exp(val1), expl(val1), 1e-6);
  ck_assert_double_infinite(s21_exp(val2));
  ck_assert_double_nan(s21_exp(val3));
  ck_assert_double_infinite(s21_exp(val4));
}
END_TEST

// FABS TEST
START_TEST(s21_test_fabs_check_1) {
  ck_assert_ldouble_eq_tol(s21_fabs(-5.4548454), fabs(-5.4548454), 1e-6);
}
END_TEST

START_TEST(s21_test_fabs_check_2) {
  ck_assert_ldouble_eq_tol(s21_fabs(5.4548454), fabs(5.4548454), 1e-6);
}
END_TEST

START_TEST(s21_test_fabs_check_3) {
  ck_assert_ldouble_eq_tol(s21_fabs(0.), fabs(0.), 1e-6);
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_infinite(s21_fabs(S21_INF_NEG));
  ck_assert_ldouble_infinite(s21_fabs(S21_INF_POS));
}
END_TEST

// FLOOR TEST
START_TEST(s21_test_floor_check_1) {
  double val1 = -5.495414;
  double val2 = 1658475895565.325486;
  ck_assert_ldouble_eq_tol(s21_floor(val1), floor(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(val2), floor(val2), 1e-6);
}
END_TEST

START_TEST(s21_test_floor_check_2) {
  for (double i = -1.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_floor_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  ck_assert_double_infinite(s21_floor(val1));
  ck_assert_double_infinite(s21_floor(val2));
  ck_assert_double_nan(s21_floor(val3));
}
END_TEST

// FMOD TEST
START_TEST(s21_test_fmod_check_1) {
  double val1X = 1e13;
  double val1Y = 4.0;
  double val2X = 4.957778;
  double val2Y = 1.957778;
  double val3X = -4.957778;
  double val3Y = 1.957778;
  double val4X = -4.957778;
  double val4Y = -1.957778;
  double val5X = -1.547565e10;
  double val5Y = -1.45564554545454545454;
  ck_assert_ldouble_eq_tol(s21_fmod(val1X, val1Y), fmod(val1X, val1Y), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(val2X, val2Y), fmod(val2X, val2Y), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(val3X, val3Y), fmod(val3X, val3Y), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(val4X, val4Y), fmod(val4X, val4Y), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(val5X, val5Y), fmod(val5X, val5Y), 1e-6);
}
END_TEST

START_TEST(s21_test_fmod_check_2) {
  double val1X = 50.0;
  double val1Y = 0.0;
  double val2X = S21_INF_POS;
  double val2Y = 7.65;
  double val3X = S21_INF_NEG;
  double val3Y = 5.444;
  double val4X = S21_NAN;
  double val4Y = 5.01;
  ck_assert_double_nan(s21_fmod(val1X, val1Y));
  ck_assert_double_infinite(s21_fmod(val2X, val2Y));
  ck_assert_double_infinite(s21_fmod(val3X, val3Y));
  ck_assert_double_nan(s21_fmod(val4X, val4Y));
}
END_TEST

// LOG TEST
START_TEST(s21_test_log_check_1) {
  double val1 = 6.454;
  double val2 = 400000000000000000;
  double val3 = 0.5;
  double val4 = S21_E;
  ck_assert_ldouble_eq_tol(s21_log(val1), logl(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(val2), logl(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(val3), logl(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(val4), logl(val4), 1e-6);
}
END_TEST

START_TEST(s21_test_log_check_2) {
  for (double i = 0.1; i <= 50; i += 1) {
    ck_assert_ldouble_eq_tol(s21_log(i), logl(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_log_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  double val4 = 0;
  double val5 = -1;
  double val6 = 2e-5;
  ck_assert_double_nan(s21_log(val1));
  ck_assert_double_infinite(s21_log(val2));
  ck_assert_double_nan(s21_log(val3));
  ck_assert_double_infinite(s21_log(val4));
  ck_assert_double_nan(s21_log(val5));
  ck_assert_ldouble_eq_tol(s21_log(val6), logl(val6), 1e-6);
}
END_TEST

// POW TEST
START_TEST(s21_test_pow_check_1) {
  double base1 = 20.1;
  double exp1 = 4;
  double base2 = 4.95478;
  double exp2 = 0.957548;
  double base3 = 20154.957488;
  double exp3 = 1.950378;
  double base4 = 4.95778;
  double exp4 = -10.958;
  double base5 = -0.54;
  double exp5 = 15;
  double base6 = 2;
  double exp6 = -0.211111;
  double base7 = 15;
  double exp7 = 4.25;
  ck_assert_ldouble_eq_tol(s21_pow(base1, exp1), pow(base1, exp1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base2, exp2), pow(base2, exp2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base3, exp3), pow(base3, exp3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base4, exp4), pow(base4, exp4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base5, exp5), pow(base5, exp5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base6, exp6), pow(base6, exp6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base7, exp7), pow(base7, exp7), 1e-6);
}
END_TEST

START_TEST(s21_test_pow_check_2) {
  double base1 = -50.0;
  double exp1 = 5.1;
  double base2 = S21_INF_POS;
  double exp2 = S21_INF_POS;
  double base3 = S21_INF_NEG;
  double exp3 = S21_INF_NEG;
  double base4 = S21_NAN;
  double exp4 = S21_NAN;

  ck_assert_double_nan(s21_pow(base1, exp1));
  ck_assert_ldouble_eq(s21_pow(base2, exp2), pow(base2, exp2));
  ck_assert_ldouble_eq(s21_pow(base3, exp3), pow(base3, exp3));
  ck_assert_ldouble_eq(s21_pow(base3, exp2), pow(base3, exp2));
  ck_assert_ldouble_eq(s21_pow(base2, exp3), pow(base2, exp3));
  ck_assert_ldouble_eq(s21_pow(0, 0), pow(0, 0));
  ck_assert_double_nan(s21_pow(base4, exp4));
  ck_assert_double_nan(s21_pow(base4, exp2));
  ck_assert_double_nan(s21_pow(base4, exp3));
  ck_assert_double_nan(s21_pow(base3, exp4));
  ck_assert_double_nan(s21_pow(base2, exp4));
  ck_assert_double_nan(s21_pow(0, exp4));
  ck_assert_ldouble_eq_tol(s21_pow(base4, 0), pow(base4, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base2, 0), pow(base2, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base3, 0), pow(base3, 0), 1e-6);
}
END_TEST

// SIN TEST
START_TEST(s21_test_sin_check_1) {
  double val1 = 0.00000154654654;
  double val2 = S21_PI;
  double val3 = 1e-9;
  double val4 = 1e9;
  ck_assert_ldouble_eq_tol(s21_sin(val1), sin(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(val2), sin(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(val3), sin(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(val4), sin(val4), 1e-6);
}
END_TEST

START_TEST(s21_test_sin_check_2) {
  for (double i = -S21_PI * 5; i <= S21_PI * 5; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_sin_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  ck_assert_double_nan(s21_sin(val1));
  ck_assert_double_nan(s21_sin(val2));
  ck_assert_double_nan(s21_sin(val3));
}
END_TEST

// SQRT TEST
START_TEST(s21_test_sqrt_check_1) {
  double val1 = 0.0000545;
  double val2 = 1e16;
  double val3 = 0;
  double val4 = 1025.854745;
  ck_assert_ldouble_eq_tol(s21_sqrt(val1), sqrt(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(val2), sqrt(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(val3), sqrt(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(val4), sqrt(val4), 1e-6);
}
END_TEST

START_TEST(s21_test_sqrt_check_2) {
  for (double i = 1; i <= 20; i += 1) {
    ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrt(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_test_sqrt_check_3) {
  double val1 = S21_INF_NEG;
  double val2 = S21_INF_POS;
  double val3 = S21_NAN;
  double val4 = -5;
  ck_assert_double_nan(s21_sqrt(val1));
  ck_assert_double_infinite(s21_sqrt(val2));
  ck_assert_double_nan(s21_sqrt(val3));
  ck_assert_double_nan(s21_sqrt(val4));
}
END_TEST

// TAN TEST
START_TEST(s21_test_tan_check_1) {
  double val1 = 0.54654;
  double val2 = 1;
  double val3 = -4;
  double val4 = 54678.56454;
  ck_assert_ldouble_eq_tol(s21_tan(val1), tan(val1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(val2), tan(val2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(val3), tan(val3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(val4), tan(val4), 1e-6);
}
END_TEST

START_TEST(s21_test_tan_check_2) {
  for (double i = -S21_PI; i <= S21_PI; i += .1) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), 1e-6);
  }
}
END_TEST

Suite *s21_suit(void) {
  Suite *suite = suite_create("s21_math");

  TCase *tcase_math_test = tcase_create("s21_math_tcase");

  tcase_add_test(tcase_math_test, s21_test_abs_check_1);
  tcase_add_test(tcase_math_test, s21_test_abs_check_2);
  tcase_add_test(tcase_math_test, s21_test_abs_check_3);

  tcase_add_test(tcase_math_test, s21_test_acos_check_1);
  tcase_add_test(tcase_math_test, s21_test_acos_check_2);
  tcase_add_test(tcase_math_test, s21_test_acos_check_3);

  tcase_add_test(tcase_math_test, s21_test_asin_check_1);
  tcase_add_test(tcase_math_test, s21_test_asin_check_2);
  tcase_add_test(tcase_math_test, s21_test_asin_check_3);

  tcase_add_test(tcase_math_test, s21_test_atan_check_1);
  tcase_add_test(tcase_math_test, s21_test_atan_check_2);

  tcase_add_test(tcase_math_test, s21_test_ceil_check_1);
  tcase_add_test(tcase_math_test, s21_test_ceil_check_2);
  tcase_add_test(tcase_math_test, s21_test_ceil_check_3);

  tcase_add_test(tcase_math_test, s21_test_cos_check_1);
  tcase_add_test(tcase_math_test, s21_test_cos_check_2);
  tcase_add_test(tcase_math_test, s21_test_cos_check_3);

  tcase_add_test(tcase_math_test, s21_test_exp_check_1);
  tcase_add_test(tcase_math_test, s21_test_exp_check_2);
  tcase_add_test(tcase_math_test, s21_test_exp_check_3);

  tcase_add_test(tcase_math_test, s21_test_fabs_check_1);
  tcase_add_test(tcase_math_test, s21_test_fabs_check_2);
  tcase_add_test(tcase_math_test, s21_test_fabs_check_3);

  tcase_add_test(tcase_math_test, s21_test_floor_check_1);
  tcase_add_test(tcase_math_test, s21_test_floor_check_2);
  tcase_add_test(tcase_math_test, s21_test_floor_check_3);

  tcase_add_test(tcase_math_test, s21_test_fmod_check_1);
  tcase_add_test(tcase_math_test, s21_test_fmod_check_2);

  tcase_add_test(tcase_math_test, s21_test_log_check_1);
  tcase_add_test(tcase_math_test, s21_test_log_check_2);
  tcase_add_test(tcase_math_test, s21_test_log_check_3);

  tcase_add_test(tcase_math_test, s21_test_pow_check_1);
  tcase_add_test(tcase_math_test, s21_test_pow_check_2);

  tcase_add_test(tcase_math_test, s21_test_sin_check_1);
  tcase_add_test(tcase_math_test, s21_test_sin_check_2);
  tcase_add_test(tcase_math_test, s21_test_sin_check_3);

  tcase_add_test(tcase_math_test, s21_test_sqrt_check_1);
  tcase_add_test(tcase_math_test, s21_test_sqrt_check_2);
  tcase_add_test(tcase_math_test, s21_test_sqrt_check_3);

  tcase_add_test(tcase_math_test, s21_test_tan_check_1);
  tcase_add_test(tcase_math_test, s21_test_tan_check_2);

  suite_add_tcase(suite, tcase_math_test);
  return suite;
}

int main(void) {
  int failed_count = 0;
  Suite *suite = s21_suit();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}