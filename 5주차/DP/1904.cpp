#include <iostream>

int arr[1000001] = {0, };

int pibonaci(int n){
    if(arr[n] != 0){
        return arr[n];
    }
    arr[n] = (pibonaci(n - 1) + pibonaci(n - 2)) % 15746; // �̷��� ���ϸ� �Ǻ���ġ ������ 100��°�ױ��� ���ؾ��ؼ� �Ұ���, �������� ������ �̿��Ͽ� ���//
    // if c = a + b : c % k = a % k + b % k //

    return arr[n];
}

int main(){
    int n;
    std::cin >> n;
    arr[1] = 1;
    arr[2] = 2;

    std::cout << pibonaci(n) % 15746 << std::endl;

    return 0;

}