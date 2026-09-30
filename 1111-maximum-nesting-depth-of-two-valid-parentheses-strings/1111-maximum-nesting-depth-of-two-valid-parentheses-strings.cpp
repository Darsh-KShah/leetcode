class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;

        int dep = 0;

        for(auto &i : seq) {
            if(i == '(') res.push_back(++dep % 2);
            else res.push_back(dep-- % 2);
        }

        return res;
    }
};