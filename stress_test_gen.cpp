#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    cout << rand() % 100 + 1 << endl;
    return 0;
}
