#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Liczba calkowita n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("BŁĄD\n");
        return 1;
    }

    if (n < 3) {
        double e = exp(1.0);
        int zaokąglone_e = (int)(e * pow(10, n - 1) + 0.5);
        printf("e zaokraglone do %d miejsca po przecinku: %.*f\n", n, n - 1, (double)rounded_e / pow(10, n - 1));
    } else {
        printf("Wartosc liczby e do %d miejsc po przecinku: %.*f\n", n, n, exp(1.0));
    }

    return 0;
}