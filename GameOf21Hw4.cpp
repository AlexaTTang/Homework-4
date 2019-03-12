#include "pch.h"
#include <iostream>
#include <cstdlib> //for rand and srand
#include <ctime> // for the time function

using namespace std;
class Die
{
private:
	int sides; //number of sides
	int value; // the die's value
public:
	Die(int = 6); //constructor
	void roll(); // Rolls the die
	int getSides(); //returns the number of sides
	int getValue(); //returns the die's value
};

//defining member functions of Die class outside of class

//**************************************************
//the construtor accepts an argument for the number 
//of sides for the die, and performs a roll.       
//**************************************************

Die::Die(int numSides)
{
	//get the system time
	unsigned seed = time(0);

	//seed the random number generator
	//initializing randomness
	srand(seed);
	sides = numSides;

	//perform an initial roll
	roll();
}

//************************************************
//the roll member function simulates the rolling 
//of the die                                     
//************************************************

void Die::roll()
{
	//constant for the minimum die value
	const int MIN_VALUE = 1;

	//get a random value for the die 
	value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}

//*******************************************
// the getSides member function returns the 
//number of sides for the die
//*******************************************

int Die::getSides()
{
	return sides;
}

//*******************************************
// the getValue member function returns the 
//value for the die
//*******************************************

int Die::getValue()
{
	return value;
}


int main()
{
	char ans;//char variable to hold the user's answer to prompt
	
	const int DICE_SIDES = 6;//representing the six sided dice
	
	//~~~~~~~~~~~~~~~~~~~~~~
	//delete later
	const int MAX_ROLLS = 5;
	//~~~~~~~~~~~~~~~~~~~~~~

	int CompTotal = 0;
	int PlayerTotal = 0;

	//creating instances of the Die class for player
	Die Playerdie1(DICE_SIDES);
	Die Playerdie2(DICE_SIDES);

	//creating instances of the Die class for the computer
	Die Compdie1(DICE_SIDES);
	Die Compdie2(DICE_SIDES);

	cout << "A game of 21\n" << endl;
	//***********************
	//Computer's roll loop
	//***********************

		//Computer rolling
		//Computer's first roll
		Compdie1.roll();
		Compdie2.roll();
		CompTotal = Compdie1.getValue() + Compdie2.getValue();
		//loop for computer to continue rolling 
		while (CompTotal <= 21)
		{
			//while its total does not sum up to 21 
			//computer rolls again
			Compdie1.roll();
			Compdie2.roll();
			CompTotal = CompTotal + Compdie1.getValue() + Compdie2.getValue();
			//if its total is greater than 21 exit out of while loop
			if (CompTotal > 21)
			{
				break;
			}
		}
		
		
		do
		{
			//prompt asking user if they want to roll
			cout << "Would you like to roll? y/n" << endl;
			cin >> ans;
			//if their answer is y
			if (ans == 'y')
			{
				Playerdie1.roll();
				Playerdie2.roll();
				PlayerTotal = PlayerTotal + Playerdie1.getValue() + Playerdie2.getValue();
				cout << "This is your current total: " << PlayerTotal << endl;
			}
			//if their answer is anything other than y
			//breaks out of the do while loop
			else
			{
				break;
			}
		// while the player's answer is y the loop will run
		}while (ans == 'y');
	
	
	//checks if Player's total is equal to 21 or larger than the computer's total but less than 21
	if (PlayerTotal <= 21 && (CompTotal < PlayerTotal || CompTotal > 21) /* && (CompTotal < 21 || CompTotal > 21)*/)
	{
		cout << "You beat the computer! \n" 
			 << "Your total: " << PlayerTotal << "\n"
			 <<"The computer's total: " << CompTotal 
			 << endl;
	}
	if (PlayerTotal > 21 && (PlayerTotal < CompTotal < 21 || CompTotal == 21))
	{
		cout << "You lost! \n"
			<< "Your total: " << PlayerTotal << "\n"
			<< "The computer's total: " << CompTotal
			<< endl;
	}
	return 0;
}
