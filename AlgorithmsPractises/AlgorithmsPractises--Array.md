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

##### 4 [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)

题目描述如下：

> Given *numRows*, generate the first *numRows* of Pascal's triangle.
>
> For example, given *numRows* = 5,
> Return
>
> ```
> [
>      [1],
>     [1,1],
>    [1,2,1],
>   [1,3,3,1],
>  [1,4,6,4,1]
> ]
> ```

这是要求打印出给定行数的帕斯卡金字塔，这里需要找出这个金字塔的规律，从第三行开始，每行除了首尾都是1外，其他数值都等于上一行同个位置和前一个位置的相加结果，解法如下：

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows <= 0)
            return vector<vector<int>>();
        vector<vector<int> > res;
        if(numRows >= 1)
            res.push_back({1});
        if(numRows >= 2)
            res.push_back({1, 1});
        for(int i=2; i < numRows; i++){
            vector<int> temp(i+1,1);
            for(int j = 1; j <= i-1; j++){
                temp[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(temp);
        }
        return res;
    }
};
```

一个更简洁的代码如下：

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
};
```

上述解法首先是按照给定的行数定义一个相同数量元素的`vector<vector<int>>`，然后循环的时候，再根据当前所在行调整`vector`的大小，并将首尾数组赋值为1。

##### 5 [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)

题目如下：

> Given an index *k*, return the *k*th row of the Pascal's triangle.
>
> For example, given *k* = 3,
> Return `[1,3,3,1]`.

这是给定一个行的索引值，返回帕斯卡金字塔该层的数值。实现如下：

```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
            return vector<int>();
        vector<int> res(rowIndex+1);
        res[0]=1;
        for(int i=0; i <= rowIndex; i++){
            for(int j=i; j>0; j--){
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};
```

上述解法是采用从右到左的方式来改变当前层的元素，因为要求空间复杂度是`O(k)`，也就是需要改变原数组的数值，而从右到左的相加可以得到所需结果。

另一种解法如下：

```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
            return vector<int>();
        vector<int> r;
        r.resize(rowIndex + 1);
        r[0] = r[rowIndex] = 1;
        for(auto i = 1; i < (r.size() + 1)/2; ++i)
        {
            r[i] = r[rowIndex - i] = (unsigned long)r[i - 1]*(unsigned long)(rowIndex - i + 1)/i;
        }
        return r;
    }
};
```

上述解法首先是因为每行的元素都是对称的，其次对于帕斯卡金字塔中第n行的第k个元素可以表示为`C(n-1,k-1)`，即从n-1个不同元素中取m-1个元素的组合数。

##### 6 [Move Zeroes](https://leetcode.com/problems/move-zeroes/)

题目描述如下：

> Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.
>
> For example, given `nums = [0, 1, 0, 3, 12]`, after calling your function, `nums` should be `[1, 3, 12, 0, 0]`.
>
> **Note**:
>
> 1. You must do this **in-place** without making a copy of the array.
> 2. Minimize the total number of operations.

这道题目是将数组中的0都移动到数组末尾，而非0元素的排序保持不变，解法如下：

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <=0)
            return;
        int lens = nums.size();
        int counts=0;
        int j = 0;
        for(int i=0; i<lens; i++){
            if(nums[i] == 0)
                counts++;
            else{
                nums[j++] = nums[i];
            }
        }
        while(counts>0 && j>0){
            nums[j++] = 0;
            counts--;
        }
    }
};
```

上述解法在循环中需要统计0的个数，然后对于非0元素，则用一个变量`j`来将其从头开始放置，最后再根据0的个数，将后面的空间都赋值为0。

一个更简洁的代码如下：

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <=0)
            return;
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
```

这是一个更简洁更快的解法。

##### 7 [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) 

题目描述如下：

> Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

给定一个数组,判断数组中是否包含重复的数字,第一种解法如下:

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 0)
            return false;
        int lens = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<lens; i++){
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};
```

这个解法首先是对数组进行排序，然后再遍历数组，如果相邻两个数值相等，就说明是重复数字。

第二种解法如下：

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 0)
            return false;
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};
```

这个解法就是利用了`set`数据结构中存储着都是数值不同的特性，如果其大小比原数组小，说明数组中存在重复的数字。

##### 8 [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)

题目描述如下:

> Given an array of integers and an integer *k*, find out whether there are two distinct indices *i* and *j* in the array such that **nums[i] = nums[j]** and the difference between *i* and *j* is at most *k*.

这道题目是给出一个数组和一个数字`k`，在数组中搜索是否存在相同的两个数字的索引值差不大于`k`，如果有，返回`true`,否则返回`false`。解法如下：

```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) 
            return false;
        if (k >= nums.size()) 
            k = nums.size() - 1;
        set<int> cand;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) 
                cand.erase(nums[i-k-1]);
            if (!cand.insert(nums[i]).second) 
                return true;
        }
        return false;
    }
};
```

上述方法采用了`set`以及滑动窗口的思想，其实就是判断在一个长度为`k`的窗口内是否存在相同的两个数字，当遍历索引值大于`k`值后，首先会删除窗口的第一个元素，即`nums[i-k-1]`，然后由于`set`只能存在单独不重复的数字，如果插入操作失败，说明已经存在一个相同的数字，此时就满足条件，可以返回`true`。

另一种解法如下：

```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) 
            return false;
        if (k >= nums.size()) 
            k = nums.size() - 1;
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k)
                return true;
            mp[nums[i]] = i; 
        }
        return false; 
    }
};
```

思路是一样的，不过这是采用`unordered_map`这种数据结构

##### 9 [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/)

题目描述如下：

> Given an array of integers, find out whether there are two distinct indices *i* and *j* in the array such that the difference between **nums[i]** and **nums[j]** is at most *t* and the difference between *i* and *j* is at most *k*.

给定一个数组，以及一个`t`和`k`，要求寻找两个数字，这个数字的差值不大于`t`,且其索引值也不大于`k`。解法如下：

```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0) 
            return false;
        if (k >= nums.size()) 
            k = nums.size() - 1;
        set<int> cand;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) 
                // keep the set contains nums i j at most k
                cand.erase(nums[i-k-1]);
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = cand.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
            // x - nums[i] <= t ==> |x - nums[i]| <= t    
            if (pos != cand.end() && *pos - nums[i] <= t) 
                return true;
            cand.insert(nums[i]);
        }
        return false; 
    }
};
```

上述解法首先使用`set`，然后使用滑动窗口的思路，保证索引值的差值符合要求，然后利用`set`的`lower_bound()`函数返回第一个大于等于`nums[i]-t`的索引值，原因在上述代码注释中给出，因为要求$|nums[i]-nums[j]| \le t$，因此可以推导得到$num[i] - t \ge x$，然后继续判断这个索引值如果是在滑动窗口内，且符合要求，就可以返回`true`。

