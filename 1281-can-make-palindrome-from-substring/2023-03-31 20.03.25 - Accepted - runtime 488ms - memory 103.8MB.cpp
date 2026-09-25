class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        const int N = 1e5+10;
        int hsh[N][26];
    	for (int i = 0; i < N; ++i) {
    		for (int j = 0; j < 26; ++j) {
    			hsh[i][j]=0;
    		}
    	}
        int n = s.size();
    	for (int i = 1; i <= n; ++i) {
    		(hsh[i][s[i-1]-'a'])++;
    	}
    	for(int i = 0; i<26; i++){
    		for(int j= 1; j<=n; j++){
    			hsh[j][i]+=hsh[j-1][i];
    		}
    	}
			int m = queries.size();
			vector<bool>ans(m);
    	for(int j = 0; j<queries.size(); j++){
    		int oddcnt = 0;
            int l = queries[j][0], r = queries[j][1], k = queries[j][2]*2;
    		for(int i = 0; i<26; i++){
    			int cnt = hsh[r+1][i]-hsh[l][i];
    			if(cnt%2) oddcnt++;
    		}
    		if(oddcnt-k>1) ans[j]=false;
    		else ans[j]=true;
    	}
			return ans;
    }
};