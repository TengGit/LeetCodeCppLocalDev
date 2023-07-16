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

// https://leetcode.com/problems/two-sum/

#include "lchelper.hpp"
using namespace std;
using LC::ListNode;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<array<int, 2>> va(sz);
        for (int i = 0; i < sz; i++) {
            va[i][0] = nums[i];
            va[i][1] = i;
        }
        sort(va.begin(), va.end());
        int i = 0, j = sz-1;
        while (va[i][0] + va[j][0] != target) {
            if (va[i][0] + va[j][0] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return {va[i][1], va[j][1]};
    }
};

int main() {
    LC::RunCode(&Solution::twoSum);
    return 0;
}