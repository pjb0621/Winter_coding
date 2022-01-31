#include <iostream>

void sieve(int* tab, int max){
    int temp = 1;
    tab[1] = 1;
    for (int i = 2; i * i <= max; ++i){
        if(!tab[i]){
            temp = 2 * i;
            while(temp <= max){
                tab[temp] = 1;
                temp += i;
            }
        }
    }
    
}



int main(){
    int n = 1;
    while(1){
        int count = 0;
        std::cin >> n;
        if(n == 0){
            break;
        }
        int tab[2*n + 1] = {0, };
        sieve(tab, 2 * n);
        for (int i = n + 1; i <= 2 * n; i++){
            if(tab[i] == 0){
                count++;
            }
        }

        if(count != 0){
            std::cout << count << '\n';
        }

    }

    return 0;
    

}