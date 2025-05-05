class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int countEqual = 0;
        map<pair<int, int>, int> m;

        for (auto d: dominoes) {
            if (d[0] > d[1]) {
                swap(d[0], d[1]);
            }
            ++m[make_pair(d[0], d[1])];
        }

        for (auto n: m) {
            countEqual += n.second * (n.second - 1) / 2;
        }

        return countEqual;
    }
};