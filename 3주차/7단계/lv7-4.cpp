#include <iostream>

int main(){
    int n;
    char input[21];
    std::cin >> n;
    for (int i = 0; i < n; i++){
        int num = 0;
        std::cin >> num;
        int j = 0;
        std::cin >> input;
        while(input[j] != '\0'){
            for (int k = 0; k < num; k++){
                std::cout << input[j];
            }
            j++;
        }
        std::cout << "\n";
    }

    return 0;
}