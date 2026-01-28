#include "AUList.h"
#include <iostream>

AUList::AUList()
{
	length = 0;
	currentPos = -1;
}

AUList::~AUList()
{
}

bool AUList::isEmpty()
{
	return length == 0;
}

bool AUList::isFull()
{
	return length == MAX_ITEMS;
}

int AUList::getLength()
{
	return length;
}

bool AUList::Insert(ItemType item)
{
	if (isFull())
		return false;
	items[length] = item;
	length++;
	return true;
}

bool AUList::Remove(ItemType item)
{
	for (int i = 0; i < length; i++)
	{
		if (items[i].ComparedTo(item) == relationType::EqualTo)
		{
			items[i] = items[length - 1];
			length--;
			return true;
		}
	}
	return false;
}

ItemType AUList::GetItem(ItemType item, bool& found)
{
	for (int i = 0; i < length; i++)
	{
		if (items[i].ComparedTo(item) == relationType::EqualTo)
		{
			found = true;
			return items[i];
		}
	}
	found = false;
	return ItemType();
}

void AUList::EmptyList()
{
	length = 0;
	currentPos = -1;
}

ItemType AUList::GetNextItem()
{
	currentPos++;
	if (currentPos < length)
		return items[currentPos];
	else
		return ItemType();
}

void AUList::ResetList()
{
	currentPos = -1;
}

void AUList::PrintList()
{
	for (int i = 0; i < length; i++)
	{
		items[i].Print();
		std::cout << " ";
	}
	std::cout << std::endl;
}