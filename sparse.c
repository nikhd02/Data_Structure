// .                     .
// ..                   ..
// ...                 ...
// ....               ....
// .....             .....
// ......           ......
// .......         .......
// ........       ........
// .........     .........
// ..........   ..........
// ....................... 

#include <stdio.h>

int main() {
    int n = 10; // Number of rows

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf(".");
        }
        for (int k = 1; k <= n - i; k++) {
            printf(" ");
        }
        for (int k = 1; k <= n - i; k++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf(".");
        }
        printf("\n");
    }

    // for (int i = n - 1; i >= 1; i--) {
    //     for (int j = 1; j <= i; j++) {
    //         printf(".");
    //     }
    //     for (int k = 1; k <= n - i; k++) {
    //         printf(" ");
    //     }
    //     for (int k = 1; k <= n - i; k++) {
    //         printf(" ");
    //     }
    //     for (int j = 1; j <= i; j++) {
    //         printf(".");
    //     }
    //     printf("\n");
    // }

    return 0;
}