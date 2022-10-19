class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        traverse(graph, path, res, 0);
        return res;
    }
    
    void traverse(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res, int start){
        path.push_back(start);
        if(start == graph.size() - 1){
            res.push_back(path);
        }else{
            for(int t : graph[start]){
                traverse(graph, path, res, t);
            }
        }
        
        path.pop_back();
    }
};