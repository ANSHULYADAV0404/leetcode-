class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (st.size()>0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        // Clear the stack
        while (!st.empty()) {
            st.pop();
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (st.size()>0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        int maxarea = 0;

        // Calculate maximum area
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};