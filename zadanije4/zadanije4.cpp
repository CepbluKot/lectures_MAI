#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <bitset>


class Protocol
{
public:

	virtual void send(char* buf, int len);

};


class BinaryProtocol : public Protocol
{

public:


	void send(char*, int);
};

class HexProtocol : public Protocol
{
public:

	char* buffer = nullptr;
	void send(char* buf, int len) {
		buffer = (char*)malloc(len * sizeof(char));
		buffer = buf;
	}
};

void BinaryProtocol::send(char* buf, int len)
{

}
/*
void HexProtocol::send(char* buf, int len)
{
	
}
*/
int main() {
	HexProtocol heh;
	char sample[8] = "c";
	heh.send(sample, 8);


}
