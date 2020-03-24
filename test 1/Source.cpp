#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

//Roll dice function
int dieroll(void) {
	int ran;
	int roll = 0;
	srand(time(NULL));
	ran = rand() % 6 + 1;
	roll = ran;
	cout << "You rolled a " << ran << "." << endl;
	return ran;
}
//Roll dice for movement card
int draw(void) {
	int ran;
	int roll = 0;
	srand(time(NULL));
	ran = rand() % 6 + 1;
	roll = ran;
	cout << "Your movement card is:" << endl;
	system("pause");
	return ran;
}
//Adds two numbers
int addition(int a, int b)
{
	int r;
	r = a + b;
	return r;
}
//Subtracts two numbers
int subtraction(int a, int b)
{
	int r;
	r = a - b;
	return r;
}
//Compares ship stats plus a dice roll to challenge levels
int compare(int a, int b, int c)
{
	int r;
	int u = a + b;
	if (u >= c)
	{
		r = 1;
	}
	else r = 0;
	cout << "Your total score is " << u << " VS a challenge level of " << c << endl;
	return r;
}
//Gets an integer from player
int getValueFromUser()
{

	int input{};
	cin >> input;

	return input;
}
//Gets a string from player
string getWordFromUser()
{
	string input{};
	cin >> input;

	return input;
}
//Checks storage space in ship
int cargoBay(int a, int b, int c, int d, int e)
{
	int u;
	int r;
	u = a + b + c + d;
	r = e - u;
	return r;
}
//Displays ship stats
void ship(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	int u = d + e + g + h;
	int r = i - u;
	cout << "The WinterShields stats are\nEngineering = " << a << "\nBrute Force = " << b << "\nSocial = " << c << endl;
	cout << "You have " << f << " credits\n" << d << " gas\n" << e << " spare parts" << endl;
	cout << "Your carrying " << g << " cargo\n" << h << " contraband" << endl;
	cout << "You have " << r << " Inventory slots available\n";
}
//Random events
int events(int a, int b)	//a=die roll, b=story
{
	//Integer used to change story path depending on results
	int r = b;
	//Gets dice roll result to see which event to use and tells player what is happening
	if (a == 1 || a == 6)
	{
		cout << "\nEngine trouble\n";
		cout << "Press enter to roll a die\n";
		cin.ignore();
	}
	else if (a == 2 || a == 3)
	{
		cout << "\nSmooth sailing\n";
	}
	else if (a == 4)
	{
		cout << "\nHailed by Alliance vessel\n";
		cout << "If you are caught with contraband you will be fined and loose the contraband you have\n Would you like to allow a search, run for it, or talk them off?\n";
		cout << "Type allow, run, or talk and press enter\n";
	}
	else if (a == 5)
	{
		cout << "\nMysterious Transmission\n";
		cout << "Will you investigate the signal or ignore it and continue on your way?\nEnter investigate or ignore.\n";
		string choice = getWordFromUser();
		if (choice == "investigate")
		{
			r = 8;
		}
		else if (choice == "ignore")
		{
			cout << "You continue on your way\n";
		}

	}
	return r;

}
//Engineering test and result
int eng_num(int& test, int& secondDie, int engineering, int& gas, int e, string congrats)
{
	int r;
	secondDie = dieroll();
	//Perform a test to see if player succeeds in their action
	test = compare(engineering, secondDie, 5);
	//Check to see if player has enough spare parts to fix the ship
	if (e > 0)
	{
		//pass
		if (test == 1)
		{
			cout << congrats << "You fixed the ship\n";
		}
		//fail due to test
		else if (test == 0)
		{
			cout << "You failed to repair the engine. Burn extra fuel to reach your destination\n";
			gas = subtraction(gas, 1);
		}
	}
	//fail due to lack of parts
	else
	{
		cout << "You lack the spare parts to fix up the ship.\n";
		cout << "You failed to repair the engine. Burn extra fuel to reach your destination\n";
		gas = subtraction(gas, 1);
	}
	r = gas;

	return r;
}
//Hailded by Alliance test and results
int event_hailed(int& test, int& secondDie, int bruteForce, int social, int credits, int contraband, string congrats)
{
	//integer for result
	int r = 1;
	//How does the player respond
	string choice = getWordFromUser();
	if (choice == "allow")
	{
		//Check ship for contraband
		if (contraband > 0)
		{
			r = 0;
		}
		else if (contraband <= 0)
		{
			cout << "Be on your way citizen\nPress enter to continue\n";
			cin.ignore();
		}
	}
	else if (choice == "run")
	{
		//Perform a test to see if player succeeds in their action
		cout << "Press enter to roll a die\n";
		cin.ignore();
		secondDie = dieroll();
		test = compare(bruteForce, secondDie, 7);
		//passed test
		if (test == 1)
		{
			cout << congrats << "You escaped the Alliance\n";
		}
		//failed test
		else if (test == 0)
		{
			r = 0;
		}
	}
	//Perform a test to see if player succeeds in their action
	else if (choice == "talk")
	{
		cout << "Press enter to roll a die\n";
		cin.ignore();
		secondDie = dieroll();
		test = compare(social, secondDie, 7);
		//pass
		if (test == 1)
		{
			cout << congrats << "You talked your way out of it\n";
		}
		//fail
		else if (test == 0)
		{
			r = 0; 
		}
	}
	return r;
}

