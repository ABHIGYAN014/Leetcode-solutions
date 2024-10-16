class Solution {
public:
    string addBinary(string a, string b) {
         string result;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // Start with carry
            
            if (i >= 0) {
                sum += a[i--] - '0'; // Add bit from a
            }
            if (j >= 0) {
                sum += b[j--] - '0'; // Add bit from b
            }
            
            result.push_back((sum % 2) + '0'); // Append the result bit
            carry = sum / 2; // Update carry
        }

        reverse(result.begin(), result.end()); // Reverse to get the correct order
        return result;
    }
};