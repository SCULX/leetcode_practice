// 题目链接  https://leetcode.cn/problems/simplify-path/

#include<cstdio>
#include<string>
#include<vector>
using namespace std;

// 模拟的时间复杂度太高，分支多且复杂，很容易出错
// 思路：进行模拟
string simplifyPath1(string path) {
    int len = path.length();
    string res = "/"; // 简化后的规范路径,初始化为/开头
    vector<string> dirs; // // 路径中目录
    string dir; // 路径中目录
    int flag = 0;  // .(1)和..(2)的区分标志,初始为没有.(0)

    for (int i = 1; i < len; i++){
        
        if(path[i]=='/'){
            if(flag == 1){
                // 表示目前构成了./,是同级目录
                if(!dir.empty()){
                    dirs.push_back(dir); // 将当前目录加入列表
                    dir.clear(); // 重置收集目录的字符串
                }
                flag = 0; 
            }
            else if(flag == 2){
                // 表示目前构成了../,是上级目录
                if(!dirs.empty()){
                    dirs.pop_back(); // 清除之前的一个目录，实现返回上一级
                }
                flag = 0; // 重置标记
            }
            else{
                if(!dir.empty()){
                    // 目录字符串不为空时，说明已经收集到一个完整目录，加入列表
                    dirs.push_back(dir);
                    dir.clear(); // 重置收集目录的字符串
                }
                flag = 0;
            }
        }
        else if(path[i]=='.'){
            if(flag == 0){
                // 前一个字符不是.,当前状态为.
                flag = 1;
            }
            else if(flag == 1){
                // 前一个字符是.,当前状态为..
                flag = 2;
            }
            else if(flag == 2){
                // 此时...是目录或文件
                dir.append("...");
                flag = 3; // 表示现在时得到目录字符串的状态
            }
            else{
                // 此时tool..应该是目录或文件
                dir.push_back(path[i]);
            }
            
        }
        else{
            if(flag == 2)
                dir.append("..");
            if(flag == 1)
                dir.append(".");
            dir.push_back(path[i]);
            flag = 3;  // 处理file..这种情况，应认为目录
        }
    }

    // 处理最后dir中可能的情况
    if(!dir.empty()){
        if(dir==".." && !dirs.empty()){
            dirs.pop_back();
        }
        else{
            if(dir != "."){
                dirs.push_back(dir);
            }
        }
    }
    else{
        // 因为.. 为结束的字符串，dir中时暂时不存的，所以用flag来判断
        if(flag == 2){
            if(!dirs.empty()){
                dirs.pop_back();
            }
        }
    }

    for (int i = 0; i < dirs.size();i++){
        res += dirs[i];
        if(i != dirs.size()-1){
            res += '/';  // 非最后一个目录或文件,需要用/分隔
        }
    }

    return res;
}

// 使用字符分割
void Stringsplit(const string& str, const char split, vector<string>& res)
{
	if (str == "") return;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + split;
	size_t pos = strs.find(split);
 
	// 若找不到内容则字符串搜索函数返回 npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}
}


// 根据官方解释，利用栈来解决，可以降低时间复杂度
// 思路，用/对path进行split,会得到4种类型
// ① 空字符串，因为///这样分割会产生空串
// ② .    ③ ..  ④ 其余非空字符串
// 对于①和②都不需要处理，用栈存储非空字符串，得到④就压入栈;遇到③时,如果栈非空,则弹出栈顶元素
string simplifyPath(string path) {
    vector<string> strstack;   // 用数组来模拟栈
    vector<string> splitedstr;  // split后的字符串
    Stringsplit(path, '/', splitedstr); // 分割字符串
    string res = "/";  // 简化后的路径

    for (int i = 0; i < splitedstr.size();i++){
        if(splitedstr[i]==".."){
            if(!strstack.empty()){
                strstack.pop_back();
            }
        }else{
            if(splitedstr[i] != "." && splitedstr[i] != ""){
                strstack.push_back(splitedstr[i]);
            }
        }
    }

    for (int i = 0; i < strstack.size();i++){
        res += strstack[i];
        if( i != strstack.size()-1){
            res += "/";
        }
    }
    return res;
}

int main(){

    string path = "/..hidden";

    string res = simplifyPath(path);

    printf("%s\n", res.c_str());

    return 0;
}