
class segtree
{
    vector<long long> seg;

public:
    segtree(long long n)
    {
        seg.resize(4 * n + 1);
    }
    long long pull(long long a,long long b){
        return a^b;
    }
    void build(long long idx, long long low, long long high, long long arr[])
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        long long mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = pull(seg[2 * idx + 1] , seg[2 * idx + 2]);
    }
    long long query(long long idx, long long low, long long high, long long l, long long r)
    {
        // no overlap
        if (l > high || r < low)
            return 0;
        // complete ovarlap
        if (l <= low && r >= high)
            return seg[idx];

        long long mid = (low + high) >> 1;
        long long left = query(2 * idx + 1, low, mid, l, r);
        long long right = query(2 * idx + 2, mid + 1, high, l, r);
        return pull(left , right);
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    tc0
    {
        int n, q;
        cin >> n >> q;
        int arr[n];
        segtree seg1(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        seg1.build(0, 0, n - 1, arr);
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << seg1.query(0, 0, n - 1, --l, --r) << endl;
        }
    }
}