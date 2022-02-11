#include <iostream> 
#include <vector> 

using namespace std;

 int main() 
 { 
	vector<int> itemCounts(3); 
	itemCounts.at(0) = 122;
	itemCounts.at(1) = 119; 
	itemCounts.at(2) = 117; 
//	cout << itemCounts.back();
	int i;
	itemCounts.resize(5);
	for (i=0;i<itemCounts.size();i++)
		cout << itemCounts.at(i) << endl;
	return 0; 
}
