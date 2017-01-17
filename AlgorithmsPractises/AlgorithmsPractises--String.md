### AlgorithmsPractises--String

------

记录算法练习中的练习题以及实现的代码，练习题主要是来自[LeetCode](https://leetcode.com/problemset/algorithms/)，主要还是按照级别，由简单到难的顺序练习，并且主要是有关字符串的算法题。

##### 1 [Reverse String](https://leetcode.com/problems/reverse-string/)

题目描述如下：

> Write a function that takes a string as input and returns the string reversed.
>
> **Example:**
> Given s = "hello", return "olleh".

这是翻转一个给定的字符串。解法如下：

```c++
class Solution {
public:
    string reverseString(string s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            char c = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = c;
        }
        return s;
    }
};
```

每次循环都交换首尾两个字符，并逐渐往字符串中间移动。

##### 2 [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/)

题目描述如下：

> Write a function that takes a string as input and reverse only the vowels of a string.
>
> **Example 1:**
> Given s = "hello", return "holle".
>
> **Example 2:**
> Given s = "leetcode", return "leotcede".
>
> **Note:**
> The vowels does not include the letter "y".

这是交换字符串中的元音字母，也就是`a, e, i, o, u`以及其大写，解法如下：

```c++
class Solution {
public:
    string reverseVowels(string s) {
        int bg = 0, end = s.size()-1;
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        while(bg < end){
            while(bg < end && vowels.find(s[bg]) == vowels.end())
                bg++;
            while(bg < end && vowels.find(s[end]) == vowels.end())
                end--;
            if(bg >= end)
                break;
            swap(s[bg], s[end]);
            bg++;
            end--;
        }
        return s;
    } 
};
```

首先使用`set`来保存元音字母，作为一个字典来查找，然后使用两个指针，分别指向字符串首尾，然后每次从建立好的`set`中查询当前字符是否元音字母，如果不是，就分别将指针增加或减少，这里需要注意进行边界判断，即`bg < end`，否则如果字符串中没有元音字母，运行会出错。

##### 3  [Ransom Note](https://leetcode.com/problems/ransom-note/)

题目描述如下：

> Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
>
> Each letter in the magazine string can only be used once in your ransom note.
>
> **Note:**
> You may assume that both strings contain only lowercase letters.
>
> ```
> canConstruct("a", "b") -> false
> canConstruct("aa", "ab") -> false
> canConstruct("aa", "aab") -> true
> ```

这道题目是给定两个字符串，判断第一个字符串是否能用第二个字符串中的字符组成，解法如下：

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magz(26,0);
        for(char c: magazine){
            int pos = c - 'a';
            magz[pos]++;
        }
        for(char r: ransomNote){
            int pos = r - 'a';
            if(--magz[pos]<0)
                return false;
        }
        return true;
    }
};
```
上述题目是使用一个`vector`作为一个字典使用，先将第二个字符串的字符和其出现次数用这个`vector`来存储，然后遍历第一个字符串，从`vector`中寻找是否有符合的字符。

##### 4 [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) 

题目描述如下：

> Given a roman numeral, convert it to an integer.
>
> Input is guaranteed to be within the range from 1 to 3999.

这是需要将罗马数字变成阿拉伯数字。解法如下：

```c++
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
       int sum = T[s.back()];
       for (int i = s.length() - 2; i >= 0; --i) 
       {
           if (T[s[i]] < T[s[i + 1]])
           {
               sum -= T[s[i]];
           }
           else
           {
               sum += T[s[i]];
           }
       }
       return sum;
    }
};
```

首先采用`unordered_map`将罗马数字及其对应的阿拉伯数字存储起来，然后循环的时候是从字符串最右侧开始，当左侧的罗马数字小于右侧罗马数字，那么结果应该是相减，否则则是相加的结果。

##### 5 