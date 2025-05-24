#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
// onek aager code
// aro optimize kora jay
    
    while (t--) {
        string s;
        cin >> s;
        
        int sum = 0;
        for (char c : s) {
            if (c != 'N' && c != 'W' && c != 'D') {
                sum++;
            }
        }
        
        if (sum < 6) {
            if (sum == 1) {
                cout << sum << " BALL" << endl;
            } else {
                cout << sum << " BALLS" << endl;
            }
        } else {
            int overs = sum / 6;
            int balls = sum % 6;
            
            if (overs == 1) {
                if (balls == 0) {
                    cout << overs << " OVER" << endl;
                } else if (balls == 1) {
                    cout << overs << " OVER " << balls << " BALL" << endl;
                } else {
                    cout << overs << " OVER " << balls << " BALLS" << endl;
                }
            } else {
                if (balls == 0) {
                    cout << overs << " OVERS" << endl;
                } else if (balls == 1) {
                    cout << overs << " OVERS " << balls << " BALL" << endl;
                } else {
                    cout << overs << " OVERS " << balls << " BALLS" << endl;
                }
            }
        }
    }
    
    return 0;
}