#include <iostream>

template <typename T>
class smartPtr
{
    T *object;
    
    public:
    // передача объекта
    smartPtr(T* dataForObject) : object(dataForObject) { }
    
    // АВТО чистка
    ~smartPtr()
    {
        delete object;
    } 

    // перегрузка операторов (чтобы можно было с их помощью обращатсья)
    T* operator->() 
    {
        return object;
    }
    T& operator*()
    {
        return *object;
    }
};


int main()
{
    int* dataz = new int(12);
    smartPtr<int> smth(dataz);
    std::cout<<*smth;
}