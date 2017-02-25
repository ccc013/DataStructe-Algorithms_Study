## AlgorithmsPractise--Search

------

#### 1. [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)

题目描述如下：

> Write an efficient algorithm that searches for a value in an *m* x *n* matrix. This matrix has the following properties:
>
> - Integers in each row are sorted in ascending from left to right.
> - Integers in each column are sorted in ascending from top to bottom.
>
> For example,
>
> Consider the following matrix:
>
> ```
> [
>   [1,   4,  7, 11, 15],
>   [2,   5,  8, 12, 19],
>   [3,   6,  9, 16, 22],
>   [10, 13, 14, 17, 24],
>   [18, 21, 23, 26, 30]
> ]
>
> ```
>
> Given **target** = `5`, return `true`.
>
> Given **target** = `20`, return `false`.

这是给定一个二维数组，数组中的元素是有序的，从左到右是递增，从上到下也是递增，需要查找数组中是否存在给定的一个数字。解法如下：

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        int rows = matrix.size();
        if(rows <= 0)
            return found;
        int columns = matrix[0].size();
        if(rows > 0 && columns > 0){
            int r = 0, col = columns - 1;
            while(r < rows && col >= 0){
                if(matrix[r][col] == target){
                    found = true;
                    break;
                }else if(matrix[r][col] > target){
                    col--;
                }else{
                    r++;
                }
            }
        }
        return found;
    }
};
```

上述解法，选择初始搜索地方是数组的右上角，因为这个地方的数值在跟给定数值比较后，可以排除一行或者一列的元素，同样效果的初始地点是左下角。

跟这个题目类似的还有[Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)，要求也是非常相似，解法也可以继续用上述解法。

