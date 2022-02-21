#include <iostream>
#include <stack>


int main(){
    std::stack<int> st;
    std::stack<int> len;
    int n;
    std::cin >> n;
    int max = 0;
    for(int i = 0; i < n; i++){
        int input;
        std::cin >> input;
        if(!st.size()){
            st.push(input);
            len.push(i + 1);
        }
        else if(st.top() < input){
            st.push(input);
            len.push(i + 1);
        }
        else{
            while(st.top() >= input){
                int height = st.top();
                len.pop();
                st.pop();
                if(!st.size()){
                    if(max < height * i){
                        max = height * i;
                    }
                    break;      
                }
                else{
                    if(max < height * (i - len.top())){
                        max = height * (i - len.top());
                    }
                }
            }    
            st.push(input);
            len.push(i + 1);

        }
    }
    while(st.size()){
        int height = st.top();
        len.pop();
        st.pop();
        if(!st.size()){
            if(max < height * n){
                max = height * n;
            }
        }
        else{
            if(max < height * (n - len.top()) ){
                max = height * (n - len.top());
            }
        }
    }


    std::cout << max;
}