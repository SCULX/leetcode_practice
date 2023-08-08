// 题目链接  https://leetcode.cn/problems/sort-colors/

#include<cstdio>
#include<vector>
using namespace std;

// 进阶的中等题：使用常数空间的一趟扫描算法
// 思路：根据元素只有3种，有序后0在前，2在后，所以一趟扫描时同时对0和2进行位置定位
// 剩下的1自然固定到了正确位置
// 使用双指针，一个指向0有序后的正确位置，一个指向1有序后的正确位置
void sortColors(vector<int>& nums) {
    int len = nums.size();

    int zero_point = 0; // 0元素在有序后的位置，从前往后遍历
    int two_point = len - 1; // 2元素在有序后的位置，并且从后往前遍历、

    // 到遍历到two_point时，表示前面已经有序了，并且two_point后面的都是2，已经满足题意，所以中止循环
    for (int i = 0; i <= two_point;i++){
        // -------------- while一定要在if(nums[i]==0)之前，否则有些情况无法处理，因为需要每次都更新zero_point-----------------
        // 遇到2后，需要不断移动two_point来进行交换，直到遇到一个不是2的数，
        // 因为一次交换可能使得nums[i]还是2，并且这是一遍扫描，所以这样会出错
        // 于是需要找到一个本应该处在i位置的元素
        while(nums[i]==2 && i < two_point){
            // 交换nums[i]与nums[two_point]
            int temp = nums[two_point];
            nums[two_point] = nums[i];
            nums[i] = temp;
            // two_point左移
            two_point--;
        }
        
        if(nums[i]==0){
            // 交换nums[i]与nums[zero_point]
            int temp = nums[zero_point];
            nums[zero_point] = nums[i];
            nums[i] = temp;
            // zero_point右移
            zero_point++;
        }
    }
}


// 原地对nums排序（居然是mid难度题???)
// 0,1,2分别表示红色、白色、蓝色
void sortColors1(vector<int>& nums) {
    int len = nums.size();

    for (int i = 0; i < len;i++){
        for (int j = 0; j < i;j++){
            if(nums[i]<nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}



int main(){

    vector<int> nums = {2,2,0,1,1,2,0};
    sortColors(nums);
    for (int i = 0; i < nums.size();i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}