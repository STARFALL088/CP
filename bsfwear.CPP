lli l = 0, h = (lli)2e18;
lli ans = h;

while (l <= h) {
    lli mid = (l + h) >> 1; // Equivalent to (l + h) / 2
    if (f(mid)) {
        ans = mid;
        h = mid - 1;
    } else {
        l = mid + 1;
    }
}

// Replace f(mid) with your condition function