#include <iostream>

using namespace std;


int main() {

	int i = 10;

	int j = 21;

	int const * p = &i;


	p = &j;  // it will change as pointer points to a value is constant not pointer is constant


	int * const p2 = &i;  // here pointer is constant, the pointer pointing to a value is not constant 

	(*p2)++;
	// p2 = &j;  // i can't do this

    cout<<*p2;




	// int const * const p3 = &i;

	// p3 = &j;

	// (*p3)++;

}

