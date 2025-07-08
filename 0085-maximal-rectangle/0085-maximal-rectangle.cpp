class Solution {
public:
    vector<int> NSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> PSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);

        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxarea = max(maxarea, area);
        }
    
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0); // histogram heights
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Build/update histogram for each column
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            // Apply largestRectangleArea on the current histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

};