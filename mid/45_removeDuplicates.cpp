// 题目链接  https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

#include<cstdio>
#include<vector>
using namespace std;

// 思路：原地删除nums中重复元素，就是依次遍历，计数。出现次数超过2次的就将后续元素向前移位
int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    int temp = nums[0]; // 临时暂存一个数
    int count = 1; // 为temp出现次数进行计数(初始化为出现1次)

    for (int i = 1; i < len;i++){
        if(nums[i]==temp){
            count++;
        }
        else{
            // 遇到新的数，重置暂存变量和统计出现次数
            temp = nums[i];
            count = 1;
        }
        
        if(count > 2){
            // 后面的元素向前移位
            // 对于[0,0,0(i),0,0,1,1,2]这种情况,直接判断后续是否还为0,移动1到0(i)的位置，更进一步简化流程
            int pos = i + 1;   // 当前位置往后的第一个不等于当前元素的位置
            int curpos = i;  // 当前位置
            while(pos< len && nums[pos] == temp){
                pos++;
            }
            while(pos < len ){
                nums[curpos++] = nums[pos++];
            }
            len = len - (pos-curpos); // 更新数组长度
            i--; // 移位后，需再次判断当前位置的元素
        }
    }
    return len;
}

int main(){

    vector<int> nums = {1,2,2,2};

    int len = removeDuplicates(nums);

    for (int i = 0; i < len;i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}