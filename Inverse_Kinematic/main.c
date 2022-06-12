#include <stdio.h>
#include <math.h>
void moveToPos(double x, double y, double z){

    double b = atan(y/x)*(180 /3.14);
    double l = sqrt(x*x + y*y);
    double h = sqrt(l*l + z*z);

    double phi = atan(z/l)*(180/3.14);
    double theta = acos((h/2)/75)*(180/3.14);

    double a1 = phi + theta;
    double a2 = phi - theta;

    moveToAngle(b,a1,a2);
}
int main()
{
    printf("");
    return 0;
}