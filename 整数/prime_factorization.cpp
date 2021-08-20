#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(), (c).end())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define sqr(x) ((x) * (x))
#define bit(n) (1LL << (n))
#define pcnt(x) __builtin_popcountll(x)
#define PB push_back
#define MP make_pair
// using Edge = pair<int, int>;
// using Graph = vector<vector<Edge>>;
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

// using mint = modint1000000007;
using mint = modint998244353;
// const long double PI = 3.14159265358979;
// const int INF = 1001001001;

/*  PrimeFact
    init(N): 初期化。O(N log log N)
    get(n): クエリ。素因数分解を求める。O(log n)
 */
template <typename T>
struct PrimeFact
{
  vector<T> spf;
  PrimeFact(T N) { init(N); }
  void init(T N)
  {
    spf.assign(N + 1, 0);
    for (T i = 0; i <= N; i++)
      spf[i] = i;
    for (T i = 2; i * i <= N; i++)
    {
      if (spf[i] == i)
      {
        for (T j = i * i; j <= N; j += i)
        {
          if (spf[j] == j)
          {
            spf[j] = i;
          }
        }
      }
    }
  }
  map<T, T> get(T n)
  {
    map<T, T> m;
    while (n != 1)
    {
      m[spf[n]]++;
      n /= spf[n];
    }
    return m;
  }
};

int main()
{
  PrimeFact pf(10000);
  for (auto x : pf.get(999))
  {
    cout << x.first << " " << x.second << endl;
  }
}
