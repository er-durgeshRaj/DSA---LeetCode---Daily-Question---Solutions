// QUESTION
// Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

// Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

 

// Example 1:


// Input: path = "NES"
// Output: false 
// Explanation: Notice that the path doesn't cross any point more than once.
// Example 2:


// Input: path = "NESWW"
// Output: true
// Explanation: Notice that the path visits the origin twice.
 

// Constraints:

// 1 <= path.length <= 104
// path[i] is either 'N', 'S', 'E', or 'W'.
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        
        int x = 0;
        int y = 0;
        string key = to_string(x) + "_" + to_string(y);
        st.insert(key);
        
        for(char &ch : path) {
            if(ch == 'E') {
                x += 1;
            } else if(ch == 'W') {
                x -= 1;
            } else if(ch == 'N') {
                y += 1;
            } else {
                y -= 1;
            }
            
            key = to_string(x) + "_" + to_string(y);
            if(st.find(key) != st.end()) {
                return true;
            }
            
            st.insert(key);
        }
        
        return false;
    }
};
