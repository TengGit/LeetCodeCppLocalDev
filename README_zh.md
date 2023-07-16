# LeetCode Helper

本仓库包含一些能帮助你在本地运行/调试 LeetCode 代码的东西。
如果不想充会员，但是想使用自动补全&断点调试，那么可以考虑试试这个。

当然前提是你有一个本地用的习惯的 IDE。

## 如何使用

```shell
cp ./lc_q1.cpp ./lc_q1234.cpp
# 编辑 ./lc_q1234.cpp 的源代码
# 编辑 ./leetcode.in 的测试用例
./lc.sh 1234
```

源码类似于这种格式：
```cpp
#include "lchelper.hpp"
using namespace std;
using LC::ListNode;


// 复制粘贴本行以下的内容
class Solution {
public:
    vector<int> yourFunction(vector<int>& param1, int param2) {
        
    }
};
// 复制粘贴本行以上的内容

int main() {
    LC::RunCode(&Solution::yourFunction); // 改函数名的时候需要在这里也改一下
    return 0;
}
```


## 支持的题目

**没有树、不是设计类**的所有**算法**题目（不支持树是因为我懒得写 TreeNode
的输入输出了）。


## 许可证
使用 MIT 许可证。
