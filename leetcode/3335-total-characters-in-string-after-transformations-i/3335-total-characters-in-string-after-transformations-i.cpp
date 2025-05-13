class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        
        // Use a vector to track counts of each character after each transformation
        vector<long long> counts(26, 0);
        
        // Initialize counts from initial string
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        // Perform t transformations
        for (int i = 0; i < t; i++) {
            vector<long long> newCounts(26, 0);
            
            // Process each character count
            for (int j = 0; j < 26; j++) {
                if (j == 25) { // 'z'
                    // 'z' becomes "ab"
                    newCounts[0] = (newCounts[0] + counts[j]) % MOD; // 'a'
                    newCounts[1] = (newCounts[1] + counts[j]) % MOD; // 'b'
                } else {
                    // Other characters become the next character
                    newCounts[j + 1] = (newCounts[j + 1] + counts[j]) % MOD;
                }
            }
            
            counts = newCounts;
        }
        
        // Calculate total length after t transformations
        long long totalLength = 0;
        for (long long count : counts) {
            totalLength = (totalLength + count) % MOD;
        }
        
        return static_cast<int>(totalLength);
    }
};