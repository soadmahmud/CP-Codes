#include <iostream>
using namespacre std;

class base
{
    public:

    base()
    {
        cout << "Base Default\n";
    }
};

class child : public base
{
    public:

    child()
    {
        cout << "Chold class base\n";
    }
};

int main()
{
    child c;

    return 0;
}