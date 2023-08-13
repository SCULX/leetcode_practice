// 题目链接  https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/

#include<cstdio>
#include<vector>
using namespace std;

// 定义   正序：有序不减数组(如[4,4,5,6,0,1,2,4]中[0,1,2,4]这部分)  反序：有序不减数组螺旋部分(如[4,4,5,6,0,1,2,4]中[4,4,5,6]这部分)
bool search(vector<int>& nums, int target) {
    int len = nums.size();
    int low = 0, high = len - 1;

    while(low<=high){
        int mid = (low + high) / 2;
        
        if(nums[mid]==target){
            return true;
        }

        if(nums[mid] < nums[high]){
            // 此时的mid处于正序的范围,即[mid...high]区间是有序的
            if(target>nums[mid] && target<=nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        else if(nums[mid]>nums[high]){
            // 此时的mid处于反序的范围,即[low...mid]区间是有序的
            if (target < nums[mid] && target>=nums[low]) {
                    high = mid - 1;
            }
            else{
                    low = mid + 1;
            }
        }
        else{
            // 当nums[mid]==nums[high]时,情况比较复杂
            // 若nums[mid]<nums[low],表示[mid...high]是有序区间;若nums[mid]==nums[mid],则无法判断什么区间有序
            if(nums[mid]==nums[low]){
                // 无法区分什么区间有序时,直接让左指针向右移动,右指针向左移动
                    low++;
                    high--;
            }
            else if(nums[mid]>nums[low]){
                // 此时[low...mid]区间均有序
                if(target>nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            else{
                // nums[mid]<nums[low]时,[mid...high]区间有序
                if(target>nums[mid] && target<=nums[high]){
                    low = mid + 1;
                }
                else if(target>nums[mid] && target>nums[high]){
                    high = mid - 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
    }
    return false;
}

int main(){

    vector<int> nums = {3,5,1};
    int target = 3;

    bool isFound = search(nums, target);

    isFound ? printf("true\n") : printf("false\n");
    return 0;
}