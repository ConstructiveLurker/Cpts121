/* 
 * Programmer: Tyler Avery
 * Class: Cpts121, Fall 2018
 * Programming Assignment: 05
 * Date: September 27, 2018
 *
 * Description: Has the user play a game of craps.
*/

// printf and scanf
#include <stdio.h>
// srand
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_game_rules (void);
double get_bank_balance (void);
double get_wager_amount (void);
int check_wager_amount (double wager, double balance);
int roll_die (void);
int calculate_sum_dice (int die1_value, int die2_value);
int is_win_loss_or_point (int sum_dice);
int is_point_loss_or_neither (int sum_dice, int point_value);
double adjust_bank_balance (double bank_balance, double wager, int add_or_subtract);
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double wager);

int main (void)
{
	double initial_bank_balance,
	       current_bank_balance,
	       wager;

	int number_rolls = 0,
	    die1_value,
	    die2_value,
	    sum_dice = 0,
	    win_loss_neither,
	    point_value = 0;

	char repeat;

	// Setup
	print_game_rules ();
	initial_bank_balance = get_bank_balance ();
	current_bank_balance = initial_bank_balance;
	srand (time(0));


	// After first roll
	while (current_bank_balance > 0)
	{
		// First Roll
        	do {
			wager = get_wager_amount ();
			
			if (check_wager_amount (wager, current_bank_balance) == 0)
				printf ("Invalid wager.\n");

		} while (check_wager_amount (wager, current_bank_balance) == 0);	

        	number_rolls++;
        	die1_value = roll_die ();
        	die2_value = roll_die ();
        	sum_dice = calculate_sum_dice (die1_value, die2_value);

        	printf ("The sum of your dice is: %d\n", sum_dice);

			win_loss_neither = is_win_loss_or_point (sum_dice);

        	// you get your point value
			if (win_loss_neither == -1)
        	{
                	point_value = sum_dice;
                	printf ("Your point value is: %d\n\n", point_value);

				// play the game
				do
				{	
					number_rolls++;
					die1_value = roll_die ();
					die2_value = roll_die ();
					sum_dice = calculate_sum_dice (die1_value, die2_value);

					printf ("Your current number of rolls is: %d\n", number_rolls);
					printf ("The sum of your dice is: %d\n", sum_dice);
					printf ("Your point value is: %d\n\n", point_value);

				} while ((sum_dice != point_value) && (sum_dice != 7));
			
				win_loss_neither = is_point_loss_or_neither (sum_dice, point_value);

                current_bank_balance = adjust_bank_balance (current_bank_balance, wager, win_loss_neither);
				
				printf ("Your current bank balance is: $%.2f\n", current_bank_balance);

                chatter_messages (number_rolls, win_loss_neither, initial_bank_balance, current_bank_balance, wager);
				
				// continuation
				do 
				{
					printf ("\nDo you want to continue? (Y) / (N)\n");
					scanf (" %c", &repeat);
	
					printf ("\n");
					
					switch (repeat)
					{
						case 'C':
						case 'c':
						case 'S':
						case 's':
							break;
						default:
							printf ("Error: Invalid character.\n");
							break;
					}			
				} while ((!((repeat == 'Y') || (repeat == 'y') || (repeat == 'N') || (repeat == 'n')))
			
			// you don't get a point value
			} else {
				current_bank_balance = adjust_bank_balance (current_bank_balance, wager, win_loss_neither);

				printf ("Your current bank balance is: $%.2f\n", current_bank_balance);
			}
	}

	return 0;
}

// print out the game rules
void print_game_rules (void)
{
	printf ("Game Rules:\n");
	printf ("You roll two six-sided die. \nThe sum of the die is added, and your result is decided there.\n\n");
	printf ("On the first throw, you win if the sum is 7 or 11.\n");
	printf ("You lose if the sum is 2, 3, or 12.\n"); 
	printf ("If the sum is 4, 5, 6, 8, 9, or 10, then the sum becomes the player's \"point\".\n\n");
	printf ("To win, you must continue rolling the dice until you \"make your point.\"\n"); 
	printf ("You lose if you roll a 7 before making the point.\n\n");
}

// set your initial bank balance
double get_bank_balance (void)
{
	double initial_bank_balance;

	printf ("Enter your initial bank balance: ");
	scanf ("%lf", &initial_bank_balance);
	printf ("Your initial bank balance is $%.2f.\n\n", initial_bank_balance);

	return initial_bank_balance;
}

// get the user's wager
double get_wager_amount (void)
{
	double wager;

	printf ("Enter your wager: ");
	scanf ("%lf", &wager);

	return wager;
}

// see if your wager is valid
int check_wager_amount (double wager, double current_bank_balance)
{
	if ((wager > current_bank_balance) || (wager < 0.01))
		return 0;
	else
		return 1;
}

// role the dice
int roll_die (void)
{
	int die;

	die = (rand()%6) + 1;

	return die;
}

// add the sum of your dice
int calculate_sum_dice (int die1_value, int die2_value)
{
	int sum_dice;

	sum_dice = die1_value + die2_value;

	return sum_dice;
}

// First Roll
int is_win_loss_or_point (int sum_dice)
{
	int temp;

	switch (sum_dice)
	{
		case 7:
		case 11:
			printf ("You've won!\n\n");
			temp = 1;
			break;
		case 2:
		case 3:
		case 12:
			printf ("You've lost! The house wins.\n\n");
			temp = 0;
			break;
		case 4:
		case 5:
		case 6:
		case 8:
		case 9:
		case 10:
			temp = -1;
			break;
		default:
			temp = 0;
			break;
	}

	return temp;
}

// After the first roll
int is_point_loss_or_neither (int sum_dice, int point_value)
{
	if (sum_dice == point_value)
		return 1;
	if (sum_dice == 7)
		return 0;
	else
		return -1;
}

// change the bank balance depending on player's result
double adjust_bank_balance (double current_bank_balance, double wager, int win_loss_neither)
{
	if (win_loss_neither == 1)
		current_bank_balance = current_bank_balance + wager;
	else if (win_loss_neither == 0)
		current_bank_balance = current_bank_balance - wager;
	else
		current_bank_balance = current_bank_balance;
	
	return current_bank_balance;
}

void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance, double wager)
{
	// if you lost
	if (win_loss_neither == 0) 
		printf ("Sorry, you busted!\n\n");
	// if you've gained money
	else if (current_bank_balance > initial_bank_balance)
		printf ("You're up big, now's the time to cash in your chips!\n\n");
	// wager dependent
	else if (wager > (current_bank_balance / 2))
		printf ("Oh, you're going for broke, huh?\n\n");
	else if (wager < current_bank_balance)
		printf ("Aw c'mon, take a chance!\n\n");
	else if (number_rolls > 10)
		printf ("Now's the time to bet big! Go big or go home!\n\n");
	else 
		printf ("Take a chance!\n\n");
}
