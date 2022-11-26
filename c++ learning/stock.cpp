 /*
    10개의 다른 주식들이 있고, 10명의 사람들이 있음.
    사람들을 주식을 팔거나, 새로 사는게 가능함.(예산 있어야함)

    시뮬레이션 동안 주식들의 가격은 오르고 내림
    시뮬레이션 할때, 프로그램은 어떤 사람이 가장 많은 돈을 가진지 추적함.(the most money acroos their assets)

    The stocks
    TOTAL_STOCK의 값이 존재함. 
    각각의 주식은 랜덤 값으로 초기화됨(0, MAX_STOCK_VALUE]
    시뮬레이션 동안, 주식의 가격은 오르거나, 내림 (changeStockValue() 함수)
    0아래로는 안내려감.

    <The Participants>
    NUM_PEOPLE : 참가자 수
    각각의 참가자는 자기만의 RECORD를 가짐(여러개의 상수값으로 이루어짐)
    RECORD 양식은 다음과 같음
    [ID][BUDGET]][NUM_STOCKS][STOCK_ID_0][STOCK_AM_0]...[STOCK_ID_4][STOCK_AM_4]

    설명을 하자면
    ID는 참가자 고유의 ID (0 <= 범위 <= NUM_PEOPLE -1)
    BUDGET은 참가자 예산임. 이예산안에서 주식 구매 가능 (초기값:STARTING_BUDGET)
    NUM_STOCKS : 참가자가 현재 가지고 있는 서로 다른 종류의 주식 개수
    STOCK_ID_N: 참가자가 가진 N번째 주식의 ID
    STOCK_AM_N: N번째 주식의 양

    -> 아마 예상해보자면 배열 한개에 몰아 넣어야 겠지?
    2차원 배열로 participants[i][j] 면 i는 참가자 j는 전부 record 를 담아둘것.

    알아둬야할건 각각 참가자가 최대 SLOTS_PER_PERSON 만큼 서로 다른 주식을 가질 수 있음.
    그래서 남은칸은 0으로 채워둘것
    그런, 구현할때 사용하지 않느 ㄴ슬롯은 그렇게 중요하지 않다고 함.

    SLOTS_PER_PERSON 이상으로 주식 종류를 가질수는 없다.
    그래서 주식 종류가 초과하려하면? 막아야함.

    <Assets>
    참가자의 자산은 그들이 가진돈 + 주식가치.

    <The Global Participants Array>
    전역 참가자 배열은 참가자 records 에대한 포인터를 저장하고 있음.
    이거는 정렬되어야함!
    즉, 배열 시작부터 참가자의 정보를 출력할때
    첫번째 참가자는 가장 많은 자산을 가지고 있어야함 (자산순 정렬)
    만약 자산 가치가 똑같은 사람이 여러명이면, id 순으로 정렬할 것
    -> 두가지 기준으로 정렬을 해야한다.

    그리고 이 global participants array는 자산의 가치가 바뀔때마다(changeStockValue(), buySTock, sellstock)
    갱신되어야함

    <구현해야할 것>
    init(), buySTock(), sellstock(), changeSTockValue(), getAssets

    */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT 50 // maximum length of input string. You can ignore this one.
#define NUM_PEOPLE 10 // number of participants
#define TOTAL_STOCKS 10 // total number of available stocks
#define SLOTS_PER_PERSON 5 // amount of stock slots per participant
#define STARTING_BUDGET 500 // participant's starting budget
#define MAX_STOCK_VALUE 100 // maximum stock value for initialization


//Meaningful indices into each participant record
enum indices {ID=0, BUDGET=1, NUM_STOCKS=2, STOCK_START=3};

//Global Variables
int *participants[NUM_PEOPLE]; // Global array saving pointers to participant records
int stocks[TOTAL_STOCKS]; // Global array saving values of each stock

//Forward Declarations for convenience
void printRanking();
void printStockValues();
void init(int seed);
int buyStock(int id, int stockId, int amount);
int sellStock(int id, int stockId, int amount);
int changeStockValue(int stockId, int amount);
int getAssets(int *participant);
int getBudget();
int getStockValue();
int findParticipant();
void updateRanking();
int ownsStockAt();

// [GIVEN FUNCTIONS] - These functions are predefined
// If these do not work properly, you have to adjust your implementation.
void printRanking(){
    int currRank = 1;
    int currScore = getAssets(participants[0]);

    for(int i = 1; i <= NUM_PEOPLE; i++){
        if(currScore != getAssets(participants[i-1])){
          currRank = i;
          currScore = getAssets(participants[i-1]);
    }

    printf("%2d.\tParticipant %d\t%4d\t%4d\n", currRank, participants[i-1][ID], participants[i-1][BUDGET], currScore);

    }
}

