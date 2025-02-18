class Solution {
    string helper(string pattern,vector<int>&visi,string st,int index){
        if(index==pattern.size()+1){
            return st;
        }
        for(int i=1;i<=9;i++){
            if(!visi[i]){
                if(index>0&&pattern[index-1]=='I'&&st.back()-'0'>=i)continue;
                if(index>0&&pattern[index-1]=='D'&&st.back()-'0'<=i)continue;
                visi[i]=true;
                st+=to_string(i);
               string res= helper(pattern,visi,st,index+1);
                 if (!res.empty()) return res; 
                st.pop_back();
                visi[i]=false;
            }
        }
  return "";
    }
public:
    string smallestNumber(string pattern) {
        vector<int>visi(10,0);
        string st;
        return helper(pattern,visi,st,0);
    }
};