// 题目链接   https://leetcode.cn/problems/gas-station/


#include<cstdio>
#include<vector>
#include <numeric>
using namespace std;


// 思路：此题用贪心算法,充分利用了很多潜在信息,去掉了很多不必要重复判断的点
// 核心思想：只遍历一遍,记录汽车中汽油数量变化(sum),若从i到end(end不为数组末尾),且恰好在end处sum<0,说明
// i不能作为start,且i与end之间都无法作为start,下一次应该从end+1开始进行start测试(因为i能作为start,说明gas[i]-start[i]>=0,若在i与end
// 之间找一个结点作为start,那么它累加到end一定为负,因为加上i这个非负数都为负,没有i只会更少)
// 所以当end处sum<0,下一个能作为起点的是end+1，继续遍历到gas.length-1,若在其间找到了一个start,使得在gas.length-1处sum>=0,
// 那么就不用判断从gas.length-1往0方向再走到start是否可行
// 因为前提是判断了这组数一定存在解,且这个解是唯一的而0...start之间已经判断过无法找到start,那么这个唯一的解就是start
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int sum = 0; // 汽车油量
    int start = 0;  // 起始点

    for (int i = 0; i < len;i++){
        sum += gas[i] - cost[i];
    }

    if(sum < 0){
        // sum<0,表示总的gas<总的cost,无解
        return -1;
    }

    sum = 0;  // 重置sum
    // 使用贪心策略去寻找那个start
    for (int i = 0; i < len;i++){
        sum += gas[i] - cost[i];
        if(sum < 0){
            start = i + 1;
            sum = 0; // sum重置,模拟选择i+1作为起点,重新模拟
        }
    }

    return start;
}

// --------------------- 利用折线图的算法也不是最简单的----------------------
// 思路：暴力算法是O(N^2)的时间复杂度,但是从另一个角度去考虑,可以降低到O(N)的时间复杂度
// (借鉴)根据gas[i]-cost[i]的值得出在i结点汽油变化数量,从数组的下标0这个汽油站开始遍历
// 用sum来求和沿途中的汽车汽油数量,满足题意的只有sum在每一时刻都>=0,然而从0开始遍历的不一定满足
// 画出sum-i的折线图，寻找图中最低点,如果将最低点视为起始点,那么折线图总会在x轴上方,即满足了
// 每一时刻sum>=0,据此思想可以更加快速寻找到那个起始点
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {

    int len = gas.size();

    int sum = 0; // 汽车邮箱中的汽油数量
    int min_sum = 0;  // 折线图中sum最小的那个值
    int start = 0;   // 出发点
    for (int i = 0; i < len;i++){
        sum += gas[i] - cost[i];
        if(sum < min_sum){
            min_sum = sum;
            // 为什么start=i+1?
            // 可以从折线图中考虑,当sum在i这个点最小,说明从i-1到i图像是下降的,也表示i处gas[i]-cost[i]为负数
            // 那么i这个点无法作为出发点,因为本来就没有足够油往后行驶
            // 当sum为全局最小时,表示i到i+1图像是上升的,即i+1处gas[i]-cost[i]为非负数,可以作为出发点
            start = i + 1;
        }
    }

    if(sum < 0){
        // 遍历完数组后,sum<0表示总的gas<总的cost,自然是无法循环一周的
        return -1;
    }

    // 处理start为数组中最后一个元素下标情况
    return start == len ? 0 : start;
}


// ------------------- 这种暴力解法一定会超时-------------------------
// 从start个(下标从0开始)油站开始绕行，是否能绕行一周
bool isCompleteCircuit(vector<int>& gas, int start, vector<int>& cost){
    int sum_gas = 0;
    int cur_pos = start;
    int next_pos = start+1;

    while(next_pos != start){
        sum_gas = sum_gas + gas[cur_pos] - cost[cur_pos];  // 从cur_pos走到next_pos后邮箱还剩的油
        if(sum_gas<0){
            return false;  // 无法从cur_pos走到next_pos汽油站
        }

        next_pos = (cur_pos + 1) % gas.size();
        cur_pos = next_pos;  // 更新位置
    }
    return true;
}


// 思路：类似一种银行家算法的思路,不过此题更简单,可能的序列相邻结点之间是有序的
int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {

    // 如果能充值的汽油数量小于绕行一周需要的汽油数量,则一定无法绕行一周

    if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)){
        return -1;
    }

    for (int i = 0; i < gas.size();i++){

        // 可以从下标为i的汽油站出发(当且仅当获得的汽油数能抵过消耗的汽油)
        if(gas[i]>=cost[i]){
            // 找到了可以出发的汽油站
            if(isCompleteCircuit(gas,i,cost)){
                return i;
            }
        }
    }
    return -1;  // 无法找到满足题意的出发汽油站
}

int main(){

    vector<int> gas = {5,1,2,3,4};
    vector<int> cost = {4,4,1,5,1};

    int res = canCompleteCircuit(gas, cost);

    printf("%d\n", res);

    return 0;
}
