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
   vector<string> lines;
   string line;
   while (getline(cin, line))
   {
      if (!line.empty())
         lines.push_back(line);
   }

   int rows = sz(lines) - 1;
   int cols = sz(lines[0]);

   auto isSep = [&](int c)
   {
      for (int r = 0; r <= rows; ++r)
         if (lines[r][c] != ' ')
            return false;
      return true;
   };

   vi nums;
   char op = 0;
   int ans = 0;

   for (int c = cols - 1; c >= 0; --c)
   {
      if (isSep(c))
      {
         if (!nums.empty())
         {
            int res = (op == '+') ? 0 : 1;
            for (int x : nums)
            {
               if (op == '+')
                  res += x;
               else
                  res *= x;
            }
            ans += res;
            nums.clear();
            op = 0;
         }
         continue;
      }

      string s;
      for (int r = 0; r < rows; ++r)
      {
         char ch = lines[r][c];
         if (ch >= '0' && ch <= '9')
            s.push_back(ch);
      }
      if (!s.empty())
         nums.pb(stoll(s));

      char chOp = lines[rows][c];
      if (chOp == '+' || chOp == '*')
         op = chOp;
   }

   if (!nums.empty())
   {
      int res = (op == '+') ? 0 : 1;
      for (int x : nums)
      {
         if (op == '+')
            res += x;
         else
            res *= x;
      }
      ans += res;
   }

   cout << ans << endl;
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
