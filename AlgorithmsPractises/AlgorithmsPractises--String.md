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

##### 5 [Length of Last Word](https://leetcode.com/problems/length-of-last-word/) 

题目描述如下:

> Given a string *s* consists of upper/lower-case alphabets and empty space characters `' '`, return the length of last word in the string.
>
> If the last word does not exist, return 0.
>
> **Note:** A word is defined as a character sequence consists of non-space characters only.
>
> For example, 
> Given *s* = `"Hello World"`,
> return `5`.

题目是给定一个字符串，返回最后一个单词的长度，单词是通过空格来区分的。解法如下：

```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') 
            tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};
```

上述解法的思路是首先从字符串的尾部开始搜索第一个非空格的字符，然后从这个字符开始往前移动，直到遇到空格符，此时计算得到的长度就是目标所求长度了。

##### 6 [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string/)

题目描述如下：

> Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
>
> Please note that the string does not contain any **non-printable** characters.
>
> **Example:**
>
> ```
> Input: "Hello, my name is John"
> Output: 5
> ```

这道题目是计算给定字符串中单词的个数。解法如下：

```c++
class Solution {
public:
    int countSegments(string s) {
        int num = 0;
        int lens = s.size();
        int i=0;
        while(i < lens){
            if(i<lens && s[i] != ' '){
                i++;
                num++;
                while(i < lens && s[i] != ' ')
                    i++;
            }
            if(i < lens && s[i] == ' ')
                i++;
        }
        return num;
    }
};
```

上述解法是统计出现的第一个非空字符，然后遇到空字符，则跳过。

另一个解法如下：

```c++
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        s.push_back(' ');
        for(int i = 1; i < s.size(); ++i)
          if(s[i] == ' ' && s[i-1] != ' ') ++res;
        return res;
    }
};
```

这个解法首先在字符串末尾加一个空格字符，它是判断当前字符是空格而前一个字符是非空字符来计算单词的数目的。

##### 7 [Count and Say](https://leetcode.com/problems/count-and-say/)

题目描述如下：

> The count-and-say sequence is the sequence of integers beginning as follows:
> `1, 11, 21, 1211, 111221, ...`
>
> `1` is read off as `"one 1"` or `11`.
> `11` is read off as `"two 1s"` or `21`.
> `21` is read off as `"one 2`, then `one 1"` or `1211`.
>
> Given an integer *n*, generate the *n*th sequence.
>
> Note: The sequence of integers will be represented as a string.

这是给定一个整数的序列。解法如下：

```c++
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                 while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                    count++;    
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
```

上述解法，给定的`n`是循环的次数，根据当前`res`字符串的长度和内容来生成新的序列。

##### 8 [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/) 

题目描述如下：

> Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
>
> **Example 1:**
>
> ```
> Input: "abab"
>
> Output: True
>
> Explanation: It's the substring "ab" twice.
>
> ```
>
> **Example 2:**
>
> ```
> Input: "aba"
>
> Output: False
>
> ```
>
> **Example 3:**
>
> ```
> Input: "abcabcabcabc"
>
> Output: True
>
> Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
> ```

给定一个字符串，判断它是否由其一个子串重复几次构成。解法如下：

```c++
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.length();
        for (int i = 1; i <= n / 2; i++)
            if (n % i == 0 && str.substr(i) == str.substr(0, n - i))
                return true;
        return false;
    }
};
```

上述解法首先是利用了`string`的`substr()`函数，如果该函数只有一个参数，表示截取从该参数`i`开始后面所有的字符串，而两个参数，则分别表示开始位置和截取的长度。这个解法的思路是首先子串的长度必须是能被源字符串长度所整除的，因为要求是由子串重复整数倍组成的，然后从起始位置到源字符串长度减去子串长度所得到的字符串必然会等于从以子串长度为索引位置开始的字符串。前者其实是在尾部减去一个子串，而后者则是从开头减去一个子串，相当于前者向右平移一个子串长度就是得到后者的。

