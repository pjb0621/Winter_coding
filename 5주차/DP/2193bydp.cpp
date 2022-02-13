#include <iostream>

long long memo[91][2] = {0,};

long long pinary(int n, int status){
    if(memo[n][status] != 0){
        return memo[n][status];
    }
    else if(n == 1){
        return 1;
    }
    int ans;
    if(status == 1){
        ans = pinary(n - 1, 0);
    }
    else{
        ans = pinary(n - 1, 0) + pinary(n - 1, 1);
    }
    memo[n][status] = ans;

    return memo[n][status];
}

int main(){
    memo[1][1] = 1;
    memo[1][0] = 0;
    memo[2][1] = 1;
    memo[2][0] = 2;
    int n;
    std::cin >> n;
    std::cout << pinary(n, 1) << std::endl;

    return 0;
}