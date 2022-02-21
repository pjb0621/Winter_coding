#include <iostream>
#include <string>
#include <stack>    

int main(){
    std::stack<char> st;
    std::stack<int> plst;
    std::string input;
    std::cin >> input;
    plst.push(0);
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '*' || input[i] == '/'){
            if(!plst.top()){
                st.push(input[i]);
                plst.top()++;
            }
            else if(st.top() == '+' || st.top() == '-'){
                st.push(input[i]);
                plst.top()++;

            }
            else{
                int k = plst.top();
                for(int i = 0; i < k; i++){
                    if(st.top() == '+' || st.top() == '-'){
                        break;
                    }
                    std::cout << st.top();
                    st.pop();
                    plst.top()--;
                }
                st.push(input[i]);
                plst.top()++;
            }
        }
        else if(input[i] == '+' || input[i] == '-'){
            if(!plst.top()){
                st.push(input[i]);
                plst.top()++;
            }
            else{
                int k = plst.top();
                for(int i = 0; i < k; i++){
                    std::cout << st.top();
                    st.pop();
                }
                st.push(input[i]);
                plst.top() = 1;
            }
        }
        else if(input[i] == '('){
            plst.push(0);
        }
        else if(input[i] == ')'){
            int k = plst.top();
            for(int i = 0; i < k; i++){
                std::cout << st.top();
                st.pop();
            }
            plst.pop();
        }
        else{
            std::cout << input[i];
        }
    }

    int k = st.size();
    for(int i = 0; i < k; i++){
                    std::cout << st.top();
                    st.pop();
        }

    return 0;
}