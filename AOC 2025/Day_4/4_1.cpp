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
   vector<vector<char>> grid, dummy;
   string line;

   while (getline(cin, line))
   {
      vector<char> row(all(line));
      grid.pb(row);
   }

   dummy = grid;
   int rows = sz(grid);
   int cols = sz(grid[0]);

   int rolls = 0;
   for (int i = 0; i < rows; ++i)
   {
      for (int j = 0; j < cols; ++j)
      {
         int adjacent = 0;
         if (grid[i][j] == '@')
         {
            if (j < cols - 1 && grid[i][j + 1] == '@') // right
               adjacent++;
            if (j > 0 && grid[i][j - 1] == '@') // left
               adjacent++;
            if (i < rows - 1 && grid[i + 1][j] == '@') // top
               adjacent++;
            if (i > 0 && grid[i - 1][j] == '@') // bottom
               adjacent++;
            if (i < rows - 1 && j < cols - 1 && grid[i + 1][j + 1] == '@') // bottom right
               adjacent++;
            if (i > 0 && j > 0 && grid[i - 1][j - 1] == '@') // top left
               adjacent++;
            if (i < rows - 1 && j > 0 && grid[i + 1][j - 1] == '@') // bottom left
               adjacent++;
            if (i > 0 && j < cols - 1 && grid[i - 1][j + 1] == '@') // top right
               adjacent++;

            if (adjacent < 4)
            {
               rolls++;
               // grid[i][j] = '.';
            }
         }
      }
   }

   cout << rolls << endl;
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

   // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

   return 0;
}