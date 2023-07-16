// MIT License
//
// Copyright (c) 2023 TengGit
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// https://leetcode.com/problems/valid-palindrome-ii/

#include "lchelper.hpp"
using namespace std;
using LC::ListNode;

class Solution {
    static bool valid(const char *start, const char *end, bool remain) {
        while (start < end) {
            if (*start != *end) {
                return remain ?
                       valid(start+1, end, false) ||  valid(start, end-1, false) :
                       false;
            }
            ++start;
            --end;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return valid(s.c_str(), s.c_str() + s.size() - 1, true);
    }
};

int main() {
    LC::RunCode(&Solution::validPalindrome);
    return 0;
}