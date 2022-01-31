#include <iostream>

int main(){
    int arr[26];
    char alpa[26] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int i = 0; i < 26; i++){
        arr[i] = 0;
    }
    int i = 0;
    char input[1000000];
    std::cin >> input;
    while(input[i]){
        if (input[i] >= 97 && input[i] <= 122){
            input[i] -= 32;
        }
        for (int j = 0; j < 26; j++){
            if(input[i] == alpa[j] ){
                arr[j]++;
            }
        }
        i++;
    }
    int max = -1;
    int index = -1;
    for (int k = 0; k < 26; k++){
        if (arr[k] > max){
            max = arr[k];
            index = k;
        }
    }
    for (int k = 0; k < 26; k++){
        if (max == arr[k] && k != index){
            std::cout << "?" << std::endl;

            return 0;
        }
    }

    std::cout << alpa[index] << std::endl;

    return 0;

}