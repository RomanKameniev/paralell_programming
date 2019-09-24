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

time_t calculate()
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
    return finish - start;
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
        time_t calc = calculate();
        printf("time of %d iteration is = %lg \n test item of arr=> %d \n", i, (double)calc / CLOCKS_PER_SEC, c[0][0]);
    }
    int key;
    printf("End \n");
    scanf("%d", &key);
    return 0;
}