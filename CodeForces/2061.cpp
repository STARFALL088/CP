#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<ll, int> freq;
    for (ll x : arr)
    {
        freq[x]++;
    }

    for (auto i : freq)
    {
        ll val = i.first;
        ll count = i.second;
        if (count >= 4)
        {
            cout << val << " " << val << " " << val << " " << val << "\n";
            return;
        }
    }

    vector<ll> pairs;
    vector<ll> singles;

    for (auto i : freq)
    {
        ll val = i.first;
        ll count = i.second;
        if (count >= 2)
        {
            pairs.push_back(val);
            if (count > 2)
            {
            }
        }
        else
        {
            singles.push_back(val);
        }
    }

    if (pairs.size() >= 2)
    {
        cout << pairs[0] << " " << pairs[0] << " " << pairs[1] << " " << pairs[1] << "\n";
        return;
    }

    if (pairs.size() == 1 && singles.size() >= 2)
    {
        sort(singles.begin(), singles.end());
        for (int i = 1; i < singles.size(); i++)
        {
            ll l = pairs[0];
            ll base1 = singles[i - 1];
            ll base2 = singles[i];

            if (2 * l > abs(base1 - base2))
            {
                cout << l << " " << l << " " << base1 << " " << base2 << "\n";
                return;
            }
        }
    }

    cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
} 