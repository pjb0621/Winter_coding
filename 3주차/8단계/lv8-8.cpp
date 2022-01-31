#include <iostream> 
#include <cstring>

int main(){
    char num1[10001];
    char num2[10001];
    int ans[10001];
    int ia = 10000;
    int c = 0;
    for (int i = 0; i < 10001; i++){
        ans[i] = 0;
    }

    std::cin >> num1 >> num2;
    
    int i1 = strlen(num1) - 1;
    int i2 = strlen(num2) - 1;

    
    while((i1 + 1) && (i2 + 1)){
        ans[ia] = (num1[i1] + num2[i2] + c - 96) % 10;
        if(num1[i1] + num2[i2] - 96 + c > 9){
            c = 1;
        }
        else{
            c = 0;
        }
        i1--;
        i2--;
        ia--;
    }

    if(i1 == -1 && i2 == -1){
        if(c == 1){
            ans[ia] = 1;
        }
    }
    else if(i1 == -1){
        while(i2 + 1){
            ans[ia] = (num2[i2] - 48 + c) % 10;
            if(num2[i2] -48 + c > 9){
                c = 1;
            }
            else{
                c = 0;
            }
            i2--;
            ia--;
        }
        if(c == 1){
            ans[ia] = 1;
        }
        
    }

    else{
        while(i1 + 1){
            ans[ia] = (num1[i1] - 48 + c) % 10;
            if(num1[i1] - 48 + c > 9){
                c = 1;
            }
            else{
                c = 0;
            }
            i1--;
            ia--;
        }
        if(c == 1){
            ans[ia] = 1;
        }
    }

    int i = 0;
    while(ans[i] == 0){
        i++;
    }

    for (int j = i; j < 10001; j++){
        std::cout << ans[j];
    }

    return 0;
    


}

