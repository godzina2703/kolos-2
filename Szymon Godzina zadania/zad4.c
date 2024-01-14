#include <stdio.h>

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void zamianaWierszy(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[rows - 1 - i][j];
            matrix[rows - 1 - i][j] = temp;
        }
    }
}

void zamianaKolumn(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][cols - 1 - j];
            matrix[i][cols - 1 - j] = temp;
        }
    }
}

int main() {
    int rows, cols;

    // Wczytaj rozmiary tablicy od użytkownika
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &rows);

    printf("Podaj liczbe kolumn: ");
    scanf("%d", &cols);


    // Deklaruj dwuwymiarową tablicę o podanych rozmiarach
    int matrix[rows][cols];

    // Wczytaj elementy tablicy od użytkownika
    printf("Podaj elementy tablicy:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Wybór operacji
    int choice;
    printf("Wybierz operacje:\n");
    printf("1. Odbicie lustrzane w poziomie\n");
    printf("2. Odbicie lustrzane w pionie\n");
    scanf("%d", &choice);

    // Wykonaj wybraną operację i wyświetl wynikową tablicę
    switch (choice) {
        case 1:
            zamianaWierszy(rows, cols, matrix);
            break;
        case 2:
            zamianaKolumn(rows, cols, matrix);
            break;
        default:
            printf("Niepoprawny wybor operacji.\n");
            return 1; // Zakończ program z kodem błędu
    }

    // Wyświetl wynikową tablicę
    printf("Wynikowa tablica:\n");
    printMatrix(rows, cols, matrix);

    return 0;
}