class Solution {
public:
    void sortColors(vector<int>& num) {
        int l=0;
        int h=num.size()-1;
        int m=0;
        while(m<=h){
            if(num[m]==0)
                swap(num[l++],num[m++]);
            else if(num[m]==2)
                swap(num[m],num[h--]);
            else
                m++;
        }
    }
};