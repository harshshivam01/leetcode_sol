class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0){
        return false;

       }
       long y=x;
       long s=0;
       while(y>0){
        int rem=y%10;
        s=(s*10)+rem;
        y=y/10;
       }
       if(s==x){
        return true;
       }
       else{
        return false;
       }
    }
};