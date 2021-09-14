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
        buf = new char[strlen(tbuf) + 1];
        for (int i = 0; i < strlen(tbuf) + 1; i++) buf[i] = tbuf[i];
        
    }
    ~FooString()
    {
        delete[] buf;
    }
    void show()
    {
        cout << buf;
    }
    
    bool compare(char* str)
    {
        
        if (strlen(buf) != strlen(str)) 
        {
            return false;
        }
        else 
        {
            for (int i = 0; i < strlen(buf) + 1; i++) {
                if (buf[i] != str[i]) return false;
            }
        }
        return true;
    }

   
};



int main()
{
   char stri[10] = "abc";
   char capi[10] = "adc";
    FooString lol(stri);
    cout << lol.compare(capi);
    return 0;
}
