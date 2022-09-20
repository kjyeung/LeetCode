class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.empty()) return res;
        int n = graph.size();
        vector<int> path;
        traverse(0, n - 1, path, graph);
        return res;
    }
    
    void traverse(int start, int end, vector<int>&path, vector<vector<int>>& graph){
        path.push_back(start);
        if(start == end){
            res.push_back(path);
        }else{
            for(int next : graph[start]){
                traverse(next, end, path, graph);
            }
        }
       
        path.pop_back();
        return;
    }    
};