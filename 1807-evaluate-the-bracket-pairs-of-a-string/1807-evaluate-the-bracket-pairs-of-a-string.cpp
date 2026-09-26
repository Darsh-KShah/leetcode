class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(auto &i : knowledge) 
            mp[i[0]] = i[1];

        bool isK = false;

        string res = "", key = "";

        for(auto &i : s) {
            if(i == '(') isK = true;
            else if(i == ')') {
                if(mp.count(key)) res += mp[key];
                else res.push_back('?');

                isK = false;            
                
                key.clear();
            } else if(isK) key.push_back(i);
            else res.push_back(i);
        }

        return res;
    }
};