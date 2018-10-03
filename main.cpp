#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *node_1 = l1, *node_2 = l2;
        ListNode *head, *last, *node;
        int count = 0;
        while (node_1 && node_2) {
            node = new ListNode(node_1->val + node_2->val);
            if (count == 0) {
                head = node;
            } else {
                last->next = node;
            }
            last=node;
            count++;

            node_1 = node_1->next;
            node_2 = node_2->next;
        }

        node_1 = node_1 ? node_1 : node_2;
        while (node_1) {
            node = new ListNode(node_1->val);
            if (count == 0) {
                head = node;
            } else {
                last->next = node;
            }
            last=node;

            count++;
            node_1 = node_1->next;
        }
        node = head;
        int value = 0, cValue = 0;
        while (node) {
            node->val += cValue;
            cValue = node->val / 10;
            node->val = node->val % 10;

            last = node;
            node = node->next;
        }
        if (cValue != 0) {
            last->next = new ListNode(cValue);
        }
        return head;
    }
};

int main() {
    int nums_1[4] = {1, 3, 5, 7}, nums_2[5] = {0};
    ListNode *l1 = new ListNode(nums_1[0]), *last = l1;

    for (int i = 1; i < 4; i++) {
        last->next = new ListNode(nums_1[i]);
        last = last->next;
    }

    ListNode *l2 = new ListNode(nums_2[0]);

    last = l2;

    for (int i = 1; i < 2; i++) {
        last->next = new ListNode(nums_2[i]);
        last = last->next;
    }

    Solution s;
    auto result = s.addTwoNumbers(l1, l2);
    while (result) {
        cout << result->val << ",";
        result = result->next;
    }
//    l1->next = new ListNode(2)
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}