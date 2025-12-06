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

const int MOD = 1e9 + 7;

// O(n^2)
// void solve()
// {
//    string s;

//    int sumJolt = 0;

//    int c = 0;
//    while (getline(cin, s))
//    {
//       int n = sz(s);
//       int first = 0, second = 0;
//       int res = 0;
//       int mx = 0;
//       for (int i = 0; i < n - 1; ++i)
//       {
//          if (s[i] - '0' <= first)
//             continue;
//          c++;
//          first = s[i] - '0';
//          second = *max_element(s.begin() + i + 1, s.end()) - '0';
//          res = (first * 10 + second);

//          mx = max(mx, res);
//          res = 0;
//       }
//       sumJolt += mx;
//    }
//    bug(c);
//    cout << sumJolt << endl;
// }

// O(n) Precomputation of max suffixes
void solve()
{
   string s;
   int sumJolt = 0;

   while (getline(cin, s))
   {
      int n = sz(s);
      vector<int> suffixMax(n, -1);

      int curr = -1;
      for (int i = n - 1; i >= 0; --i)
      {
         if (i + 1 < n)
            curr = max(curr, (int)(s[i + 1] - '0'));

         suffixMax[i] = curr;
      }

      int mx = 0, first = -1;
      for (int i = 0; i < n - 1; ++i)
      {
         if (s[i] - '0' <= first)
            continue;

         first = s[i] - '0';
         int second = suffixMax[i];
         int res = (first * 10 + second);

         mx = max(mx, res);
         res = 0;
      }
      // bug(mx);
      sumJolt += mx;
   }

   cout << sumJolt;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   clock_t z = clock();

   int t = 1;
   while (t--)
      solve();

   cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

   return 0;
}