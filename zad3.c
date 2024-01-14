#include <stdio.h>
#include <string.h>

int main() {
    char znaki[100], noweZnaki[200];
    
    printf("Podaj ciag znakow: ");
    if (scanf("%99[^\n]", znaki) != 1) {
        printf("BŁĄD: Wprowadzono niepoprawne dane\n");
        return 1;
    }

    int length = strlen(znaki);

    // nowy ciąg
    int noweIndeksy = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j <= i; ++j) {
            noweZnaki[newIndex++] = znaki[i];
        }
    }

    // Dodanie znaku null-terminatora na końcu nowego ciągu
    noweZnaki[newIndex] = '\0';

    // Wypisanie nowego ciągu
    printf("Nowy ciag znakow: %s\n", noweZnaki);

    return 0;
}
