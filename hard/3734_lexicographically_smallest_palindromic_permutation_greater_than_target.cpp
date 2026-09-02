/**
 * 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
 * https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/
 *
 * You are given two strings s and target, each of length n, consisting of
 * lowercase English letters.
 *
 * Return the lexicographically smallest string that is both a palindromic
 * permutation of s and strictly greater than target.
 *
 * If no such permutation exists, return an empty string.
 *
 * Example 1:
 *     Input: s = "baba", target = "abba"
 *     Output: "baab"
 *     Explanation:
 *     - The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
 *     - The lexicographically smallest permutation that is strictly greater than target is "baab".
 *
 * Example 2:
 *     Input: s = "baba", target = "bbaa"
 *     Output: ""
 *     Explanation:
 *     - None of them is lexicographically strictly greater than target.
 *       Therefore, the answer is "".
 *
 * Example 3:
 *     Input: s = "abc", target = "abb"
 *     Output: ""
 *     Explanation:
 *     - s has no palindromic permutations.
 *       Therefore, the answer is "".
 *
 * Example 4:
 *     Input: s = "aac", target = "abb"
 *     Output: "aca"
 *     Explanation:
 *     - The only palindromic permutation of s is "aca".
 *     - "aca" is strictly greater than target.
 *       Therefore, the answer is "aca".
 *
 * Constraints:
 *     1 <= n == s.length == target.length <= 300
 *     s and target consist of only lowercase English letters.
 */

#include <cassert>
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

class Solution {
public:
    std::string lexPalindromicPermutation(const std::string& s,
                                          const std::string& target) {
        const size_t n = s.length();
        if (n == 1) {
            return s[0] > target[0] ? s : ""; 
        }

        // 1. Подсчет символов строки s
        constexpr size_t kAlphaSize = 26;
        std::array<int, kAlphaSize> freq_char{0};
        for (char c : s) {
            ++freq_char[c - 'a'];
        }

        // 2. Подготовка массива для построения палиндрома
        //    и поиск центрального символа для нечетной длины строки
        std::array<int, kAlphaSize> freq_half_char{0};
        char middle_char = 'a';
        for (size_t i = 0, count_odd = 0; i < freq_char.size(); ++i) {
            if (freq_char[i] % 2 != 0) {
                middle_char = static_cast<char>('a' + i);
                ++count_odd;
            }
            if (count_odd > n % 2) {
                return "";
            }
            freq_half_char[i] = freq_char[i] / 2;
        }

        // 3. Попытка построить палиндром лексикографически не меньший S
        std::string palindrom;
        palindrom.reserve(n);
        size_t half_n = n / 2;
        bool is_greater = false;
        for (size_t i = 0; i < half_n; ++i) {
            for (size_t j = target[i] - 'a'; j < freq_half_char.size(); ++j) {
                if (freq_half_char[j] > 0) {
                    palindrom.push_back(static_cast<char>('a' + j));
                    --freq_half_char[j];
                    break;
                }
            }
            if (palindrom.size() != i + 1) { // Не нашлось буквы равной или большей target[i]
                return "";
            }

            if (palindrom[i] > target[i]) {
                is_greater = true;
                break;
            }
        }

        // 4. Пелиндром уже лексикографически больше, заполяем остаток минимальными символами
        for (size_t i = palindrom.size(), j = 0; i < half_n && is_greater; ++i) {
            while (j < freq_half_char.size() && freq_half_char[j] == 0) {
                ++j;
            }
            if (j == freq_half_char.size()) {
                return "";
            }
            palindrom.push_back(static_cast<char>('a' + j));
            --freq_half_char[j];
        }

        // 5. Для нечетной длины строки добавляем центральный символ
        if (n % 2 != 0) {
            palindrom.push_back(middle_char);
            is_greater = is_greater || palindrom.back() > target[half_n];
        }

        // 6. Если палиндром не превосходитлексографически S, делаем пермутацию не трогая middle_char
        if (!is_greater && !std::next_permutation(palindrom.begin(), palindrom.begin() + half_n)) {
            return "";
        }

        // Строим вторую половину палиндрома
        palindrom.resize(n);
        for (size_t i = 0; i < half_n; ++i) {
            palindrom[n - i - 1] = palindrom[i];
        }
        return palindrom;
    }
};

void Test1() {
    const std::string s = "baba";
    const std::string target = "abba";
    const std::string expected = "baab";

    const std::string result = Solution().lexPalindromicPermutation(s, target);

    assert(result == expected);
}

void Test2_NoValidPermutation() {
    const std::string s = "baba";
    const std::string target = "bbaa";
    const std::string expected = "";

    const std::string result = Solution().lexPalindromicPermutation(s, target);

    assert(result == expected);
}

void Test3_CannotFormPalindrome() {
    const std::string s = "abc";
    const std::string target = "abb";
    const std::string expected = "";

    const std::string result = Solution().lexPalindromicPermutation(s, target);

    assert(result == expected);
}

void Test4_OddLength() {
    const std::string s = "aac";
    const std::string target = "abb";
    const std::string expected = "aca";

    const std::string result = Solution().lexPalindromicPermutation(s, target);

    assert(result == expected);
}

int main() {
    Test1();
    Test2_NoValidPermutation();
    Test3_CannotFormPalindrome();
    Test4_OddLength();

    std::cout << "All tests passed!\n";
    return 0;
}