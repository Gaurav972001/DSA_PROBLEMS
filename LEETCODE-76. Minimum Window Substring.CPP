class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        unordered_map<char, int>m1;
        unordered_map<char, int>m2;
        
        for(int i=0;i<t.size();i++)
            m1[t[i]]++;
        
        int i=-1, j=-1;
        int curcn=0;
        int cn=t.size();
        
        while(true){
            bool flag1=false;
            bool flag2=false;
            int n=s.size();
            while(curcn<cn && i<n-1){
                i++;
                m2[s[i]]++;
                if(m2[s[i]]<=m1[s[i]]){
                    curcn++;
                }
                flag1=true;
            }
            while(j<i && curcn==cn){
                string temp=s.substr(j+1, i-j);
                if(ans.size()==0 || temp.size()<ans.size())
                    ans=temp;
                j++;
                if(m2[s[j]]==1)
                    m2.erase(s[j]);
                else
                    m2[s[j]]--;
                if(m2[s[j]]<m1[s[j]])
                    curcn--;
                flag2=true;
            }
            if(flag1==false && flag2==false)
                break;
        }
        return ans;
    }
};