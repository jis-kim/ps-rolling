class Solution {
public:
    string addBinary(string a, string b) {
        auto aI = a.rbegin();
        auto bI = b.rbegin();

        bool up = false;
        int size = max(a.size(), b.size()) + 1;
        string result(size, '1');

        while (aI != a.rend() || bI != b.rend()) {
            int aNum = 0, bNum = 0;
            if (aI != a.rend()) {
                aNum = *aI - '0';
                ++aI;
            }
            if (bI != b.rend()) {
                bNum = *bI - '0';
                ++bI;
            }
            int n = aNum + bNum + (up ? 1 : 0);
            up = n >= 2;

            --size;
            if (n % 2 == 0) {
                result[size] = '0';
            }
        }
        if (!up) result.erase(0, 1);
        return result;
    }
};