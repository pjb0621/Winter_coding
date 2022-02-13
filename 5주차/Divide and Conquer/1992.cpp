#include <iostream>
void quadtree(char **arr,int x, int y, int n){
    char c = arr[y][x];
    for (int i = y; i < y + n; i++){
        for (int j = x; j < x + n; j++){
            if(c != arr[i][j]){
                std::cout << "(";
                for (int a = 0; a < 2; a++){
                    for (int b = 0; b < 2; b++){
                        quadtree(arr, x + n / 2 * b, y + n / 2 * a, n / 2);
                    }
                }
                std::cout << ")";
                return;
            }
        }
    }
    if(c == '0'){
        std::cout << "0";
    }
    else{ std::cout << "1";}
    return;
}

int main(){
    int n;
    std::cin >> n;
    char **arr;
    arr = new char*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new char[n];
    }
    for(int i = 0; i < n; i++ ){
        std::cin >> arr[i];
    }
    quadtree(arr, 0, 0, n);
    
}