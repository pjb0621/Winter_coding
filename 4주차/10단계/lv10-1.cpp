#include <iostream>

int fac(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    int ans;
    ans = n * fac(n - 1);

    return ans;
}

int main(){
    int n;
    std::cin >> n;
    std::cout << fac(n);
}
