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
		Element(const Element& source) = delete;
		Element& operator=(const Element& source) = delete;
	public:
		int data;
		Element* pNext = nullptr;
	};

public:
	Stack() = default;
	~Stack() {
		delete pBegin;
	}
	Stack(const Stack& source){
		*this = source;
	}
	Stack& operator=(const Stack& source) {

		delete pBegin;
		pBegin = nullptr;

		if (!source.Empty()) {
			pBegin = new Element(source.pBegin->data);
			Element* pSourceLast = source.pBegin->pNext;
			Element* pLast = pBegin;
			while (pSourceLast != nullptr) {
				pLast->pNext = new Element(pSourceLast->data);
				pSourceLast = pSourceLast->pNext;
				pLast = pLast->pNext;
			}
			nElements = source.nElements;
		}
		return *this;
	}

public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

private:
	Element* pBegin = nullptr;
	int nElements = 0;
};