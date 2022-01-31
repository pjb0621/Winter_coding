#include <iostream>

void recursive(int **check, int x, int y, int n){
    if( n == 3){
        check[y+1][x+1] = 1;
        return;
    }
    for (int i = 0; i < n /3; i++){
        for (int j = 0; j < n / 3; j++){
            check[y + n / 3 + i][x + n / 3 + j] = 1;
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            recursive(check, x + n / 3 * j , y + n / 3 * i, n / 3);
        }
    }
}


int main(){
    int n;
    std::cin >> n;
    int **check;
    check = new int*[n];
    for (int i = 0; i < n; i++){
        check[i] = new int[n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            check[j][i] = 0;
        }
    } 

    recursive(check, 0, 0, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(check[i][j] == 0){
                std::cout << '*';
            }
            else{
                std::cout << ' ';
            }
        }
        std::cout << '\n';

    }
}

