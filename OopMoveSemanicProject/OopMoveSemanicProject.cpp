#include <iostream>

void ValueArg(int& n)
{
    std::cout << "l-value func work\n";
}

void ValueArg(int&& n)
{
    std::cout << "r-value func work\n";
}


int main()
{
    int a{ 100 };
    ValueArg(a);
    ValueArg(300);
}
