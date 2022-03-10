#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int Effort(int a, int b)
{
    int num[4][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9},
                     {-1, 0, -1}};

    int x[2], y[2];

    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(num[i][j] == a)
            {
                x[0] = j;
                y[0] = i;
            }
            if(num[i][j] == b)
            {
                x[1] = j;
                y[1] = i;
            }
        }
    }

    return abs(x[1]-x[0]) + abs(y[1]-y[0]);
}

int TotalEffort(int h, int m)
{
    return Effort(h/10, h%10) + Effort(h%10, m/10) + Effort(m/10, m%10);
}

int main(void)
{
    int h, m;
    char c;


    cin>>h>>c>>m;

    int minH = h, minM = m, minE = TotalEffort(h, m);

    for(int i = 0; h+i*24<100; i++)
    {
        for(int j = 0; m+j*60<100; j++)
        {
            if(TotalEffort(h+i*24, m+j*60) < minE)
            {
                minE = TotalEffort(h+i*24, m+j*60);
                minH = h + i*24;
                minM = m + j*60;
            }
        }
    }

    printf("%02d:%02d\n", minH, minM);


    return 0;
}