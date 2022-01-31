#include <iostream> 

int main(){
    char alpa[10][4] = { {0,0,0,0}, {'A','B','C',0}, {'D','E','F',0}, {'G','H','I',0}, {'J','K','L',0},{'M','N','O',0},{'P','Q','R','S'}, {'T','U','V',0},
    {'W','X','Y','Z'},{0,0,0,0}};
    char input[16];
    std::cin >> input;
    int i = 0;
    int time = 0;
    while(input[i] != '\0'){
        for(int j = 0; j < 10; j++){
            for (int k = 0; k < 4; k++){
                if (alpa[j][k] == input[i]){
                    time += j+2;
                    break;
                }
            }
        }
        i++;
    }

    std::cout << time << std::endl;

    return 0;
}