##### 9 [Implement strStr()](https://leetcode.com/problems/implement-strstr/)

题目描述如下：

> Implement strStr().
>
> Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

给定两个字符串，求第二个字符串在第一个字符串出现的第一个位置。解法如下：

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lens1 = haystack.size(), lens2 = needle.size();
        int res = haystack.find(needle);
        if(res >= 0){
            while(res < lens1 && res >= 0){
                if(haystack.substr(res, lens2) == needle){
                    return res;
                }else{
                    res = haystack.find(needle, res+1);
                }
            }
        }
        return res;
    }
};
```

上述解法采用了`string`的`find()`和`substr()`两个函数。首先采用`find()`找到符合的第一个位置，然后求取第一个字符串中从得到的位置开始与第二个字符串长度`lens2`同样大小的子串，然后进行比较，如果相同，则返回这个位置，否则就从这个位置开始重新查找第二个字符串的第一个字符出现的位置，重复这个过程，直到循环到第一个字符串末尾。

另一个解法如下：

```c++
class Solution {
public: 
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (!n) return 0;
        for (int i = 0; i < m - n + 1; i++) {
            int j = 0;
            for (; j < n; j++)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == n) return i;
        }
        return -1;
    }
};
```

这个解法就必要直接了，外循环的长度是两个字符串长度相减，然后内部循环就是从第一个字符串的第一个位置开始，然后循环`n`次，`n`是第二个字符串长度，依次比较这`n`个长度的字符，如果都相同，就返回`i`，否则就`i++`,再次重复这个过程，直到达到循环结束条件，这是一个暴力搜索的过程。

##### 10 [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)

题目描述如下：

> Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
>
> For example:
>
> Given `"aacecaaa"`, return `"aaacecaaa"`.
>
> Given `"abcd"`, return `"dcbabcd"`.

这是一道困难级别的题目，题目要求给定一个字符串，通过在字符串前面或末尾添加字符来获取一个最短的回文。参考的解法如下：

```c++
class Solution {
public:
    string shortestPalindrome(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size(),l;
        for(l=n;l>=0;l--)
        {
            if(s.substr(0,l)==s2.substr(n-l))
                break;
        }
        return s2.substr(0,n-l)+s;
    }
};
```

上述解法是首先反转字符串，然后从最大长度开始检查原字符串和反转后的字符串是否相等，如果相等，就将反转后的字符串，即`s2`的前面`n-l`个字符添加到原字符串`s`前面。

一个更快的解法如下：

```c++
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }
        
        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};
```

这个解法是利用到了KMP的思路。参考自这篇[文章](https://discuss.leetcode.com/topic/14526/c-8-ms-kmp-based-o-n-time-o-n-memory-solution)。

##### 11 [Is Subsequence](https://leetcode.com/problems/is-subsequence/)

题目描述如下：

> Given a string **s** and a string **t**, check if **s** is subsequence of **t**.
>
> You may assume that there is only lower case English letters in both **s** and **t**. **t** is potentially a very long (length ~= 500,000) string, and **s** is a short string (<=100).
>
> A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).
>
> **Example 1:**
> **s** = `"abc"`, **t** = `"ahbgdc"`
>
> Return `true`.
>
> **Example 2:**
> **s** = `"axc"`, **t** = `"ahbgdc"`
>
> Return `false`.

给定两个字符串`s,t`，判断`s`是否是`t`的子串，子串要求在原来主串中的排列顺序也是一样的。解法如下：

```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length(), sIdx = 0, tLen = t.length();
        for (int i=0; i<tLen && sIdx<sLen; i++) 
            if (t[i]==s[sIdx]) sIdx++;
        return sIdx==sLen;
    }
};
```

上述解法是循环主串`t`，并且记录字符串`s`得到的索引值`sIdx`，如果是符合要求的子串，那么最终`sIdx`会等于子串的长度，否则就不是。

