#include<iostream>
using namespace std;

class r
{
    public:

    string name;

    int id;

    void set()
    {
        cin >> name >> id;
    }

    void show()
    {
        cout << "Name: " << name << endl << "ID: " << id << endl;
    }
};

int main()
{
    r a, b, c;

    a.set();

    b.set();

    c.set();

    a.show();

    b.show();

    c.show();

    return 0;
}
