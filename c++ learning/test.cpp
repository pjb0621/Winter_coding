#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int a(int *participants);
int main(){
    

    int arr[3][2] = { {1,2}, {3,4}, {5,6},};
    int (*participants)[2] = arr;


    for(int i = 0; i < 3; i++){
        for(int j = 0; j <2; j++){
            printf("%d ", participants[i][j]);
        }
        printf("\n");
    }

    a(participants[1]);
}


int a(int *participants){

    int num = participants[1][0];
    printf("%d\n",num);
    return 0;
}