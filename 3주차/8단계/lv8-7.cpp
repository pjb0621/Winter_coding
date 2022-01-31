    #include <iostream>

    int main(){
        int N;
        std::cin >> N;
        int save = N;
        int num_of_5 = 0;
        int num_of_3 = 0;
        int mox = N / 5;
        if (N % 5  == 0){
            num_of_5 = mox;
            std::cout << mox << std::endl;
            return 0;
        }
        N -= 5 * mox;
        while(N % 3 != 0){
            N += 5;
            mox -= 1;
            if ( N > save){
                N = save;
                break;
            }
        }
        if ( N % 3 != 0){
            std::cout << -1 << std::endl;
            return 0;
        }
        num_of_3 = N / 3;
        num_of_5 = mox;
        std::cout << num_of_5 + num_of_3 << std::endl;

        return 0;
        
    }
    