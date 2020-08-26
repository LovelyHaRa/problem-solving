#include<cstdio>
#define _USE_MATH_DEFINES
#include<cmath>
using namespace std;

int main(void)
{
	double r;
	scanf("%lf", &r);
	/*
	  유클리드 기하학에서의 원의 넓이 : PI*r*r
	  택시 기하학에서의 원의 넓이
	   2*r=sqrt(2)*a -> 4*r*r=2*a*a
	   2*r*r=a*a
	   정사각형의 넓이 = 2*r*r
	 */
	printf("%.6lf\n", r*r*M_PI);
	printf("%.6lf\n", 2*r*r);
}