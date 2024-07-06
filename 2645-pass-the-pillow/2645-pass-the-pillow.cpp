class Solution {
public:
    int passThePillow(int n, int time) {
       int i=1;
       int dir=1;
       while(time--){
          if(dir){
            i++;
            if(i==n)dir=!dir;
          }
          else{
            i--;
            if(i==1)dir=!dir;
          }
       } 
       return i;
    }
};