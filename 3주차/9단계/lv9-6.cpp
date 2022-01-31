#include <iostream>

void sieve(int* tab, int max){
    int temp;
    tab[1] = 1;
    for (int i = 2; i * i <= max; i++){
        if(tab[i] == 0){
            temp = i * 2;
            while(temp <= max){
                tab[temp] = 1;
                temp += i;
            }
        }
    }
}

int main(){
    int N,n;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        int index;
        int dif = 10000;
        std::cin >> n;
        int tab[n] = {0, };
        sieve(tab, n - 1);
        for (int j = 2; j <= n / 2; j++){
            if(!tab[j]){
                if(!tab[n - j]){
                    if (n - 2*j < dif){
                        dif = n - 2 * j;
                        index = j;
                    }
                }
            }
        }
        std::cout << index << ' ' << n - index << std::endl;
    }

    return 0;
}