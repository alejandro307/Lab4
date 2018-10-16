/* File: VectorDriver.cpp
* Athr: Dimitri Zarzhitsky
* Date: October 16, 2002
*
* Desc: provides the basic framework and examples for an introduction to
*       the STL::vector, iterators, and the algorithms facilities.
*
* Edited by: Rafer Cooley
* Date: Oct 15. 
* Alejandro	Bermudez
*/
typedef unsigned long ulong;

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// fill vector that has pre-allocated space with consecutive numbers
void fill_vector(vector<short> &data) {
  for (ulong i=0; i<data.size(); i++) {
    data.at(i) = i;
  }
}

//fill an empty vector with 10 random numbers
void add_numbers(vector<short> &data)
{
	srand(time(0));
	for(int i = 0; i < 10; i++)
	{
		int random = rand() % 100;
		data.push_back(random);
	}
}
// print our vector in a fancy way
void print(const vector<short> &data) {
  if (data.empty()) {
    cout << "<empty>";
  } else {
    cout << "<" << data.at(0);
    for (ulong i=1; i<data.size(); i++) {
      cout << ", " << data.at(i);
    }
    cout << ">";
  }
}

//print out vector elements of even indexes (also in a fancy way)


//Use itertor to check if an element is contained in the vector
//returns true if it is contained in the vector
//returns false if it is not contained in the vector

void print_even(const vector<short> &data) {
  if (data.empty()) {
    cout << "<empty>";
  } 
  else {
    cout << "<" << data.at(0);
    for (ulong i=1; i<data.size(); i++) 
		{
			if((i) % 2 == 0)
			{
				cout << ", " << data.at(i);
			}
		}
    cout << ">";
  }
}
// use iterator to sum the elements of a vector
short compute_sum(const vector<short> &data) {
  std::vector<short>::const_iterator iter = data.begin();

  short sum = 0;
  while (iter != data.end()) {
    sum += *iter;
    iter++;
  }

  return sum;
}
bool is_present(const vector<short> &data, short value) {
  std::vector<short>::const_iterator iter = data.begin();
	
	while (iter != data.end()) 
	{
		if(*iter == value)
		{
			return true;
		}
			iter++;
	}
	return false;
}
// TODO: implement add_numbers
// TODO: implement print_even
// TODO: implement is_present
// TODO: implement std::sort function
