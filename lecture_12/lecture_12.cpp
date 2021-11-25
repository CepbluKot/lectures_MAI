#include <iostream>

template <typename T>
class list
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node *prev;
		Node(T smth) : data(smth), next(nullptr), prev(nullptr) {}
	};
	Node *first;
	Node *last;

public:
	list()
	{
		first = nullptr;
		last = nullptr;
	}

	~list()
	{
		if (first != last)
		{
			Node *currNode = first;
			while (currNode != last)
			{
				Node *copyCurrArd = currNode;
				currNode = currNode->next;
				delete copyCurrArd;
			}
			delete last;
		}
	}

	void pushBack(T data)
	{
		Node *newNode = new Node(data);
		if (!first)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			Node *copyLast = last;
			last = newNode;
			last->prev = copyLast;
		}
	}

	void PrintList()
	{
		Node *currElement = first;
		while (currElement) // currElement != nullptr
		{
			std::cout << currElement->data << " curr: " << currElement << " next: " << currElement->next << " prev: " << currElement->prev << std::endl;
			currElement = currElement->next;
		}
	}
};

int main()
{
	list<float> l;
	l.pushBack(1);
	l.pushBack(2);
	l.pushBack(3);
	l.PrintList();
}