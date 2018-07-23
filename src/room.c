#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Prints the lose screen if mana reaches 0
int printLoseScreen(int mana, int gold){

        printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"https://s-media-cache-ak0.pinimg.com/originals/4b/64/67/4b6467309bdfadfd648c30c9f9aebc72.png\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);
        printf("                        <p>Your mana has been  <b>depleted to 0!</b></p>");
        printf("                        <p><b>YOU HAVE BEEN BESTED BY THE DUNGEON CRAWLER! GG EZ</b></p>");
        printf("                        <p>Thanks for playing (Hopefully the baby ducks help you feel better!)</p><br>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");

        return 0;

}

//Prints the win screen if gold reaches 100
int printWinScreen(int mana, int gold){

	printf("        <body>");

        printf("                <center>");

        printf("                        <img src=\"http://www.tourismmerritt.com/images/com_eventbooking/FireworksSM.jpg\" width=80%% height=80%%>");

        printf("                        <p>Current Mana: %d</p>\n", mana);
        printf("                        <p>Current Gold: %d</p>\n", gold);
        printf("                        <p>You have collected <b>100 gold pieces!</b></p>");
        printf("                        <p><b>YOU HAVE BESTED THE DUNGEON CRAWLER! CONGRATULATIONS</b></p>");
        printf("                        <p>Thanks for playing!</p><br>");

        printf("                </center>");
        printf("        </body>");
        printf("</html>");

	return 0;

}

//Adds mana to the room's resources
int addRoomMana(int droppedMana){

	FILE * fp;
        fp = fopen("resources.csv", "r");

        int *mana = malloc(10);
        int *gold = malloc(10);
        int *occupied = malloc(10);

        fscanf(fp, "%d,%d,%d", mana, gold, occupied);

        fclose(fp);

        *mana = *mana + droppedMana;

        FILE * fp2;
        fp2 = fopen("resources.csv", "w+");

        fprintf(fp2, "%d,%d,%d", *mana, *gold, *occupied);

        fclose(fp2);

	return 0;
}

//Updates whether the room is occupied or not
int roomOccupied(int roomOccupied){

	FILE * fp;
        fp = fopen("resources.csv", "r");

        int *mana = malloc(10);
        int *gold = malloc(10);
        int *occupied = malloc(10);

        fscanf(fp, "%d,%d,%d", mana, gold, occupied);

        fclose(fp);

        if (!(roomOccupied == 0)){

		*occupied = 1;

	}

	else{

		*occupied = 0;

	}

        FILE * fp2;
        fp2 = fopen("resources.csv", "w+");

        fprintf(fp2, "%d,%d,%d", *mana, *gold, *occupied);

        fclose(fp2);

	return 0;
}

//Adds gold to the room's resources
int addRoomGold(int droppedGold){

	FILE * fp;
	fp = fopen("resources.csv", "r");

	int *mana = malloc(10);
	int *gold = malloc(10);
	int *occupied = malloc(10);

	fscanf(fp, "%d,%d,%d", mana, gold, occupied);

	fclose(fp);

	*gold = *gold + droppedGold;

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

//Prints the initial challenge accepted screen
int printPlayBody(int mana, int gold){

	printf("        <body>");

	printf("                <center>");

	printf("                        <img src=\"http://amari.azureedge.net/phuket/hotel-photos/superior-room-1.jpg?a\" width=80%% height=80%%>");

	printf("                        <p>Current Mana: %d</p>\n", mana);
	printf("                        <p>Current Gold: %d</p>\n", gold);
	printf("                        <p>You have accepted the challenge!</p>");
	printf("                        <p>For this challenge, you must guess a random number between 1 and 50 in just <b>10 TRIES</b></p>");
	printf("                        <p><b>ARE YOU READY TO PLAY?</p><br>");


	printf("                        <form action=\"http://cs.mcgill.ca/~jnimij/cgi-bin/challenge.cgi?inventory=%%%d2C%d&command=0&randNumber=0&numGuesses=10\" method=\"get\">", mana, gold);
	printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                <input type=\"hidden\" name=\"command\" value=\"0\">");
        printf("                                <input type=\"hidden\" name=\"randNumber\" value=\"0\">");
        printf("                                <input type=\"hidden\" name=\"numGuesses\" value=\"10\">");
	printf("                                <input type=\"submit\" value=\"Let's Go!\">");
	printf("                        </form>");

        printf("                        <form action=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi?inventory=10%%%d2C%d&command=refresh\" method=\"get\">", mana, gold);
        printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                <input type=\"hidden\" name=\"command\" value=\"Refresh\">");
        printf("                                <input type=\"submit\" value=\"Naaaaaaah\"><br>");
        printf("                        </form>");



	printf("                </center>");
	printf("        </body>");
	printf("</html>");

	return 0;

}

