/*

Problem link: https://leetcode.com/problems/first-unique-number/

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.


Example 1:

Input:
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output:
[null,2,null,2,null,3,null,-1]
Explanation:
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1


*/

#include <thread>         // std::thread
#include <mutex>          // std::mutex

class FirstUnique {
public:

    FirstUnique(vector<int>& nums) {
        for(auto x : nums) {
            counter[x]++;
            q.push(x);
        }
    }

    int showFirstUnique() {
        mtx.lock();
        int ans = -1;
        while(!q.empty()) {
            int cur = q.front();
            if (counter[cur] == 1) {
                ans = cur;
                break;
            }
            q.pop();
        }
        mtx.unlock();
        return ans;
    }

    void add(int value) {
        q.push(value);
        counter[value]++;
    }

private:
    unordered_map<int, int> counter;
    queue<int> q;
    mutex mtx;

};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
