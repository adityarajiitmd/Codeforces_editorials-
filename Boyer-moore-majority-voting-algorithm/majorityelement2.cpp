Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// here the threshold can be anything. one must be aware of the algorithm variation
vector<int> majorityElement(vector<int>& nums) {
        int el1=INT_MIN;
        int el2=INT_MIN;
        int vt1=0;
        int vt2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(vt1==0 && el2!=nums[i]){
                el1=nums[i];
                vt1++;
            }
            else if(vt2==0 && el1!=nums[i]){
                el2=nums[i];
                vt2++;
            }
            else if(el1==nums[i])vt1++;
            else if(el2==nums[i])vt2++;
            else{
                vt1--;
                vt2--;
            }
        }
        vt1=0;
        vt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1)vt1++;
            if(nums[i]==el2)vt2++;
        }
        vector<int>ans;
        if(vt1>n/3)ans.push_back(el1);
        if(vt2>n/3)ans.push_back(el2);
        return ans;
