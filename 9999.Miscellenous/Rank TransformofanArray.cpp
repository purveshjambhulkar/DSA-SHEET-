class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //find rank
        unordered_map<int , int> valuetoRank;
        vector<int> tempArr = arr;

        //sort and remove duplicates from the arr
        sort(tempArr.begin() , tempArr.end());
        tempArr.erase(unique(tempArr.begin() , tempArr.end()) , tempArr.end());

        for(int i = 0 ; i < tempArr.size() ; i++){
            valuetoRank[tempArr[i]] = i+1;
        }

        for(int i = 0 ; i < arr.size() ; i++){
            arr[i] = valuetoRank[arr[i]];
        }

        return arr;


    }
};