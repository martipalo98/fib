#include <stdio.h>

int i = 100, a=2, b=50;
int main(){
    while(i>0) {
        if(a!=b) {
            b = 3*(b-a);
        }
    }
    return 0;
}