#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps = 1e-8;

int main()
{
    double n;
    scanf("%lf", &n);
    double l=-10000,r=10000;
    while(r-l>eps)
    {
        double mid = (r+l)/2;
        if(mid*mid*mid>=n) r=mid;
        else l=mid;
    }
    printf("%lf\n",l);
    return 0;
}