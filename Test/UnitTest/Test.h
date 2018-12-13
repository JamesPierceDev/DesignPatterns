#ifndef TEST_H
#define TEST_H

#include <assert.h>
#include <iostream>
#include <vector>
#include "../Test/Lottery.h"

class Test
{
public:
	Test() {
	};

	void TestTooFew()
	{
		std::vector<int> tooFew = { 1, 2, 3, 4 };
		assert(l.testNumbers(tooFew) == false);
		std::cout << "Test passed: Too few numbers input" << std::endl;
	}

	void TestInvalidInput()
	{
		std::vector<int> invalid = { 24, 1, 2, 44, 37, 66 };
		assert(l.testNumbers(invalid) == false);
		std::cout << "Test passed: Invalid input" << std::endl;
	}

	void TestRepeatedNumbers()
	{
		std::vector<int> repeated = { 1, 2, 2, 3, 4, 5 };
		assert(l.testNumbers(repeated) == false);
		std::cout << "Test passed: Repeated numbers" << std::endl;
	}

	void TestSuccess()
	{
		std::vector<int> pass = { 1, 2, 3, 4, 5, 6 };
		assert(l.testNumbers(pass) == false);
		std::cout << "Test passed: Successful input" << std::endl;
	}




private:
	Lottery l;
};


#endif
