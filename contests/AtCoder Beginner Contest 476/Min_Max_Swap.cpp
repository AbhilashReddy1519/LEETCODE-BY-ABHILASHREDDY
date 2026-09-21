#include <bits/stdc++.h>
using namespace std;

struct Node {
    pair<int, int> mn;
    pair<int, int> mx; 
};

class SegmentTree {
    int n;
    vector<Node> tree;
    Node merge(Node a, Node b) {
        Node res;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        return res;
    }
    void build(int node, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[node].mn = {arr[l], l};
            tree[node].mx = {arr[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, arr);
        build(node * 2 + 1, mid + 1, r, arr);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            tree[node].mn = {value, idx};
            tree[node].mx = {value, idx};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, value);
        else
            update(node * 2 + 1, mid + 1, r, idx, value);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) {
            return {
                {INT_MAX, -1},
                {INT_MIN, -1}
            };
        }
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = (l + r) / 2;
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, arr);
    }
    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }
    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }
    SegmentTree st(permutation);
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        Node res = st.query(l, r);
        int minValue = res.mn.first;
        int minIndex = res.mn.second;
        int maxValue = res.mx.first;
        int maxIndex = res.mx.second;

        swap(permutation[minIndex], permutation[maxIndex]);
        st.update(minIndex, permutation[minIndex]);
        st.update(maxIndex, permutation[maxIndex]);
    }
    for (int i = 0; i < n; i++) {
        cout << permutation[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}