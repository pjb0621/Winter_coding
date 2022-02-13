#include <iostream>

int combination[1001][1001] = {0, };

int getcom(int n, int k){
    if(combination[n][k] != 0){
        return combination[n][k];
    }
    else if(k == 0 || n == k){
        return 1;
    }
    else{
        combination[n][k] = (getcom(n -1, k) + getcom(n - 1, k - 1)) % 10007;
    }

    return combination[n][k] % 10007;
    
}

int main(){
    int n,k;
    std::cin >> n >> k;
    combination[0][0] = 1;
    combination[1][1] = 1;
    std::cout << getcom(n, k);

    return 0;
}