#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int size;
        cin >> size;
        std::vector < int > p(size);
        for (int i = 0; i < size; i++)
            cin >> p[i];
        sort(p.begin(), p.end());
        bool vua = 0;
        for (int i = 0; i < size; i++) if (p[i ] > i+1) vua = 1;
        if (vua==1&&size!=1) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;

    }
}