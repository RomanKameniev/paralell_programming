#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 1024
#define RAND_KEY 100

clock_t start, finish;
long long int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

void generateArr(long long int arr[MAX][MAX])
{
    time_t t;
    //int key = 3;
    srand((unsigned)time(&t));
    for (int x = 0; x < MAX; x++)
    {
        for (int y = 0; y < MAX; y++)
        {
            //arr[x][y] = key;
            //key++;
            arr[x][y] = rand() % RAND_KEY;
        }
    }
}

long long int power(long long int a, long long int b)
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
            long long int temp = 0;
            for (int k = 0; k < MAX; k++)
            {
                temp += power(a[i][k], b[k][j]);
            }
            // printf("%d ", temp);
            c[i][j] = temp;
        }
        //printf("\n");
    }
    finish = clock();
    return finish - start;
}
int main()
{
    printf("default value: \n arr length= %d \n key range from 0 to %d \n ", MAX, RAND_KEY);
    for (int i = 1; i <= 10; i++)
    {
        printf("init arr a && b\n");
        generateArr(a);
        generateArr(b);
        printf("calculating arr\n");
        time_t calc = calculate();
        printf("time of %d iteration is = %lg \n, test item of arr=> %d \n", i, (double)calc / CLOCKS_PER_SEC, c[0][0]);
    }
    int key;
    scanf("%d", &key);
    return 0;
}