//Prints the room exit screen
int printExitBody(int mana, int gold){

	printf("        <body>");

	printf("                <center>");

	printf("                        <img src=\"https://energy.gov/sites/prod/files/styles/borealis_default_hero_respondlarge/public/door_5481543.jpg?itok=dIFozoNp\"");

	printf("                        <p><br>Aww... sorry to see you go...</p>");
	printf("                        <p>Come play again soon!</b></p>");
	printf("			<p>You finished with %d mana and %d gold</p>\n", mana, gold);

	printf("                </center>");
	printf("        </body>");
	printf("</html>");

	return 0;

}

//Prints the default room screen
int printDefaultBody(int mana, int gold){

	printf("        <body>");

	printf("                <center>");

	printf("                        <img src=\"http://amari.azureedge.net/phuket/hotel-photos/superior-room-1.jpg?a\" width=80%% height=80%%>");

	printf("                        <p>Current Mana: %d</p>\n", mana);
	printf("                        <p>Current Gold: %d</p>\n", gold);

	printf("                        <p>You come to a nice room and find a comfy bed</p>");
	printf("			<p>Sitting on the bed you notice an <b>INVISIBLE DUCK</b></p>");
	printf("                        <p>It quacks ominously as it offers you a <b>CHALLENGE</b></p>");
	printf("                        <p>What will you do? (<b>Drop</b> some gold, <b>Play</b> the game, <b>Exit</b> (run away), <b>Refresh</b> the screen)</p><br>");

	printf("                        <form action=\"http://cs.mcgill.ca/~lhovon/cgi-bin/transporter.py\" method=\"post\">");
	printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
	printf("                                <input type=\"hidden\" name=\"url\" value=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi?command=Refresh\">");
	printf("                                <input type=\"submit\" name=\"transport\" value=\"North\">");
	printf("                        </form>");

	printf("			<table>");
        printf("				<td>");

        printf("                        		<form action=\"http://cs.mcgill.ca/~nladd/cgi-bin/transporter.py\" method=\"get\">");
        printf("                                		<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                		<input type=\"hidden\" name=\"url\" value=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi?command=Refresh\">");
        printf("                                		<input type=\"submit\" name=\"transport\" value=\"West\">");
        printf("                        		</form>");

	printf("				</td>");
	printf("				<td></td>");
        printf("                                <td></td>");
        printf("                                <td></td>");
        printf("                                <td></td>");
        printf("                                <td></td>");
	printf("                                <td>");

        printf("                                        <form action=\"cs.mcgill.ca/~msukka1/cgi-bin/transporter.py\" method=\"get\">");
        printf("                                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
        printf("                                                <center><input type=\"text\" name=\"command\" size=\"25\"></center><br>");
        printf("                                                <input type=\"hidden\" name=\"randNumber\" value=\"0\">");
        printf("                                                <input type=\"hidden\" name=\"numGuesses\" value=\"10\">");
        printf("                                                <center><input type=\"submit\" value=\"Submit Command\"></center><br>");
        printf("                                        </form>");
        printf("				</td>");

        printf("                                <td></td>");
        printf("                                <td></td>");
        printf("                                <td></td>");
        printf("                                <td></td>");
        printf("                                <td></td>");
        printf("                                <td>");

	printf("                        		<form action=\"http://cgi.cs.mcgill.ca/~hnguye124/cgi-bin/transporter.py\" method=\"get\">");
	printf("                                		<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
	printf("                                		<input type=\"hidden\" name=\"url\" value=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi?command=REFRESH\">");
	printf("                                		<input type=\"submit\" name=\"transport\" value=\"East\">");
	printf("                        		</form>");
        printf("                                <td>");
        printf("			</table>");

	printf("                        <form action=\"http://cs.mcgill.ca/~walhas1/cgi-bin/transporter.py\" method=\"get\">");
	printf("                                <input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", mana, gold);
	printf("                                <input type=\"hidden\" name=\"url\" value=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi?command=REFRESH\">");
	printf("                                <input type=\"submit\" name=\"transport\" value=\"South\">");
	printf("                        </form>");

	printf("                </center>");
	printf("        </body>");
	printf("</html>");

	return 0;

}

int main(int argc, char *argv[]){

        //Updates the room's occupied status, then creates copies of the input query for use with tokenizers

	roomOccupied(1);
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

	//Gets the command from the input array
	int commandIndex = 0;
        for (commandIndex = 0; commandIndex < i; commandIndex++){

                if (strcmp(inputArray[commandIndex], "command") == 0){

                        break;

                }

        }

        char *command = malloc(10);
        command = inputArray[commandIndex+1];
	
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

	if (playerGold >= 100){

		printWinScreen(playerMana, playerGold);

	}

	else if (playerMana <= 0){

		printLoseScreen(playerMana, playerGold);

	}

        else if (strcmp(command, "Play") == 0 || strcmp(command, "PLAY") == 0 || strcmp(command, "play") == 0){

		printPlayBody(playerMana, playerGold);

        }

        else if (strcmp(command, "Exit") == 0 || strcmp(command, "EXIT") == 0 || strcmp(command, "exit") == 0){

		//Sets room to unoccupied, then prints exit page
		roomOccupied(0);
		printExitBody(playerMana, playerGold);
		addRoomMana(playerMana);
		addRoomGold(playerGold);

        }
        
	else if (strcmp(command, "Drop") == 0 || strcmp(command, "DROP") == 0 || strcmp(command, "drop") == 0){

		//Decrements player gold by the specified amount, then increments player mana by half the amount
                int dropAmount = atoi(inputArray[commandIndex+2]);
                playerGold = playerGold - dropAmount;

		int manaIncrease = (dropAmount/2);
		playerMana = playerMana + manaIncrease;

		//If the player does not have enough gold to drop, undoes the changes and prints an error page
                if (playerGold < 0){
			
			playerMana = playerMana - manaIncrease;
			playerGold = playerGold + dropAmount;

			printf("<center><img src=\"http://staffingstream.wpengine.netdna-cdn.com/wp-content/uploads/2013/09/92407260.jpg\" width=100%% height=100%%<br><br>");
                        printf("You don't have enough gold to drop...<br>");
			printf("<a href=\"http://cs.mcgill.ca/~jnimij/cgi-bin/room.cgi?inventory=%d%%2C%d&command=refresh\"> <input type=\"submit\" value=\"Go Back\"></form>", playerMana, playerGold);

                }
		
		else{
		
			printDefaultBody(playerMana, playerGold);
			addRoomGold(dropAmount);

		}

        }

        else if (strcmp(command, "Refresh") == 0 || strcmp(command, "REFRESH") == 0 || strcmp(command, "refresh") == 0){

                printDefaultBody(playerMana, playerGold);

        }

        else{

                printf("Invalid input");

        }

        return 0;
}
