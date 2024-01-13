class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> charFreq(26, 0);

        for(char ch: s) {
            charFreq[ch - 'a']++;
        }
        for(char ch: t) {
            charFreq[ch - 'a']--;
        }

        int steps = 0;
        for(int freq: charFreq) {
            steps = freq > 0 ? steps + freq : steps; 
        }
        return steps;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
