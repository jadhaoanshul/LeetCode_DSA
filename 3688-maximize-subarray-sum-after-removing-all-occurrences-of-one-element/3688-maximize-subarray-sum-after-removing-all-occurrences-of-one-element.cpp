using ll = long long;

struct Node
{
    ll prefix, suffix, sum, max_sum;

    Node(int val = 0)
    {
        prefix = suffix = sum = max_sum = val;
    }

    void change(int val)
    {
        prefix = suffix = sum = max_sum = val;
    }
};

class SegTree
{
private:
    int tree_size;
    vector<Node> seg_tree;

    Node merge(const Node &a, const Node &b)
    {
        Node result;

        result.sum = a.sum + b.sum;
        result.max_sum = max({a.max_sum, b.max_sum, a.suffix + b.prefix});

        result.prefix = max(a.prefix, a.sum + b.prefix);
        result.suffix = max(b.suffix, b.sum + a.suffix);

        return result;
    }

    void build(int lx, int rx, int ni, vector<int> &nums)
    {
        if (rx - lx == 1)
        {
            if (lx < nums.size())
                seg_tree[ni] = Node(nums[lx]);
            return;
        }

        int m = (lx + rx) >> 1;

        build(lx, m, ni * 2 + 1, nums);
        build(m, rx, ni * 2 + 2, nums);

        seg_tree[ni] = merge(seg_tree[ni * 2 + 1], seg_tree[ni * 2 + 2]);
    }

    void update(int idx, int val, int lx, int rx, int ni)
    {
        if (rx - lx == 1)
        {
            seg_tree[ni].change(val);
            return;
        }

        int m = (lx + rx) >> 1;

        if (idx < m)
            update(idx, val, lx, m, ni * 2 + 1);

        else
            update(idx, val, m, rx, ni * 2 + 2);

        seg_tree[ni] = merge(seg_tree[ni * 2 + 1], seg_tree[ni * 2 + 2]);
    }

public:
    SegTree(int n)
    {
        tree_size = 1;

        while (tree_size < n)
            tree_size <<= 1;

        seg_tree = vector<Node>(tree_size * 2, Node());
    }

    void build(vector<int> &nums)
    {
        build(0, tree_size, 0, nums);
    }

    void update(int idx, int val)
    {
        update(idx, val, 0, tree_size, 0);
    }

    ll query()
    {
        return seg_tree[0].max_sum;
    }
};

class Solution
{
public:
    long long maxSubarraySum(vector<int> nums)
    {
        int n = nums.size();
        int max_num = -1e6;

        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; ++i)
        {
            indices[nums[i]].push_back(i);
            max_num = max(max_num, nums[i]);
        }

        if (max_num <= 0)
            return max_num;

        SegTree seg_tree(n);
        seg_tree.build(nums);

        ll ans = seg_tree.query();

        for (const auto &[num, idx_vector] : indices)
        {

            for (const auto &idx : idx_vector)
                seg_tree.update(idx, 0);

            ans = max(ans, seg_tree.query());

            for (const auto &idx : idx_vector)
                seg_tree.update(idx, num);
        }

        return ans;
    }
};