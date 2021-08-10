/*
蟻本150P 領域の個数

線分の端点とその前後だけ見れば良い
端点+前後をぶち込んだvectorを作って、ソートして重複削除する

std::uniqueは隣接する重複要素を削除する
（戻り値は重複を除いた範囲の、末尾の次を指すイテレータ）
従って、重複削除の手順は sort => unique => erase
*/

#include <bits/stdc++.h>
using namespace std;
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

int w, h, n;
const int MAX_N = 501;
bool fld[MAX_N * 6][MAX_N * 6];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int compress(int *x1, int *x2, int w)
{
  vector<int> xs;
  FOR(i, 0, n - 1)
  {
    FOR(d, -1, 1)
    {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (1 <= tx1 && tx1 <= w)
        xs.PB(tx1);
      if (1 <= tx2 && tx2 <= w)
        xs.PB(tx2);
    }
  }

  SORT(xs);
  xs.erase(unique(ALL(xs)), xs.end());

  FOR(i, 0, n - 1)
  {
    x1[i] = find(ALL(xs), x1[i]) - xs.begin();
    x2[i] = find(ALL(xs), x2[i]) - xs.begin();
  }

  return xs.size();
}

int main()
{
  w = 10;
  h = 10;
  n = 5;

  int x1[MAX_N] = {1, 1, 4, 9, 10};
  int x2[MAX_N] = {6, 10, 4, 9, 10};
  int y1[MAX_N] = {4, 8, 1, 1, 6};
  int y2[MAX_N] = {4, 8, 10, 5, 10};

  w = compress(x1, x2, w);
  h = compress(y1, y2, h);

  MEMSET(fld, 0);
  FOR(i, 0, n - 1)
  {
    FOR(x, x1[i], x2[i])
    {
      FOR(y, y1[i], y2[i])
      {
        fld[y][x] = true;
      }
    }
  }

  int ans = 0;
  FOR(i, 0, w - 1)
  {
    FOR(j, 0, h - 1)
    {
      if (fld[j][i])
        continue;
      ++ans;

      queue<pair<int, int>> que;
      que.push(MP(j, i));
      while (!que.empty())
      {
        int quey = que.front().first;
        int quex = que.front().second;
        que.pop();

        FOR(dnum, 0, 3)
        {
          int nextx = quex + dx[dnum];
          int nexty = quey + dy[dnum];
          if (nextx < 0 || nextx >= w || nexty < 0 || nexty >= h)
            continue;
          if (fld[nexty][nextx])
            continue;

          que.push(MP(nexty, nextx));
          fld[nexty][nextx] = true;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}

