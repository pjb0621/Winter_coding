//�� �������� ����Ÿ�� �ϳ��� 0 ����Ÿ�� �ϳ��� 1�̶�� �ϸ� 1904�� 01Ÿ�� ������ ���������� 0�� ȥ�ڿ� ������ 1�� ȥ�ڿ� �� �����Ƿ�//

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