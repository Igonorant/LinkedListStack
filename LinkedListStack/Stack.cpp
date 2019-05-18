#include "Stack.h"

void Stack::Push(int val)
{
	if (Empty()) {
		pBegin = new Element(val);
	}
	else {
		Element* pLast = pBegin;
		while (pLast->pNext != nullptr) {
			pLast = pLast->pNext;
		}
		pLast->pNext = new Element(val);
	}
}

int Stack::Pop()
{
	if (Empty()) {
		return -1;
	}
	else {
		Element* pLast = pBegin;
		Element* pBeforeLast = pBegin;
		while (pLast->pNext != nullptr) {
			pBeforeLast = pLast;
			pLast = pLast->pNext;
		}
		int data = pLast->data;
		if (pLast != pBeforeLast) {
			delete pLast;
			pBeforeLast->pNext = nullptr;
		}
		else {
			delete pBegin;
			pBegin = nullptr;
		}
		return data;
	}
}

int Stack::Size() const
{
	if (Empty()) {
		return 0;
	}
	else {
		int counter = 1;
		Element* pLast = pBegin;
		while (pLast->pNext != nullptr) {
			counter++;
			pLast = pLast->pNext;

		}
		return counter;
	}
}

bool Stack::Empty() const
{
	if (pBegin == nullptr) {
		return true;
	}
	return false;
}
