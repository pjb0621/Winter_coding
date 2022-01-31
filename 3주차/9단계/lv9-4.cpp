#include <iostream>
#include <cmath>

void primeg(int p, int *prime){
    int index = 1;
    for (int i = 3; i <= p; i++){
        int ifa = 1;
        int j = 0;
        while(prime[j] <= pow(i, 0.5) && prime[j]){
            if(i % prime[j] == 0){
                ifa = 0;
                break;
            }
            j++;
        }
        if (ifa == 1){
            prime[index] = i;
            index++;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int m,n;
    std::cin >> m >> n;
    int prime[1000];
    for (int i = 0; i < 1000; i++){
        prime[i] = 0;
    }
    prime[0] = 2;
    float p = pow(n,0.5);
    primeg(p, prime);
    int *ans = new int[n - m + 1];
    for (int i = 0; i < n - m + 1; i++){
        if(i + m == 1){
            continue;
        }
        int j = 0;
        int ifa = 1;
        int p = pow(i + m , 0.5);
        while( p >= prime[j] && prime[j]){
            if ( (i + m) % prime[j] == 0){
                ifa = 0;
                break;
            }
            j++;
        }
        if(ifa == 1){
            std::cout << i + m << '\n';
        }
    }

    return 0;
    
}