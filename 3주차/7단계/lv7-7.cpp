#include <iostream>

int main(){
    char num1[4];
    char num2[4];
    std::cin >> num1 >> num2;
    for (int i = 2; i >= 0; i--){
        if(num1[i] > num2[i]){
            std::cout << num1[2] << num1[1] << num1[0] << std::endl;
            return 0;
        }
        else if (num1[i] == num2[i]){
            continue;
        }
        else {
            std::cout << num2[2] << num2[1] << num2[0] << std::endl;
            return 0;
        }
    }
}