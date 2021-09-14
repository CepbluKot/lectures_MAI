#include <iostream>
#include <cstring>
using namespace std;

class FooString
{
private:
    char* buf;
public:
    FooString(char* tbuf) 
    {
        int size = strlen(buf) + 1;
        buf = new char[size];
        cout << size;
        
    }
    ~FooString()
    {
        delete[] buf;
    }
    void show()
    {
        
    }
    
    bool compare(FooString str)
    {

    }

   
};



int main()
{
   char str[10] = "abc";
   
    FooString lol(str);
    return 0;
}
