# LeetCode Helper

This repository contains something that may help to
run code & debug locally, in your favourate IDE
rather than in the LeetCode UI, as if you were a
Premiere user of LeetCode.

## How to use

```shell
cp ./lc_q1.cpp ./lc_q1234.cpp
# edit your source code in ./lc_q1234.cpp
# edit your testcases in ./leetcode.in
./lc.sh 1234
```

The format of your source code may be like this:
```cpp
#include "lchelper.hpp"
using namespace std;
using LC::ListNode;


// copy-paste from below
class Solution {
public:
    vector<int> yourFunction(vector<int>& param1, int param2) {
        
    }
};
// copy-paste from above

int main() {
    LC::RunCode(&Solution::yourFunction); // don't forget to modify this
                                          // when you change your function name
    return 0;
}
```


## What's supported

All **algorithims problems** which are **neither designing problems,
nor those containing TreeNode struct** (because I am too lazy to
impement TreeNode input/output).


## License
Licensed under the MIT License.
