#include <iostream>

int main(){
    char input[1000001];
    int key = 0;
    int count = 0;
    int i = 0;
    std::cin.getline(input, 1000001);
    while(input[i] != '\0'){
        if (input [i] != ' ' && key == 0){
            count++;
            key = 1;
        }
        else if (input[i] == ' '){
            key = 0;
        }
        i++;
    }

    std::cout << count;

    return 0;
}