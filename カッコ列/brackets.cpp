/*
typ90 b
https://atcoder.jp/contests/typical90/tasks/typical90_b

文字列 C が正しいカッコ列であるための必要十分条件
条件1　すべての i (1≤i≤|C|)(1≤i≤|C|) について、左から i 文字目までの時点で ( より ) の方が多くなることはない
条件2　文字列 C は ( と ) から成り、これら 2 つが同数出現する。

https://qiita.com/e869120/items/1ccb2bdf16890637e767
*/

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
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
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
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

using mint = modint1000000007;

int main(void)
{
  int n;
  cin >> n;

  FOR(bit, 0, (1 << n) - 1)
  {
    string s;
    int left = 0;
    int right = 0;
    bool rgreater = false;
    FORD(i, n - 1, 0)
    {
      if (bit & (1 << i))
      {
        s += ")";
        ++right;
      }
      else
      {
        s += "(";
        ++left;
      }

      if (right > left)
        rgreater = true;
    }

    if (left != right || rgreater)
      continue;

    cout << s << endl;
  }
}
