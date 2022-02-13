//제일 오른쪽 타일에서 2개를 채울경우 나뉘어있지 않은 정사각형으로도 채울 수 있으므로 점화식은 F(n) = F(n-1) + 2 * F(n - 2)이다//

#include <iostream>

int arr[1000001] = {0, };

int pibonaci(int n){
    if(arr[n] != 0){
        return arr[n];
    }
    arr[n] = (pibonaci(n - 1) + 2 * pibonaci(n - 2)) % 10007;


    return arr[n];
}

int main(){
    int n;
    std::cin >> n;
    arr[1] = 1;
    arr[2] = 3;

    std::cout << pibonaci(n) << std::endl;

    return 0;

}