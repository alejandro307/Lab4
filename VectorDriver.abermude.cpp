
/* 
Alejandro Bermudez
File: VectorDriver.cpp
* Athr: Dimitri Zarzhitsky
* Date: October 16, 2002
*
* Desc: provides the basic framework and examples for an introduction to
*       the STL::vector, iterators, and the algorithms facilities.
*/
 
typedef unsigned long ulong;

#include <iostream>
#include <vector>

#include "VectorDriver.h"
#include <algorithm>

void fill_vector(vector<short> &data) {
	for (ulong i = 0; i<data.size(); i++) {
		data.at(i) = i;
	}
}

void print(const vector<short> &data) {
	if (data.empty()) {
		cout << "<empty>";
	}
	else {
		cout << "<" << data.at(0);
		for (ulong i = 1; i<data.size(); i++) {
			cout << ", " << data.at(i);
		}
		cout << ">";
	}
}

short compute_sum(const vector<short> &data) {
	std::vector<short>::const_iterator iter = data.begin();

	short sum = 0;
	while (iter != data.end()) {
		sum += *iter;
		iter++;
	}

	return sum;

int main() {
  cout << "  ..:: B E G I N  S A M P L E  C O D E  ::.." << endl << endl;
  vector<short> sample_vector(5);

  cout << "new vector: ";
  print(sample_vector);
  cout << endl;

  fill_vector(sample_vector);

  cout << "filled vector: ";
  print(sample_vector);
  cout << endl;
  
  //Testing the is_present function 
	cout << "Checking for the number 2 in the vector (1 means present and 0 means absent) " << endl;
	cout << "The number 2 is " << is_present(sample_vector, 2) << endl;
	
	 cout << "Checking for the number 5 in the vector (1 means present and 0 means absent) " << endl;
	cout << "The number 5 is " << is_present(sample_vector, 5) << endl;

  cout << "sum of vector's elements: " << compute_sum(sample_vector) << endl;
  cout << endl << "   ..::  E N D   S A M P L E  C O D E  ::.." << endl;
	
	//Testing the add_numbers function
	vector<short> sample2_vector(0);
	add_numbers(sample2_vector);
	cout << "Randomly filled vector: ";
	print(sample2_vector);
	cout << endl;
	 
	 //Testing the print_even function
	cout << "Printing out the even indexes: ";
	print_even(sample2_vector);
	cout << endl;
	
	//Testing the add_numbers function twice in a row with the same argument
	//When I called the function twice in a row with the same argument, 
	// It duplicated the content of the vector with the same set of random numbers.
	add_numbers(sample2_vector);
	cout << "Calling the add_numbers function twice in a row with the same argument:";
	print(sample2_vector);
	cout << endl;

	
	//Testing the sort algorithm 
	vector<short> sample3_vector(0);
	add_numbers(sample3_vector);
	cout << "The unsorted vector:";
	print(sample3_vector);
	cout << endl;
	std::sort(sample3_vector.begin(), sample3_vector.end()) ;
	cout << "The sorted vector:";
	print(sample3_vector);
	cout << endl;
	

  return 0;
}
