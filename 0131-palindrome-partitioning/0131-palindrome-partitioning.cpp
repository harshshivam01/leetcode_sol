class Solution {
public:
 void f(int i, vector<vector<string>>&ans,string s,vector<string >&temp){
    if(i==s.size()){
        ans.push_back(temp);
        return;
    }
    for(int j=i;j<s.size();j++){
        string str=s.substr(i,j-i+1);
        if(check(str)){
           temp.push_back(str);
           f(j+1,ans,s,temp);
           temp.pop_back();
        }
    }
 }
 bool check(string str){
    int n =str.size();
    int i=0;
    int j=n-1;
    while(i<n){
        if(str[i]!=str[j])
        {
           return false ;
        }else{
            i++;j--;
        }

    }
    return true;
 }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string >temp;
        f(0,ans,s,temp);
        return ans ;
    }
};