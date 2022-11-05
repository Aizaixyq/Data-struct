#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct List {
    int val;
    List *next;
    List() : val(0), next(nullptr) {}
    List(int val) : val(val), next(nullptr) {}
    List(int val, List *next) : val(val), next(next) {}
};

List *reversed(List *node) {
    if (node == nullptr) {
        return node;
    }
    vector<List *> re;
    while (node) {
        re.emplace_back(node);
        node = node->next;
    }
    int n = re.size() - 1;
    for (int i = n; i > 0; --i) {
        re[i]->next = re[i - 1];
    }
    re[0]->next = nullptr;
    return re[n];
}

List *head_insertion() {
    cout << "**Head_insertion**\nEnter length:";
    int len;
    cin >> len;
    List *head = new List(len);
    for (int i = 0; i < len; ++i) {
        cout << "Please enter number:";
        int val;
        cin >> val;
        List *p = new List(val, head->next);
        head->next = p;
    }
    head->next = reversed(head->next);
    return head;
}

List *end_insertion(List *node, int len) {
    if (len <= 0) {
        return nullptr;
    }
    cout << "Please enter number:";
    int val;
    cin >> val;
    List *n = new List(val);
    node->next = n;
    end_insertion(n, len - 1);
    return node;
}

void List_input(List *node) {
    while (node && node->next) {
        cout << node->val << "->";
        node = node->next;
    }

    if (node) {
        cout << node->val << endl;
    } else {
        cout << "Empty LinkedList" << endl;
    }
}

int main() {
    cout << "Choose a method:" << endl;
    cout << "(1)head_insertion\n(2)end_insertion\nEnter[1 or 2]:";
    int q;
    cin >> q;
    if (q == 1) {
        List *head = head_insertion();
        cout << "Enter over" << endl << endl; //头插法
        List_input(head);
    }
    if (q == 2) {
        cout << "**End_insertion**\nEnter length:";
        int len;
        cin >> len;
        List *head1 = new List(len);
        head1 = end_insertion(head1, len);
        cout << "Enter over" << endl; //尾插法
        List_input(head1);
    }
    return 0;
}