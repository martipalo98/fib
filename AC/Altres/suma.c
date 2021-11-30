#include <stdio.h>

int suma(int a, int b);

int main(int argc, char** argv) {
    int a = 0;
    int b = 0;

    if(argc == 3) {
        a = (int)argv[0];
        b = (int)argv[1];
    }

    int res = suma(a, b);

    printf("Resultat: %i\n", res);

    return 0;
}