#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " = [ ";                                                       \
  for (const auto &val : x)                                                    \
    cerr << val << " ";                                                        \
  cerr << "]\n";
#define error(args...)                                                         \
  {                                                                            \
    string _s = #args;                                                         \
    replace(_s.begin(), _s.end(), ',', ' ');                                   \
    stringstream _ss(_s);                                                      \
    istream_iterator<string> _it(_ss);                                         \
    _err(_it, args);                                                           \
  }
void _err(istream_iterator<string> it) { cerr << "\n"; }
template <typename T, typename... Args>
void _err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " | ";
  _err(++it, args...);
}
#else
#define debug(x)
#define error(...)
#endif

#endif // DEBUG_H