#include <iostream>
#include <vector>
#include <algorithm>

int input[50] = {0, };

int makemin(std::vector<int> vec, int n){
    int count = 0,index = 0, i = 0;
    while(input[i]){
        int r = 0, l = 0;
        while(vec[(index + r) % n] != input[i] && vec[((index - l) + n)% n] != input[i]){
            r++;
            l++;
        }
        count += r;
        if(vec[((index - l) + n)% n] == input[i]){
            vec.erase(vec.begin() + (index - r + n) % n); 
            index = (index - r + n) % n;
            if(index == n - 1){
                index = 0;
            }
            n = n - 1;
        }
        else{
            vec.erase(vec.begin() + (index + r) % n); 
            index = (index + r) % n;
            if(index == n - 1){
                index = 0;
            }
            n = n - 1;
        }
        i++;
    }
    return count;
}

int main(){
    std::vector<int> vec;
    int n,k;
    std::cin >> n >> k;
    for (int i = 0; i < k; i++){
        std::cin >> input[i];
    }
    for(int i = 0; i < n; i++){
        vec.push_back(i + 1);
    }
    std::cout << makemin(vec, n) << std::endl;
    
    return 0;
}