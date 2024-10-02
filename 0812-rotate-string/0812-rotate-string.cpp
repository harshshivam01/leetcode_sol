class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        string dual=goal+goal;
        if(dual.contains(s))return true;
        else {
            return false;
        }
    }
};