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
	nElements++;
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
		nElements--;
		return data;
	}
}

int Stack::Size() const
{
	return nElements;
}

bool Stack::Empty() const
{
	if (nElements == 0) {
		return true;
	}
	return false;
}
