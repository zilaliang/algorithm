
#include <iostream>

#include"Solutionn.h"
using namespace std;
int main() {
    // 创建 Solution 实例
    Solution solu;
    vector<int>nums={1,4,6,8,10};
    int res=solu.searchInsert(nums,11);
    cout<<res<<endl;
    return 0;
    //zzzzzzzzzzzzzzzzzzz
}
