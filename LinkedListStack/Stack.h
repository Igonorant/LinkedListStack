#pragma once

class Stack
{
private:
	class Element {
	public:
		Element() = default;
		Element(const int val) {
			data = val;
		}
		~Element() {
			delete pNext;
		}

	public:
		int data;
		Element* pNext = nullptr;
	};

public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

private:
	Element* pBegin = nullptr;
};