#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int test = 100000;

    // Open the output file
    ofstream outputFile("output.txt");
    if (!outputFile)
    {
        cerr << "Error opening the output file." << endl;
        return 1;
    }

    // Redirect cout to the output file
    streambuf* originalCoutBuffer = cout.rdbuf();
    cout.rdbuf(outputFile.rdbuf());

    cout << test << endl;

    int a = 2e5 - 1e4, b = 2;

    cout << a << endl;

    while (a--)
        cout << b << " ";

    cout << endl;

    while (test--)
    {
        a = 1;
        b = 2;

        cout << a << endl;

        while (a--)
        {
            if (a)
                cout << b << " ";
            else
                cout << b;
        }

        if (test)
            cout << endl;
    }

    // Restore cout to the original stream buffer
    cout.rdbuf(originalCoutBuffer);

    // Close the output file
    outputFile.close();

    return 0;
}
