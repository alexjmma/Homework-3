#include <iostream>
using namespace std;
class IntVectArray
{
public:
	IntVectArray(int vsize = 10);	// default constructor
	IntVectArray(int elemlist[], int arraysize); // constructor with init parameters
	IntVectArray(const IntVectArray& intvect);  // copy constructor
	IntVectArray& operator = (const IntVectArray& intvect); // assignment constructor
	~IntVectArray();	  // destructor
	void printElements();  // prints all elements in the array

private:
	int *vector;		// the vector
	int vectorsize;	// size of the vector 

};

IntVectArray::IntVectArray(int vsize)  // default constructor
{
	vectorsize = vsize;
	vector = new int[vectorsize];
}

// constructor with initialization parameters
IntVectArray::IntVectArray(int elemlist[], int arraysize)
{
	vectorsize = arraysize;
	vector = new int[vectorsize];
	for (int x = 0; x < vectorsize; x++)
	{
		vector[x] = elemlist[x];
	}
}
// copy constructor
IntVectArray::IntVectArray(const IntVectArray& intvect)
{
	//To be completed
	vectorsize = intvect.vectorsize;
	vector = new int[vectorsize];
	for (int x = 0; x < vectorsize; x++)
	{
		vector[x] = intvect.vector[x];
	}
}

// assignment constructor
IntVectArray& IntVectArray::operator = (const IntVectArray &intvect)
{
	// To be completed	
	for (int x = 0; x < vectorsize; x++)
	{
		vector[x] = intvect.vector[x];
	}
	return *this;
}

// destructor
IntVectArray::~IntVectArray()
{
	// To be completed
	delete[] vector;
}

void IntVectArray::printElements()
{
	// to be completed
	for (int x = 0; x < vectorsize; x++)
	{
		cout << vector << endl;
	}
}

int main()
{
	// implementation of an integer vector using array

	// try vector a
	int IntArraya[10] = { 2, 7, 3, 6, 11, 43, 72, 119, 339, 711 };
	IntVectArray aVect(IntArraya, 10);
	cout << "Printing all elements in aVect:" << endl;
	aVect.printElements();

	// try vector 
	int IntArrayb[10] = { 1, 21, 57, 63, 13, 71, 92, 179, 923, 421 };
	IntVectArray bVect(IntArrayb, 10);
	cout << "Printing all elements in bVect:" << endl;
	bVect.printElements();

	// try the assigment constructor
	bVect = aVect;
	cout << "Assigned bVect = aVect. Printing all elements in bVect after assignment operation:" << endl;
	bVect.printElements();

	// try the copy constructor
	IntVectArray cVect = aVect;
	cout << "cVect was created to be a copy of aVect. Printing all elements in cVect:" << endl;
	cVect.printElements();
	return 0;
}
