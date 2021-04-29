#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void uzupelnij(int **tab, int Y, int X)
{
    srand(time(NULL));
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

int main()
{
    int X = 5, Y = 5;
    int **tab;
    tab = generuj(Y, X);
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
    return 0;
}
