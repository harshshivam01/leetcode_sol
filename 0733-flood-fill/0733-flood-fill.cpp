class Solution {
public:
   int check(int x,int y,int m,int n ){
    if(x>=0&&y>=0&&x<m&&y<n)return 1;
    else return 0;
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int col=image[sr][sc];
        image[sr][sc]=color;
        queue<pair<int ,int>>q;
        vector<vector<int>>visi(m,vector<int >(n,0));
        // visi[sr][sr]=1;
        q.push({sr,sc});
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                   int nx=x+dx[i];
                   int ny=y+dy[i];
                   if(check(nx,ny,m,n)==1&&image[nx][ny]==col&&visi[nx][ny]==0){
                      image[nx][ny]=color;
                      visi[nx][ny]=1;
                      q.push({nx,ny});
                   }
                   else{
                    continue;
                   }
                }
            }
        }
        return image;
    }
};