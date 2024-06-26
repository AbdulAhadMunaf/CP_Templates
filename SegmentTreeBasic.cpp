class segmentTree
{
private:
    // change
    struct item
    {
        int v;
    };

    int size;
    std::vector<item> store;

    // change
    item NEUTRAL_ELEMENT = {(int)1e10};

    // change
    item merge(item a, item b)
    {
        return {min(a.v, b.v)};
    }

    // change
    item single(int v)
    {
        return {v};
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            store[x] = single(v);
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
        {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            set(i, v, 2 * x + 2, mid, rx);
        }

        store[x] = merge(store[2 * x + 1], store[2 * x + 2]);
    }

    void build(std::vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < static_cast<int>(a.size()))
            {
                store[x] = single(a[lx]);
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);

        store[x] = merge(store[2 * x + 1], store[2 * x + 2]);
    }

    item get(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
        {
            return NEUTRAL_ELEMENT;
        }

        if (lx >= l && rx <= r)
        {
            return store[x];
        }

        int mid = (lx + rx) / 2;
        item left = NEUTRAL_ELEMENT;
        item right = left;
        left = get(l, r, 2 * x + 1, lx, mid);
        right = get(l, r, 2 * x + 2, mid, rx);

        return merge(left, right);
    }

public:
    segmentTree()
    {
        size = 0;
    }

    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        store.resize(2 * size);
    }
    
    void build(std::vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    item get(int l, int r)
    {
        r++;
        return get(l, r, 0, 0, size);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
};