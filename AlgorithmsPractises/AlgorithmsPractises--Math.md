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

##### 3 [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) 

题目描述如下：

> Given a column title as appear in an Excel sheet, return its corresponding column number.
>
> For example:
>
> ```
>     A -> 1
>     B -> 2
>     C -> 3
>     ...
>     Z -> 26
>     AA -> 27
>     AB -> 28 
> ```

这是一个跟EXCEL有关的题目，字母A到Z分别依次表示1到26，然后AA表示27，AB表示28。解法如下：

```c++
class Solution {
public:
    int titleToNumber(string s) {
        if(s.size() <= 0)
            return 0;
        int n = s.size();
        int num = 0;
        for(int i=0; i<n; i++){
            int tmp = s[i] - 65 + 1;
            num += pow(26, n-i-1) * tmp;
        }
        return num;
    }
};
```

这是一个相当于二十六进制的问题，先取得当前字符对应表示的数字，这可以通过减去65再加1，这是根据对应的ASCII表，然后根据其所在位置判断其对应要乘的26的阶数。

一个更简洁以及快速的解法如下：

```c++
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++);
        return result;
    }
};
```

由于对字符串取值是从其高位开始，所以每次相加的时候让之前累加的结果乘以一个26，再加上当前位置的字母表示的数字即可。

##### 4 [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)

题目描述如下：

> Given a positive integer, return its corresponding column title as appear in an Excel sheet.
>
> For example:
>
> ```
>     1 -> A
>     2 -> B
>     3 -> C
>     ...
>     26 -> Z
>     27 -> AA
>     28 -> AB 
> ```

跟上一题相反，这是给出数字转换成字符串，解法如下：

```c++
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        char tmp;
        while(n > 0){
            n -= 1;
            tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        return res;
    }
};
```

这里需要注意的是`n -= 1;`这一步，如果不执行这一步，在后面无论是整除和求余操作，在遇到26的倍数的数字的时候会出现错误。

##### 5 [Add Binary](https://leetcode.com/problems/add-binary/)

题目描述如下：

> Given two binary strings, return their sum (also a binary string).
>
> For example,
> a = `"11"`
> b = `"1"`
> Return `"100"`.

给定两个二进制表示的字符串，返回其求和的字符串形式。解法如下：

```c++
class Solution {
public:
    string addBinary(string a, string b) {
         string result = "";
        int apos = a.size() - 1;
        int bpos = b.size() - 1;
        int adigit, bdigit, carry = 0;
        
        while (apos >= 0 || bpos >= 0 || carry == 1)
        {
            adigit = bdigit = 0;
            
            if (apos >= 0) adigit = a[apos--] == '1';
            if (bpos >= 0) bdigit = b[bpos--] == '1';
            
            // Another way: the digit is 1 if adigit + bdigit + carry == 1 or == 3, but I noticed that
            // XOR is more concise:
            result = static_cast<char>(adigit ^ bdigit ^ carry + '0') + result; 
            carry = adigit + bdigit + carry >= 2;
        }
        
        return result;
    }
};
```

在循环中要注意`carry == 1`的条件，这是表示有进位的情况，循环先从每个字符串尾部开始，也就是二进制的最低位开始进行相加，通过判断每一位是否为字符`1`，来得到`adigit`和`bdigit`，然后相加的时候使用异或操作，即`adigit ^ bdigit ^ carry`，同时要用`static_cast`来转换成字符`char`类型，然后要计算是否有进位，即`carry`的数值。

##### 6 [Plus One](https://leetcode.com/problems/plus-one/)

题目描述如下：

> Given a non-negative integer represented as a **non-empty** array of digits, plus one to the integer.
>
> You may assume the integer do not contain any leading zero, except the number 0 itself.
>
> The digits are stored such that the most significant digit is at the head of the list.

