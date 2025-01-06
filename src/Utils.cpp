#include "Utils.h"

int dist2d(long double x1, long double y1, long double x2, long double y2){
    long double xd = x1-x2;
    long double yd = y1-y2;
    return (int)(sqrt(xd*xd+yd*yd)+0.5);
}