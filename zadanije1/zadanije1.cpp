#include <iostream>
#include <string>
int variant(int variant, std::string name, std::string surname, int num) {
    if (variant == 1) {
        int sum = 0;
        for (int i = 0; i < surname.length(); i++)
            sum += surname[i] - 0;
        return sum % num;
    }
    if (variant == 2) {
        int sum = 0;
        return (name[0] - 0) % num;
    }
}


int main()
{   
    std::string name = "Igor";
    std::string surname = "Malysh";
    int var = 1;
    int num = 19;
    std::cout << variant(var, name, surname, num);
}

