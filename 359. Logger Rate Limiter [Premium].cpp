// Problem Link: https://leetcode.com/problems/logger-rate-limiter/
// Easy

class Logger {
private:
    unordered_map<string, int> loggerTrack;
public:
    Logger() {

    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if( !loggerTrack.count(message)  || loggerTrack[message] + 10 <= timestamp) {
            loggerTrack[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

 // Time Complexity: O(1)
 // Space Complexity: O(N)
