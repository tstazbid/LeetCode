class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(currentEnergy < enemyEnergies[0]) return 0;
        
        long long points = 0;
        long long currentEnergyLL = currentEnergy;
        
        for(int i = 1; i < enemyEnergies.size(); i++) {
            currentEnergyLL += enemyEnergies[i];
        }
        
        points += currentEnergyLL / enemyEnergies[0];
        
        return points;
    }
};

// Time Complexity: O(n logn)
// Space Complexity: O(1)