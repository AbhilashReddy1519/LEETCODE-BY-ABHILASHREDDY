#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<int> P(N), Q(N);
  for (int &x : P)
  {
    cin >> x;
    --x;
  }
  for (int &x : Q)
  {
    cin >> x;
    --x;
  }

  /*
      Construct permutation f on positions.

      f[i] = position in Q where P[i] occurs.

      The graph consisting of edges
          i -> f[i]
      is a collection of cycles.
  */
  vector<int> posQ(N);
  for (int i = 0; i < N; ++i)
    posQ[Q[i]] = i;

  vector<int> f(N);
  for (int i = 0; i < N; ++i)
    f[i] = posQ[P[i]];

  vector<int> vis(N, 0);

  /*
      dp[a][b] = number of ways of choosing, for every value,
      which of its two occurrences eventually belongs to P.

      For a column:
          00 -> counted by a
          01 -> counted by b
          10 -> counted by c
          11 -> counted by d

      Since there are N zeroes and N ones:
          a = d
          c = N - 2*a - b
  */
  int S = N + 1;
  auto id = [S](int a, int b)
  {
    return a * S + b;
  };

  vector<ll> dp(S * S, 0);
  dp[id(0, 0)] = 1;

  /*
      Compute the initial distribution.

      For every cycle of f, let its vertices be

          v0 -> v1 -> ... -> v(L-1) -> v0.

      For every edge choose which endpoint gets 0.

      Let s_i be the bit put on the P-cell of vertex v_i.

      At vertex v_i:
          top    = s_i
          bottom = 1 - s_{i-1}

      Therefore:
          (0,0): a++  if prev=1, cur=0
          (0,1): b++  if prev=0, cur=0
          (1,0): c++
          (1,1): d++

      We only need a and b.

      We process each cycle while keeping the global dp.
      This costs O(N^3) total.
  */

  for (int root = 0; root < N; ++root)
  {
    if (vis[root])
      continue;

    vector<int> cyc;
    int v = root;

    while (!vis[v])
    {
      vis[v] = 1;
      cyc.push_back(v);
      v = f[v];
    }

    int L = (int)cyc.size();

    /*
        Process this cycle.

        We have to fix s_{L-1}, because the cycle closes.
        Try both possible values 0 and 1.
    */

    vector<ll> newdp(S * S, 0);

    for (int start = 0; start <= 1; ++start)
    {
      // cur[last][a][b]
      vector<ll> cur0(S * S, 0);
      vector<ll> cur1(S * S, 0);

      // Before processing the first vertex,
      // the previous bit is s_{L-1} = start.
      if (start == 0)
      {
        for (int a = 0; a <= N / 2; ++a)
        {
          for (int b = 0; 2 * a + b <= N; ++b)
          {
            cur0[id(a, b)] = dp[id(a, b)];
          }
        }
      }
      else
      {
        for (int a = 0; a <= N / 2; ++a)
        {
          for (int b = 0; 2 * a + b <= N; ++b)
          {
            cur1[id(a, b)] = dp[id(a, b)];
          }
        }
      }

      for (int pos = 0; pos < L; ++pos)
      {
        vector<ll> nxt0(S * S, 0);
        vector<ll> nxt1(S * S, 0);

        for (int a = 0; a <= N / 2; ++a)
        {
          for (int b = 0; 2 * a + b <= N; ++b)
          {
            int idx = id(a, b);

            ll x0 = cur0[idx];
            ll x1 = cur1[idx];

            /*
                previous = 0, current = 0:
                    type 01 -> b++
            */
            if (x0)
            {
              if (b + 1 <= N - 2 * a)
              {
                ll &z = nxt0[id(a, b + 1)];
                z += x0;
                if (z >= MOD)
                  z -= MOD;
              }

              /*
                  previous = 0, current = 1:
                      type 11
                      nothing to track
              */
              ll &z = nxt1[idx];
              z += x0;
              if (z >= MOD)
                z -= MOD;
            }

            /*
                previous = 1, current = 0:
                    type 00 -> a++
            */
            if (x1)
            {
              if (2 * (a + 1) + b <= N)
              {
                ll &z = nxt0[id(a + 1, b)];
                z += x1;
                if (z >= MOD)
                  z -= MOD;
              }

              /*
                  previous = 1, current = 1:
                      type 10
                      nothing to track
              */
              ll &z = nxt1[idx];
              z += x1;
              if (z >= MOD)
                z -= MOD;
            }
          }
        }

        cur0.swap(nxt0);
        cur1.swap(nxt1);
      }

      /*
          Close the cycle.

          If the initial previous bit was start,
          the final bit must also be start.
      */
      for (int a = 0; a <= N / 2; ++a)
      {
        for (int b = 0; 2 * a + b <= N; ++b)
        {
          int idx = id(a, b);

          ll val = (start == 0 ? cur0[idx] : cur1[idx]);

          newdp[idx] += val;
          if (newdp[idx] >= MOD)
            newdp[idx] -= MOD;
        }
      }
    }

    dp.swap(newdp);
  }

  /*
      Now dp[a][b] is the number of initial binary boards
      corresponding to the choices of which occurrence of each
      value eventually belongs to P.
  */

  /*
      Board DP.

      State:
          a = #00
          b = #01
          c = N - 2a - b
          d = a

      Target:
          a = 0
          b = N
      because every column is 01.

      From a state, count how many operations produce each state.

      Row swaps:
        00 <-> 11:
            a--, b++
            2 * a^2 choices

        01 <-> 10:
            a++, b--
            2 * b * c choices

        all other row swaps:
            state unchanged
            N(N-1) - 2a^2 - 2bc choices

      Column swaps:
        01 -> 10:
            b--
            b choices

        10 -> 01:
            b++
            c choices

        00 or 11:
            state unchanged
            2a choices

      Therefore:
          same =
              N(N-1) - 2a^2 - 2bc + 2a
  */

  vector<ll> cur = dp;
  vector<ll> nxt(S * S, 0);

  for (int step = 0; step < M; ++step)
  {
    fill(nxt.begin(), nxt.end(), 0);

    for (int a = 0; a <= N / 2; ++a)
    {
      for (int b = 0; 2 * a + b <= N; ++b)
      {
        int idx = id(a, b);
        ll val = cur[idx];

        if (val == 0)
          continue;

        ll c = N - 2LL * a - b;

        // Number of operations that leave (a,b) unchanged.
        ll same =
            1LL * N * (N - 1) - 2LL * a * a - 2LL * b * c + 2LL * a;

        same %= MOD;
        if (same < 0)
          same += MOD;

        // 1. Same state
        {
          ll add = val * same % MOD;
          nxt[idx] += add;
          if (nxt[idx] >= MOD)
            nxt[idx] -= MOD;
        }

        // 2. 00 + 11 -> 01 + 10
        //    (a,b) -> (a-1,b+1)
        if (a > 0)
        {
          ll ways = 2LL * a * a % MOD;
          ll add = val * ways % MOD;

          int ni = id(a - 1, b + 1);
          nxt[ni] += add;
          if (nxt[ni] >= MOD)
            nxt[ni] -= MOD;
        }

        // 3.  01 + 10 -> 00 + 11
        //    (a,b) -> (a+1,b-1)
        if (b > 0)
        {
          ll ways = 2LL * b * c % MOD;
          ll add = val * ways % MOD;

          int ni = id(a + 1, b - 1);
          nxt[ni] += add;
          if (nxt[ni] >= MOD)
            nxt[ni] -= MOD;
        }

        // 4. Column swap: 01 -> 10
        //    b--
        if (b > 0)
        {
          ll add = val * b % MOD;

          int ni = id(a, b - 1);
          nxt[ni] += add;
          if (nxt[ni] >= MOD)
            nxt[ni] -= MOD;
        }

        // 5. Column swap: 10 -> 01
        //    b++
        if (c > 0)
        {
          ll add = val * c % MOD;

          int ni = id(a, b + 1);
          nxt[ni] += add;
          if (nxt[ni] >= MOD)
            nxt[ni] -= MOD;
        }
      }
    }

    cur.swap(nxt);
  }

  cout << cur[id(0, N)] % MOD << '\n';

  return 0;
}