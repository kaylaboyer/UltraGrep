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



class SafetyBarrier
{
private:
	unsigned nThreads;
	std::mutex consoleMutex;
	unsigned barrierThreshold;
	unsigned barrierCount;
	std::mutex barrierMutex;
	unsigned barrierGeneration;
	std::condition_variable barrierCondition;
	//std::unique_lock<std::mutex> barrierMutexlock;
public:
	SafetyBarrier(unsigned threadNum)
	{
		nThreads = threadNum;
		barrierThreshold = nThreads + 1;
		barrierCount = barrierThreshold;
		barrierGeneration = 0;
	}
	void barrier();

};