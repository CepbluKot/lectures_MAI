#include <iostream>
#include <string>
#include <sstream>
#include "list_h.h"

template<class T>
std::string toString(const T& x)
{
  std::ostringstream ss;
  ss << x;
  return ss.str();
}

template <typename T>
T hashFuncMain(T data, int tableSize, int key)
{
    int result = 0;
    std::string sData = toString<T>(data);
    for (int i = 0 ; i < sData.size(); i++)
    {
        result += key * (sData[i] - '0');
        key *= 2;
    }
    return result % tableSize;
}

template <typename T>
T hashFunc1(T& data, int tableSize)
{
    return hashFuncMain(data, tableSize, tableSize - 1);
}

template <typename T>
class hashTable
{
    public:
    hashTable()
    {
        
    }
    ~hashTable()
    {
        
    }

    void add(T data)
    {
        int index = hashFunc1(data, size);
        arr[index].pushHere.pushBack(data);
    }

    void find(int key)
    {
        arr[index].pushHere.PrintStructList();
    }

    void changeElement(int key, size_t secondaryKey, T value)
    {
        arr[key].pushHere.changeNodeVal(value, secondaryKey);
    }

    /*void instertOnPos(T input, int index)
    {
        Node<T> nulldata(0);
        arr[index].pushHere.InsertStructNode(input, index, nulldata);
    }*/

    void printIndex(int index)
    {
        arr[index].pushHere.PrintStructList();
    }

    void delet(int index, int secondaryKey)
    {
        arr[index].pushHere.RemoveNode(secondaryKey);
    }

    private:
    template <typename nodeType>
    struct Node
    {
        T data;
        Node(T input) : data(input) {}
    };
    struct listWNodes
    {
        list<Node<T> > pushHere;
    };
    const int size = 10;
    listWNodes* arr = new listWNodes[size];
};

int main()
{
    
}