void printStockValues(){
    for(int i = 0; i < TOTAL_STOCKS; i++)
        printf("Stock #%2d\t%3d\n", i, stocks[i]);
}

// [MANDATORY FUNCTIONS] - You need to implement these

void init(int seed){

}

int buyStock(int id, int stockId, int amount){

    printf("Participant %d is trying to buy %d unit(s) of stock #%d\n", id, amount, stockId);

}

int sellStock(int id, int stockId, int amount){

    printf("Participant %d is trying to sell %d unit(s) of stock #%d\n", id, amount, stockId);

}

int changeStockValue(int stockId, int amount){

    printf("Stock #%d's value is %s by %d\n", stockId, (amount < 0)?"decreased":"increased", abs(amount));

}

int getAssets(int *participant){

}

// [RECOMMENDED FUNCTIONS] - You may or may not implement and use these
// These functions are hints to show you what functions might be helpful
// You can implement the homework without them
// But using functions to break your code into easily understandable parts is good practice
// So, give it a try :)

int getBudget(){}

int getStockValue(){}

// Since the participants need to be ordered by the vlaue of their assets
// doing the sorting in a function might be helpful
void updateRanking(){}

//You will have to find a specific participant in the array quite often
//So abstracting it into a function might help
int findParticipant(){}

//Returning the position of a specific stock might be helpful
int ownsStockAt(){}

//add as many more functions as necessary

//The main is fully commented in case you are curious about how it works
//Parts important for your implementation are marked

int main(){

    int seed;

    scanf("%d", &seed);
    getchar(); //Using getchar() here to consume the leftover newline character from scanf

    init(seed);


    char input[MAX_INPUT]; //place to store the input string
    char *arg[5]; //array to store single arguments
    int running = 1; //flag to determine whether to end the program or not
    int argNum; //number of arguments passed in the input string
    int ret; //variable to save function return values

    //Entering user input loop. What might be the benefit of using a do...while-loop?
    do{

        fgets(input, MAX_INPUT-1, stdin); // reading MAX_INPUT-1 number of characters from stdin
        // to leave space for the null character!

        char input[MAX_INPUT]; //place to store the input string
        char *arg[5]; //array to store single arguments
        int running = 1; //flag to determine whether to end the program or not
        int argNum; //number of arguments passed in the input string
        int ret; //variable to save function return values

        //Entering user input loop. What might be the benefit of using a do...while-loop?
        do{

            fgets(input, MAX_INPUT-1, stdin); // reading MAX_INPUT-1 number of characters from stdin
            // to leave space for the null character!
            // strtok() is a little difficult. This part simply reads the string input and cuts
            // it into the individual arguments, which are stored in the arg array
            // If you are curious about strtok(), check this link: https://man7.org/linux/man-pages/man3/strtok.3.html
            arg[0] = strtok(input, " ");
            for(argNum = 1; argNum < 5; argNum++)
                if(!(arg[argNum] = strtok(NULL, " "))) break;

            //switching based on the first letter of the first argument string
            switch(arg[0][0]){

                case 'q':
                running = 0; break;

                case 'p':
                printf("\n");
                printStockValues();
                printf("\n");
                printRanking();
                break;

                case 's':
                if(argNum < 4) { 
                    printf("Not enough arguments for this command!\n"); break;}
                    //[IMPORTANT] Decide sellStock()'s return value based on the below if statement and the error message
                    ret = sellStock(atoi(arg[1]), atoi(arg[2]), atoi(arg[3]));
                if(!ret)
                    printf("[ERROR] The seller does not own enough stocks!\n");
                else if(ret < 0)
                    printf("[ERROR] The seller does not own this stock!\n");
                    break;

                case 'v':
                    if(argNum < 3) { printf("Not enough arguments for this command!\n"); break;}
                    //[IMPORTANT] Decide changeStockValue()'s return value based on the below if statement and the error message
                    if(!changeStockValue(atoi(arg[1]), atoi(arg[2])))
                    printf("[ERROR] Stock values cannot fall to 0!\n");
                    break;

                default:
                printf("Invalid Command\n"); //Ignore invalid commands
                };
        }while(running);



    printf("Final Ranking:\n");
    printRanking();
    }
}

