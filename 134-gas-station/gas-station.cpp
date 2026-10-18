class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currgas = 0;
        int start = 0;
        int totalgas = 0, totalcost = 0; // Declared outside the loop properly
        
        for (int i = 0; i < gas.size(); i++) {
            totalgas += gas[i];    // Removed 'int'
            totalcost += cost[i];  // Removed 'int'
            
            currgas += (gas[i] - cost[i]);
            if (currgas < 0) {
                currgas = 0;
                start = i + 1;
            }
        }
        
        if (totalgas < totalcost) {
            return -1;
        }
        
        return start;
    }
};