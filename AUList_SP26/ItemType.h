#ifndef ITEM_TYPE_H
#define ITEM_TYPE_H

#include <iostream>

typedef int Type;
const int MAX_ITEMS = 100;

enum class relationType
{
	LessThan,
	GreaterThan,
	EqualTo
};

class ItemType
{
public:

	ItemType();

	void Initialize(Type value_);

	relationType ComparedTo(ItemType item) const;

	void Print(std::ostream& stream) const;

private:
	Type value;
};

#endif // !ITEM_TYPE_H

