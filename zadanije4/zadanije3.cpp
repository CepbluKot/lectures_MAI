#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <bitset>
#include <string>
#include <sstream>

class Protocol
{
public:
  virtual void send(char *buf, int len){};
};

class BinaryProtocol : public Protocol
{

public:
  char *buffer;
  void send(char *buf, int len)
  {
    buffer = (char *)malloc(len * sizeof(char));
    buffer = buf;
    for (int i = 0; i < len; i++)
      std::cout << std::bitset<4>(buffer[i]).to_string() << " ";
  }
};

class HexProtocol : public Protocol
{
public:
  char *buffer;
  void send(char *buf, int len)
  {
    buffer = (char *)malloc(len * sizeof(char));
    buffer = buf;
    for (int i = 0; i < len; i++)
      std::cout << "0x" << std::hex << int(buffer[i]) << " ";
  }
};

struct ConnectionList
{
  Protocol *mas[100];
  int count = 0;
};

void addProtocol(ConnectionList *p, Protocol *newProtocol)
{
  p.mas[p.count] = newProtocol;
  p.count += 1;
}

int main(int argc, char **argv)
{
  BinaryProtocol bin;
  HexProtocol hex;

  char sample[9] = "software";
  std::string param = argv[1];
  std::ifstream in(param);
  std::string line;
  int count = 0;
  if (in.is_open())
  {
    while (getline(in, line))
    {
      if (line == "BinaryProtocol")
        bin.send(sample, 9);
      std::cout << std::endl;
      if (line == "HexProtocol")
        hex.send(sample, 9);
    }
  }
}
