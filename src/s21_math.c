#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_acos(double x) {
  long double res = S21_NAN;
  if (x == 1) res = 0;
  if (x == -1) res = S21_PI;
  if (x < 1 && x >= 0) res = s21_atan(s21_sqrt(1 - x * x) / x);
  if (x < 0 && x > -1) res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  return res;
}

long double s21_asin(double x) {
  long double res;
  if (x == 1 || x == -1) {
    res = x == 1 ? S21_PI2 : -S21_PI2;
  } else if (x > 1 || x < -1) {
    res = S21_NAN;
  } else {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return res;
}

long double pow_integer(double base, long long int exp) {
  long double res = 1;
  int sign = exp > 0 ? 1 : 0;
  if (exp < 0) exp = -exp;
  for (long long int i = 0; i < exp; i++) {
    if (sign)
      res *= base;
    else
      res /= base;
  }
  return res;
}

long double s21_atan(double x) {
  long double res = 0;
  if (x == 0) {
    res = 0;
  } else if (x == 1.0 || x == -1.0) {
    res = (x == 1.0) ? (S21_PI / 4) : -(S21_PI / 4);
  } else if (x == S21_INF_POS || x == S21_INF_NEG) {
    res = (x == S21_INF_POS) ? S21_PI2 : -S21_PI2;
  } else {
    int check = s21_fabs(x) > 1 ? -1 : 1;
    long double fault = 0;
    int i = 0;
    do {
      fault = (pow_integer(-1, i) * pow_integer(x, (check + 2 * check * i))) /
              (1 + 2 * i);
      res += fault;
      i++;
    } while (s21_fabs(fault) > 1e-9);
    if (check == -1) res = (S21_PI * s21_fabs(x) / (2 * x) - res);
  }
  return res;
}

long double s21_ceil(double x) {
  long double res = (long long int)x;
  if (x != x)
    res = S21_NAN;
  else if (x == S21_INF_NEG)
    res = S21_INF_NEG;
  else if (x == S21_INF_POS)
    res = S21_INF_POS;
  if (x > 0 && res != x) res++;
  return res;
}

long double s21_cos(double x) {
  long double res = 0;
  double pow = 1;
  double fault;
  int minus = 1;
  if (x != x)
    res = S21_NAN;
  else if (x == S21_INF_NEG)
    res = S21_NAN;
  else if (x == S21_INF_POS)
    res = S21_NAN;
  else {
    x = s21_fmod(x, 2 * S21_PI);
    int i = 0;
    do {
      fault = (minus * pow) / s21_factorial(i * 2);
      res += fault;
      minus = -minus;
      pow = pow * x * x;
      i++;
    } while (s21_fabs(fault) > 1e-10);
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 1;
  long double fault = 1;
  if (x != x)
    res = S21_NAN;
  else if (x == S21_INF_NEG)
    res = 0;
  else if (x == S21_INF_POS)
    res = S21_INF_POS;
  else {
    int i = 1;
    do {
      fault *= x / i;
      res += fault;
      i++;
      if (res >= DBL_MAX) {
        res = S21_INF_POS;
        break;
      }
    } while (s21_fabs(fault) > 1e-10);
  }
  return res;
}

long double s21_fabs(double x) {
  long double result;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF_NEG) {
    result = S21_INF_NEG;
  } else if (x == S21_INF_POS) {
    result = S21_INF_POS;
  } else {
    if (x < 0) {
      result = -x;
    } else {
      result = x;
    }
  }

  return result;
}

long double s21_factorial(long long int x) {
  long double res;
  if (x < 1) {
    res = 1;
  } else {
    res = x * s21_factorial(x - 1);
  }
  return res;
}

long double s21_floor(double x) {
  long double res = (long long int)x;
  if (x != x)
    res = S21_NAN;
  else if (x == S21_INF_NEG)
    res = S21_INF_NEG;
  else if (x == S21_INF_POS)
    res = S21_INF_POS;
  if (x < 0 && res != x) res--;
  return res;
}

long double s21_fmod(double x, double y) {
  long double res;
  long double n;
  if (x != x || y != y) {
    res = S21_NAN;
  } else if (x == S21_INF_NEG && y != 0) {
    res = S21_INF_NEG;
  } else if (x == S21_INF_POS && y != 0) {
    res = S21_INF_POS;
  } else if (y == 0) {
    res = S21_NAN;
  } else {
    n = x / y;
    res = (long double)x - (long double)y * (long long int)n;
  }
  return res;
}

long double s21_log(double x) {
  long double result = 0;
  if (x == 0) {
    result = S21_INF_NEG;
  } else if (x < 0) {
    result = S21_NAN;
  } else if (x == S21_INF_POS) {
    result = x;
  } else if (x == 1) {
    result = 0;
  } else {
    long double temp_value = 0;
    long double fault = 0;
    do {
      fault = 2 * (x - s21_exp(temp_value)) / (x + s21_exp(temp_value));
      result = temp_value + fault;
      temp_value = result;
    } while (s21_fabs(fault) > 1e-10);
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result;
  if (base == S21_INF_NEG && exp == S21_INF_NEG) {
    result = 0;
  } else if (base == S21_INF_NEG && exp == S21_INF_POS) {
    result = S21_INF_POS;
  } else if (base < 0 && exp != (long long int)exp) {
    return S21_NAN;
  } else if (!exp) {
    result = 1;
  } else {
    int temp_sign;
    result = 0;
    if (base < 0) {
      temp_sign = -1;
    } else {
      temp_sign = 1;
    }
    result = s21_exp(exp * s21_log(base * temp_sign));
    if (s21_fmod(exp, 2)) {
      result *= temp_sign;
    }
  }
  return result;
}

long double s21_sin(double x) {
  long double res = 0;
  double pow = 1;
  double fault;
  int sign = 1;
  if (x != x)
    res = S21_NAN;
  else if (x == S21_INF_NEG)
    res = S21_NAN;
  else if (x == S21_INF_POS)
    res = S21_NAN;
  else {
    x = s21_fmod(x, 2 * S21_PI);
    int i = 0;
    do {
      fault = (sign * pow * x) / s21_factorial(i * 2 + 1);
      res += fault;
      sign = -sign;
      pow = pow * x * x;
      i++;
    } while (s21_fabs(fault) > 1e-10);
  }
  return res;
}

long double s21_sqrt(double x) {
  long double result;
  if (x < 0 || x == S21_INF_NEG) {
    result = S21_NAN;
  } else if (x == S21_INF_POS || x == 0) {
    result = (long double)x;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}

long double s21_tan(double x) {
  return s21_cos(x) ? s21_sin(x) / s21_cos(x) : S21_NAN;
}