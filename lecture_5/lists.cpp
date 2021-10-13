#include <iostream>
#include <string>
// RAII

template <typename DataType>
	class List 
	{
	private:
		template <typename coreList>
		class Node
		{
    	private: 
			Node* next;
			coreList data;
		public:
			Node(Node* nxt, coreList dat)
			{
				this->next = nxt;
				this->data = dat;
			}
		};
			
		
	public:
		List()
		{
			size = 0;
			head = nullptr; 
		}
		~List() 
		{ 
			head = nullptr;
		}
		
		void Insert(DataType newElement, int position);
    	void RemoveNode(int position);
        void PrintList();
        int size;
        List<DataType>* head;
    
};

template<typename DataType>
void List<DataType>::Insert(DataType newElement, int position)
{
	List<DataType>* nod = new List<DataType>();
	int index = 0;
	while(index != position)
	{
		nod->next = head;
		head = nod;
		index += 1;
	}
	nod->data = newElement;
}

template<typename DataType>
void List<DataType>::RemoveNode(int position)
{
	List<DataType>* nod = new List<DataType>();
	int index = 0;
	while(index != position)
	{
		nod->next = head;
		head = nod;
		index += 1;
	}
	nod->data = nullptr;
}

template<typename DataType>
void List<DataType>::PrintList()
{
	List<DataType>* nod = new List<DataType>();
	int index = 0;
	while(index < size)
	{
		std::cout<< nod->data << std::endl;
		index += 1;
	}
}




int main(int argc, char** argv) {
	
	
	return 0;
}
