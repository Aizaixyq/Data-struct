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

void delete_key(Node *&L, int key){
    Node *r, *a = new Node;
    //C:Node *r = (Node*)malloc(sizeof(Node));
    r = L;
    while(r){
        if(r->val == key){
            if(!a){
                L = L->next;
            }
            else{
                a->next = r->next;
            }
        }
        a = r;
        r = r->next;
    }
}

int main(){
    cout<<"**End_insertion**\nEnter length:";
    int len;
    cin>>len;

    List* head = new List(len);
    head = end_insertion(head, len);

    cout<<"Enter over"<<endl;//尾插法
    List_input(head);//输出链表

    delete_key(head, 2);//删除
    List_input(head);//输出链表
}