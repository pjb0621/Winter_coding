#include <iostream>

int main(){
    char alpa[8][3] = {{'c','='}, {'c','-'} , {'d','z','='}, {'d','-'}, {'l','j'}, {'n','j'}, {'s','='}, {'z','='}};
    char input[101];
    int k = 0;
    int count = 0;
    std::cin >> input;
    while(input[k] != '\0'){    
        if( input[k+1] == '='){
            count++;
            k += 2;
        }
        else if(input[k+1] == '-'){
            count++;
            k += 2;
        }

        else if(input[k+1] == 'j'){
            if (input[k] == 'l' || input[k] == 'n'){
                count++;
                k+=2;
            }
            else{
                count++;
                k++;
            }
        }

        else if(input[k+2] == '='){
            if(input[k] == 'd' && input[k+1] == 'z'){
                count++;
                k += 3;
            }
            else{
                count++;
                k++;
            }
        }

        else{
            count++;
            k++;
        }
    }

    std::cout << count << std::endl;
}