class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
         vector<vector<int>> ans;
        for (int i = 0; i<n; i++){
            int startposi = intervals[i][0];
            int endposi = intervals[i][1];
            if(!ans.empty() && endposi <=ans.back()[1]){
            continue;
            }

            for(int j = i+1; j<n; j++){
                if(intervals[j][0] <= endposi){
                endposi = max(endposi, intervals[j][1]);
                }
                // else{
                //  break;
                // }
            }
            ans.push_back({startposi , endposi});
        }
        return ans;
    }  
};