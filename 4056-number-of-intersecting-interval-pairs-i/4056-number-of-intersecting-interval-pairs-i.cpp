    class Solution {
    public:
        int countIntersectingIntervals(vector<vector<int>>& ivl) {
            int n = ivl.size();

            sort(ivl.begin(), ivl.end());

            int res = 0;

            for(int i = 0; i < n - 1; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(ivl[i][1] >= ivl[j][0]) res++;
                    else break;
                }
            }

            return res;
        }
    };