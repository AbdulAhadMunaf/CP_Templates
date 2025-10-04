class segmentTree
{
private:
    struct item
    {
        int v;
    };
    int size;
    vector<item> store;
    item NEUTRAL_ELEMENT = {0ll};

    item merge(item a, item b) { return {max(a.v, b.v)}; }
    item single(int v) { return {v}; }

    void set_point(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            store[x] = single(v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set_point(i, v, 2 * x + 1, lx, mid);
        else
            set_point(i, v, 2 * x + 2, mid, rx);
        store[x] = merge(store[2 * x + 1], store[2 * x + 2]);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                store[x] = single(a[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        store[x] = merge(store[2 * x + 1], store[2 * x + 2]);
    }

    item get_range(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
            return store[x];
        int mid = (lx + rx) / 2;
        item left = get_range(l, r, 2 * x + 1, lx, mid);
        item right = get_range(l, r, 2 * x + 2, mid, rx);
        return merge(left, right);
    }

public:
    segmentTree() : size(0) {}

    void init(int n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        store.assign(2 * size, NEUTRAL_ELEMENT);
    }

    void build(vector<int> &a) { build(a, 0, 0, size); }

    // inclusive [l, r] query
    item get(int l, int r)
    {
        if (l > r)
            return NEUTRAL_ELEMENT;
        return get_range(l, r + 1, 0, 0, size);
    }

    void set(int i, int v) { set_point(i, v, 0, 0, size); }
};