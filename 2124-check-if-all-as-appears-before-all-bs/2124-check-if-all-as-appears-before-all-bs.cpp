class Solution {
public:
    bool checkString(string s) {
        bool hasB = false;

        for(auto &i : s) {
            if(i == 'b') hasB = true;

            if(i == 'a' && hasB) return false;
        }

        return true;
    }
};