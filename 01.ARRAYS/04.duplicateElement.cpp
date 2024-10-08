
// APPROACH 2 - USING SET TO STORE THE UNIQUE ELEMENT 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> temp(nums.begin() , nums.end());

        if(temp.size() == nums.size()){
            return false;
        }else{
            return true;
        }
    }
};

//APPROACH 1 - BY SORTING

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin() , nums.end());
//         for(int i = 0 ; i < nums.size()-1 ; i++){
//             if(nums[i] == nums[i+1]){
//                 return true;
//             }
//         }
//         return false;
//     }
// };