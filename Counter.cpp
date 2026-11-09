#include "Counter.h"

Counter::Counter() {};

Counter::Counter(int val) : count(val) {};

int Counter::GetCounter() { return count; }

void Counter::Increase() { ++count; }

void Counter::Decrease() { --count; }