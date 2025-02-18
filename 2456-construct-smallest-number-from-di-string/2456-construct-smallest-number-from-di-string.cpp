class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();  // Get the length of the pattern
        string ans = "";         // Initialize the result string
        
        int d = 0;  // Counter to track consecutive 'D' (decreasing) characters

        // Iterate through each character in the pattern
        for(int i = 0; i < n; i++) {
            if(pattern[i] == 'I' && d == 0) {  
                // If the current character is 'I' and no previous 'D' is pending, add the next smallest number
                ans += to_string(i + 1);
            }
            else if(pattern[i] == 'D') {  
                // If the character is 'D', increment the counter to track consecutive 'D'
                d++;
            }
            else {  
                // If an 'I' appears after one or more 'D's, process the decreasing sequence
                int x = i + 1;  // Start from the current index + 1
                d++;  // Account for the last 'D'
                while(d) {  
                    // Append numbers in descending order for the tracked 'D' sequence
                    ans += to_string(x);
                    x--;
                    d--;
                }
            }
        }

        // Handle any remaining 'D' characters at the end
        if(d > 0) {
            d++;  // Increase count to include the last number
            int x = ans.size();  // The next number to append
            x += d;
            while(d) {
                ans += to_string(x);
                x--;
                d--;
            }
        }
        if(pattern[n - 1] == 'I') {
            ans += to_string(n + 1);
        }

        return ans;  // Return the final smallest lexicographical number
    }
};