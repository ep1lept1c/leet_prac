vector<int> g[10000];
class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(0);
        vector<int> d(10010, -1), p(n);
        d[0] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 1; i <= 100; i++) {
                if (v + i*i > n){
                    break;
                }
                if (d[v + i*i] == -1) {
                    q.push(v + i*i);
                    d[v + i*i] = d[v] + 1;
                }
            }
        }
        return d[n];
    }
};
