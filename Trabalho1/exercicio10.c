#include <stdio.h>

void intercala(int *v1, int *v2, int *v3, int n){

    for(int i = 0; i < n; i++){
        *v3 = *v1;
        v3++;
        v1++;

        *v3 = *v2;
        v3++;
        v2++;
    }
}
int main() {
    int v1[3] = {1, 3, 5};
    int v2[3] = {2, 4, 6};
    int v3[6];

    intercala(v1, v2, v3, 3);

    for (int i = 0; i < 6; i++) {
        printf("%d \n", v3[i]);
    }

    return 0;
}