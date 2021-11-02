#include <string>
#include <sstream>
#include "list_h_task2.h"
#include <typeinfo>
template <class T>
std::string toString(const T &x)
{
    std::ostringstream ss;
    ss << x;
    return ss.str();
}

template <class T>
std::string structToString(const T &x)
{
    std::ostringstream ss;
    ss << x.data;
    return ss.str();
}

template <typename T>
int hashFuncMain(T data, int tableSize, int key)
{
    int result = 0;
    std::string sData = toString<T>(data);
    for (int i = 0; i < sData.size(); i++)
    {
        result += key * (sData[i] - '0');
        key *= 2;
    }
    return result % tableSize;
}

template <typename T>
int hashFunc1(T &data, int tableSize)
{
    return hashFuncMain(data, tableSize, tableSize - 1);
}

template <typename T>
class hashTable
{
private:
    template <typename nodeType>
    struct Node
    {
        int count;
        nodeType data;
        Node() : count(1){};
        Node(nodeType input) : data(input), count(1) {}
    };

    struct listWNodes
    {
        list<Node<T> > pushHere;
    };
    int size;
    listWNodes *arr;

public:
    hashTable(int inputSize)
    {
        size = inputSize;
        arr = new listWNodes[size];
    }
    ~hashTable()
    {
    }

    void add(T elem)
    {
        bool alreadyInList = false;
        int index = hashFunc1(elem, size);
        for (int secondary_key = 0; secondary_key < arr[index].pushHere.listSize(); secondary_key++)
        {
            if (arr[index].pushHere.GetElement(secondary_key).data == elem)
            {
                alreadyInList = true;
                Node<T> newNode;
                newNode.data = elem;
                newNode.count = arr[index].pushHere.GetElement(secondary_key).count + 1;
                //std::cout<<"\n id: "<<arr[index].pushHere.GetElement(secondary_key).count<<std::endl;
                changeElement(index, secondary_key, newNode);
            }
        }

        if (!alreadyInList)
        {
            arr[index].pushHere.pushBack(elem);
        }
    }

    void changeElement(int key, size_t secondaryKey, Node<T> value)
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

    int getLen()
    {
        return size;
    }
};
