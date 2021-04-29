#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void uzupelnij(int **tab, int Y, int X)
{

    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
            tab[i][j] = rand() % 100;
    }
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

void srednia(int **tab, int Y, int X)
{
    for (int i = 0; i < X; i++)
    {
        double suma_kol = 0;
        for (int j = 0; j < Y; j++)
        {
            suma_kol = suma_kol + tab[j][i];
        }
        printf("Srednia z kolumny %d wynosi %.2lf\n", i, suma_kol / Y);
    }
    for (int k = 0; k < Y; k++)
    {
        double suma_wiersz = 0;
        for (int l = 0; l < X; l++)
        {
            suma_wiersz = suma_wiersz + tab[k][l];
        }
        printf("Srednia z wiersza %d wynosi %.2lf\n", k, suma_wiersz / X);
    }
}

int main()
{
    srand(time(NULL));
    int X = 5, Y = 3;
    int **tab;
    tab = generuj(Y, X);
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
    srednia(tab, Y, X);
    for (int i = 0; i < Y; i++)
        free(tab[i]);
    free(tab);
    return 0;
}
