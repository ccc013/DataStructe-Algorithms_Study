### AlgorithmsPractises--Array

------

记录算法练习中的练习题以及实现的代码，练习题主要是来自[LeetCode](https://leetcode.com/problemset/algorithms/)，主要还是按照级别，由简单到难的顺序练习，并且主要是有关数组的算法题。

##### 1 [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

题目描述如下：

> Given an array of integers where 1 ≤ a[i] ≤ *n* (*n* = size of array), some elements appear twice and others appear once.
>
> Find all the elements of [1, *n*] inclusive that do not appear in this array.
>
> Could you do it without extra space and in O(*n*) runtime? You may assume the returned list does not count as extra space.
>
> **Example:**
>
> ```
> Input:
> [4,3,2,7,8,2,3,1]
>
> Output:
> [5,6]
> ```

这道题目是给定一个长度为n的数组，数组元素的取值范围是[1,n]，需要找出数组中缺失的数值，实现代码如下：

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) 
              res.push_back(i+1);
        }
        return res;
    }
};
```

上述解法分两次迭代，第一次是将出现过的数值作为索引对应位置上的数值变成负数，如果没有出现该数值，那么其对应位置上的数值还是一个正数，而第二次迭代则找出还是正数的索引，并放到结果中。如对于数组`[4,3,2,7,8,2,3,1]`，缺失的是5和6，所以对应位置上的8和2会在第一轮后还是正数，而其他数值都变成负数。

第二种解法如下：

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[nums[i]-1] != nums[i]){
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] != i+1){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
```

这种解法首先第一次循环是进行交换进行排序，第二次则比较当前索引值和元素值是否相等来得到缺乏的数值。

##### 2 [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

题目描述如下：

> Given a sorted array, remove the duplicates in place such that each element appear only *once* and return the new length.
>
> Do not allocate extra space for another array, you must do this in place with constant memory.
>
> For example,
> Given input array *nums* = `[1,1,2]`,
>
> Your function should return length = `2`, with the first two elements of *nums* being `1` and `2` respectively. It doesn't matter what you leave beyond the new length.

这道题目是要移除一个排序数组中重复的数字，并返回数组长度，要求是使用当前数组，不能有辅助空间。实现代码如下：

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        int j = 1;
        int n = nums.size();
        for(int i=1; i < n; i++){
            if(nums[i] != nums[i-1])
                nums[j++] = nums[i];
        }
        return j--;
    }
};
```

上述解法是采用一个辅助指针`j`，当前数组元素与前一个数组元素不相等的时候，就修改原数组，而如果相等，也就是这是一个重复的数值，那么就会跳过，最终得到的数组就是没有重复元素的数组。

##### 3 [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

题目描述如下：

> Given an array of integers that is already **sorted in ascending order**, find two numbers such that they add up to a specific target number.
>
> The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
>
> You may assume that each input would have exactly one solution.
>
> **Input:** numbers={2, 7, 11, 15}, target=9
> **Output:** index1=1, index2=2

给定一个数组和一个目标值，找出数组中两个相加后等于目标值的元素的索引值，并且索引值是从1开始算起的。实现如下：

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() <=0)
            return vector<int>();
        vector<int> res;
        int lens = numbers.size();
        int bIndex = 0;
        int eIndex = lens - 1;
        int sum = 0;
        while(bIndex < eIndex){
            sum = numbers[bIndex] + numbers[eIndex];
            if(sum < target){
                bIndex++;
            }else if(sum > target){
                eIndex--;
            }else{
                res.push_back(bIndex+1);
                res.push_back(eIndex+1);
                break;
            }
        } 
        return res;
    }
};
```

这里使用两个变量`bIndex`和`eIndex`，分别从数组两端开始往中间遍历，当两个元素值小于目标值，让前面的指针`bIndex`往后移动，而如果是大于目标值，则让`eIndex`往前移动。

