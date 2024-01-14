#include <stdio.h>

// Funkcja obliczająca NWD dwóch liczb
int dzielenie(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funkcja rekurencyjna obliczająca NWD dla tablicy
int arrayDzielenie(int* arr, int start, int end) {
    if (start == end) {
        return arr[start];
    } else {
        int middle = (start + end) / 2;
        int leftDzielenie = arrayDzielenie(arr, start, middle);
        int rightDzielenie = arrayDzielenie(arr, middle + 1, end);
        return dzielenie(leftDzielenie, rightDzielenie);
    }
}

int main() {
    int n;

    // Wprowadzenie liczby elementów tablicy od użytkownika
    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("BŁĄD: Liczba elementow musi byc wieksza od 0\n");
        return 1;
    }

    // Dynamiczna alokacja pamięci dla tablicy
    int* array = (int*)malloc(n * sizeof(int));

    // Wprowadzenie elementów tablicy od użytkownika
    printf("Podaj elementy tablicy:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    // Obliczenie NWD dla tablicy
    int result = arrayDzielenie(array, 0, n - 1);

    // Wyświetlenie wyniku
    printf("Najwiekszy wspolny dzielnik (NWD) dla tablicy to: %d\n", result);

    // Zwolnienie zaalokowanej pamięci
    free(array);

    return 0;
}