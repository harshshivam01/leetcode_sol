class Solution {
public:
    void backtrack(int index,string digits,string temp,vector<string >&combinations,vector<string>&phone_map) {
        if(index==digits.size()){
            combinations.push_back(temp);
            return;
        }
        string val=phone_map[digits[index]-'0'];
        for(int i=0;i<val.size();i++){
            temp.push_back(val[i]);
            backtrack(index+1,digits,temp,combinations,phone_map);
            temp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};
        vector<string> phone_map = {"",    "",    "abc",  "def", "ghi",
                                    "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combinations;
        backtrack(0, digits, "", combinations, phone_map);
        return combinations;
    }
};