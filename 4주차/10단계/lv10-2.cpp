#include <iostream>

int pibo(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    int ans;
    ans = pibo(n - 1) + pibo(n - 2);

    return ans;
}

int main(){
    int n;
    std::cin >> n;
    std::cout << pibo(n) << std::endl;

}