#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#define MAX 1024
#define RAND_KEY 100

clock_t start, finish;
int64_t a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

void generateArr(int64_t arr[MAX][MAX])
{
    time_t t;
    srand((unsigned)time(&t));
    for (int x = 0; x < MAX; x++)
    {
        for (int y = 0; y < MAX; y++)
        {
            arr[x][y] = rand() % RAND_KEY;
        }
    }
}

int64_t power(int64_t a, int64_t b)
{
    return a * b;
}

double calculate_ijk()
{
    start = clock();
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            int64_t temp = 0;
            for (int k = 0; k < MAX; k++)
            {
                temp += power(a[i][k], b[k][j]);
            }
            c[i][j] = temp;
        }
    }

    finish = clock();
    return (double)(finish - start) / CLOCKS_PER_SEC;
}

double calculate_jik()
{
    start = clock();
    for (int j = 0; j < MAX; j++)
    {
        for (int i = 0; i < MAX; i++)
        {
            int64_t temp = 0;
            for (int k = 0; k < MAX; k++)
            {
                temp += power(a[i][k], b[k][j]);
            }
            c[i][j] = temp;
        }
    }

    finish = clock();
    return (double)(finish - start) / CLOCKS_PER_SEC;
}

double calculate_kji()
{
    start = clock();
    int i, j, k;
    for (k = 0; k < MAX; k++)
    {
        for (j = 0; j < MAX; j++)
        {
            int64_t temp = 0;
            for (i = 0; i < MAX; i++)
            {
                temp += power(a[i][k], b[k][j]);
            }
            c[i][j] = temp;
        }
    }

    finish = clock();
    return (double)(finish - start) / CLOCKS_PER_SEC;
}
void emptyArr(int64_t arr[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }
}

int main()
{
    printf("C seq program \n");
    printf("default value: \n arr length= %d \n key range from 0 to %d \n ", MAX, RAND_KEY);
    for (int i = 1; i <= 10; i++)
    {
        printf("init arr a && b\n");
        generateArr(a);
        generateArr(b);
        printf("calculating arr\n");
        double ijk_time = calculate_ijk();
        printf(" ijk seq time of %d iteration is = %lg \n test item of arr=> %I64ld \n", i, ijk_time, c[0][0]);
        emptyArr(c);
        double jik_time = calculate_jik();
        printf(" jki seq reverse => time of %d iteration is = %lg \n test item of arr=> %I64ld \n", i, jik_time, c[0][0]);
        emptyArr(c);
        double kji_time = calculate_kji();
        printf(" jki seq reverse => time of %d iteration is = %lg \n test item of arr=> %I64ld \n", i, kji_time, c[0][0]);
    }
    int key;
    printf("End \n");
    scanf("%d", &key);
    return 0;
}
