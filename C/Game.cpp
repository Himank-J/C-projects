#include<stdio.h>
#include<string.h>
int driver(int, int);
int user_move(int, char);
int table_print();
int table_evaluation(char);
int turns_left();
char table[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}};

int main()
{
    int user1_shape=1,user2_shape=0;
    int shape_choice;
    printf("Choose your shape user1: \n");
    printf("Enter 1 for X \n");
    printf("Enter 2 for O \n");
    scanf("%d",&shape_choice);
    if(shape_choice==2){
        user1_shape=0;
        user2_shape=1;
    }
    else if(shape_choice>2 || shape_choice<1)
    {
        printf("Invalid choice, please try again.\n");
        main();
    }
    int start_condition;
    printf("Would you like to have the first turn in the game? : \n");
    printf("Enter 1 for Yes \n");
    printf("Enter 2 for No \n");
    scanf("%d",&start_condition);
    if (start_condition == 2)
        start_condition = 0;
    else if(start_condition>2 || start_condition<1)
    {
        printf("Invalid choice, please try again.\n");
        main();
    }
    printf("The game table would look like this \n");
    printf("You will be required to move the cursor to the postion you want to change using keyboard : \n");
    table_print();
    driver(user1_shape,start_condition);
    int play_again;
    printf("Would you like to play again? \n");
    printf("Enter 1 for Yes \n");
    printf("Enter 2 for No \n");
    scanf("%d",&play_again);
    if (play_again==1){
        int reset = 1;
        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                table[row][col]=reset + '0';
                reset++;
            }
        }
        main();
    }
    else
        return 0;
}
int driver(int user_s,int turn_condition){//hridyesh
char user1_shape,user2_shape;
 int user1_choice,user2_choice;
if(user_s == 1)
{
        user1_shape = 'X';
        user2_shape = 'O';
}
 else
{
        user1_shape = 'O';
        user2_shape = 'X';
}
while(1){
        int check;
        if (turn_condition == 1)
        {
            printf("It is user 1's turn \n");
            printf("Which block would you like to place your shape in? \n");
            scanf("%d",&user1_choice);
            check = user_move(user1_choice,user1_shape);
            if (check==0)
            {
                turn_condition--;
                table_print();
            }
        }
        else if (turn_condition == 0)
        {

            printf("The user 2's turn \n");
            printf("Which block would you like to place your shape in? \n");
            scanf("%d",&user2_choice);
            check = user_move(user2_choice,user2_shape);
             if (check==0)
            {
                table_print();
                turn_condition++;
            }
        }
        if (table_evaluation(user2_shape)==10)
		{
            printf(" user 2 won and the final table looks like: \n ");
            table_print();
            return 0;
        }
        else if(table_evaluation(user2_shape)==-10)
		{
            printf("user1 won and the final table looks like: \n");
            table_print();
            return 1;
        }
        if(turns_left()==0){
            printf("Its a tie and the final table looks like: \n");
            table_print();
            return 0;
        }
    }
}
int table_print(){//parth
    printf("-------------\n");
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(col==0){
                printf("|");
            }
            printf(" %c |",table[row][col]);
        }
        printf("\n");
        printf("-------------");
        printf("\n");
    }
    return 0;
}


int user_move(int user_choice, char user_shape){//ishaan
    char choice = user_choice + '0';
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(table[row][col]==choice){
                table[row][col]=user_shape;
                return 0;
            }
        }
    }
    printf("Entered value is invalid. Please choose a valid choice \n");
    return 1;
}


int table_evaluation(char shape){//kavya
    for(int row=0; row<3; row++){
        if (table[row][0] == table[row][1] &&
            table[row][0] == table[row][2]){
                if (table[row][0] == shape)
                    return (10);
                else
                    return (-10);
        }
    }
    for(int col=0; col<3; col++){
        if (table[0][col] == table[1][col] &&
            table[0][col] == table[2][col]){
                if (table[0][col] == shape)
                    return (10);
                else
                    return (-10);
        }
    }
    if (table[0][0] == table[1][1] &&
        table[0][0] == table[2][2]){
            if (table[0][0] == shape)
                return (10);
            else
                return (-10);
    }
    else if (table[2][0] == table[1][1] &&
             table[2][0] == table[0][2]){
                if (table[2][0] == shape)
                    return (10);
                else
                    return (-10);
        }
    return 0;
}

int turns_left(){//parth
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if ((table[row][col] != 'X')&&(table[row][col] != 'O')){
                return 1;
            }
        }
    }
    return 0;
}


