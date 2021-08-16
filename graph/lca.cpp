// ABC014 D
// https://atcoder.jp/contests/abc014/tasks/abc014_4

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
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

using mint = modint1000000007;

using Graph = vector<vector<int>>;

struct LCA
{
  vector<vector<int>> parent; // parent[d][v] := 2^d-th parent of v
  vector<int> depth;
  LCA() {}
  LCA(const Graph &G, int r = 0) { init(G, r); }
  void init(const Graph &G, int r = 0)
  {
    int V = (int)G.size();
    int h = 1;
    while ((1 << h) < V)
      ++h;
    parent.assign(h, vector<int>(V, -1));
    depth.assign(V, -1);
    dfs(G, r, -1, 0);
    for (int i = 0; i + 1 < (int)parent.size(); ++i)
      for (int v = 0; v < V; ++v)
        if (parent[i][v] != -1)
          parent[i + 1][v] = parent[i][parent[i][v]];
  }
  void dfs(const Graph &G, int v, int p, int d)
  {
    parent[0][v] = p;
    depth[v] = d;
    for (auto e : G[v])
      if (e != p)
        dfs(G, e, v, d + 1);
  }
  int get(int u, int v)
  {
    if (depth[u] > depth[v])
      swap(u, v);
    for (int i = 0; i < (int)parent.size(); ++i)
      if ((depth[v] - depth[u]) & (1 << i))
        v = parent[i][v];
    if (u == v)
      return u;
    for (int i = (int)parent.size() - 1; i >= 0; --i)
    {
      if (parent[i][u] != parent[i][v])
      {
        u = parent[i][u];
        v = parent[i][v];
      }
    }
    return parent[0][u];
  }
};

int main(void)
{
  int n;
  cin >> n;
  Graph g(n);
  FOR(i, 0, n - 2)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].PB(b);
    g[b].PB(a);
  }

  LCA lca(g);

  int q;
  cin >> q;
  FOR(i, 0, q - 1)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;

    int lcanum = lca.get(a, b);

    int len = lca.depth[a] + lca.depth[b] - 2 * lca.depth[lcanum];
    cout << len + 1 << endl;
  }
}
