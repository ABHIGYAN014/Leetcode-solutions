class Solution {
public:
    void solve(int index,vector<string>&ans,string output,vector<string>&mpp,string digits)
    {
        if(index >=digits.length())
        {
            ans.push_back(output);
            return;
        }
         int digit=digits[index]-'0';
         string value=mpp[digit];
         for(int i=0;i<value.length();i++)
         {
            char ch=value[i];
            output.push_back(ch);
            solve(index+1,ans,output,mpp,digits);
            output.pop_back();
         }   

    }
    vector<string> letterCombinations(string digits) {
        int index=0;
        vector<string>ans;
        vector<string>mpp(10);
        if(digits.length()==0)
        {
            return ans;
        }
        string output="";
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";

        solve(index,ans,output,mpp,digits);
        return ans;

    }
};