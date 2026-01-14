
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
vector<vi> multiply(vector<vi> &a, vector<vi> &b)
{
    int n = a.size();
    vector<vi> res(n, vi(n, inf));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return res;
}
 
vector<vi> matrix_expo(vector<vi> v, int p)
{
    int n = v.size();
    vector<vi> res(n, vi(n, 0));
 
    while (p)
    {
        if (p & 1)
            res = multiply(res, v);
        v = multiply(v, v);
        p >>= 1;
    }
    return res;
}
 