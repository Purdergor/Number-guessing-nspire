#include <libndls.h>
#include <time.h>


int main(){

    srand(time(NULL));

    
    int tries = 0;
    int min = 1;
    int max = 10;
    char *num = NULL;
    char *default_num = "0";
    int answer = rand() % (max - min + 1) + min;
    int num_value = 0;

    show_msgbox("Welcome to the Number Guessing Game!","Hit ok to guess a number between 1 and 10");
    do{

        show_msg_user_input("Guess a number between","Please enter a numer",default_num,&num);
        num_value = atoi(num);
        tries++;


        if(num_value < answer){
            show_msgbox("Too low!","Try again");
            
        }
        else if(num_value > answer){
            show_msgbox("Too high!","Try again.");

        }
        else{
            show_msgbox("Congratulations!", "You guessed the number");
        }

        free(num);
        num = NULL;
    }while(num_value != answer);
    char tries_msg[32];
    sprintf(tries_msg, "You got it in %d tries!", tries);
    show_msgbox("Game Over!", tries_msg);

    return 0;

}