class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        map<int,vector<string>> mpp;

        for(int i=0; i<list1.size(); i++){
            for(int j=0; j<list2.size(); j++){

                if(list1[i]==list2[j]){
                    mpp[i+j].push_back(list1[i]);
                }
            }
        }

        auto it = mpp.begin();
        vector<string> ans = it->second;
        return ans;
        
    }
};