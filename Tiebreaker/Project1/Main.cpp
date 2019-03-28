#include <iostream>
#include <thread>
#include <vector>

/// <summary>
/// Petersons Tie Breaker Algorithm
/// for n threads
/// </summary>

const int n = 25; //Threads to run
int in[n] = { 0 }; //Conditional
int last[n] = { 0 }; //Last thread that ran

void ProcessOne(int i)
{
	while (true)
	{
		//Iterate over number of threads
		for (int j = 0; j < n; j++)
		{
			//Condition i = current thread
			in[i] = j;
			//Last executed = current condition
			last[j] = i;
			//Iterate in range of threads
			for (int k = 0; k < n; k++)
			{
				//If this thread was the last executed, skip
				if (i != k) 
					while (in[k] >= in[i] && last[j] == i);
			}
		}
		//Critical Section
		//Output current thread number
		std::cout << "P:" << i << "\n";
		in[i] = -1;
		//Noncritical section
	}
}

int main()
{
	//Vector of threads
	std::vector<std::thread> threads;
	//Add threads to vector
	for (int i = 0; i < n; i++)
	{
		threads.push_back(std::thread(ProcessOne, i));
	}

	//Threads await execution
	for (auto & thread : threads) {
		thread.join();
	}
	return 1;
}