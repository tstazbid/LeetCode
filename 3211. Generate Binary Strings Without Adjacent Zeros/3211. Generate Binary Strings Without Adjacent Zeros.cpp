class Solution {
private:
    void generateValidBinaryStrings(vector<string>& validStrs, string& curr, int n) {
        if(curr.length() == n) {
            validStrs.push_back(curr);
            return;
        }
        if(curr[curr.size() - 1] == '0') {
            curr.push_back('1');
            generateValidBinaryStrings(validStrs, curr, n);
            curr.pop_back();    
        } else {
            curr.push_back('1');
            generateValidBinaryStrings(validStrs, curr, n);
            curr.pop_back();
            curr.push_back('0');
            generateValidBinaryStrings(validStrs, curr, n);
            curr.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> validStrs;
        string curr = "0";
        generateValidBinaryStrings(validStrs, curr, n);
        curr = "1";
        generateValidBinaryStrings(validStrs, curr, n);
        
        return validStrs;
    }
};

// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)