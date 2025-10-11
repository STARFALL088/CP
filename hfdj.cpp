#include <iostream>

using namespace std;

double volume(int r, int h, double z)
{
    return r*h*z;
}

double volume(int h, double r, double z)
{
    return r*h*z;
}

int main()
{
    cout << volume(2,3,4);
}