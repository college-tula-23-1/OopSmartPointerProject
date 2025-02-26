#include <iostream>
#include "SmartPointer.h"

class Resource
{
    int value;
public:
    Resource(int value = 0) : value { value }
    {
        std::cout << "Resource construct\n";
    }

    int& Value() { return value; }

    ~Resource()
    {
        std::cout << "Resource destruct\n";
    }
};

void Func()
{
    SmartPointer<Resource> resource(new Resource(100));

    resource->Value() = 100;
    (*resource).Value() = 200;

    SmartPointer<Resource> resource2(resource);

    int n;
    std::cout << "input n: ";
    std::cin >> n;

    if (n == 0)
        return;

    std::cout << "other code\n";
}

int main()
{
    
    Func();

    Resource* r = new Resource();
    r->Value() = 200;
    (*r).Value() = 300;
    
}
