#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

void rozklad(int n, int max, int* vals, int p) {
    // rozkladamy 'n' na skladniki nieprzekraczajace 'max' i wynik rozkladu 
    // umieszczamy w tablicy 'vals' poczynajac od indeksu 'p'
    if (n == 0) {
        printf("%d ", vals[0]);
        for(int i = 1; i < p; i++) printf("+ %d ", vals[i]);
        printf("\n");
    }
    else {
        for(int i = min(n, max); i > 0; i--) {
            vals[p] = i;
            rozklad(n - i, i, vals, p + 1);
        }
    }
}

void rozloz(int n) {
    if (n > 0) {
        int vals[n];
        rozklad(n, n, vals, 0);
    }
}

int main(void){

    rozloz(14);

    return 0;
}