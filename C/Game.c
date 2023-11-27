#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
	int Win= (rand() % 1000) + 1;
	int guess;
	int counter=10;
	 srand(time(0));
	
	while (counter != 0) {
		Printf("guess a number between 1 and 100 : \n");
	scanf("%d",guess);
	
	    if (guess < win){
	    		printf("the number is bigger , try again :\n ");
	    			scanf("%d",guess);
	    	
		} else if (guess >win) {
				printf("the number is smaller try again :\n ");
					scanf("%d",guess);
		}else {
			printf("you win!");
		}
		counter --;
	}
 
	return 0;
}
