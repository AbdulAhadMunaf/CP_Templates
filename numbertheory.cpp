#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

int mul(int A, int B)
{
    if (log10l(A) + log10l(B) > 18.3)
        return 3e18;
    return A * B;
}

int log(int a, int b)
{
    int ans = 0;
    while (a >= b)
        a /= b, ans++;
    return ans;
}

int sqrt(int n)
{
    int x = 1;
    bool decreased = false;
    for (;;)
    {
        int nx = (x + n / x) >> 1;
        if (x == nx || nx > x && decreased)
            break;
        decreased = nx < x;
        x = nx;
    }
    return x;
}

int floorSqrt(int x)
{
    if (x == 0 || x == 1)
        return x;

    int start = 1, end = x / 2, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int sqr = mid * mid;
        if (sqr == x)
            return mid;

        if (sqr <= x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void preprocess()
{
    fac[0] = inv_fac[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fac[i] = (i * fac[i - 1]) % mod;
        inv_fac[i] = binpow(fac[i], mod - 2, mod);
    }
}
int NCR(int n, int r)
{
if (r > n)
{
    return 0;
}
    return (((fac[n] * inv_fac[n - r]) % mod) * inv_fac[r]) % mod;
}



// For linear Diophantine eqs

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}

int binpow(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector<int> getdivs(int n)
{
    vector<int> divs;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }

    // getunique(divs);
    return divs;
}

bool prime[15000105];
void sieve(int n)
{
    for (int i = 0; i <= n; i++)
        prime[i] = 1;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = prime[0] = 0;
}
