#include "ItemType.h"
#include <iostream>

ItemType::ItemType()
{
}

void ItemType::Initialize(Type value_)
{
	value = value_;
}

relationType ItemType::ComparedTo(ItemType item) const
{
	if (value < item.value)
		return relationType::LessThan;
	else if (value > item.value)
		return relationType::GreaterThan;
	else
		return relationType::EqualTo;
}

void ItemType::Print(std::ostream& stream) const
{
	stream << value;
}