#include <math.h>
#include "treug.h"

bool is_valid_sides(double a, double b, double c)
{
    return (a > 0 && b > 0 && c > 0);
}

bool is_triangle(double a, double b, double c)
{
    return (a + b > c && a + c > b && b + c > a);
}

double triangle_perimeter(double a, double b, double c)
{
    return a + b + c;
}

double triangle_area(double a, double b, double c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
