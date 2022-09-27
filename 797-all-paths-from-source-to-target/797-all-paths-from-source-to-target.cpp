class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> res;
        path.push_back(0);
        for(int next: graph[0]){
            traverse(res, path, graph, next);
        }
        return res;
        
    }
    
    void traverse(vector<vector<int>>& res, vector<int>& path, vector<vector<int>>& graph, int s){
        path.push_back(s);
        if(s == graph.size() - 1){
            res.push_back(path);
            
        }else{
            for(int t : graph[s]){
                traverse(res, path, graph, t);
            }
        }
        
        path.pop_back();
        return;
    }
};