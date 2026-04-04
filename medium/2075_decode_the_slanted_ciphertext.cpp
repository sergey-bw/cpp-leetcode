/**
 * 2075. Decode the Slanted Ciphertext
 * https://leetcode.com/problems/decode-the-slanted-ciphertext/
 * 
 * A string $originalText$ is encoded using a slanted transposition "cipher" to a string 
 * $encodedText$ with the help of a matrix having a given number of rows.
 * 
 * $originalText$ is placed first in the top-left cell and then down the diagonal 
 * (from top-left to bottom-right). After reaching the bottom-right edge of the 
 * diagonal, it continues at the top cell of the next column. Empty cells are filled 
 * with spaces ' '. The $encodedText$ is formed by reading the matrix row by row.
 * 
 * Note: $originalText$ does not have any trailing spaces ' '. 
 * Return the original string.
 * 
 * Example 1:
 *     Input: encodedText = "iveo    eed   l te   olc", rows = 4
 *     Output: "i love leetcode"
 *     Explanation: The matrix looks like this (with '_' representing spaces):
 *     
 *       Col: 0 1 2 3 4 5
 *     Row 0: i v e o _ _ 
 *     Row 1: _ _ e e d _
 *     Row 2: _ _ l _ t e
 *     Row 3: _ _ _ o l c
 *     
 *     Reading diagonals starting from the top row:
 *     1st diag (starts at 0,0): 'i', '_', 'l', 'o'
 *     2nd diag (starts at 0,1): 'v', 'e', '_', 'l'
 *     3rd diag (starts at 0,2): 'e', 'e', 't', 'c'
 *     4th diag (starts at 0,3): 'o', 'd', 'e'
 *     Combined: "i_lo" + "ve_l" + "eetc" + "ode" = "i love leetcode"
 * 
 * Example 2:
 *     Input: encodedText = "coding", rows = 1
 *     Output: "coding"
 *     Explanation: Matrix is just 1 row: [c, o, d, i, n, g]. Diagonals are single characters.
 * 
 * Example 3:
 *     Input: encodedText = " b  ac", rows = 2
 *     Output: " abc"
 *     Explanation: 
 *       Col: 0 1 2
 *     Row 0: _ b _
 *     Row 1: _ a c
 *     Diagonals: ('_', '_'), ('b', 'a'), ('_', 'c'). 
 *     Decoded: "__ba_c". 
 *     After stripping trailing spaces: " abc". (Note that leading spaces are kept).
 * 
 * Constraints:
 *     0 <= encodedText.length <= 10^6
 *     encodedText consists of lowercase English letters and ' ' only.
 *     encodedText is a valid encoding of some originalText that does not have trailing spaces.
 *     1 <= rows <= 1000
 *     The testcases are generated such that there is only one possible originalText.
 */

#include <cassert>
#include <string>

class Solution {
public:
    std::string decodeCiphertext(const std::string& encoded_text, const size_t rows) {
        if (encoded_text.empty() || rows < 2) {
            return encoded_text;
        }

        const size_t cols = encoded_text.length() / rows;

        std::string decoded_text;
        decoded_text.reserve(cols * rows);

        for (size_t i = 0; i < cols; ++i) {
            for (size_t row = 0; row < rows && i + row < cols; ++row) {
                decoded_text.push_back(encoded_text[row * cols + i + row]);
            }
        }

        const size_t last_index = decoded_text.find_last_not_of(' ');
        if (last_index == std::string::npos) {
            return "";
        }

        decoded_text.resize(last_index + 1);
        return decoded_text;
    }
};

void Test1() {
    std::string encoded_text = "iveo    eed   l te   olc";
    int rows = 4;
    std::string answer = "i love leetcode";
    assert(Solution().decodeCiphertext(encoded_text, rows) == answer);
}

void Test2() {
    std::string encoded_text = "coding";
    int rows = 1;
    std::string answer = "coding";
    assert(Solution().decodeCiphertext(encoded_text, rows) == answer);
}

void Test3() {
    std::string encoded_text = " b  ac";
    int rows = 2;
    std::string answer = " abc";
    assert(Solution().decodeCiphertext(encoded_text, rows) == answer);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}