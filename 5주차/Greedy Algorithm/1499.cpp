#include <iostream>
#include <algorithm>

int main(){
    int n,l;
    int count = 0;
    std::cin >> n >> l;
    int length = 1;
    int loc = new int[n];
    for (int i = 0; i < n; i++){
        std::cin >> loc[i];
    }
    std::sort(loc, loc + n);
    int i = 0;
    while(i < n - 1){
        if(length + loc[i+1] - loc[i] > l){
            count++;
            length = 1;
        }
        else{length += loc[i+1] - loc[i];}
        i++;
    }
    count++;


    std::cout << count << std::endl;

    return 0;
}   