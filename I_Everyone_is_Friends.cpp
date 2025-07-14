class segtree2 {
  vll seg2;

public:
  segtree2(int n) { seg2.resize(4 * n + 1); }

  void build(int idx, int low, int high, int arr[]) {
    if (low == high) {
      seg2[idx] = arr[low];
      return;
    }
    int mid = (low + high) >> 1;
    build(2 * idx + 1, low, mid, arr);
    build(2 * idx + 2, mid + 1, high, arr);
    seg2[idx] = min(seg2[2 * idx + 1], seg2[2 * idx + 2]);
  }
  int query(int idx, int low, int high, int l, int r) {
    // no overlap
    if (l > high || r < low)
      return 0;
    // complete ovarlap
    if (l <= low && r >= high)
      return seg2[idx];

    int mid = (low + high) >> 1;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return min(left, right);
  }
};

