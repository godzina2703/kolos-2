#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int array[], int n) {  
    int i, j;  
    for (i = 0; i < n - 1; i++) {  
        for (j = 0; j < n - i - 1; j++) {  
          if (array[j] > array[j + 1]) {  
            int temp = array[j];  
            array[j] = array[j + 1];  
            array[j + 1] = temp;  
            }  
        }  
    }  
}  


bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int* filterPrimes(int* array, int size, int* resultSize) {
    int* primes = NULL;
    *resultSize = 0;

    for (int i = 0; i < size; i++) {
        if (isPrime(array[i])) {
            primes = (int*)realloc(primes, (*resultSize + 1) * sizeof(int));
            primes[*resultSize] = array[i];
            (*resultSize)++;
        }
    }

    return primes;
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

    // Alokacja dynamicznej tablicy jednowymiarowej
    int* array = (int*)malloc(n * sizeof(int));

    // Wprowadzenie elementów tablicy od użytkownika
    printf("Podaj elementy tablicy:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    // Wywołanie funkcji filterPrimes
    int resultSize;
    int* primeArray = filterPrimes(array, n, &resultSize);

    // Wyświetlenie tablicy liczb pierwszych
    printf("Liczby pierwsze w tablicy:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", primeArray[i]);
    }
    printf("\n");

    // Zwolnienie zaalokowanej pamięci
    free(array);
    free(primeArray);

    return 0;
}