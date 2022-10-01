//Title: agltem.cpp
//Author: Danny Zheng
//Date: 3/31/2021
//Description: agItem class that manages the simulation


#include "AgItem.h"

 // Name: AgItem (Default constructor)
  // Desc: Creates an AgItem with size 0, Base_Worth of 1 and not harvestable
  // Preconditions:  Abstract class
  // Postconditions: Abstract class so used with child classes only.
AgItem::AgItem() {
	//sets size to 0, worth to 1, and harvestable as false
	m_size = 0;
	m_worth = BASE_WORTH;
	m_isHarvestable = false;
}

// Name: AgItem (Overloaded constructor)
// Desc: Creates an AgItem with size, worth, and IsHarvestable passed
// Preconditions:  Abstract class
// Postconditions: Abstract class so used with child classes only.
AgItem::AgItem(int size, int worth, bool harvestable) {
	//overloaded constructor = variables from default
	m_size = size;
	m_worth = worth;
	m_isHarvestable = harvestable;
}

// Name: ~AgItem (Destructor
// Desc: Deletes anything dynamically allocated
// Preconditions:  AgItem
// Postconditions: Can be trivially implemented but required for subclass (tree)
AgItem::~AgItem() {
	
}

//Accessors
// Name: GetSize
// Desc: Returns m_size
// Preconditions:  None
// Postconditions: None
int AgItem::GetSize() {
	//returns m_size
	return m_size;
}
// Name: GetWorth
// Desc: Returns m_worth
// Preconditions:  None
// Postconditions: None
int AgItem::GetWorth() {
	//gets worth
	return m_worth;
}

// Name: GetIsHarvestable
// Desc: Returns m_isHarvestable
// Preconditions:  None
// Postconditions: None
bool AgItem::GetIsHarvestable() {
	//gets if harvestable
	return m_isHarvestable;
}
// Name: SetSize
// Desc: Sets the size of an AgItem
// Preconditions:  None
// Postconditions: m_size is set
void AgItem::SetSize(int size) {
	//sets size
	m_size = size;
}
// Name: SetIsHarvestable
// Desc: Sets m_isHarvestable
// Preconditions:  None
// Postconditions: m_isHarvestable is set
void AgItem::SetIsHarvestable(bool harvest) {
	//sets harvestable
	m_isHarvestable = harvest;
}
// Name: SetWorth
// Desc: Sets m_worth
// Preconditions:  None
// Postconditions: m_worth is set
void AgItem::SetWorth(int worth) {
	m_worth = worth;

}