//Title: Vegetable.cpp
//Author: Danny Zheng
//Date: 3/31/2021
//Description: Vegetable class that manages the simulation

#include "Vegetable.h"

  // Name: Vegetable (Default constructor)
  // Desc: Creates a vegetable with size 0
  // Preconditions:  Uses AgItem default constructor
  // Postconditions: A vegetable is created.
Vegetable::Vegetable() {
	SetSize(0);
	SetIsHarvestable(false);
	
}

// Name: Harvest
// Desc: If the vegetable is harvestable (fully mature), returns size to increase farm's food
// Preconditions:  IsHarvestable
// Postconditions: Returns integer size of vegetable for food
int Vegetable::Harvest() {
	int size = GetSize();
	if (size == MAX_VEG_SIZE)
	{
		SetIsHarvestable(true);
	}
	if (GetIsHarvestable() == true)
	{
		return size;
	}
	else
	{
		return 0;
	}
}

// Name: Tick
// Desc: A season passes in the vegetable's life if they are fully mature, IsHarvestable flipped
// Preconditions:  If the size is less than the maximum vegetable size, increases size
// Postconditions: Vegetable either grows or becomes harvestable
// Assume that a vegetable is always fed.
void Vegetable::Tick(bool fed) {
	//checks if veg size is max
	if (GetSize() == MAX_VEG_SIZE)
	{
		SetIsHarvestable(true);
	}
	else{
		SetSize(GetSize() + 1);
	}
}

// Name: GetType
// Desc: Returns the name of the subtype (Vegetable)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Vegetable)
string Vegetable::GetType() {
	//gets type veg
	string type = "Vegetable";
	return type;
}

// Name: overloaded operator<<
// Desc: Allows Vegetable objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format
//                 Vegetable | Not Harvestable | Seedling
ostream& Vegetable::operator<<(ostream& output){
	string type = GetType();
	string size = Veg_Size[GetSize()];
	string harvest;
	//Cecks if plan is harvestable or not
	if (GetIsHarvestable() == false)
	{
		harvest = "Not Harvestable";
	}
	else if (GetIsHarvestable() == true)
	{
		harvest = "Harvestable";
	}
	output << type << CONCAT << harvest << CONCAT << size << endl;
	return output;
}