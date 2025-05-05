class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int countEqual = 0;
        map<pair<int, int>, int> m;

        for (auto d: dominoes) {
            pair<int, int> dPair{d[0], d[1]};
            if (dPair.first > dPair.second) {
                swap(dPair.first, dPair.second);
            }
            ++m[dPair];
        }

        for (auto n: m) {
            if (n.second > 1) {
                countEqual += n.second * (n.second - 1) / 2;
            }
        }

        return countEqual;
    }
};