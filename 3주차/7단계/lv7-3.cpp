#include <iostream>

int main(){
    char input[101];
    char alpa[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::cin >> input;
    for (int i = 0; i < 26; i++){
        int j = 0;
        while(true){
            if (alpa[i] == input[j]){
                std::cout << j << ' ';
                break;
            }
            j++;
            if (input[j] == '\0'){
                std::cout << -1 << ' ';
                break;
            }
        }

    }

    return 0;

}