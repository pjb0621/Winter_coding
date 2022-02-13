#include <iostream>

int zero = 0;
int one = 0;
int minus = 0;

void count(int **paper, int n,int x, int y){
    int num = paper[y][x];
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(num != paper[i][j]){
                for (int a = 0; a < 3; a++){
                    for(int b = 0; b < 3; b++){
                        count(paper, n / 3, x + n / 3 * a, y + n / 3 * b);
                    }
                }
                return;
            }
        }
    }
    if (num == 0){
        zero++;
    }
    else if( num == 1){
        one++;
    }
    else{
        minus++;
    }
    return;
}

int main(){
    int n;
    std::cin >> n;
    int **paper;
    paper = new int*[n];
    for(int i = 0; i < n; i++){
        paper[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> paper[i][j];
        }
    }
    count(paper, n, 0, 0);
    std::cout << minus << '\n' << zero << '\n' << one << std::endl;
}