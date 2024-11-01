//I wanted to improve the rock paper scisors game I uploaded on 2401030.
//(1) Repeat game until user decides to stop
//(2) Throw an error message when user enters invalid choice


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int gameUser() 
{
	printf("Rock, Paper, Scisors\n");
	printf("Beat the computer!\n");
	printf("1. Rock 2. Paper 3. Scisors\n");
	printf("Choose one:");
	
	int user_choice;
	
	scanf("%d",&user_choice);
	
	if (user_choice==1){
		printf("User chose rock.\n");
		return user_choice;
	}
	else if (user_choice==2){
		printf("User chose paper.\n");
		return user_choice;
	}
	else if (user_choice==3){
		printf("User chose scisors.\n");
		return user_choice;
	}
	else {
		return 0;
	}
}


int gameComputer() 
{
	srand(time(NULL));
	int computer_choice;
	
	computer_choice = rand()%3+1;
	
	if (computer_choice==1){
		printf("Computer chose rock.\n");
	}
	else if (computer_choice==2){
		printf("Computer chose paper.\n");
	}
	else {
		printf("Computer chose scisors.\n");
	}
	
	return computer_choice;
}


int main() 
{
    char play_again;
    int user_choice;
    do {
		int user_choice = gameUser();
		
		if (user_choice==0){
			printf("Invalid Choice.\n");
		}
		
		else{
			int computer_choice = gameComputer();     
			
	      		if (user_choice == computer_choice) {
	            	    printf("Draw\n");
	                } 
			else if ((computer_choice % 3) + 1 == user_choice) {
	                   printf("User won!\n");
	                } 
			else {
	                   printf("User lost...\n");
	                }
		}

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);  
        play_again = toupper(play_again); 
        
    } while (play_again == 'Y'); 

    printf("Thanks for playing!\n");
    return 0;
}
