#include <iostream>

int main(){
    int n = 0;
    int count = 0;
    std::cin >> n;
    char input[101];
    char temp[26];
    for (int i = 0; i < n; i++){
        for (int i = 0; i < 26; i++){
            temp[i] = ' ';
        }
        std::cin >> input;
        int k = 0;
        int index = 0;

        bool while_flag = false;
        while(input[k] != '\0'){
            for (int i = 0; i < index; i++){
                if (input[k] == temp[i]){
                    while_flag = true;
                    break;
                }
            }
            if(input[k] != input[k+1]){
                temp[index] = input[k];
                index++;
            }
            k++;
        }
        if(while_flag == false){
            count++;
        }

    
    }

    std::cout << count << std::endl;
}