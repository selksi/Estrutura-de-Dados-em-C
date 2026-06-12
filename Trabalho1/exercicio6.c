#include <stdio.h>

void dobra(int *x){
    *x = *x * 2;
    printf("Valor dobrado: %d\n", *x);
}

int main(){
    int x = 5;
    int y = 12;
    int z = 1;

    int *p1 = &x, *p2 = &y;

    dobra(p1);
    dobra(p2);
    dobra(&z);

    return 0;
}