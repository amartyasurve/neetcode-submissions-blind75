class Solution {
public:
    void bfs(int x,int y,int n,int m,vector<vector<int>>&visited,vector<vector<char>>&grid){
     queue<pair<int,int>>q;
     q.push({x,y});
     int xarray[4]={-1,0,1,0};
     int yarray[4]={0,-1,0,1};
     while(!q.empty()){
        pair<int,int>top=q.front();
        int xc=top.first;
        int yc=top.second;
        q.pop();
        visited[xc][yc]=1;
        for(int i=0;i<4;i++){
            if(xc+xarray[i]>=0 && xc+xarray[i]<n && yc+yarray[i]>=0 && yc+yarray[i]<m && visited[xc+xarray[i]][yc+yarray[i]]==0 && grid[xc+xarray[i]][yc+yarray[i]]=='1'){
                q.push({xc+xarray[i],yc+yarray[i]});   
            }
        }
     }
    }
    int numIslands(vector<vector<char>>& grid) {
        /*
        no. of times the bfs is called that many islands are presnt 
        queue<pair<int,int>>q {x,y};
        visited grid
        */
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,n,m,visited,grid);
                }
            }
        }
        return count;
    }
};
