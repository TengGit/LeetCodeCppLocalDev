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

// https://leetcode.com/problems/row-with-maximum-ones/

#include "lchelper.hpp"
using namespace std;
using LC::ListNode;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int idx = 0, count = 0, sz = mat.size(), cs = mat[0].size();
        printf("%d %d\n", sz, cs);
        for (int i = 0; i < sz; i++) {
            int cur = 0;
            for (int x: mat[i]) {
                if (x == 1) {
                    cur++;
                }
            }
            if (cur > count) {
                count = cur;
                idx = i;
            }
        }
        return {idx, count};
    }
};

int main() {
    LC::RunCode(&Solution::rowAndMaximumOnes);
    return 0;
}