#include <stdio.h>

int main(int argc, int argv[]) {
	
	double x = 665857.0;
	double y = 470832.0;
	float dX = 665857.0;
	float dY = 470832.0;
	long long  llX = 665857.0;
	long long  llY = 470832.0;

	double res = (x*x*x*x) - 4*(y*y*y*y) - 4*(y*y);
	printf("La x val: %.10f i la y val: %.10f\n", x, y);
	printf("Z double = %lf\n", res);
	
	float res2 = (dX*dX*dX*dX) - 4*(dY*dY*dY*dY) - 4*(dY*dY);
	
	printf("Z float = %f\n", res2);
	
	

	long long  res3 = (llX*llX*llX*llX) - 4*(llY*llY*llY*llY) - 4*(llY*llY);
	
	printf("La x val: %lld i la y val: %lld \n", llX, llY);
	
	printf("Z int = %lld\n", res3);
	

	
	return 0;
}