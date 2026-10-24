class Solution {
public:
    // Helper function to convert "MM-DD" to day number of the year (1 to 365)
    int getDayNumber(string date) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = day;
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonths[i];
        }
        return totalDays;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrival = getDayNumber(arriveAlice);
        int aliceLeave = getDayNumber(leaveAlice);
        int bobArrival = getDayNumber(arriveBob);
        int bobLeave = getDayNumber(leaveBob);
        
        // Find latest arrival and earliest departure
        int start = max(aliceArrival, bobArrival);
        int end = min(aliceLeave, bobLeave);
        
        // Calculate overlapping days
        if (start <= end) {
            return (end - start + 1);
        }
        
        return 0;
    }
};