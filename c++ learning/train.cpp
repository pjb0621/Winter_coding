#include <stdio.h>
#include <stdlib.h>


// implement your function if you needed

void printResults(int* train_W, int* train_N, int len, int extensionCnt){
    printf("Car # | ");
    for(int i= 0; i<len; i++){
        printf("%5d ", i);
    }
    printf("\n");
    printf("Count | ");
    for(int i = 0; i < len; i++){
        printf("%5d ", trian_N[i]);
    }

    printf("\n");
    printf("Weight | ");
    for(int i = 0; i < len; i++){
        printf("%5d ",train_W[i]);
    }
    printf("\n");
    printf("Number of Extensions: %d\n", extensionCnt);
}
int main()
{
    int n, cap_N, cap_W;
    scanf("%d", &n);
    scanf("%d", &cap_N); // numeric limit for each car
    scanf("%d", &cap_W); // weight limit for each car

    int len = 2;
    int extensionCnt = 0;
    int* train_W = (int*) calloc(len, sizeof(int));
    int* train_N = (int*) calloc(len, sizeof(int));

    int left_W[]
}