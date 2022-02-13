//이 문제에서 가로타일 하나를 0 세로타일 하나를 1이라고 하면 1904번 01타일 문제와 동일해진다 0은 혼자올 수없고 1은 혼자올 수 있으므로//

#include <iostream>

int arr[1000001] = {0, };

int pibonaci(int n){
    if(arr[n] != 0){
        return arr[n];
    }
    arr[n] = (pibonaci(n - 1) + pibonaci(n - 2)) % 10007;


    return arr[n];
}

int main(){
    int n;
    std::cin >> n;
    arr[1] = 1;
    arr[2] = 2;

    std::cout << pibonaci(n) << std::endl;

    return 0;

}