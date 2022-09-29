#include<iostream>
using std::cout;
using std::cin;
using std::endl;

struct List{
    int val;
    List *next;
    List(): val(0), next(nullptr) {}
    List(int val): val(val), next(nullptr){}
    List(int val, List *next): val(val), next(next){}
};
using Node=List;

List* end_insertion(List* node, int len){
    if(len <= 0){
        return nullptr;
    }
    cout<<"Please enter number:";
    int val;
    cin>>val;
    List* n = new List(val);
    node->next = n;
    end_insertion(n, len - 1);
    return node;
}

void List_input(List *node){
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

int delete_key(Node *&L, int key){
    Node *r = new Node;
    Node *a = nullptr;
    r = L;
    int sum = 0;
    while(r){
        Node *q = r;
        if(r->val == key){
            sum++;
            if(!a){
                L = L->next;
                r = r->next;
            }
            else{
                a->next = r->next;
                r = r->next;
            }
            delete q;
            continue;
        }
        a = r;
        r = r->next;
    }
    return sum;
}

int main(){
    cout<<"**End_insertion**\nEnter length:";
    int len;
    cin>>len;

    List* head = new List(len);
    head = end_insertion(head, len);

    cout<<"Enter over"<<endl;//尾插法
    List_input(head);//输出链表

    head->val -= delete_key(head->next, 2);//删除并修改长度
    List_input(head);//输出链表
}