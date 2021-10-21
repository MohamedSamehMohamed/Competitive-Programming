struct BIT
{
    int tree[N];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    void add(int pos, int val)
    {
        for(++pos ; pos <= N ; pos += (pos & (-pos))) tree[pos - 1] += val;
    }
    int get(int pos)
    {
        int ret = 0;
        for(++pos ; pos ; pos -= (pos & (-pos))) ret += tree[pos - 1];
        return ret;
    }
}bit;





// tourist


template <typename T>
class MyFenwick {
public:
    vector<T> bitArray;
    int n;

    MyFenwick(int _n) : n(_n) {
        bitArray.resize(n);
    }

    void modify(int x, T v) {
        while (x < n) {
            bitArray[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {
        T v{};
        while (x >= 0) {
            v += bitArray[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};
