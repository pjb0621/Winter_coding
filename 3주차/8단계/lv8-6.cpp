#include <iostream>

int sum(int k ,int n){
    int num = 0;
    if(k == 0){
        return n;
    }
    else{
        for (int i = 0; i < n; i++){
            num += sum(k-1, i+1);
        }
    }

    return num;
}

int main(){
    int k,n,T;
    std::cin >> T;
    for (int i = 0; i < T; i++){
        std::cin >> k >> n;
        std::cout << sum(k,n) << std::endl;
    }

    return 0;
}
