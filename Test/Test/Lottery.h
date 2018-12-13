#ifndef LOTTERY_H
#define LOTTERY_H

#include <vector>
#include <random>
#include <iostream>

class Lottery
{
public:
	Lottery();
	~Lottery();

	bool getNumbers();
	bool testNumbers(std::vector<int>);
	void genNumbers();
	void checkNumbers();

private:
	std::vector<int> input_numbers;
	std::vector<int> rep_numbers;
	std::vector<int> winning_numbers;
	int count;
};

#endif

