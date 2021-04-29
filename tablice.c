#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void uzupelnij(int **tab, int Y, int X)
{

    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
            tab[i][j] = rand() % 100;
    }
}

void wypisz(int **tab, int Y, int X)
{
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
    printf("\n");
}

int **generuj(int Y, int X)
{
    int **tab;
    tab = (int **)malloc(Y * sizeof(int *));
    for (int i = 0; i < Y; i++)
        tab[i] = (int *)malloc(X * sizeof(int));
    uzupelnij(tab, Y, X);
    return tab;
}

void obliczenia(int **tab, int Y, int X)
{
    for (int i = 0; i < X; i++)
    {
        double suma_kol = 0;
        for (int j = 0; j < Y; j++)
        {
            suma_kol = suma_kol + tab[j][i];
        }
        double kwadraty_kol = 0;
        for (int j = 0; j < Y; j++)
        {
            kwadraty_kol = kwadraty_kol + pow((tab[j][i] - suma_kol / Y), 2);
        }
        printf("Srednia z kolumny %d wynosi %.2lf natomiast wariancja wynosi %.2lf\n\n", i, suma_kol / Y, kwadraty_kol / Y);
    }
    for (int i = 0; i < Y; i++)
    {
        double suma_wiersz = 0;
        for (int j = 0; j < X; j++)
        {
            suma_wiersz = suma_wiersz + tab[i][j];
        }
        double kwadraty_wiersz = 0;
        for (int j = 0; j < X; j++)
        {
            kwadraty_wiersz = kwadraty_wiersz + pow((tab[i][j] - suma_wiersz / X), 2);
        }
        printf("Srednia z wiersza %d wynosi %.2lf natomiast wariancja wynosi %.2lf\n\n", i, suma_wiersz / X, kwadraty_wiersz / X);
    }
}

int main()
{
    srand(time(NULL));
    int X, Y;
    printf("Program służy do generowania tablic 2d o zadanej liczbie kolumn X oraz liczbie wierszy Y wypełnionych losowymi liczbami, następnie dla każdej kolumny oraz wiersza obliczana jest średnia oraz wariancja\n");
    printf("\nPodaj liczbę kolumn X:\n");
    scanf("%d", &X);
    printf("Podaj liczbę wierszy Y:\n");
    scanf("%d", &Y);
    printf("\n");
    int **tab;
    tab = generuj(Y, X);
    wypisz(tab, Y, X);
    obliczenia(tab, Y, X);
    for (int i = 0; i < Y; i++)
        free(tab[i]);
    free(tab);
    return 0;
}
