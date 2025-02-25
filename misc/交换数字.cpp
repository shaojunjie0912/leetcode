#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        // NOTE: 异或, 不能交换本身 nums[0] nums[0]
        numbers[0] = numbers[0] ^ numbers[1];
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
};
