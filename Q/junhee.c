#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.141592

main(int argc, char *argv[])
{
    double integ(double a, double b, int n, double (*f)(double));
    double *f(double);
    double lower, upper, val;
    int nsteps;

    if (argc < 4)
    {
        printf("usage: integ sin/cos/tan lower-limit upper-limit [no-of-steps]\n");
        return 1;
    }

    nsteps = (argc == 5) ? atof(argv[4]) : 100;
    lower = atof(argv[2]);
    upper = atof(argv[3]);

    if (strcmp(argv[1], "sin") == 0)
    {
        val = integ(lower, upper, nsteps, sin);
    }
    else if (strcmp(argv[1], "cos") == 0)
    {
        val = integ(lower, upper, nsteps, cos);
    }
    else if (strcmp(argv[1], "tan") == 0)
    {
        val = integ(lower, upper, nsteps, tan);
    }
    else
    {
        printf("unrecognized trigonometric function name: %s\n", argv[1]);
        return 1;
    }

    printf("int_%g^%g %s(x) = %.3g with %d parts\n", lower, upper, argv[1], val, nsteps);
    return 0;
}

double integ(double a, double b, int n, double (*f)(double))
{
    double sum, x, x1, delta, area;
    int i;

    delta = (b - a) / n;
    for (i = 0, sum = 0.0; i < n; i++)
    {
        x = a + i * delta;
        x1 = x + delta;
        area = delta * (f(x) + f(x1)) / 2;
        sum += area;
    }
    return sum;
}

double f1(double x)
{
    return x * x + x;
}
