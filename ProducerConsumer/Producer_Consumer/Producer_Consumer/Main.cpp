#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

//C++ mutual exclusion object
std::mutex mutex;
//Sync primitive that can be used to block a thread
std::condition_variable cv;
int thread_count;

/*Consumer*/
void consumer(int n)
{
	//Required for std::condition_variable to block the thread
	std::unique_lock<std::mutex> lock(mutex);
	while (thread_count == 0)
	{
		//Causes current thread to block until the condition
		//variable is notified
		cv.wait(lock);
	}

	std::cout << "n: " << n + 1 << std::endl;
	std::cout << "Threads running concurrently: " << thread_count - 1 << std::endl;
	thread_count--;
}

/*Producer*/
void producer(int n)
{
	std::unique_lock<std::mutex> lock(mutex);
	thread_count++;

	//Notifies the condition variable to stop blocking
	//the incoming thread
	cv.notify_one();
}

int main()
{
	std::thread producers[1000];
	std::thread consumers[1000];

	for (int i = 0; i < 1000; i++)
	{
		producers[i] = std::thread(producer, i);
		consumers[i] = std::thread(consumer, i);
	}

	for (int j = 0; j < 1000; j++)
	{
		producers[j].join();
		consumers[j].join();
	}

	std::system("PAUSE");

	return 0;
}