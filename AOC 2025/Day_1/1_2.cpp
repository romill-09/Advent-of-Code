#include <bits/stdc++.h>

using namespace std;

#define rl09 romill_09
#define int long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vp vector<pii>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define vinput(a)    \
   for (auto &i : a) \
      cin >> i;
#define print(a)        \
   for (auto x : a)     \
      cout << x << " "; \
   cout << endl
#define printP(a)   \
   for (auto x : a) \
   cout << x.F << " " << x.S << endl
#define printR(a, x, y)        \
   for (int i = x; i < y; i++) \
      cout << a[i] << " ";     \
   cout << endl

inline int power(int a, int b)
{
   int x = 1;
   while (b)
   {
      if (b & 1)
         x *= a;
      a *= a;
      b >>= 1;
   }
   return x;
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
   const char *comma = strchr(names + 1, ',');
   cout.write(names, comma - names) << " : " << arg1 << " | ";
   __f(comma + 1, args...);
}

const int MOD = 100;

void solve()
{
   string s;
   long long zeroes = 0;

   // Dial starts at 50
   int current = 50;

   while (cin >> s)
   {
      char dir = s[0]; // 'R' or 'L'
      long long dist = stoll(s.substr(1));

      // t0 = steps until the FIRST time we hit 0
      int t0;

      if (dir == 'R')
      {
         // Moving right increases the number
         // We hit 0 after reaching 100
         t0 = (MOD - current) % MOD;
         if (t0 == 0)
            t0 = MOD; // If already 0, next hit is after 100 steps
      }
      else
      {
         // Moving left decreases the number
         // We hit 0 after stepping current times
         t0 = current % MOD;
         if (t0 == 0)
            t0 = MOD; // If already 0, next hit is after 100 steps
      }

      // Count total hits of 0 DURING the rotation.
      // If dist < t0 → we never reach 0.
      if (dist >= t0)
      {
         // 1 hit at t0, and additional hits every 100 steps after that
         zeroes += 1 + (dist - t0) / MOD;
      }

      // Update the dial's final position.
      // The +MOD ensures the modulo is always non-negative.
      current = ((current + (dir == 'R' ? dist : -dist)) % MOD + MOD) % MOD;
   }

   cout << zeroes << endl;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   clock_t z = clock();

   solve();

   return 0;
}