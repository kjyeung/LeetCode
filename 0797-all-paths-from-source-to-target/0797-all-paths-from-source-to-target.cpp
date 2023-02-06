class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        for(int next : graph[0]){
            traverse(graph, res, path, next);
        }
        return res;
    }
    
    void traverse(vector<vector<int>>& graph, vector<vector<int>> & res, vector<int>& path, int next){
        path.push_back(next);
        if(next == graph.size() - 1){
            res.push_back(path);
        }
        else{
            for(int s : graph[next]){
                traverse(graph, res, path, s);
            }
        }
        
        path.pop_back();
        return ;
    }
};