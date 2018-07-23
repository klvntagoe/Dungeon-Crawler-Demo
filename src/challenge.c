#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <time.h>

//Prints the game exit screen
int printGameExit(int mana, int gold){

        printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"http://amari.azureedge.net/phuket/hotel-photos/superior-room-1.jpg?a\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);
        printf("                        <p>Aww don't you like our game? :(</p>");
        printf("                        <p>Or are you just scared of <b>INVISIDUCK'S CHALLENGE...</b></p>");

        printf("                        <form action=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi\" method=\"get\">");
        printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                <input type=\"hidden\" name=\"command\" value=\"Refresh\"<br>");
        printf("                                <input type=\"submit\" value=\"Return to Room\"><br>");
        printf("                        </form>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");

        return 0;

}

//Prints the game start screen
int printStartPlaying(int mana, int gold, int randNumber, int guessesRemaining){

        printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"http://amari.azureedge.net/phuket/hotel-photos/superior-room-1.jpg?a\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);
	printf("			<p>Guesses Remaining: %d</p>\n", guessesRemaining);
        printf("                        <p>Guess a number between 1 and 50!</p>");
        printf("                        <p>What is your first guess?</p><br>");


        printf("                        <form action=\"http://cs.mcgill.ca/~jnimij/cgi-bin/challenge.cgi\" method=\"get\">");
        printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                <input type=\"text\" name=\"command\" size=\"25\"><br>");
        printf("                                <input type=\"hidden\" name=\"randNumber\" value=\"%d\">", randNumber);
        printf("                                <input type=\"hidden\" name=\"numGuesses\" value=\"%d\">", guessesRemaining);
        printf("                                <input type=\"submit\" value=\"Submit Guess\"><br>");
        printf("                        </form>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");

        return 0;

}

//Prints the game screen after an incorrect guess
int printKeepPlaying(int mana, int gold, int randNumber, int guessesRemaining){

        printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"http://amari.azureedge.net/phuket/hotel-photos/superior-room-1.jpg?a\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);
        printf("                        <p>Guesses Remaining: %d</p>\n", guessesRemaining);
        printf("                        <p>You have guessed wrong!</p>");
        printf("                        <p>Keep trying!</p>");
        printf("                        <p>What is your next guess?</p><br>");


        printf("                        <form action=\"http://cs.mcgill.ca/~jnimij/cgi-bin/challenge.cgi\" method=\"get\">");
        printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                <input type=\"text\" name=\"command\" size=\"25\"><br>");
        printf("                                <input type=\"hidden\" name=\"randNumber\" value=\"%d\">", randNumber);
        printf("                                <input type=\"hidden\" name=\"numGuesses\" value=\"%d\">", guessesRemaining);
        printf("                                <input type=\"submit\" value=\"Submit Guess\"><br>");
        printf("                        </form>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");

        return 0;

}

//Prints the game screen after winning the game
int printWin(int mana, int gold, int randNumber, int guessesRemaining, int roomMana, int roomGold){

        printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"http://amari.azureedge.net/phuket/hotel-photos/superior-room-1.jpg?a\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);
	
	int guessesTaken = 10 - guessesRemaining;

        printf("                        <p>You have guessed the correct number (%d) in %d guesses!</p>", randNumber, guessesTaken);
        printf("                        <p><b>CONGRATULATIONS!</b></p>");
        printf("                        <p>What shall be your prize? Input the amount of mana you'd like to receive and supplemental gold will be provided</p><br>");
	printf("			<p><b>AVAILABLE SPOILS</b> Mana: %d Gold: %d</p><br>", roomMana, roomGold);


        printf("                        <form action=\"http://cs.mcgill.ca/~jnimij/cgi-bin/win.cgi\" method=\"get\">");
        printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                <input type=\"text\" name=\"command\" size=\"25\"><br>");
        printf("                                <input type=\"submit\" value=\"Submit Command\"><br>");
        printf("                        </form>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");

        return 0;

}

//Prints the game screen after losing the game
int printLose(int mana, int gold){

        printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"http://amari.azureedge.net/phuket/hotel-photos/superior-room-1.jpg?a\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);
        printf("                        <p>You have failed the challenge!</p>");
        printf("                        <p>Today just isn't your day!</p>");
        printf("                        <p>What shall you do now?</p><br>");


        printf("                        <form action=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi\" method=\"get\">");
        printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                <input type=\"text\" name=\"command\" size=\"25\"><br>");
        printf("                                <input type=\"submit\" value=\"Submit Command\"><br>");
        printf("                        </form>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");

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


int main(int argc, char *argv[]){

	//Used for random number generation
	srand(time(NULL));

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

	//Gets the command from the input array and assigns its integer value to guess
        int commandIndex = 0;
        for (commandIndex = 0; commandIndex < i; commandIndex++){

                if (strcmp(inputArray[commandIndex], "command") == 0){

                        break;

                }

        }

	char *command = malloc(10);
        command = inputArray[commandIndex+1];
	int guess = atoi(command);

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

	//Gets the random number from the input array
	int randIndex = 0;
	for (randIndex = 0; randIndex < i; randIndex++){

		if (strcmp(inputArray[randIndex], "randNumber") == 0){

			break;

		}

	}

        int generateNumber = atoi(inputArray[randIndex+1]);

	//Gets number of guesses remaining from the input array
	int guessIndex = 0;
        for (guessIndex = 0; guessIndex < i; guessIndex++){

                if (strcmp(inputArray[guessIndex], "numGuesses") == 0){

                        break;

                }

        }

	int guessesRemaining = atoi(inputArray[guessIndex+1]);

	//Generates a random number or keeps the original random number depending on the input string
	int val;

	if (generateNumber == 0){
	
		val = (rand()%50)+1;

	}

	else{

		val = generateNumber;

	}

	//Reads in the room's available resources
	FILE * fp;
        fp = fopen("resources.csv", "r");

        int *roomMana = malloc(10);
        int *roomGold = malloc(10);
        int *occupied = malloc(10);

        fscanf(fp, "%d,%d,%d", roomMana, roomGold, occupied);

        fclose(fp);

	//Prints page head, followed by the appropriate page content
	printHead();

	if ((generateNumber == 0) && (guessesRemaining == 10)){

		printStartPlaying(playerMana, playerGold, val, guessesRemaining);
		guessesRemaining--;

	}

	else if ((strcmp(command, "quit") == 0) || (strcmp(command, "Quit") == 0) || (strcmp(command, "QUIT") == 0)){

		printGameExit(playerMana, playerGold);

	}

	else{

		guessesRemaining--;

		if (guessesRemaining > 0){

			if (guess == val){

				printWin(playerMana, playerGold, val, guessesRemaining, *roomMana, *roomGold);

			}

			else{

				printKeepPlaying(playerMana, playerGold, val, guessesRemaining);	

			}

		}

		else{

			printLose(playerMana, playerGold);

		}

	}

	return 0;
	
}
