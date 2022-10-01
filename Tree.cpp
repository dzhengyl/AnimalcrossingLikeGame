//Title: Tree.cpp
//Author: Danny Zheng
//Date: 3/31/2021
//Description: Tree class that manages the simulation


#include "Tree.h"

  // Name: Tree (Default constructor)
  // Desc: Creates a tree with size 0 and age of 0
  // Preconditions:  Uses AgItem default constructor
  // Postconditions: A tree is created.
Tree::Tree(){
	//all tree size starts at 0 not harvestable and age 0
	SetSize(0);
	m_age = 0;
	SetIsHarvestable(false);
}

// Name: ~Tree
// Desc: Destructor for tree (and importantly fruit)
// Preconditions:  Tree exists
// Postconditions: All fruit is purged from tree.
Tree::~Tree() {
	//deletes the fruits in fruits vector
	for (unsigned int i = 0; i < m_fruit.size(); i++)
	{
		cout << " A fruit has been harvested" << endl;
		delete m_fruit[i];
		m_fruit[i] = nullptr;
		SetSize(0);
	}
}
// Name: Tick
// Desc: A season passes is the tree's life (always fed)
// Preconditions: Tree exists
// Postconditions: Returns amount of fruit harvested each season.
// One of the following occurs:
//    1. Tree is not Mature yet and ages. Every 4 seasons, size increases til age 12 when fruits
//    2. Tree is Mature and grows a one fruit a season. Fruit is harvested every season.
//    3. Tree is 60 seasons old and is cut down (IsHarvesteable)
void Tree::Tick(bool fed) {
	//constant to check if tree is pole size
	const int pole = 2;
	//adds to age
	m_age++;
	//depending on age, we either harvest, setsize, or harvest fruits
	if (m_age != SEASONS_TO_HARVEST)
	{
		if (m_age == SEASONS_TO_SIZE)
		{
			SetSize(1);
		}
		if (m_age == (SEASONS_TO_SIZE + SEASONS_TO_SIZE))
		{
			SetSize(pole);
		}
		if (m_age >= SEASONS_TO_FRUIT)
		{
			SetSize(pole + 1);
			Fruit* myfruit = new Fruit();
			m_fruit.push_back(myfruit);
		}
	}
	// checks if its season to harvest
	else if (m_age == SEASONS_TO_HARVEST)
	{
		SetIsHarvestable(true);
	}
}

// Name: Harvest
// Desc: If there is fruit, removes last fruit and returns 1. If 60 seasons old, returns 0
// Preconditions:  Tree exists
// Postconditions: Fruit is returned(1 farm food) or dead tree (0 worth and 0 farm food)
int Tree::Harvest() {
	//checks if theres a fruit and see if age is 60
	if (m_fruit.size() > 0 && m_age != SEASONS_TO_FRUIT)
	{
		delete m_fruit[m_fruit.size() - 1];
		m_fruit.pop_back();
		return 1;
	}
	//if age 60 doesnt return anything
	if (m_age == 60)
	{
		SetIsHarvestable(true);
		return 0;
	}
	//if theres no fruit
	if (m_fruit.size() < 1)
	{
		return 0;
	}
	else
	{
		return 0;
	}
}

// Name: GetType
// Desc: Returns the name of the subtype (Tree)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Tree)
string Tree::GetType() {
	//returns tree
	string tree = "Tree";
	return tree;

}

// Name: overloaded operator<<
// Desc: Allows Tree objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format:
//                 Tree  | Seedling | Not Harvestable | Not Fruiting | Fruit Count: 0
ostream& Tree::operator<<(ostream& output) {
	//string and int istantiations 
	string type = GetType();
	string size = TREE_SIZE[GetSize()];
	string harvest;
	int fruit_count = 0;
	string fruiting;
	
	//chekcs if its harvestable
	if (GetIsHarvestable() == false)
	{
		harvest = "Not Harvestable";
	}
	else if (GetIsHarvestable() == true)
	{
		harvest = "Harvestable";
	}
	if (m_age >= SEASONS_TO_FRUIT) {
		fruiting = "Fruiting";
	}
	else if (m_age < SEASONS_TO_FRUIT)
	{
		fruiting = "Not Fruiting";
	}
	//output statement for  Tree  | Seedling | Not Harvestable | Not Fruiting | Fruit Count 
	output << type << CONCAT << size << CONCAT << harvest << CONCAT << fruiting << CONCAT << "Fruit Count: "<< fruit_count << endl;
	return output;

}
