#define  _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //从第一个元素开始遍历所有的
        //暴力循环
        int n = nums.size();
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return{ i,j };
                }
            }
            //return{ i,j };
        }
    }
};
int main ()
{
    vector<int> a = { 3 ,2 ,4 ,6,9};
    int b = 15;
    Solution s;
    vector<int> res = s.twoSum(a,b);
    for (auto element : res)
    {
        std::cout << element << " ";
    }
    return 0;
}