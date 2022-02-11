#ifndef CARH
#define CARH
#include <string>
using namespace std;

class Car
{
private:
	int modelYear;
	int purchasePrice;
	int currentValue;
	int num_parts = 0;
	string *parts = nullptr;

public:
	Car();
	Car(int, int);
	void SetModelYear(int userYear);
	int GetModelYear() const;
	void SetPurchasePrice(int userPrice);
	int GetPurchasePrice() const;
	void CalcCurrentValue(int currentYear);
	void PrintInfo() const;
	void setParts(int numpart, string new_parts[]); // set the num_parts and parts
	int getNumParts() const;
	string getPart(int index) const;
	string *getParts() const;

	Car(const Car &);			 // copy constructor
	Car &operator=(const Car &); // copy assignment operator
	~Car();						 // destructor
};

#endif