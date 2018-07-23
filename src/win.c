#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Subtracts mana won by the player from the room resources
int subtractRoomMana(int takenMana){

        FILE * fp;
        fp = fopen("resources.csv", "r");

        int *mana = malloc(10);
        int *gold = malloc(10);
        int *occupied = malloc(10);

        fscanf(fp, "%d,%d,%d", mana, gold, occupied);

        fclose(fp);

        *mana = *mana - takenMana;

        FILE * fp2;
        fp2 = fopen("resources.csv", "w+");

        fprintf(fp2, "%d,%d,%d", *mana, *gold, *occupied);

        fclose(fp2);

        return 0;
}

//Subtracts gold won by the player from the room resources
int subtractRoomGold(int takenGold){

        FILE * fp;
        fp = fopen("resources.csv", "r");

        int *mana = malloc(10);
        int *gold = malloc(10);
        int *occupied = malloc(10);

        fscanf(fp, "%d,%d,%d", mana, gold, occupied);

        fclose(fp);

        *gold = *gold - takenGold;

        FILE * fp2;
        fp2 = fopen("resources.csv", "w+");

        fprintf(fp2, "%d,%d,%d", *mana, *gold, *occupied);

        fclose(fp2);

        return 0;

}

//Prints page head
int printHead(){

        printf("Content-Type:text/html\n\n");

        printf("<html>");

        printf("        <head>");

        printf("                <title>Roooooom</title>");

        printf("        </head>");

        return 0;

}

//Prints error page if player tries to take too much mana
int printGreedy(int mana, int gold){

	printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"http://www.grf-football.co.uk/wp-content/uploads/2016/10/greed-2020epmellon.wordpress.com_.jpg\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);

        printf("                        <p>You're only allowed to take a total of 5 items (you're being too <b>GREEDY</b>)</p>");
	
	printf("			<form>");
	printf("				<input type=\"button\" value=\"I'M NOT GREEDY\" onClick=\"history.go(-1);return true;\"");
	printf("			</form>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");



	return 0;

}

//Prints summary page once mana and gold have been added to the player's inventory
int printWin(int mana, int gold){

        printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"http://amari.azureedge.net/phuket/hotel-photos/superior-room-1.jpg?a\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);

        printf("                        <p>Your mana and gold have been added to your inventory</p>");


        printf("                        <form action=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi?inventory=%%%d2C%d&commandBox=0&randNumber=0&numGuesses=10\" method=\"get\">", mana, gold);
        printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                <input type=\"hidden\" name=\"command\" value=\"Refresh\">");
        printf("                                <input type=\"submit\" value=\"Return to Room\"><br>");
        printf("                        </form>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");

        return 0;

}


int main(int argc, char *argv[]){

        //Creates copies of the input query for use with tokenizers

        char *userInput = malloc(200);
        userInput = getenv("QUERY_STRING");
        char *token = malloc(200);
        char *token2 = malloc(200);

        size_t inputLength = (strlen(userInput)+1);
        char *userInputCopy1 = malloc(inputLength);
        char *userInputCopy2 = malloc(inputLength);

        strcpy(userInputCopy1, userInput);
        userInputCopy1[inputLength-1] = '\0';
        strcpy(userInputCopy2, userInput);
        userInputCopy2[inputLength-1] = '\0';

	//Tokenizes the input string into simple arguments
        int i = 1;
        int j = 1;

        token = strtok(userInputCopy1, "=&+?");

        while (token != NULL){


                i++;
                token = strtok(NULL, "=&+?");

        }

	//Creates an input array with the tokenized query
        char *inputArray[i];

        token2 = strtok(userInputCopy2, "=&+?");

        inputArray[0] = token2;

        while (token2 != NULL){

                token2 = strtok(NULL, "=&+?");
                inputArray[j] = token2;
                j++;

        }

	//Gets the command from the input array, then assigns its value to the manaTaken variable
	int commandIndex = 0;
        for (commandIndex = 0; commandIndex < i; commandIndex++){

                if (strcmp(inputArray[commandIndex], "command") == 0){

                        break;

                }

        }

        char *command = malloc(10);
        command = inputArray[commandIndex+1];
	
	int manaTaken = atoi(command);

	//Gets the inventory from the input array
        int invIndex = 0;
        for (invIndex = 0; invIndex < i; invIndex++){

                if (strcmp(inputArray[invIndex], "inventory") == 0){

                        break;

                }

        }

	//Parses inventory into mana and gold
        char *inventory = malloc(10);
        inventory = inputArray[invIndex+1];

        char *token3 = malloc(10);
        token3 = strtok(inventory, "%");
        int playerMana = atoi(token3);

        token3 = strtok(NULL, "");
        char* gold = malloc(5);
        sscanf(token3, "2C%s", gold);
        int playerGold = atoi(gold);

	//Prints page head, followed by the appropriate page content depending on the user's input
        printHead();

	if (manaTaken > 5){

		printGreedy(playerMana, playerGold);

	}

	else if (manaTaken < 0){

		printf("Invalid input");

	}

	else{

		int goldTaken = 5 - manaTaken;

		subtractRoomMana(manaTaken);
		playerMana = playerMana + manaTaken;

		subtractRoomGold(goldTaken);
		playerGold = playerGold + goldTaken;

				
		printWin(playerMana, playerGold);

	}

	return 0;

}




