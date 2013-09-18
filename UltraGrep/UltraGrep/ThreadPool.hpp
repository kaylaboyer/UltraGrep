#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <memory> //shared_ptr, unqiue_ptr
#include <mutex> // really critical section 
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <vector>

class ThreadPool
{
public:
	std::vector<std::thread> myThreads;
	unsigned nThreads;
	std::mutex consoleMutex;
	unsigned barrierThreshold;
	unsigned barrierCount;
	unsigned barrierGeneration;
	std::mutex barrierMutex;
	std::condition_variable barrierCondition;
	ThreadPool(int threadCount)
	{
		nThreads = threadCount;
		barrierThreshold = nThreads + 1;
		barrierCount = barrierThreshold;
		barrierGeneration = 0;
	}
	void barrier();
};


void ThreadPool::barrier()
{



}