#include <iostream>

int printN(int N)
{

    N != 0 ? printN(N - 1) : N = N;
    std::cout << "\n"
              << N;
    return N;
}

int main()
{
}