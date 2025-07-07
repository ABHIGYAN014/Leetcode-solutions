class Solution {
public:

string solve(string &s){
   int n = s.size();
   string ans = "";
   int k=0;
   for(int i=0;i<n;i++){
     int j = i;
        k++;
        string temp = "";
        string res = "";
         while(j<n && s[j] != ' '){
            if(j==i){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' 
            || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'){
               temp += "ma";
               res +=s[j];
            }
            else{
                temp+=s[j];
                temp+="ma";
            }
        }
            else{
               res+=s[j];
            }
            j++;
     }
        res+=temp;
        res.append(k,'a');
        ans+=res;
        ans+=" ";
        i=j;
   } 
   ans.pop_back();
    return ans;
}

    string toGoatLatin(string sentence) {
        return solve(sentence);
    }
};