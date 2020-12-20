#include <iostream>

/*
This program was tested by trying negative numbers, and values that arent 1-3. 
The program will make the user enter a new number in these scenarios.
*/

void twenty_three() {
char y_n = 'y'; 
	restart: 
	while (y_n == 'y') { 
	int const start_sticks = 23; //declare starting sticks variable, setting the total amount of sticks to 23
	int input; //the user inputted value of sticks they desire to take
	int computer; //the amount of sticks the computer takes
	int remaining_sticks = 23; //the amount of sticks left

	std::cout << "Welcome to 23, the game of strategically picking up sticks!\n"
		<< "First, we start with 23 sticks. You can pick either 1, 2 or 3 sticks to pick up.\n"
		<< "Pick the amount of sticks you would like to take and the game will begin.\n";

	while (remaining_sticks != 0) { //run this loop until the pile of sticks runs out
	try_again: //program repeats if you enter an invalid value
		std::cout << "Your sticks: ";
		std::cin >> input; //input the amount of sticks you want to take
		if (input > 3 || input < 1) { //check if the input is greater than 3 or less than 1 and chastise the user for disregarding the rules if it is
			std::cout << "Hey! I said you could only take 1, 2 or 3 sticks! Try again.\n";
			goto try_again; //jump back to the top of the loop
		}
		if (input > remaining_sticks) { //check if the number of inputted sticks exceeds the amount of remaining sticks and restart the loop if it is
			std::cout << "Sorry, there aren't that many sticks left!\n";
			goto try_again;
		}
		remaining_sticks = remaining_sticks - input; //subtract the user's input from the remaining sticks
		std::cout << "You took: " << input << " sticks.\n"; //echo the amount of sticks the user put in
		std::cout << remaining_sticks << " sticks remain.\n"; //output remaining sticks

		if (remaining_sticks > 4) { //check if the remaining sticks is greater than 4
			computer = 4 - input; //calculation for the amount of sticks the computer takes
		}
		else if (remaining_sticks == 4) { //check if the amount of sticks left is 4
			computer = 3; //computer takes 3 sticks to leave 1
		}
		else if (remaining_sticks == 3) { //check if the amount of sticks left is 3
			computer = 2; //computer takes 2 sticks to leave 1
		}
		else if (remaining_sticks == 2) { //check if the amount of sticks left is 2
			computer = 1; //computer takes 1 sitck to leave 1
		}
		else if (remaining_sticks == 1) { //check if the amount of sticks left is 1
			std::cout << "The computer picked up the final stick.\n"; //tell the player that the computer picked the last stick up
			std::cout << "You won! You just beat our best supercomputer!\n"; //tell the player that they won
			std::cout << "Would you like to play again? (y/n): "; //ask the user if they want to play again
			std::cin >> y_n;
			goto restart; //jump back to the start of the while loop
			
		}
		else { //check if the value is less than 1 (aka. 0)
			std::cout << "You take the final stick...\n"; //tell the player that they took the final stick
			std::cout << "You lost... I guess the robots are taking over after all.\n"; //tell the player that they lost
			std::cout << "Would you like to play again? (y/n): "; 
			std::cin >> y_n;
			goto restart;
		}
		remaining_sticks = remaining_sticks - computer; //subtract the computer's choice of sticks to take from the remaining sticks
		std::cout << "The computer chose to pick up: " << computer << " sticks.\n"; //output the amount of sticks the comouter chose
		std::cout << remaining_sticks << " sticks remain.\n"; //output the amount of sticks that remain


	}
}
	std::cout << "See you later! I hope you had fun :)\n";
}

int main() {
	twenty_three(); 
}