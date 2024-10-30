//
// Created by Administrator on 24-9-14.
//

#ifndef SOLUTIONN_H
#define SOLUTIONN_H
#include <algorithm>
#include<vector>
#include <string>
#include<unordered_map>
#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    /*====================================================数组======================================================*/
    //三数之和
    //四数之和
    //反转链表
    //环形链表II

    //代码随想录数组2.就移除个元素很难么？
    // 暴力解法，两层for循环，暴力搜索
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < nums.size(); j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 因为下标i以后的数值都向前移动了一位，所以size--
            }
        }
    }
    // 双指针法
    int removeElement2(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex] = nums[fastIndex];  // 保留不等于 val 的元素
                slowIndex++;  // 慢指针前进
            }
        }
        return slowIndex;
    }
    //代码随想录数组1.每次遇到二分法，都是一看就会，一写就废
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        // 二分搜索
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;  // 找到目标值，直接返回索引
            } else if (nums[mid] < target) {
                left = mid + 1;  // 目标值在右边
            } else {
                right = mid - 1;  // 目标值在左边
            }
        }
        // 如果没有找到目标值，返回left，即插入位置
        return left;
    }
    //34. 在排序数组中查找元素的第一个和最后一个位置
    vector<int> searchRange(vector<int>& nums, int target) {/**/
        // 二分查找找到中间位置
        
        // 找到中间位置后，向两边扩展
    }
    //33. 搜索旋转排序数组
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }


    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack<int> st;
        st.push(-1);  // 初始化栈，放入一个虚拟下标，方便计算长度

        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);  // 存储左括号的下标
            } else {
                st.pop();  // 匹配一个左括号

                if (st.empty()) {
                    // 没有匹配的左括号，把当前下标作为新的基准
                    st.push(i);
                } else {
                    // 计算有效长度
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }

        return maxlen;
    }


    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

};


    // 辅助函数，用于创建链表
    ListNode* createList(const std::vector<int>& values) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        for (int value : values) {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
        return dummy.next;
    }

    // 辅助函数，用于打印链表
    void printList(ListNode* head) {
        while (head) {
            std::cout << head->val;
            if (head->next) std::cout << " -> ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    // 辅助函数，用于删除链表
    void deleteList(ListNode* head) {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

#endif //SOLUTIONN_H
