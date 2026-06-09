class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int stopsAllowed=k+1;
        vector<vector<pair<int,int>>>adjList(n);
        vector<int>dist(n,1e8);
        for(vector<int> flight:flights){
            adjList[flight[0]].push_back({flight[1],flight[2]});
        }
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>,greater<pair<int,pair<int,int>>>min_heap;
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> min_heap;
        queue<pair<int,pair<int,int>>> min_heap;

        min_heap.push({0,{0,src}});
        dist[src]=0;
        while(!min_heap.empty()){
            pair<int,pair<int,int>>top=min_heap.front();
            int currK=top.first;
            int currDist=top.second.first;
            int currNode=top.second.second;
            min_heap.pop();
            if(currK==stopsAllowed)break;
            // cout<<"debug :: "<<"currNode : "<<currNode<<" currK: "<<currK<<" currDist: "<<currDist<<"\n";
            for(pair<int,int> adjPair:adjList[currNode]){
                int adjNode=adjPair.first;
                int adjDist=adjPair.second;
                // cout<<"debug :: "<<"adjNode : "<<adjNode<<" adjK: "<<currK+1<<" adjDist: "<<adjDist<<"\n";
                if(adjDist+currDist<dist[adjNode]){
                    dist[adjNode]=adjDist+currDist;
                    min_heap.push({currK+1,{dist[adjNode],adjNode}});
                }

            }
        }
        if(dist[dst]==1e8)return -1;
        return dist[dst];
    }
};
