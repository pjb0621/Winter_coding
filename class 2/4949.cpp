#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
   
    while(1){
        string arr;
        stack<char> prev;
        getline(cin, arr);
       // cout << arr << endl;
        if(arr[0] == '.' && arr.size() == 1) break;
        int cnt = 0;
        bool flag = false;

        for(int i = 0 ; i < arr.length(); i++){


            if(cnt< 0) break;
            if(arr[i] == '('){
                prev.push('(');
                cnt++;
            }
            else if(arr[i] == '['){
                prev.push('[');
                cnt++;
            }
            else if(arr[i] == ')'){
                if(prev.empty() || prev.top() == '['){
                    flag = true;
                    break;
                }
                else { // 상쇄 되는 경우
                    prev.pop();
                    cnt--;
                }
            }
            else if(arr[i] == ']'){
                if(prev.empty() || prev.top() == '(') {
                    flag = true;
                    
                }
                else{
                    prev.pop();
                    cnt--;
                } 
            }
        }

        if (flag){
            cout << "no" << endl;
        }
        else if(cnt == 0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}