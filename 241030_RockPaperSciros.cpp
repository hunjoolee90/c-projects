// Rock Paper Scisors Game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int startGame()
{
	printf("Rock, Paper, Scisors\n");
	printf("Beat the computer!\n");
	printf("1. Rock 2. Paper 3. Scisors\n");
	printf("Choose one:");
	
	int user_choice;
	
	scanf("%d",&user_choice);
	
	if (user_choice==1){
		printf("User chose rock.\n");
	}
	else if (user_choice==2){
		printf("User chose paper.\n");
	}
	else {
		printf("User chose scisors.\n");
	}
	
	return user_choice;
}


int generator()
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
	
	int user_choice = startGame();
	int computer_choice = generator();
	
	
	if(user_choice==computer_choice+1 || (user_choice==1 && computer_choice==3)){
		printf("User won!");
	}
	else if(user_choice==computer_choice){
		printf("Draw");
	}
	else{
		printf("User lost...");
	}
	
	return 0;
}
