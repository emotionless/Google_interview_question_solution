/*
Problem link: https://leetcode.com/problems/guess-the-majority-in-a-hidden-array/

We have an integer array nums, where all the integers in nums are 0 or 1. You will not be given direct access to the array, instead, you will have an API ArrayReader which have the following functions:

int query(int a, int b, int c, int d): where 0 <= a < b < c < d < ArrayReader.length(). The function returns the distribution of the value of the 4 elements and returns:
4 : if the values of the 4 elements are the same (0 or 1).
2 : if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
0 : if two element have a value equal to 0 and two elements have a value equal to 1.
int length(): Returns the size of the array.
You are allowed to call query() 2 * n times at most where n is equal to ArrayReader.length().

Return any index of the most frequent value in nums, in case of tie, return -1.

Follow up: What is the minimum number of calls needed to find the majority element?



Example 1:

Input: nums = [0,0,1,0,1,1,1,1]
Output: 5
Explanation: The following calls to the API
reader.length() // returns 8 because there are 8 elements in the hidden array.
reader.query(0,1,2,3) // returns 2 this is a query that compares the elements nums[0], nums[1], nums[2], nums[3]
// Three elements have a value equal to 0 and one element has value equal to 1 or viceversa.
reader.query(4,5,6,7) // returns 4 because nums[4], nums[5], nums[6], nums[7] have the same value.
we can infer that the most frequent value is found in the last 4 elements.
Index 2, 4, 6, 7 is also a correct answer.
Example 2:

Input: nums = [0,0,1,1,0]
Output: 0
Example 3:

Input: nums = [1,0,1,0,1,0,1,0]
Output: -1


Constraints:

5 <= nums.length <= 10^5
0 <= nums[i] <= 1

*/


// solved by Milon

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:

    int guessMajority(ArrayReader &reader) {
        int n = reader.length();
        int first = reader.query(0, 1, 2, 3);
        int negInd = -1;
        int cnt = 1;
        for (int i = 4; i < n; i++) {
            int res = reader.query(0, 1, 2, i);
            if (first == res)
                cnt++;
            else
                negInd = i;
        }
        int res0124 = reader.query(0, 1, 2, 4);
        if (res0124 == reader.query(1, 2, 3, 4))
            cnt++;
        else
            negInd = 0;

        if (res0124 == reader.query(0, 2, 3, 4))
            cnt++;
        else
            negInd = 1;

        if (res0124 == reader.query(0, 1, 3, 4))
            cnt++;
        else
            negInd = 2;

        if (cnt * 2 == n)
            return -1;
        else if (cnt*2 > n)
            return 3;
        else
            return negInd;
    }
};
