#ifndef AU_LIST_H
#define AU_LIST_H

#include "ItemType.h"

class AUList
{
public:
	AUList();
	~AUList();

	bool isEmpty();
	bool isFull();
	int getLength();
	bool Insert(ItemType item);
	bool Remove(ItemType item);
	ItemType GetItem(ItemType item, bool& found);
	void EmptyList();
	ItemType GetNextItem();
	void ResetList();
	void PrintList();

private:
	ItemType items[MAX_ITEMS];
	int length;
	int currentPos;
};

#endif // !AU_LIST_H

