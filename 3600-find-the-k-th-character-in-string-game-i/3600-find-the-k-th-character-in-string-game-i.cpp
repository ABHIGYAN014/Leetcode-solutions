class Solution {
public:
    char kthCharacter(int k) {
        // Initial length of the word
        int length = 1;

        // Determine the smallest length >= k
        while (length < k) {
            length *= 2;
        }

        char currentChar = 'a'; // Starting character

        // Reverse trace k back to the initial character
        while (length > 1) {
            int halfLength = length / 2;

            if (k > halfLength) {
                // If k is in the second half
                k -= halfLength; // Adjust k
                currentChar++;    // Move to the next character
                if (currentChar > 'z') {
                    currentChar = 'a'; // Wrap around if beyond 'z'
                }
            }

            length = halfLength; // Halve the length
        }

        return currentChar; // The resolved character
    }
};
