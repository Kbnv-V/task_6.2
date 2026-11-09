#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
	int count{};

public:
	Counter();
	Counter(int val);

	int GetCounter();

	void Increase();
	void Decrease();
};

#endif

