// solution 참고 : 박윤아 

#include <string>
#include <iostream>
using namespace std;

int main(){

    // 문자열을 입력받음.  
    string str = "";
    cin >> str; 
    int cnt = 0;
    int length = str.length();
    int i = 0;

    // 크로아티아 알파벳 구분 
    // d + z  , l + j , n + j case 분류.
   

    while(i < length){

        if(i <= length - 1){
            
            if(str[i] == 'c' && str[i+1] == '-'){
                cnt ++;
                i += 2;
                continue;
                
            }
            if(str[i] == 'c' && str[i+1] == '='){
                cnt ++;
                i += 2;
                continue;
                
            }
            if(str[i] == 'd' && str[i+1] == '-'){
                cnt ++;
                i += 2;
                continue;
            }
            if(str[i] == 'l' && str[i+1] == 'j'){
                cnt ++;
                i += 2;
                continue;
            }
            if(str[i] == 'n' && str[i+1] == 'j'){
                cnt ++;
                i += 2;
                continue;
            }
            if(str[i] == 's' && str[i+1] == '='){
                cnt ++;
                i += 2;
                continue;
            }
            if(str[i] == 'z' && str[i+1] == '='){
                cnt ++;
                i += 2;
                continue;
            }
            if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '='){
                cnt ++;
                i += 3;
                continue;
            }
            cnt ++;
        }
        
        
        i++;
     
        
    }

    cout << cnt << endl; 


}
