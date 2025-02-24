class Solution {
public:
   void solve(vector<string>&result,string output,int open,int close,int n)
   {
    if(open==0&&close==0)
    {
      result.push_back(output);
      return;
    }
    //recursion
    if(open>0)  //adding (
    {   output.push_back('(');
        solve(result,output,open-1,close,n);
        output.pop_back();
    }
    //adding)
    if(close>open)
    {
        output.push_back(')');
        solve(result,output,open,close-1,n);
        output.pop_back();
    }
   }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        int open=n;
        int close=n;
        string output="";
        solve(result,output,open,close,n);
        return result;
    }
};