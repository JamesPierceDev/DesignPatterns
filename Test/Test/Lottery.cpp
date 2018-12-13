#include "Lottery.h"

/// <summary>
/// Lottery class constructor
/// </summary>
Lottery::Lottery() : count(0)
{
}

Lottery::~Lottery()
{
}

/// <summary>
/// 
/// </summary>
bool Lottery::getNumbers()
{
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Enter a lotto number" << std::endl;
		int number;
		std::cin >> number;

		if (rep_numbers.size() > 0)
		{
			input_numbers.push_back(number);
			rep_numbers.push_back(number);
		}
		else
		{
			return false;
		}
	}

	for (auto i : input_numbers)
	{
		//If any of the numbers match
		if (std::find(rep_numbers.begin(), rep_numbers.end(), i) != rep_numbers.end() == true)
		{
			return false;
		}
		else
		{
			if (i < 1 || i > 46)
			{
				return false;
			}
			rep_numbers.push_back(i);
		}
	}
	return true;
}

bool Lottery::testNumbers(std::vector<int> v)
{

	for (auto i : v)
	{
		int number;
		number = i;

		if (rep_numbers.size() > 0)
		{
			input_numbers.push_back(number);
			rep_numbers.push_back(number);
		}
		else
		{
			return false;
		}
	}

	for (auto i : input_numbers)
	{
		//If any of the numbers match
		if (std::find(rep_numbers.begin(), rep_numbers.end(), i) != rep_numbers.end() == true)
		{
			return false;
		}
		else
		{
			if (i < 1 || i > 46)
			{
				return false;
			}
			rep_numbers.push_back(i);
		}
	}
	return true;
}

/// <summary>
/// 
/// </summary>
void Lottery::genNumbers()
{
	for (int i = 0; i < 6; i++)
	{
		int num = rand() % 47 + 1;
		winning_numbers.push_back(num);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="n"></param>
/// <param name="r"></param>
void Lottery::checkNumbers()
{
	std::vector<int> n = input_numbers;
	std::vector<int> r = winning_numbers;
	for (int i = 0; i < n.size(); i++)
	{
		if (std::find(r.begin(), r.end(), n.at(i)) != r.end())
		{
			count++;
		}
	}
	std::cout << "You matched " << count << " numbers" << std::endl;
}