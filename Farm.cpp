//Title: Farm.cpp
//Author: Danny Zheng
//Date: 3/31/2021
//Description: Farm class that manages the simulation

#include "Farm.h"

// Name: Farm (Default constructor)
  // Desc: Creates a Farm (with 6 food, 0 money, season = 1)
  // Preconditions:  None
  // Postconditions: A farm is created
Farm::Farm() {
	//sets season to 1
	m_season = 1;
	m_money = 0;
	m_food = 6;
	
}

// Name: Farm (Destructor)
// Desc: Deallocates everything in the farm
// Preconditions:  None
// Postconditions: The farm is cleared out
Farm::~Farm() {
	//loops thru the vector to delete
	for (unsigned int i = 0; i < m_farm.size(); i++)
	{
		delete m_farm[i];
		m_farm[i] = nullptr;
	}
}

// Name: ChooseItem
// Desc: Allows the user to choose either an animal, vegetable, or tree
// Preconditions:  None
// Postconditions: returns 1 (animal), 2 (vegetable), or 3 (tree) (reprompts for anything else)
int Farm::ChooseItem() {
	int userinput;
	//makes a do while to make sure user is inputting something correct
	do
	{
		cin.clear();
		cout << "Which agricultural item are you interested in?" << endl;
		cout << "1. Animal \n 2. Vegetable \n 3. Tree" << endl;
		cin >> userinput;
	} while (userinput < 1 || userinput > 3);
	return userinput;
}

// Name: AddItem (int type, int quantity)
// Desc: Dynamically allocates new animals, vegetables, or trees and adds to m_farm
// Preconditions:  None
// Postconditions: Adds 1 (animal), 2 (vegetable), or 3 (tree) to m_farm
void Farm::AddItem(int type, int quantity) {
	// if type num for animal is 1
	//create veg int const
	const int veg = 2;
	if (type == 1) {
		for (int i = 0; i < quantity; i++) {
			Animal* myAnimal = new Animal();
			m_farm.push_back(myAnimal);
			cout << "A new Animal has been added" << endl;
		}
	}
    //type 2 (vegetables) 
	//adds new veg
	else if (type == veg)
	{
		for (int i = 0; i < quantity; i++) {
			Vegetable* myVegetable = new Vegetable();
			m_farm.push_back(myVegetable);
			cout << "A new Vegetable has been added" << endl;
		}
	}
	//adds new tree
	else
	{
		for (int i = 0; i < quantity; i++) {
			Tree* myTree = new Tree();
			m_farm.push_back(myTree);
			cout << "A new Tree has been added" << endl;
		}
	}
}

// Name: Tick (int season)
// Desc: Simulates a specific number of seasons
// For each season:
//               1. Calls Tick for each item in m_farm
//               2. Tries to harvest mature items (vegetables and fruit add food; animals money)
//               3. Removes anything harvested from m_farm
//               4. Displays the status automatically
// Preconditions:  None
// Postconditions: Time passes
void Farm::Tick(int seasons) {
	//sets fed to true since it will be always true for trees and veg and later sets fed to flase if false
	bool fed = true;
	const string ANIMAL = "Animal";
	const string TREE = "Tree";
	for (int j = 0; j < seasons; j++)
	{
		cout << "SEASON " << m_season << endl;
		//loops to check if anything is harvestable
		for (unsigned int i = 0; i < m_farm.size(); i++)
		{
			//if theres not enough food, then we set fed to false
			if (m_farm[i]->GetType() == ANIMAL)
			{
				if (m_food > 0) {
					m_food = m_food - 1;
				}
				else if (m_food < 1) {
					fed = false;
				}
			}
			if (m_farm[i]->GetType() == TREE)
			{
				m_food = m_food + m_farm[i]->Harvest();
				
			}
			if (m_farm[i]->GetType() == ANIMAL)
			{
				m_money = m_money + m_farm[i]->Harvest();
			}
			else
			{
				m_food = m_food + m_farm[i]->Harvest();
			}
		}
		
		//loops to remove the object from vector
		for (unsigned int i = 0; i < m_farm.size(); i++)
		{
			//ticks for everything in farm
			m_farm[i]->Tick(fed);
		}
		
		for (unsigned int i = 0; i < m_farm.size(); i++) {
			if (m_farm[i]->GetIsHarvestable() == true && m_farm.size() > 1) {
				cout << "The " << m_farm[i]->GetType() << " is harvested. " << endl;
				delete m_farm[i];
				m_farm.erase(m_farm.begin() + (i));
				i = -1;
			}
			else if (m_farm[i]->GetIsHarvestable() == true && m_farm.size() == 1) {
				cout << "The " << m_farm[i]->GetType() << " is harvested. " << endl;
				delete m_farm[i];
				m_farm.erase(m_farm.begin() + (i));
				i = 0;
			}
		}
		Status();
		//adds to season
		
		m_season = m_season + 1;
		
	}
}

// Name: Menu
// Desc: Displays a menu with the following:
//     1. Add Item to Farm (adds a single item to m_farm)
//     2. Add Two of Each Item to Farm (Adds two of each item to m_farm)
//     3. Simulate Time (Asks the user how many seasons to simulate)
//     4. Farm Status (Displays the status of the farm)
//     5. Quit (Quits the simulation)
// Preconditions:  None
// Postconditions:  If returns 5, quits
int Farm::Menu() {
	//main menu
	int userinput;
	//chekcs for valid input
	do
	{
		cin.clear();
		cout << " 1. Add Item to Farm \n 2. Add Two of Each Item to Farm \n 3. Simulate Time \n 4. Farm Status \n 5. Quit" << endl;
		cin >> userinput;
		cin.ignore(256, '\n');
		
	} while (userinput < 1 || userinput > 5);
	return userinput;
}

// Name: StartSimulation
// Desc: Manages the introduction, menu, and quitting
// Preconditions:  Displays welcome message
// Postconditions: As long as menu doesn't return 5, keeps running
void Farm::StartSimulation() {
	int userinput;
	//checks for valid input
	const int item2 = 2;
	const int total_inputs = 4;
	const int quit = 5;
	const int seasons = 3;
	do
	{
		userinput = Menu();
		if (userinput == 1)
		{
			AddItem(ChooseItem(),1);
		}
		if (userinput == item2)
		{
			//adds however many times the user inputted
			for (int i = 1; i < total_inputs; i++)
			{
				AddItem(i, item2);
			}
		}
		if (userinput == seasons)
		{
			//asks how many seasons the user wants to stiumulate
			int seasons;
			cin.clear();
			cout << "How many season to stimulate? " << endl;
			cin >> seasons;
			Tick(seasons);
		}
		if (userinput == total_inputs){
			//displays the status
			Status();
		}
		// while usser does not want to quit
	} while (userinput != quit);
}
// Name: Status
// Desc: Displays farm food, money, season, and each agricultural item
// Preconditions:  None
// Postconditions: Displays farm data
void Farm::Status() {
	//couts the title,food, etc
	cout << "*** Farm Status ***" << endl;
	cout << "Food: " << m_food << endl;
	cout << "Money: " << m_money << endl;
	cout << "Season: " << m_season << endl;
	cout << "Agricultural Items: " << endl;
	//loops vector and prints each object
	for (unsigned int i = 0; i < m_farm.size(); i++)
	{
		(*m_farm.at(i)) << cout << endl;
		
	}
	if (m_farm.size()==0)
	{
		cout << "None" << endl;
	}
}