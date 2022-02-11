#include "inventory.h"

inventory::inventory(int _size)
{
	size = _size;
	nElements = 0;
	items = new item[size];
}

inventory::~inventory()
{
	if (items != nullptr)
	{
		delete[] items;
	}
}

void inventory::addItem(const item &_item)
{
	if (nElements < size)
	{
		items[nElements] = _item;
		nElements++;
	}
}

void inventory::removeItem(const string &_serialNumber)
{
	for (int i = 0; i < nElements; i++)
	{
		if (items[i].serialNumber == _serialNumber)
		{
			for (int j = i + 1; j < nElements; j++)
				items[j - 1] = items[j];
			nElements--;
			break;
		}
	}
}

void inventory::print()
{
	for (int i = 0; i < nElements; i++)
		cout << "Description: " << items[i].description << ", Price: " << items[i].price << ", SN: " << items[i].serialNumber << ", Quantity: " << items[i].quantity << endl;
	cout << endl;
}

// Write the implementation of the copy constructor here
inventory::inventory(const inventory &other)
{
	size = other.size;
	nElements = other.nElements;

	delete[] items;
	items = new item[other.size];

	for (int i = 0; i < nElements; i++)
	{

		items[i].description = other.items[i].description;
		items[i].price = other.items[i].price;
		items[i].serialNumber = other.items[i].serialNumber;
		items[i].quantity = other.items[i].quantity;
	}
}

// Write the implementation of the copy assignment operator here
inventory &inventory::operator=(const inventory &other)
{

	size = other.size;
	nElements = other.nElements;

	delete[] items;
	items = new item[other.size];

	for (int i = 0; i < nElements; i++)
	{

		items[i].description = other.items[i].description;
		items[i].price = other.items[i].price;
		items[i].serialNumber = other.items[i].serialNumber;
		items[i].quantity = other.items[i].quantity;
	}

	return *this;
}
