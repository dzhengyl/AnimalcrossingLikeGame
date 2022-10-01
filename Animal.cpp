//Title: animal.cpp
//Author: Danny Zheng
//Date: 3/31/2021
//Description: animal class that manages the simulation

#include "Animal.h"
 // Name: Animal (Default constructor)
  // Desc: Creates an Animal with size 0
  // Preconditions:  Uses AgItem default constructor
  // Postconditions: An animal (chicken) is created.
Animal::Animal() {
	//sets size to 0 and makes default settings for new chicken
	SetSize(0);
	m_IsHungry = false;
	SetIsHarvestable(false);
	m_name = "Chicken";
}

// Name: Tick
// Desc: A season passes in the animal's life (passed boolean if it was fed - eats "farm's food")
// Preconditions: If farm has food, animal is automatically fed
// Postconditions: One of the following occurs
//    1. Animal is fed and size increases (not max yet)
//    2. Animal is fed hits max size and is made harvestable
//    3. Animal is not fed. Size does not increase. If second no feed, is harvested (small).
void Animal::Tick(bool fed) {
	//checks if chicken is fed and if its max size yet
	if (GetSize()== ANIMAL_MAX_SIZE)
	{
		SetIsHarvestable(true);
	}
	else if (fed == true && GetSize() != ANIMAL_MAX_SIZE)
		//checks if fed is true if not fed size does not increase
	{
		SetSize(GetSize() + 1);
	}
	//if its not fed we make it hangry
	else if (fed == false && m_IsHungry == false)
	{
		m_IsHungry = true;
	}
	//if its not fed and hangry we set it harvestable
	else if (fed == false && m_IsHungry == true)
	{
		SetIsHarvestable(true);
	}
	else
	{
		SetSize(GetSize() + 1);
	}
}

// Name: Harvest
// Desc: If the animal is harvestable (adult), returns worth * size to increase farm's money
// Preconditions:  IsHarvestable
// Postconditions: Animal harvested and money is gained (worth * size)
int Animal::Harvest() {
	//mulitply worth with size to get money gained
	if (GetSize() == ANIMAL_MAX_SIZE)
	{
		SetIsHarvestable(true);
		int money_gained = GetWorth() * GetSize();
		return money_gained;
	}
	else
	{
		return 0;
	}
}

// Name: GetType
// Desc: Returns the name of the subtype (Animal)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Animal)
string Animal::GetType() {
	const string animal = "Animal";
	return animal;
}

// Name: overloaded operator<<
// Desc: Allows Animal objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format:
//                 Animal | Chicken | Not Harvestable | Born | Fed
ostream& Animal::operator<<(ostream& output) {
	string type = GetType();
	string chicken = m_name;
	string harvest;
	string fed;
	string animalsize = ANIMAL_SIZE[GetSize()];
	//checks if harvestable is false
	if (GetIsHarvestable() == false)
	{
		harvest = "Not Harvestable";
	}
	else if (GetIsHarvestable() == true)
	{
		harvest = "Harvestable";
	}
	//checks if its hungry
	if (m_IsHungry == true){
		fed = "Not Fed";
	}
	else if (m_IsHungry == false)
	{
		fed = "Fed";
	}
	//output statement
	output << type << CONCAT << chicken << CONCAT << harvest << CONCAT << animalsize << CONCAT << fed << endl;
	return output;
}
