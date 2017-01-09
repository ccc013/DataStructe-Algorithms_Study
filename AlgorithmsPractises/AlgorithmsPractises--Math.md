### AlgorithmsPractises--Math

------

记录算法练习中的练习题以及实现的代码，练习题主要是来自[LeetCode](https://leetcode.com/problemset/algorithms/)，主要还是按照级别，由简单到难的顺序练习，并且主要是有关数学的算法题。

##### 1 [Add Digits](https://leetcode.com/problems/add-digits/)

题目描述如下：

> Given a non-negative integer `num`, repeatedly add all its digits until the result has only one digit.
>
> For example:
>
> Given `num = 38`, the process is like: `3 + 8 = 11`, `1 + 1 = 2`. Since `2` has only one digit, return it.
>
> **Follow up:**
> Could you do it without any loop/recursion in O(1) runtime?

题目要求给定一个正整数，求它的每个数位之和，返回结果必须只有一位数，即小于10。实现如下：

```c++
class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        int res = num - 9 * ((num - 1) / 9);
        return res;
    }
};
```

上述代码可以在$O(1)$时间内完成，其核心公式是$dr(n) = n - 9 * \lfloor \frac{n-1}{9} \rfloor$，参考[Digital root](https://en.wikipedia.org/wiki/Digital_root)。更详尽的解释如下：

> For base *b* (decimal case *b* = 10), the digit root of an integer is:
>
> - dr(*n*) = 0 if *n* == 0
> - dr(*n*) = (*b*-1) if *n* != 0 and *n* % (*b*-1) == 0
> - dr(*n*) = *n* mod (*b*-1) if *n* % (*b*-1) != 0
>
> or
>
> - dr(*n*) = 1 + (*n* - 1) % 9
>
> Note here, when *n* = 0, since (*n* - 1) % 9 = -1, the return value is zero (correct).
>
> From the formula, we can find that the result of this problem is immanently periodic, with period (*b*-1).
>
> Output sequence for decimals (*b* = 10):
>
> ~input: 0 1 2 3 4 ...
> output: 0 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 ....

这就是上一题的解答思路。

##### 2 [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)

题目描述如下：

> Given a **non-empty** integer array of size *n*, find the minimum number of moves required to make all array elements equal, where a move is incrementing *n* - 1 elements by 1.
>
> **Example:**
>
> ```
> Input:
> [1,2,3]
>
> Output:
> 3
>
> Explanation:
> Only three moves are needed (remember each move increments two elements):
>
> [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
> ```

给定一个数组，每次`move`操作是将其中`n-1`个元素增加1，求需要多少次`move`操作后使得数组元素都相等。解法如下：

```c++
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return 0;
        int minNum = nums[0];
        long sum = nums[0];
        for(int i=1; i < n; i++){
            minNum = min(minNum, nums[i]);
            sum += nums[i];
        }
        return sum - long(minNum) * long(n);
    }
};
```

这个解法首先是从数学思路上解答，假设`n`是数组的长度，`minNum`是当前数组的最小值，而`m`就是移动的次数，而`sum`是`m-1`次移动后数组求和的数值，`x`则是`m`次操作后，数组中的一个数字，则如果进行`m`次操作可以达到题目要求，既有
$$
sum + m * (n - 1) = x * n \\
其中，x = minNum + m \\
最终得到 m = sum - minNum * n
$$
通过这些数学公式，可以编程实现。

##### 3 