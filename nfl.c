#include <stdio.h>

int main() {
    printf("Enter 0 or 1 to stop\n");
    printf("Enter the NFL score: ");
    int score;
    scanf("%d", &score);
    if (score <= 1) return 0;

    printf("\nPossible cominations of the scoring plays: \n");
    // TD+2
    for (int i = 0; i < score/8; i += 1) {
        // TD+1
        for (int j = 0; j < score/7; j += 1) {
            // TD+0
            for (int k = 0; k < score/6; k += 1) {
                // FG
                for (int l = 0; l < score/3; l += 1) {
                    // Safety
                    for (int m = 0; m < score/2; m += 1) {
                        if (((8*i)+(7*j)+(6*k)+(3*l)+(2*m)) == score) {
                            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", i,j,k,l,m);
                        }
                    }
                }
            }
        }
    }

}