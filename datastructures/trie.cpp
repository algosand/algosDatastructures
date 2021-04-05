// I couldn't get this to work unfortunately.
template <class T>
class DSU
{
public:
    unordered_map<T, T> parent;
    unordered_map<T, int> size;
    DSU()
    {
        parent.clear();
        size.clear();
    };

    T ufind(T u)
    {
        if (parent.count(u) == 0)
        {
            return parent[u] = u;
        }
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = ufind(parent[u]);
    }

    bool uunion(T u, T v)
    {
        u = ufind(u);
        v = ufind(v);
        if (u != v)
        {
            if (size[u] < size[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
            return false;
        }
        return true;
    }

    void swap(T u, T v)
    {
        T temp = u;
        u = v;
        v = temp;
    }

    bool isConnected(T s, T e)
    {
        return ufind(s) == ufind(e);
    }
};

// Example of how to use this make sure to call DSU<char> dsu;  for instance if you want to specify the type to be char, and
// the variable name is dsu.