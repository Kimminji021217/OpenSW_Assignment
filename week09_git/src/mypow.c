#include "myops.h"

double mypow(double a, double b) {
    double result = 1;
    for (int i = 0; i < (int)b; i++) {
        result *= a;
    }
    return result;
}
