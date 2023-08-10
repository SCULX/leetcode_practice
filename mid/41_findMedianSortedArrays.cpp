// 题目链接  https://leetcode.cn/problems/median-of-two-sorted-arrays/

#include<cstdio>
#include<vector>
using namespace std;

/*
* nums: 数组
* sta: 起始位置
* end: 中止位置
* k: 拼接数组的前第k小的数
*/
// 在nums1和nums2拼接数组中寻找第k + 1小的数
int getKInnums(vector<int>& nums1,int sta1,int end1,
                    vector<int>& nums2,int sta2,int end2,int k)
{
    if(k==1){
        // k==1时表示已经找到前k小的数，只需要继续寻找下一个数即可
        // 若sta1越界，说明需要取nums2[sta2]; 若sta2越界，说明需要取nums1[sta1]
        if(sta1 > end1 ){
            return nums2[sta2];
        }
        else if(sta2>end2){
            return nums1[sta1];
        }
        else{
            return min(nums1[sta1], nums2[sta2]);
        }
    }

    int i = sta1 + k / 2 - 1;   // nums1中需要判断的元素下标
    int j = sta2 + k / 2 - 1;   // nums2中需要判断的元素下标

    if(i > end1){
        int new_k = k - (end1 - sta1) - 2;  // 还需要在nums2中继续寻找第new_k+1小的数
        return nums2[sta2 + new_k];
    }

    if(j > end2){
        // 处理j > end2的情况
        int new_k = k - (end2 - sta2) - 2; // 还需要再nums1中继续寻找第new_k+1小的数
        return nums1[sta1 + new_k];
    }


    if(nums1[i]<nums2[j]){
        // 直接把nums1[k/2]之前的数舍去
        int new_k = k - (i - sta1 + 1);
        sta1 = i + 1;
        getKInnums(nums1, sta1, end1, nums2, sta2, end2, new_k);
    }
    else{
        int new_k = k - (j - sta2 + 1);
        sta2 = j + 1;
        getKInnums(nums1, sta1, end1, nums2, sta2, end2, new_k);
    }
}

// 用二分搜索，但是思路有点难理解，需要特别细致去参悟
// 设中位数为合并后的第k个数，那么问题变为在nums1，nums2中寻找前k/2个数，直到k变为1
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int len1 = nums1.size();
    int len2 = nums2.size();

    int mid = (len1 + len2)/2;  // 得到的mid为中位数的下标(若len1+len2为偶数，则另一个中位数下标为mid-1)


    if((len1+len2)%2==0){
        // 拼接数组长度为偶数，则有2个中位数，需要返回平均值
        int pre_mid_num = getKInnums(nums1, 0, len1 - 1, nums2, 0, len2 - 1, mid);
        int mid_num = getKInnums(nums1, 0, len1 - 1, nums2, 0, len2 - 1, mid + 1);
        return (pre_mid_num + mid_num) / 2.0;
    }
    else{
        int mid_num = getKInnums(nums1, 0, len1 - 1, nums2, 0, len2 - 1, mid + 1);
        return (double)mid_num;
    }

}

// ------------  错误解法，时间复杂度不是log,而是O(m+n),要实现log,需要二分搜索------------
// 思路：需要固定时间复杂度为O(log(m+n))
// 所以直接按照合并两个有序链表的思路，在合并这2个数组时，直接一步步找到mid或者mid左右的两个数
double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(); // nums1的length
    int n = nums2.size(); // nums2的length

    bool flag = (m + n) % 2 == 0 ? true : false; // 联合数组长度是否为偶数，为偶数时flag=true
    int mid = (m + n) >> 1;  // 两数组联合后中位数的下标

    int index = 0, i = 0, j = 0;    // index定位中位数过程中的下标， i为nums1的下标， j为nums2的下标
    int nums_mid, nums_pre_mid;   // 中位数，偶数长度时中位数中左边那个数
    
    while(i < m && j < n){
        if(nums1[i]<nums2[j]){
            // 找到了中位数，并break循环(下同)
            if(index == mid){
                nums_mid = nums1[i];
                index++;
                break;
            }
            index++;
            // index++后如果等于mid，说明当前比较得到的数其实是mid-1,所以如果是需要求平均值得到中位数，
            // 那么就记录此数，并且不能break,只有找到下标为mid的数才能中止循环(下同)
            if(flag && index == mid){
                nums_pre_mid = nums1[i];
            }
            i++;
        }
        else{
            if(index == mid){
                nums_mid = nums2[j];
                index++;
                break;
            }
            index++;
            
            if(flag && index == mid){
                nums_pre_mid = nums2[j];
            }
            j++;
        }
    }

    // 处理nums1已经遍历完，但nums2还没有遍历完
    // 则后续处理均在nums2上
    if (i >= m && index <= mid)
    {   
        nums_mid = nums2[mid - index + j];
        if(flag && index < mid){
            // 表明还没有得到需要求平均值的左值
            nums_pre_mid = nums2[mid - index + j - 1];
        }
    }

    // 处理nums2已经遍历完，但nums1还没有遍历完
    // 则后续处理均在nums1上
    if (j >= n && index <= mid)
    {
        nums_mid = nums1[mid - index + i];
        if(flag && index < mid){
            // 表明还没有得到需要求平均值的左值
            nums_pre_mid = nums1[mid - index + i - 1];
        }
    }

    double mid_num = flag ? (double)(nums_mid + nums_pre_mid) / 2.0 : nums_mid;
    return mid_num;
}

int main(){

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    double mid = findMedianSortedArrays(nums1, nums2);

    printf("%lf\n", mid);

    return 0;
}