
#include "Test.h"
#include <vector>

int main(void)
{
	Test t;

	t.TestTooFew();
	t.TestInvalidInput();
	t.TestRepeatedNumbers();
	t.TestSuccess();
	
	system("pause");
	return 0;
}