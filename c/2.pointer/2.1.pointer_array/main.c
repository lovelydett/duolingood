#include <stdio.h>


int main() {
    // array name
    int a[3][10];
    for (int i = 0; i < 3; i += 1) {
        for (int j = 0; i < 10; j += 1) {
            a[i][j] = i * 10 + j;
        }
    }
    printf("Special case 1 sizeof(a): %d\n", sizeof(a));
    
    // pointer array
    int *pa[10];

    for (int i = 0; i < 10; i += 1) {
        pa[i] = (int*)a[0] + i;
    }

    // array pointer
    int (*ap)[10];
    ap = &a[0];

    printf("Special case 2 &a[0] by ap: (*(ap + 1))[0]: %d\n", (*(ap + 1))[0]);

    // size of pointer array
    printf("sizeof(pa): %d\n", sizeof(pa));
    printf("sizeof(pa[0]): %d\n", sizeof(pa[0]));

    // size of array pointer
    printf("sizeof(ap): %d\n", sizeof(ap));
    printf("sizeof(ap[1]) == sizeof(*(ap + 1)): %d, %d\n", sizeof(ap[0]), sizeof(*(ap + 1)));


    return 0;
}