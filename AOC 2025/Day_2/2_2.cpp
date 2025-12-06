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

void solve()
{
   string s, a, b;
   cin >> s;
   stringstream ss(s);
   vi invalidId;
   while (getline(ss, a, ','))
   {
      stringstream ss2(a);
      getline(ss2, a, '-');
      getline(ss2, b, '-');

      for (int i = stoll(a); i <= stoll(b); i++)
      {
         string numStr = to_string(i);
         int n = numStr.length();

         for (int j = 1; j <= n / 2; ++j)
         {
            if (n % j != 0)
               continue;

            string sub = numStr.substr(0, j);
            bool ok = true;

            for (int k = j; k < n; k += j)
            {
               if (numStr.substr(k, j) != sub)
               {
                  ok = false;
                  break;
               }
            }
            if (ok)
            {
               invalidId.pb(i);
               break;
            }
         }
      }
   }

   int sum = 0;
   for (int id : invalidId)
   {
      sum += id;
   }
   cout << sum << endl;
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   clock_t z = clock();

   int t = 1;
   //  cin >> t;
   while (t--)
      solve();

   // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

   return 0;
}