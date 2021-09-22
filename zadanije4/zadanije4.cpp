#include <iostream>

#include <stdlib.h>

#include <fstream>

#include <bitset>


class Protocol {
  public:

    virtual void send(char * buf, int len) {};

};

class BinaryProtocol: public Protocol {

  public: char * buffer;
  void send(char * buf, int len) {
    buffer = (char * ) malloc(len * sizeof(char));
    buffer = buf;
    for (int i = 0; i < len; i++)
      std::cout << std::bitset < 4 > (buffer[i]).to_string() << " ";
  }
};

class HexProtocol: public Protocol {
  public: char * buffer;
  void send(char * buf, int len) {
    buffer = (char * ) malloc(len * sizeof(char));
    buffer = buf;
    for (int i = 0; i < len; i++)
      std::cout << "0x" << std::hex << int(buffer[i]) << " ";
  }

};

int main() {
  HexProtocol heh;
  char sample[15] = "its working";
  heh.send(sample, sizeof(sample) / sizeof(char));

}
