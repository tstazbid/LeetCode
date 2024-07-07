class Solution {
public:
    string getEncryptedString(string s, int k) {
        k %= s.size();
        string base = s.substr(k);
        base += s.substr(0, k);
        return base;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)