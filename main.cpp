#include "LinkedList.h"
#include <cstdlib> //rand() for random numbers
#include <chrono>  //time functions

void insertRandoms(int _number);

int main()
{

	LinkedList myList;

	// demonstrate functionality of insertSorted
	myList._insertSorted(5);
	myList._insertSorted(4);
	myList._insertSorted(10);
	myList._insertSorted(9);
	myList._insertSorted(8);
	myList._insertSorted(6);
	myList._insertSorted(7);
	std::cout << "Demonstrate functionality: ";
	myList._print();

	// run for different values of "n"
	insertRandoms(10000);
	insertRandoms(20000);
	insertRandoms(40000);
	insertRandoms(80000);
	insertRandoms(160000);
	insertRandoms(320000);
	insertRandoms(640000);
	insertRandoms(1280000);

	return 0;
}

void insertRandoms(int _number)
{
	LinkedList myList;

	// chrono timing
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::milliseconds;

	std::cout << "n = " << _number << ": ";

	auto _beginTime = high_resolution_clock::now(); // timer start

	for (int i = 0; i < _number; i++)
	{
		int _randNum = rand() % _number;
		myList._insertSorted(_randNum);
	}

	auto _endTime = high_resolution_clock::now(); // timer end

	auto _timeTaken = duration_cast<milliseconds>(_endTime - _beginTime);

	std::cout << _timeTaken.count() << std::endl; // end string buffer
}

// log1: inserting a largest element into sorted linkedList resulted in seg fault, due to this comparison when calling _insertSorted(): while(temp->next != nullptr && _key < temp->next->key)
// resolution1: include tail pointer, and