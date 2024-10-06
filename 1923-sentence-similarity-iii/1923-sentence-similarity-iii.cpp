class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split sentences into words
        std::vector<std::string> words1 = split(sentence1);
        std::vector<std::string> words2 = split(sentence2);
        
        int n1 = words1.size();
        int n2 = words2.size();
        
        // Early exit if the length difference is more than allowed (based on problem definition)
        if (n1 < n2) {
            std::swap(words1, words2);
            std::swap(n1, n2);
        }
        
        int i = 0;
        // Compare from the beginning
        while (i < n2 && words1[i] == words2[i]) {
            i++;
        }
        
        // Compare from the end
        int j = 0;
        while (j < n2 && words1[n1 - 1 - j] == words2[n2 - 1 - j]) {
            j++;
        }
        
        return i + j >= n2;
    }
    
private:
    std::vector<std::string> split(const std::string& sentence) {
        std::vector<std::string> words;
        std::istringstream stream(sentence);
        std::string word;
        
        while (stream >> word) {
            words.push_back(word);
        }
        
        return words; 
    }
};