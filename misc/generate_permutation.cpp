#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 给定一个字符串s，长度为n，求s的所有子序列
// 1.子序列:
// 指一个字符串删掉部分字符（也可以不删）形成的字符串，可以是不连续的，比如"abcde"的子序列可以有"ace","ad"等等
// 2.将所有的子序列的结果返回为一个字符串数组
// 3.字符串里面可能有重复字符，但是返回的子序列不能有重复的子序列，比如"aab"的子序列只有"","a","aa","aab","ab","b"，不能存在2个相同的"ab"
// 4.返回字符串数组里面的顺序可以不唯一

class Solution {
public:
    // NOTE: 递归
    // 将字符串看成字符数组, 每一个字符都可以 "要" 或者 "不要"
    vector<string> generatePermutation(string s) {
        unordered_set<string> set;
        vector<string> ans;
        string path2(s.size(), 0);  // NOTE: 这里 path2 必须有长度, 否则 path2[size]!!
        R2(s, 0, path2, 0, set);
        // string path1;
        // R1(s, 0, path1, set);
        for (auto& str : set) {
            ans.push_back(std::move(str));
        }
        return ans;
    }

    void R1(string& str, int i, string& path, unordered_set<string>& set) {
        if (i == str.size()) {  // 如果来到字符串最后, 说明结束了
            set.insert(path);
            return;
        }
        // 要当前字符, 递归
        path += str[i];
        R1(str, i + 1, path, set);

        // ==== 子过程要了返回到父过程的时候必须恢复现场 ====

        // 不要当前字符, 递归
        path.pop_back();  // 删除影响, 恢复现场
        R1(str, i + 1, path, set);
    }

    // 使用 size 控制 path 大小, 不需要额外擦除, size 就是当前要写入的位置
    // 要当前字符就是赋值 path[size]
    void R2(string& str, int i, string& path, int size, unordered_set<string>& set) {
        if (i == str.size()) {                 // 如果来到字符串最后, 说明结束了
            set.insert(path.substr(0, size));  // 注意这里 substr, 只取有效范围的
            return;
        }
        path[size] = str[i];                  // 要当前字符
        R2(str, i + 1, path, size + 1, set);  // 此时size+1
        R2(str, i + 1, path, size, set);      // 不要当前字符此时变回size
    }
};
