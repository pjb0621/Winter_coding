#include <iostream>

int arr[101][10] = {0, };

int starenum(int n, int i){
    if(arr[n][i] != 0 || n == 1){
        return (arr[n][i]);
    }
    else{
        if(i == 0){
            arr[n][i] = starenum(n - 1, 1) % 1000000000;
        }
        else if(i == 9){
            arr[n][i] = starenum(n - 1, 8) % 1000000000;
        }
        else{
            arr[n][i] = (starenum(n - 1, i + 1) + starenum(n - 1, i - 1)) % 1000000000;
        }
    }

    return arr[n][i] % 1000000000;
}

int main(){
    int n;
    std::cin >> n;
    for(int i = 1; i < 10; i++){
        arr[1][i] = 1;
    }
    arr[1][0] = 0;
    arr[2][1] = 1;
    long long sum = 0;
    for (int i = 0; i < 10; i++){
        sum += starenum(n , i);
    }
    std::cout << sum % 1000000000  << std::endl;

    return 0;

}