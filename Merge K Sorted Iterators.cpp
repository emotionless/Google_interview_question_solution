/*
Link: https://leetcode.com/discuss/interview-question/345744

Given a list of k sorted iterators. Implement MergingIterator to merge them. If you are not familiar with Iterators check similar questions.

class MergingIterator implements Iterator<Integer> {
	public MergingIterator(List<Iterator<Integer>> iterators) {
	}

	public boolean hasNext() {
	}

	public Integer next() {
	}
}
Example:

MergingIterator itr = new MergingIterator([[2, 5, 9], [], [4, 10]]);
itr.hasNext(); // true
itr.next(); // 2
itr.next(); // 4
itr.next(); // 5
itr.next(); // 9
itr.next(); // 10
itr.hasNext(); // false
itr.next(); // error


Related problems: https://leetcode.com/problems/merge-k-sorted-lists
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

struct Compare {
	bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
	}
};

class MergingListNode {
public:
    MergingListNode(vector<ListNode*> lists) {
        for (auto it : lists) {
			if (it != nullptr) {
				pq.push(it);
			}
        }
    }

    bool hasNext() {
		if (pq.empty()) return false;
		return true;
    }

    int next() {
		ListNode *top = pq.top();
		pq.pop();
		if (top -> next != nullptr)
			pq.push(top -> next);
		return top -> val;
    }
private:
	priority_queue<ListNode*, vector<ListNode*>, Compare>pq;
};


int main() {
	ListNode *root1 = new ListNode(2);
	ListNode *child1 = new ListNode(5);
	child1 -> next = new ListNode(9);
	root1 -> next = child1;

	ListNode *root2 = new ListNode(4);
	root2 -> next = new ListNode(10);

    MergingListNode mln = MergingListNode({root1, nullptr, root2});

    cout << mln.hasNext() << endl;
    cout << mln.next() << endl;
    cout << mln.next() << endl;
    cout << mln.next() << endl;
    cout << mln.next() << endl;
    cout << mln.next() << endl;
    cout << mln.hasNext() << endl;


    return 0;
}
