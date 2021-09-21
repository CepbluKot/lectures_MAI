#include <iostream>
#include <string>
#include <iostream>
#include <fstream>




class Protocol
{
public:
	virtual void send(char* buf, int len);	
};


class BinaryProtocol : public Protocol
{
	void send(char* buf, int len)
	{
	
	}
}

class HexProtocol : public Protocol
{
	void send(char* buf, int len)
	{
	
	}
}

void BinaryProtocol::send(char* buf, int len)
{
	
}

void HexProtocol::send(char* buf, int len)
{
	
}

int main(){
	
	
}
