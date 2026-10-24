class Solution {
public:
    int days(string &cur, vector<int> &pf) {
        int month = stoi(cur.substr(0, 2));

        int date = stoi(cur.substr(3));

        return pf[month - 1] + date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> DOM = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> pf = {0};

        for(auto &i : DOM) 
            pf.push_back(pf.back() + i);

        return max(0, min(days(leaveAlice, pf), days(leaveBob, pf)) - max(days(arriveAlice, pf), days(arriveBob, pf)) + 1);
    }
};