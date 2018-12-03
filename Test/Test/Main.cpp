#include <iostream>
#include <assert.h>
#include <random>
#include <vector>
#include "Test.h"
#include "Lottery.h"

std::vector<int> getNumbers()
{
	Test t;
	std::vector<int> numbers;
	std::vector<int> checklst;
	for (int i = 0; i < 6; i++)
	{
		int number;
		std::cout << "Enter a lotto number" << std::endl;
		std::cin >> number;
		//t.TestRange(number); // Assert Test Range 0->46
		//assert(number > 0 && number < 47); //Assert check input is greater than 0 and less than 47
		if (checklst.size() > 0)
		{
			t.CheckRepetition(number, checklst);
			assert(std::find(checklst.begin(), checklst.end(), number) != checklst.end()==false); //Assert check number not already entered
		}
		checklst.push_back(number); //Vector holds list of number to check repeated number against
		numbers.push_back(number); //Add number to vector
	}
	return numbers;
}

/// <summary>
/// Generates 6 pseudo-random numbers
/// between 0 and 46
/// </summary>
/// <returns></returns>
std::vector<int> gennumbers()
{
	std::vector<int> randNumbers;
	for (int i = 0; i < 6; i++)
	{
		int num = rand() % 47 + 1;
		randNumbers.push_back(num);
	}
	return randNumbers;
}

/// <summary>
/// Checks and count matching numbers in vectors
/// </summary>
/// <param name="n"></param> Numbers entered
/// <param name="r"></param> Results
void checkNumbers(std::vector<int> n, std::vector<int> r)
{
	int count = 0;
	for (int i = 0; i < n.size(); i++)
	{
		if (std::find(r.begin(), r.end(), n.at(i)) != r.end())
		{
			count++;
		}
	}
	std::cout << "You've matched: " << count << " " << "numbers!" << std::endl;
}
//
//int main(void)
//{
//	Lottery * l;
//	l = new Lottery();
//
//	l->getNumbers(); //Get numbers from user
//	l->genNumbers(); //Generate winning numbers
//	l->checkNumbers(); //Check user numbers against winning numbers
//
//	system("pause");
//	return 0;
//}