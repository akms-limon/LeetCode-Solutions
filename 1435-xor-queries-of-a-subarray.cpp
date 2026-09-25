class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i = 1; i<arr.size(); i++){
            arr[i]^=arr[i-1];
        }
        vector<int>v;
        for(int i = 0; i<queries.size(); i++){
            if(queries[i][0]==0)
                v.push_back(arr[queries[i][1]]);
            else
                v.push_back(arr[queries[i][1]]^arr[queries[i][0]-1]);
        }
        return v;
    }
};