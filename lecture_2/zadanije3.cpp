#include <iostream>

#include <cstring>

#include <string>

using namespace std;

class FooString {
private:
    char* buf;
public:
    FooString(char* tbuf) {

        buf = new char[strlen(tbuf) + 1];
        for (int i = 0; i < strlen(tbuf) + 1; i++) buf[i] = tbuf[i];

    }~FooString() {
        delete[] buf;
    }
    void show() {
        std::cout << buf;
    }

    bool compare(char* str) {

        if (strlen(buf) != strlen(str)) {
            return false;
        }
        else {
            for (int i = 0; i < strlen(buf) + 1; i++) {
                if (buf[i] != str[i]) return false;
            }
        }
        return true;
    }
};

bool testCompare() {
    char strOne[20] = "word";
    FooString strTwo(&(strOne[0]));
    return strTwo.compare(strOne);
}

void runTest(bool(*testFunction)(),
    const std::string& testName) {
    if (testFunction() == 1)
        std::cout << "Test " << testName << " - OK" << std::endl;
    else
        std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main() {
    runTest(testCompare, "testCompare");
    return 0;
}
