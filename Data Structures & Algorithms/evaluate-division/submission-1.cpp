class Solution {
public:

    double dfs(string u, string v, unordered_map<string, vector<pair<double,string>>>& mp, unordered_set<string>& visited){

        if(u==v) return 1.0;

        if(visited.count(u)) return -1.0;

        visited.insert(u);

        for(auto x : mp[u]){
            double some = dfs(x.second, v, mp, visited);
            if(some!=-1.0){
                return some*(x.first);
            }
        }

        return -1.0;

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {


        unordered_map<string, vector<pair<double,string>>> mp;
        

        for(int i=0;i<values.size();i++){
            mp[equations[i][0]].push_back({values[i], equations[i][1]});
            mp[equations[i][1]].push_back({(1.0/values[i]), equations[i][0]});
        }

        vector<double> ans(queries.size(), -1.0);

        for(int i=0;i<queries.size();i++){
            string u = queries[i][0];
            string v = queries[i][1];
            unordered_set<string> visited;
            if(mp.count(u) && mp.count(v)){
                ans[i] = dfs(u,v,mp,visited);
            }
        }

        return ans;
    }
};