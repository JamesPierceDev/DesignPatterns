#ifndef TEST_H
#define TEST_H

#include <assert.h>
#include <vector>
#include "Lottery.h"


class Test
{
public:
	Test() {
	};

	void TestRange(int n) {
		assert(n > 0 && n < 47);
		std::cout << "Range Test : Pass" << std::endl;
	}

	/// <summary>
	/// Checks if numbers in n are present in c
	/// </summary>
	/// <param name="n"></param> Vector input numbers
	/// <param name="c"></param> Vector previously input numbers
	void CheckRepetition(int n, std::vector<int> c) {
		assert(std::find(c.begin(), c.end(), n) != c.end() == false); //Assert check number not already entered
		std::cout << "Repetition Test : Pass" << std::endl;
	}

private:

};

int main(void)
{
	std::vector<int> m_numbers = { 1, 2, 3, 4, 5, 6 };
	Test t;

	t.CheckRepetition(19, m_numbers);

	for (auto i : m_numbers)
	{
		t.TestRange(i);
	}
	return 0;
}

#endif
