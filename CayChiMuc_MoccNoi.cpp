#include <iostream>
#include <string>
using namespace std;
typedef string DataType;
struct Node {
    DataType Data;
    Node* Left;
    Node* Right;
};
typedef Node* Tree;
void InitTree(Tree &T) {
    T = NULL;
}
bool EmptyTree(Tree T) {
    return T == NULL;
}
Node* CreateNode(DataType x) {
    Node* p = new Node;
    p->Data = x;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}
void AddLeft(Node* p, DataType x) {
    if (p != NULL && p->Left == NULL)
        p->Left = CreateNode(x);
}
void AddRight(Node* p, DataType x) {
    if (p != NULL && p->Right == NULL)
        p->Right = CreateNode(x);
}
void PreOrder(Tree T) {
    if (T == NULL) return;
    cout << T->Data << " ";
    PreOrder(T->Left);
    PreOrder(T->Right);
}
void InOrder(Tree T) {
    if (T == NULL) return;
    InOrder(T->Left);
    cout << T->Data << " ";
    InOrder(T->Right);
}
void PostOrder(Tree T) {
    if (T == NULL) return;
    PostOrder(T->Left);
    PostOrder(T->Right);
    cout << T->Data << " ";
}
int main() {
    Tree T;
    InitTree(T);
    T = CreateNode("A");
    AddLeft(T, "A.1");
    AddRight(T, "A.2");
    AddLeft(T->Left, "A1.1");
    AddRight(T->Left, "A1.2");
    AddLeft(T->Right, "A2.1");
    AddRight(T->Right, "A2.2");
    cout << "Duyet truoc (Preorder): ";
    PreOrder(T);
    cout << "\nDuyet giua (Inorder): ";
    InOrder(T);
    cout << "\nDuyet sau (Postorder): ";
    PostOrder(T);
    return 0;
}

