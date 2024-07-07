class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i = 0; i < k; i++) colors.push_back(colors[i]);
        
        vector<int> check(colors.size());
        
        for(int i = 1; i < colors.size() - 1; i++) {
            check[i] = check[i - 1];
            if(colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) {
                check[i] += 1;
            }
        }
        
        
        int cnt = 0;
        for(int i = 0, j = k - 1; j < colors.size() - 1; i++, j++) {
            if(check[j - 1] - check[i] == k - 2) cnt++;
        }
        return cnt;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)