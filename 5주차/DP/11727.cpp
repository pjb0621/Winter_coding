//���� ������ Ÿ�Ͽ��� 2���� ä���� ���������� ���� ���簢�����ε� ä�� �� �����Ƿ� ��ȭ���� F(n) = F(n-1) + 2 * F(n - 2)�̴�//

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