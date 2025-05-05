class Solution {
private:
    /**
    * c++17이하는 primitive가 아니면 직접 hash 함수를 정의해야 한다.
    20부터는 pair에도 hash function을 제공함.
    
    T에 대해 std::hash<T>()(value)로 해시 값을 계산.
    (해시값 % 버킷 수)로 어느 버킷에 넣을지 지정한다.
    같은 bucket에 여러 값이 들어갈 수 있어서, 체이닝(chaining) 또는 open addressing 방식으로 충돌을 해결(STL은 일반적으로 체이닝 방식 사용).

    1. 다른 값은 서로 다른 해시값이 되어야한다.
    2. 빠르게 계산 가능해야 한다. (O(1)에 가까워야 함)
    3. 동일 값 입력 시 동일한 해시값이 되어야 한다.
    **/
    struct UnorderedPairHash {
        size_t operator()(const pair<int, int>& p) const {
            int a = min(p.first, p.second);
            int b = max(p.first, p.second);
            return hash<int>()(a) ^ (hash<int>()(b) << 1);
            // 둘의 해시값을 가져와 섞음.
        }
    };

    // 해시 충돌 시 ==으로 값의 차이를 판단하므로 비교연산을 재정의(기본 pair 사용x)
    struct UnorderedPairEqual {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return (a.first == b.first && a.second == b.second) ||
                (a.first == b.second && a.second == b.first);
        }
    };

public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int countEqual = 0;
        // 해시 기반 컨테이너이므로 해시 함수가 필요함.
        unordered_map<pair<int, int>, int, UnorderedPairHash, UnorderedPairEqual> m;

        for (auto d: dominoes) {
            pair<int, int> dPair{d[0], d[1]};
            // if (dPair.first > dPair.second) {
            //     swap(dPair.first, dPair.second);
            // }
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