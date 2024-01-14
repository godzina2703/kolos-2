#include <stdio.h>

// Funkcja obliczająca silnię
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Funkcja rekurencyjna obliczająca funkcję Kempnera
int kempnerFunction(int n, int current) {
    if (current % factorial(n) == 0) {
        return current;
    } else {
        return kempnerFunction(n, current + 1);
    }
}

int main() {
    int n;

    // Wprowadzenie liczby n od użytkownika
    printf("Podaj liczbe calkowita n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("BŁĄD: n musi być większe lub równe 1\n");
        return 1;
    }

    // Obliczenie funkcji Kempnera
    int result = kempnerFunction(n, 1);

    // Wyświetlenie wyniku
    printf("Funkcja Kempnera dla n=%d: %d\n", n, result);

    return 0;
}