//Main Function
int main()
{
	//Story progress variable
	int story = 1;
	int card;
	int allianceCheck;

	int total;
	int check;
	int test;

	//Dice variables
	int firstDie, secondDie;

	//Spaceship stats
	int engineering = 0;
	int bruteForce = 0;
	int social = 0;
	int gas = 3;
	int parts = 1;
	int credits = 500;
	int cargo = 0;
	int contraband = 0;
	int storage = 8;
	bool alicia = false;
	bool nathaniel = false;
	bool carlos = false;

	int fine;



	//Strings for locations
	string ria = "Ria,A space station in orbit around Boros. A less than reputable port on the edge of Alliance space. Known for it's traffic of goods through it's many ports\n";
	string boros = "Boros, A cold mining world rich in minerals but living here is harsh.\n";
	string chondax = "Chondax, a beautiful agri world. With sprawling fields and wide blue skys, its open beauty belies a sinister danger waiting to strike\n";
	string move = "Your movement card is:\n";

	//Common strings
	string full = "Your ship lacks space for that much cargo\n";
	string broke = "Insuficiant funds\n";
	string invalid = "Invalid entry please try again\n";
	string congrats = "Congratulations you passed!\n";


	//Story
	cout << "\n\n\t\t\t***Welcome to my adventure***\n\n";
	cout << "You are the captain of the WinterShield. A modest sized space ship. Your fuel is low and parts are starting to break down its time to find a job.\n";
	cout << "The goal is to earn 10,000 credits. You will make money by completing jobs. Illegal jobs will pay more but come with the risk of getting caught.\nYour ship starts with eight slots available in your cargo bay this space will be filled with fuel, spare parts, cargo and contraband\n";
	cout << "You will need fuel to fly through space, if this drops below 0 its game over!\nSpare parts will allow you to fix up your ship when it breaks down.\n";
	cout << "Your ship has three stats for overcoming challenges: Engineering, Brute Force, and Social. Your captain and crew will boost these stats\n";
	cout << "Your starting stats are\n";
	ship(engineering, bruteForce, social, gas, parts, credits, cargo, contraband, storage);
	cout << "***Good Luck***\n";
	//Game over loop
	while (story > 0) {
		//Let player choose their captain
		while (story == 1)
		{
			//Reset stats if replaying
			story = 1;
			engineering = 0;
			bruteForce = 0;
			social = 0;
			gas = 3;
			parts = 1;
			credits = 500;
			cargo = 0;
			contraband = 0;
			storage = 8;
			alicia = false;
			nathaniel = false;
			carlos = false;
			//Let player choose their captain
			cout << "You may choose your ships captain.\n";
			cout << "Your choices are Leeman, A grizzled aggressive commander. Horus, a commander of great charisma. Or Kaylee, a shipwise commander \n";
			cout << "Enter Your chosen captains name.\n";
			//Get players choice and adjust ship stats respectively
			string captain = getWordFromUser();
			if (captain == "Leeman" || captain == "leeman")
			{
				bruteForce = addition(bruteForce, 2);
				social = addition(social, 1);
				story = 2;
			}
			else if (captain == "Horus" || captain == "horus")
			{
				social = addition(social, 2);
				bruteForce = addition(bruteForce, 1);
				story = 2;
			}
			else if (captain == "Kaylee" || captain == "kaylee")
			{
				engineering = addition(engineering, 2);
				social = addition(social, 1);
				story = 2;
			}
			else
			{
				cout << invalid << endl;
			}
		}
		//Start of story. Let player choose where to go first
		while (story == 2)
		{
			cout << "\nTo see your ships stats enter \"ship\" when prompted for a word\n";
			cout << "As you move through space you may trigger random events and challenges\n";
			cout << "Now decide where to go\nYour old war buddy Harkin is now a small time smuggler at Ria station, or you could take your chances with the bounty hunters on the planet Boros\nEither choice is 1 fuel point away\n";
			cout << "Would you like to go to Ria Station or the world of Boros? Type Ria for Ria Staition or Boros for Boros and press enter\n";

			string choice = getWordFromUser();
			if (choice == "Ria" || choice == "ria")
			{
				//to move takes fuel
				gas = subtraction(gas, 1);
				//Get an integer for a random event
				firstDie = draw();
				//Set destination to user choice, could still be changed by random event
				story = 3;
				//If a random event changes the story this changes the players destination
				story = events(firstDie, story);
				//Random event start***
				//Checks for what the test was and applies nesessary changes to ship stats
				if (firstDie == 1 || firstDie == 6)
				{
					//Sets gas variable to the outcome determined by the engineering test result
					gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
				}
				else if (firstDie == 4)
				{
					//Set allianceCheck variable based on outcome of test to see if we need to adjust player stats
					allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
					//If you fail the test your fined and loose your contraband
					if (allianceCheck == 0)
					{
						fine = contraband * 100;
						credits = subtraction(credits, fine);
						contraband = 0;
						cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
					}
				}
				//Random event end***
				cout << ria << endl;
			}
			//Same as Ria choice just takes you to Boros instead
			else if (choice == "Boros" || choice == "boros")
			{
				gas = subtraction(gas, 1);
				cin.ignore();
				firstDie = draw();
				story = 4;
				story = events(firstDie, story);
				//Random event start***
				if (firstDie == 1 || firstDie == 6)
				{
					gas = eng_num(test, secondDie, engineering, gas,parts, congrats);
				}
				else if (firstDie == 4)
				{
					allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
					if (allianceCheck == 0)
					{
						fine = contraband * 100;
						credits = subtraction(credits, fine);
						contraband = 0;
						cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
					}
				}
				//Random event end***
			}
			//Allow player to see their ship stats 
			else if (choice == "Ship" || choice == "ship")
			{
				ship(engineering, bruteForce, social, gas, parts, credits, cargo, contraband, storage);
			}
			//Incase the player incorrectly enters their choice
			else
			{
				cout << invalid << endl;
			}
		}
		//On Ria
		while (story == 3)
		{
			cout << "\nWould you like to buy fuel, or spare parts for your ship, or search for harkin?\n Enter fuel, parts, or Harkin\n";
			//Get users choice
			string choice = getWordFromUser();
			if (choice == "Fuel" || choice == "fuel")
			{
				cout << "Fuel tanks each cost 100 credits. How much fuel would you like?\n";
				//How much would you like
				int fuel = getValueFromUser();
				//Cost of fuel
				int fuelCost = fuel * 100;
				//Check to see if player can afford it or not
				total = subtraction(credits, fuelCost);
				if (total < 0)
				{
					cout << broke << endl;
				}
				else if (total >= 0)
				{
					//Adjust player credits
					credits = total;
					//Adjust amount of gas player has
					gas = addition(gas, fuel);
					cout << "You spent " << fuelCost << " leaving you with " << credits << " and you now have " << gas << " fuel points\n";
				}
			}
			else if (choice == "Parts" || choice == "parts")
			{
				cout << "Parts cost 100 credits each. How many parts would you like\n";
				//How many
				int repair = getValueFromUser();
				//Cost
				int repairCost = repair * 100;
				//Check to see if player can afford it or not
				total = subtraction(credits, repairCost);
				if (total < 0)
				{
					cout << broke << endl;
				}
				else if (total >= 0)
				{
					//Adjust player credits
					credits = total;
					//Adjust players spare parts
					parts = addition(parts, repair);
					cout << "You spent " << repairCost << " leaving you with " << credits << " and you now have " << parts << " spare parts\n";
				}

			}
			else if (choice == "Harkin" || choice == "harkin")
			{
				cout << "You quickly track down Harkin on the station. He offers you a job transporting goods to Chondax. He has 4boxes of cargo and 3boxes of contraband.\n You will be paid 100 credits per box of cargo and 200 for each box of contraband you deliver\nChondax is 2 fuel points away\n";
				cout << "Would you like to accept Harkin's job? Enter 1 for yes 2 for no\n";
				int work = getValueFromUser();
				if (work == 1)
				{
					cout << "How many cargo containers would you like? Enter a number between 0 and 4\n";
					int boxes = getValueFromUser();
					//Perform a check to see if there is space on the ship for the players entry
					int check = addition(cargo, boxes);
					total = cargoBay(gas, parts, check, contraband, storage);
					if (total < 0)
					{
						cout << full << endl;
					}
					else
					{
						//Adjust cargo stat accordingly
						cargo = addition(cargo, boxes);
						//Reset variable for output
						total = cargoBay(gas, parts, cargo, contraband, storage);
						cout << "You now have " << cargo << " cargo containers. Leaving you with " << total << " inventory slots left.\n\n";
					}
					cout << "How many contraband containers would you like? Enter a number between 0 and 3\n";
					int contra = getValueFromUser();
					int check2 = addition(contraband, contra);
					total = cargoBay(gas, parts, cargo, check2, storage);
					if (total < 0)
					{
						cout << full << endl;
					}
					else
					{
						contraband = addition(contraband, contra);
						total = cargoBay(gas, parts, cargo, contraband, storage);
						cout << "You now have " << contraband << " contraband containers. Leaving you with " << total << " inventory slots left.\n\n";
					}
				}
				else if (work == 2)
				{
					story = 2;
				}
			}
			else if (choice == "Ship" || choice == "ship")
			{
				ship(engineering, bruteForce, social, gas, parts, credits, cargo, contraband, storage);
			}
			else
			{
				cout << invalid << endl;
			}
			//***End of Ria Where to go next
			cout << "You can continue on to Chondax, go to Boros, or stray here on Ria.\nChondax is 2 fuel points away. Boros is 1 fuel point away. Enter Chondax, Boros, or Ria\n";
			string choice2 = getWordFromUser();
			if (choice2 == "Chondax" || choice2 == "chondax")
			{
				gas = subtraction(gas, 2);
				story = 5;
			}
			else if (choice2 == "Boros" || choice2 == "boros")
			{
				gas = subtraction(gas, 1);
				story = 4;
				story = events(firstDie, story);
				//Random event start***
				if (firstDie == 1 || firstDie == 6)
				{
					gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
				}
				else if (firstDie == 4)
				{
					allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
					if (allianceCheck == 0)
					{
						fine = contraband * 100;
						credits = subtraction(credits, fine);
						contraband = 0;
						cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
					}
				}
				//Random event end***
			}
			else if (choice2 == "Ria" || choice2 == "ria")
			{
				story = 3;
			}
			else if (choice == "Ship" || choice == "ship")
			{
				ship(engineering, bruteForce, social, gas, parts, credits, cargo, contraband, storage);
			}
			else
			{
				cout << invalid << endl;
			}

		}
		//On Boros
		while (story == 4)
		{
			cout << boros << endl;
			cout << "After touching down on the planet Boros you make your way to the mercenary bar. You can check out the job board or search for crew members.\n Enter Board to check the job board or Bar to look for crew.\n";
			//Get user choice look for work or crew
			string choice = getWordFromUser();
			if (choice == "Board" || choice == "board")
			{
				cout << "There is only job available at the moment. Deliver 3 boxes of cargo to Chondax. A planet two fuel points away.\n Enter 1 to accept or 2 to decline.\n";
				//Accept job or not
				int job = getValueFromUser();
				//Integer for number of cargo that job offers
				int boxes = 3;
				//The Boros job
				if (job == 1)
				{
					//variable used to check if there will be inventory space on the ship for the cargo
					check = addition(boxes, cargo);
					total = cargoBay(gas, parts, check, contraband, storage);
					if (total < 0)
					{
						cout << "You don't have enough space on your ship to accept this mission\n";
					}
					else
					{
						//adjust cargo stat
						cargo = addition(cargo, boxes);
						//used for output
						total = cargoBay(gas, parts, cargo, contraband, storage);
						cout << "You now have " << cargo << " cargo containers. Leaving you with " << total << " inventory slots left.\n\n";
						//Ask player what they would like to do next and perform movement event
						cout << "Would you like to look for crew meebers on Boros, fly to Ria, or Continue to Chondax?\n";
						cout << "Ria is 1 fuel point away, Chondax is 2 fuel points away. Enter Boros, Ria or Chondax\n";
						//Users choice
						string choice2 = getWordFromUser();
						if (choice2 == "Boros" || choice2 == "boros")
						{
							story = 4;
						}
						else if (choice2 == "Ria" || choice2 == "ria")
						{
							gas = subtraction(gas, 1);
							story = 3;
							story = events(firstDie, story);
							//Random event start***
							if (firstDie == 1 || firstDie == 6)
							{
								gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
							}
							else if (firstDie == 4)
							{
								allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
								if (allianceCheck == 0)
								{
									fine = contraband * 100;
									credits = subtraction(credits, fine);
									contraband = 0;
									cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
								}
							}
							//Random event end***
						}
						else if (choice2 == "Chondax" || choice2 == "chondax")
						{
							gas = subtraction(gas, 2);
							story = 5;
							story = events(firstDie, story);
							//Random event start***
							if (firstDie == 1 || firstDie == 6)
							{
								gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
							}
							else if (firstDie == 4)
							{
								allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
								if (allianceCheck == 0)
								{
									fine = contraband * 100;
									credits = subtraction(credits, fine);
									contraband = 0;
									cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
								}
							}
							//Random event end***
						}
						else
						{
							cout << invalid << endl;
						}
					}
				}
				//Declined job, ask player where to go next and perform movement events
				else if (job == 2)
				{
					cout << "Would you like to look for crew members on Boros, fly to Ria, or Continue to Chondax?\n";
					cout << "Ria is 1 fuel point away, Chondax is 2 fuel points away. Enter Boros, Ria or Chondax\n";
					string choice2 = getWordFromUser();
					if (choice2 == "Boros" || choice2 == "boros")
					{
						story = 4;
						story = events(firstDie, story);
						//Random event start***
						if (firstDie == 1 || firstDie == 6)
						{
							gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
						}
						else if (firstDie == 4)
						{
							allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
							if (allianceCheck == 0)
							{
								fine = contraband * 100;
								credits = subtraction(credits, fine);
								contraband = 0;
								cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
							}
						}
						//Random event end***
					}
					else if (choice2 == "Ria" || choice2 == "ria")
					{
						gas = subtraction(gas, 1);
						story = 3;
						story = events(firstDie, story);
						//Random event start***
						if (firstDie == 1 || firstDie == 6)
						{
							gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
						}
						else if (firstDie == 4)
						{
							allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
							if (allianceCheck == 0)
							{
								fine = contraband * 100;
								credits = subtraction(credits, fine);
								contraband = 0;
								cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
							}
						}
						//Random event end***
					}
					else if (choice2 == "Chondax" || choice2 == "chondax")
					{
						gas = subtraction(gas, 2);
						story = 5;
						story = events(firstDie, story);
						//Random event start***
						if (firstDie == 1 || firstDie == 6)
						{
							gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
						}
						else if (firstDie == 4)
						{
							allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
							if (allianceCheck == 0)
							{
								fine = contraband * 100;
								credits = subtraction(credits, fine);
								contraband = 0;
								cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
							}
						}
						//Random event end***
					}
					else
					{
						cout << invalid << endl;
					}

				}

			}
			//Look for crew on Boros
			else if (choice == "Bar" || choice == "bar")
			{
				cout << "There are two potential crew members on Boros. Alicia, ex-soldier turned mercenary. A strong backbone for any ship. Or Nathaniel, a savy engineer able to sqeeze a little more life out of even the most decayed ships.\n";
				cout << "Alicia will add two points to your ships brute force and cost 200 credits up front plus 100 credits each time you dock\n";
				cout << "Nathaniel will add two points to your ships engineering and cost 200 credits up front plus 100 credits each time you dock\n";
				cout << "Enter the name of your chosen crew member\n";
				//Get users choice
				string choice = getWordFromUser();
				if (choice == "Alicia" ||choice == "alicia")
				{
					//Check if player can afford to hire the crew and if so adjust credits accordingly
					total = subtraction(credits, 200);
					if (total >= 0)
					{
						alicia = true;
						cout << "Congratulations Alicia joined your crew\n";
						bruteForce = addition(bruteForce, 2);
						credits = total;
					}
					else if (total < 0)
					{
						cout << broke << endl;
					}
				}
				else if (choice == "Nathaniel" || choice == "nathaniel")
				{
					//Check if player can afford to hire the crew and if so adjust credits accordingly
					total = subtraction(credits, 200);
					if (total >= 0)
					{
						nathaniel = true;
						cout << "Congratulations Nathaniel joined your crew\n";
						engineering = addition(engineering, 2);
						credits = total;
					}
					else if (total < 0)
					{
						cout << broke << endl;
					}
				}
			}
			//Display ship stats if the player desires
			else if (choice == "Ship" || choice == "ship")
			{
				ship(engineering, bruteForce, social, gas, parts, credits, cargo, contraband, storage);
			}
			else
			{
				cout << invalid << endl;
			}
			//Ask player where they would like to go next
			cout << "Would you like to stay on Boros, fly to Ria or Chondax? Enter your chosen destination\n";
			//Get player input
			string choice2 = getWordFromUser();
			if(choice2=="Ria"||choice2=="ria")
			{
				gas = subtraction(gas, 1);
				story = 3;
				story = events(firstDie, story);
				//Random event start***
				if (firstDie == 1 || firstDie == 6)
				{
					gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
				}
				else if (firstDie == 4)
				{
					allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
					if (allianceCheck == 0)
					{
						fine = contraband * 100;
						credits = subtraction(credits, fine);
						contraband = 0;
						cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
					}
				}
			}
			else if (choice2 == "Chondax" || choice2 == "chondax")
			{
				gas = subtraction(gas, 2);
				story = 5;
				story = events(firstDie, story);
				//Random event start***
				if (firstDie == 1 || firstDie == 6)
				{
					gas = eng_num(test, secondDie, engineering, gas, parts, congrats);
				}
				else if (firstDie == 4)
				{
					allianceCheck = event_hailed(test, secondDie, bruteForce, social, credits, contraband, congrats);
					if (allianceCheck == 0)
					{
						fine = contraband * 100;
						credits = subtraction(credits, fine);
						contraband = 0;
						cout << "The Alliance found your illicit goods, they took them all and gave you a fine for " << fine << ". Leaving you with " << credits << "credits.\n";
					}
				}
				//Random event end***
			}
			else if (choice == "Boros"||choice=="boros")
			{
				story = 5;
			}
			else if (choice == "Ship" || choice == "ship")
			{
				ship(engineering, bruteForce, social, gas, parts, credits, cargo, contraband, storage);
			}
			else
			{
				cout << invalid << endl;
			}
		}
		//On Chondax
		while (story == 5)
		{
			cout << chondax << endl;
			cout << "To sell cargo type: market.\nTo sell contraband type: underhive\n";
			story = 0;
		}
		//On the mysterious station
		while (story == 8)
		{
			cout << "You made it to the mysterious station!\n";
			story = 0;
		}

	//game over
		if(gas<0)
		{
			cout << "You are becalmed in the vastness of space.\nEnter 1 to play again or 2 to quit";
			int play= getValueFromUser();
			if(play == 1)
			{
				story = 1;
			}
			
		}
	}
	return 0;
}