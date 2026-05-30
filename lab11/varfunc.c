#include <stdarg.h>
#include "varfunc.h"

double sum(int count, ...) {
    double result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        result += va_arg(args, double);
    }
    va_end(args);
    return result;
}

double max(int count, ...) {
    va_list args;
    va_start(args, count);
    double result = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        double value = va_arg(args, double);
        if (value > result) {
            result = value;
        }
    }
    va_end(args);
    return result;
}

double min(int count, ...) {
    va_list args;
    va_start(args, count);
    double result = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        double value = va_arg(args, double);
        if (value < result) {
            result = value;
        }
    }
    va_end(args);
    return result;
}

double avg(int count, ...) {
    double result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        result += va_arg(args, double);
    }
    va_end(args);
    return result / count;
}
