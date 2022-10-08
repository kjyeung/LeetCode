class Solution {
public:
    int Father[100005];
    int find(int x){
        if(Father[x] != x){
            Father[x] = find(Father[x]);
        }
        return Father[x];
    }
    
    void Union(int x, int y){
        x = Father[x];
        y = Father[y];
        if(x < y) Father[y] = x;
        else Father[x] = y;
    }
    
    vector<pair<int,int>> e[30005];
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ret = 0;
        
        for(int i = 0; i < n; i++){
            Father[i] = i;
        }
        
        for(auto& edge :edges){
            int a = edge[0], b = edge[1];
            if(vals[a] < vals[b]){
                swap(a, b);
            }
            e[vals[a]].push_back({a, b});
        }
        
        set<int> ValSet(vals.begin(), vals.end());
        
        unordered_map<int, vector<int>> val2idx;
        for(int i = 0; i < n; i++){
            val2idx[vals[i]].push_back(i);
        }
        
        for(int v : ValSet){
            for(auto & [v, b] : e[v]){
                if(find(v) != find(b)) Union(v, b);
            }
            unordered_map<int,int> count;
            for(int idx : val2idx[v]){
                int root = find(idx);
                count[root]++;
            }
            
            for(auto& [v, freq]:count){
                ret += freq * (freq - 1) / 2;
            }
        }
        return ret + n;
        
    }
};