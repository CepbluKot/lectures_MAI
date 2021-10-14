#include <iostream>
#include <stdlib.h>
#include <fstream>




class Protocol
{
public:
	virtual void send(char* buf, int len);	
};


class BinaryProtocol : public Protocol
{
    void send(char*, int);
};

class HexProtocol : public Protocol
{
    
    char* buffer;
    void send(char*, int);
};

void BinaryProtocol::send(char* buf, int len)
{
	
}

void HexProtocol::send(char* buf, int len)
{
    buffer = (char*) malloc (len * sizeof(char));
    buffer = buf;
}

int main(){
	
	
}
