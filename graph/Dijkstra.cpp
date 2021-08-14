/*
1. 始点に0を書き込む
2. 未確定の地点から最も小さい値を持つ地点を１つ選び、その値を確定させる
（必要に応じてルート記録）
3. 2で確定した地点から直接つながっていて、かつ未確定な地点に対してかかる時間を計算し、
書き込まれている数より小さければ更新する
4. 全ての地点が確定していれば終了、そうでなければ2に戻る

ヨビノリより引用
https://www.youtube.com/watch?v=X1AsMlJdiok
*/

// 問題はこれ
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(), (c).end())
#define PB push_back
#define MP make_pair
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define endl "\n"
// using Edge = pair<int, int>;
using P = pair<int, int>;
struct Edge
{
  int to, cost;
};
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

int V, E;
Graph G;
int d[100050]; //MAX_V
const int INF = 1001001001;

void dijkstra(int s)
{
  // P.fisrt => 最短距離
  // P.second => 頂点の番号
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
      continue;
    for (auto x : G[v])
    {
      if (d[x.to] > d[v] + x.cost)
      {
        d[x.to] = d[v] + x.cost;
        que.push(P(d[x.to], x.to));
      }
    }
  }
}

int main(void)
{
  int r;
  cin >> V >> E >> r;
  G.assign(V, vector<Edge>());
  FOR(i, 0, E - 1)
  {
    int s, t, d;
    cin >> s >> t >> d;
    Edge edge;
    edge.to = t;
    edge.cost = d;
    G[s].PB(edge);
  }
  dijkstra(r);
  FOR(i, 0, V - 1)
  {
    if (d[i] == INF)
      cout << "INF" << endl;
    else
      cout << d[i] << endl;
  }
}