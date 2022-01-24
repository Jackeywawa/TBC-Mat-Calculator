#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int input = 1;
	int method;
	int amount;
	double craftCalc; //calculates decimal value to be rounded for true craft amount
	double craftRoundUp; //used for item based method
	double craftRoundDown; //used for mat based method
	double craftRawReverse;
	int CEYield; //number of items made from 1 craft
	int matPerCraft; //amount of method mat needed for 1 craft.
	string itemName;
	vector <string> partNames;
	vector <int> partCost;

	
	cout << "Welcome to the TBC Material Calculator!\n";
	
	while (input != 0)
	{
		cout << "\nPlease select an item to calculate mats for. Enter '0' if you wish to stop.\n";  //make this into a menu function
		cout << "1. Fel Iron Bomb\n"; //include blasting powder calculations in the future
		cout << "2. Super Sapper Charge\n";
		cout << "3. Elemental Blasting Powder\n";
		cout << "4. Arcane Bomb\n";
		cin >> input;
		switch (input) //could have a function that has a switch that takes a char parameter?
		{
#pragma region fel iron bomb
		case 1:
			matPerCraft = 5; //5 fel iron bars per craft
			CEYield = 4; //4 bombs per craft
			itemName = "Fel Iron Bomb";
			partNames.push_back("Fel Iron Bar");
			partCost.push_back(2); //bar - element 0
			partNames.push_back("Fel Iron Casing");
			partCost.push_back(3); //casing - element 1
			partNames.push_back("Fel Iron Bolts");
			partCost.push_back(2); //bolts - element 2
			partNames.push_back("Elemental Blasting Powder");
			partCost.push_back(2); //mote of earth - element 3
			partCost.push_back(1); //mote of fire - element 4
		reset:
			cout << "Do you wish to calculate using Bar # (1) or Bomb # (2)?\n"; //function for output and input
			cin >> method;
			if (method == 1) //method function for each item? contain math for each method within function. Have multiple functions based on # of methods
			{
				cout << "Please enter the amount of bars you are using:\n"; //1st cout string
				cin >> amount;
				/*while (!isdigit(amount))
				{
					cout << "Please enter a whole number value:\n";
					cin >> amount;
				}*/
				craftCalc = (double)amount / matPerCraft;
				//craftRoundUp = ceil(craftCalc);
				craftRoundDown = floor(craftCalc);
				double yield = CEYield * craftRoundDown;
				cout << "You will make " << yield << " " << itemName << endl;
				cout << "You will need " << craftRoundDown << " " << partNames[1] << " crafts and " << craftRoundDown * partCost[2] << " " << partNames[2] << " crafts.\n";
			}
			else if (method == 2)
			{
				cout << "Please enter the amount of bombs you want:\n"; //2nd cout string
				cin >> amount;
				/*while (!isdigit(amount))
				{
					cout << "Please enter a whole number value:\n";
					cin >> amount;
				}*/
				craftCalc = (double)(amount / CEYield) * matPerCraft; //calculates amount of bomb crafts
				craftRoundUp = ceil(craftCalc);
				craftRawReverse = craftCalc / matPerCraft;
				//craftRoundUp = ceil(craftCalc);
				cout << "You will need " << craftRoundUp << " " << partNames[0] << " which is smelted with " << craftRoundUp * partCost[0] << " Ores.\n";
				cout << "You will need " << craftRawReverse << " " << partNames[1] << " crafts and " << craftRawReverse * partCost[2] << " " << partNames[2] << " crafts.\n";
			}
			else if (method == 0) {
				cout << "Exiting section...\n";
				break;
			}
			else
			{
				cout << "No method selected.\n";
				goto reset;
			}
			break;
#pragma endregion
		case 2: 
			cout << "Sorry, this is not available yet!\n";
			break;
		case 3:
			cout << "Sorry, this is not available yet!\n";
			break;
#pragma region arcane bomb
		case 4:
			matPerCraft = 3; //3 thorium bars per craft
			CEYield = 3; //3 bombs per craft
			itemName = "Arcane Bomb";
			partNames.push_back("Thorium Bar");
			partCost.push_back(1); //bar - element 0
			partNames.push_back("Delicate Arcanite Converter");
			partCost.push_back(1); //arcanite bar - element 1
			partCost.push_back(1); //ironweb spider silk - element 2
			partNames.push_back("Runecloth");
			partCost.push_back(1); //Runecloth - element 3
			partNames.push_back("Arcanite Bar");
			partNames.push_back("Ironweb Spider Silk");
			partNames.push_back("Arcane Crystal");
			partCost.push_back(1); //arcane crystal - element 4
			partCost.push_back(1); //thorium bar for arc bar - element 5
		reset4:
			cout << "Do you wish to calculate using Bar # (1) or Bomb # (2)?\n"; //function for output and input
			cin >> method;
			if (method == 1) //method function for each item? contain math for each method within function. Have multiple functions based on # of methods
			{
				cout << "Please enter the amount of bars you are using:\n"; //1st cout string
				cin >> amount;
				/*while (!isdigit(amount))
				{
					cout << "Please enter a whole number value:\n";
					cin >> amount;
				}*/
				craftCalc = (double)amount / matPerCraft;
				//craftRoundUp = ceil(craftCalc);
				craftRoundDown = floor(craftCalc);
				double yield = CEYield * craftRoundDown;
				cout << "You will make " << yield << " " << itemName << endl;
				cout << "You will need " << craftRoundDown << " " << partNames[1] << " crafts and " << craftRoundDown * partCost[2] << " " << partNames[2] << ".\n";
				cout << craftRoundDown * partCost[1] << " " << partNames[1] << " is made with: " << craftRoundDown * partCost[1] << " " << partNames[3] << " and " << craftRoundDown * partCost[2] << " " << partNames[4] << endl;
				cout << craftRoundDown * partCost[1] << " " << partNames[3] << " is transmuted from " << craftRoundDown * partCost[4] << " " << partNames[5] << " and " << craftRoundDown * partCost[0] << " " << partNames[0] << endl;
			}
			else if (method == 2)
			{
				cout << "Please enter the amount of bombs you want:\n"; //2nd cout string
				cin >> amount;
				/*while (!isdigit(amount))
				{
					cout << "Please enter a whole number value:\n";
					cin >> amount;
				}*/
				craftCalc = (double)(amount / CEYield) * matPerCraft; //calculates amount of bomb crafts
				if ((amount % CEYield) != 0) { //prints out a message if possible crafts do not match with input
					cout << "Sorry, only " << amount - (amount % CEYield) << " can be actually crafted.\n";
				}
				craftRoundUp = ceil(craftCalc);
				craftRawReverse = craftCalc / matPerCraft;
				//craftRoundUp = ceil(craftCalc);
				cout << "You will need " << craftRoundUp << " " << partNames[0] << " which is smelted with " << craftRoundUp * partCost[0] << " Ores.\n";
				cout << "You will need " << craftRawReverse << " " << partNames[1] << " crafts and " << craftRawReverse * partCost[2] << " " << partNames[2] << ".\n";
				cout << craftRawReverse * partCost[1] << " " << partNames[1] << " is made with: " << craftRawReverse * partCost[1] << " " << partNames[3] << " and " << craftRawReverse * partCost[2] << " " << partNames[4] << endl;
				cout << craftRawReverse * partCost[1] << " " << partNames[3] << " is transmuted from " << craftRawReverse * partCost[4] << " " << partNames[5] << " and " << craftRawReverse * partCost[0] << " " << partNames[0] << endl;
			}
			else if (method == 0) {
				cout << "Exiting section...\n";
				break;
			}
			else
			{
				cout << "No method selected.\n";
				goto reset4;
			}
			break;
#pragma endregion
		default:
			cout << "No item selected from menu or invalid input.\n";
			break;
		}
	}
	cout << "Program ended.";

	return 0;
}
