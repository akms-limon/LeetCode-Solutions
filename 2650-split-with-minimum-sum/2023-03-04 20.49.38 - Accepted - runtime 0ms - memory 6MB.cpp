class Solution {
public:
    int splitNum(int num) {
        vector<int>v;
        int i = 0;
        while(num>0){
            v.push_back(num%10);
            num/=10;
            i++;
        }
        sort(v.begin(), v.end());
        int a=0, b=0;
        for(int i=0; i<v.size(); i++){
            a+=v[i];
            a*=10;
            if(i<v.size()-1){
                i++;
                b+=v[i];
                b*=10;
            }
        }
        a/=10;
        b/=10;
        return a+b;
    }
};