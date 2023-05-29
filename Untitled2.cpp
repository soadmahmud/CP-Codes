#include <bits/stdc++.h>
using namespace std;

class A
{
public:

    int x;

    A(int b)
    {
        x = b;
    }

    A()
    {

    }

    void operator++(A &obj)
    {

        obj.x = x + 1;
    }
};

int main()
{
    A obj(5);

    ++obj;

    cout << obj.x << endl;
}
