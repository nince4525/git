#include <stdio.h>
typedef struct
{
  double real;
  double imag;
} complex;

complex assign(complex *a, double real, double imag);
complex add(complex *a, complex *b);
complex assign(complex *a, double real, double imag)
{
  a->real = real;
  a->imag = imag;
  return *a;
}

complex add(complex *a, complex *b)
{
  complex c;
  c.real = a->real + b->real;
  c.imag = a->imag + b->imag;
  return c;
}

int main()
{
  complex a, b;
  scanf("%lf %lf", &a.real, &a.imag);
  scanf("%lf %lf", &b.real, &b.imag);

  complex C = add(&a, &b);
  printf("%lf %lf", C.real, C.imag);
}
