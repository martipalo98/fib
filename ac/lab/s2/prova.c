#include <stdio.h>

int a = 2;
int b = 4;

int main(int argc, char** argv) {
    b = b + (b-a)/2;
    printf("%i \n",b);
}