给定一个数组，每个元素表示一个整数的一个位数，现在是将每一位都加一。解法如下：

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for(int i = digits.size() - 1; i >=0 && carry; i--){
            carry = (++digits[i]%=10) == 0;
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```

上述解法，每次对一位加1后都需要对10进行求余，如果最终`carry`是`true`，那么需要在最前位加1。

#####  7 [Power of Three](https://leetcode.com/problems/power-of-three/) 

题目描述如下：

> Given an integer, write a function to determine if it is a power of three.
>
> **Follow up:**
> Could you do it without using any loop / recursion?

给出一个整数，判断其是否3的幂数。解法如下：

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0)
            return false;
        if (n<=0) 
            return false;
        int t = pow(3,(int)(log(INT_MAX)/log(3)));
        return (t%n == 0);
    }
};
```

这是先找出3的幂数中最大的一个数，然后将其对给定的整数`n`进行求余操作，如果结果为0，表示`n`是3的一个幂数，否则不是。

##### 8 [Power of Two](https://leetcode.com/problems/power-of-two/)

题目描述如下：

> Given an integer, write a function to determine if it is a power of two.

跟上题类似，这是判断2的幂数，可以使用相同的解法：

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
            return false;
        if (n<=0) 
            return false;
        int t = pow(2,(int)(log(INT_MAX)/log(2)));
        return (t%n == 0);
    }
};
```

这是先找出2的幂数中最大的一个数，然后将其对给定的整数`n`进行求余操作，如果结果为0，表示`n`是3的一个幂数，否则不是。

另一个解法如下：

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
         return n > 0 && !(n&(n-1));
    }
};
```

这是由于2的幂数的二进制形式都是最左边一位是1，然后后面的低位都是0，如对于4，二进制是`0100`,那么它跟3进行与操作得到的就是0了。

##### 9 [Missing Number](https://leetcode.com/problems/missing-number/)

题目描述如下：

> Given an array containing *n* distinct numbers taken from `0, 1, 2, ..., n`, find the one that is missing from the array.
>
> For example,
> Given *nums* = `[0, 1, 3]` return `2`.
>
> **Note**:
> Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

这是寻找缺乏的数字。解法如下：

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing =0;
        for(int i=0; i<nums.size();++i) 
            missing ^= ((i+1)^nums[i]);
        return missing;
    }
};
```

上述解法的思路是使用异或的做法，并且每次异或操作手动增加一个数字`i+1`，然后数组中缺少的数字则只会在异或操作中出现一次，而其他数字是出现两次，因此最终结果就是缺少的数字。

##### 10 [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

题目描述如下：

> Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the [Hamming weight](http://en.wikipedia.org/wiki/Hamming_weight)).
>
> For example, the 32-bit integer ’11' has binary representation `00000000000000000000000000001011`, so the function should return 3.

寻找给定一个无符号整数的二进制表示中1的个数。解法如下：

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            ++count;
            n = n & (n-1);
        }
        return count;
    }
};
```

这是通过每次循环让`n`与`n-1`进行与操作，这样会让最左端的位数为1变为0，而且有多少个1就循环多少次。效率大大提高。

##### 11 [Counting Bits](https://leetcode.com/problems/counting-bits/)

题目描述如下：

> Given a non negative integer number **num**. For every numbers **i** in the range **0 ≤ i ≤ num** calculate the number of 1's in their binary representation and return them as an array.
>
> **Example:**
> For `num = 5` you should return `[0,1,1,2,1,2]`.

这道题目是给定一个数字`n`,求在`0-n`范围内的整数，其二进制表示分别有多少个1.解法如下：

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> r;
        int i=0;
        while(i <= num){
            int count = 0;
            int it = i;
            while(it){
                ++count;
                it = it & (it-1);
            }
            r.push_back(count);
            i++;
        }
        return r;
    }
};
```

上述解法主要是使用了求取单个数字二进制表示有多少个1的思路，其时间复杂度是$O(n*sizeof(integer))$。

一个更快的解法如下：

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
```

这个方法是$O(n)$的时间复杂度。它是利用前面已经计算好的结果来得到后面的结果。代码中`ret[i&(i-1)]`这里就体现了这个思路，比如当前计算的是14，它是`1110`的二进制表示，实际上可以看做12，即`1100`再增加一个1，所以将其跟13进行与操作，得到的就是12，然后再进行加1，就得到14的1的个数了。

