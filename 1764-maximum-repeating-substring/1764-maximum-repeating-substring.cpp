#include <string>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int maxCount = 0;
        string repeatedWord = word;
        while (sequence.find(repeatedWord) != string::npos) {
            maxCount++;
            repeatedWord += word;
        }
        
        return maxCount;
    }
};
