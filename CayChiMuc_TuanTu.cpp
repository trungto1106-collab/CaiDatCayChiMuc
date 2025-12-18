#include <iostream>
#include <string>
using namespace std;
#define MAXLENGTH 100
#define NIL -1
typedef string DataType;
typedef int Node;
typedef struct {
    DataType Data[MAXLENGTH];
    int MaxNode;
} Tree;
void InitTree(Tree& T) {
    T.MaxNode = 0;
}
bool EmptyTree(Tree T) {
    return T.MaxNode == 0;
}
Node Root(Tree T) {
    if (!EmptyTree(T))
        return 0;
    return NIL;
}
Node LeftChild(Node p, Tree T) {
    Node lc = 2 * (p + 1) - 1;
    if (lc < T.MaxNode)
        return lc;
    return NIL;
}
Node RightChild(Node p, Tree T) {
    Node rc = 2 * (p + 1);
    if (rc < T.MaxNode)
        return rc;
    return NIL;
}
void AddNode(Tree& T, DataType x) {
    if (T.MaxNode >= MAXLENGTH) return;
    T.Data[T.MaxNode++] = x;
}
void PreOrder(Tree T, Node p) {
    if (p == NIL) return;
    cout << T.Data[p] << " ";
    PreOrder(T, LeftChild(p, T));
    PreOrder(T, RightChild(p, T));
}
void InOrder(Tree T, Node p) {
    if (p == NIL) return;
    InOrder(T, LeftChild(p, T));
    cout << T.Data[p] << " ";
    InOrder(T, RightChild(p, T));
}
void PostOrder(Tree T, Node p) {
    if (p == NIL) return;
    PostOrder(T, LeftChild(p, T));
    PostOrder(T, RightChild(p, T));
    cout << T.Data[p] << " ";
}
int main() {
    Tree T;
    InitTree(T);
    AddNode(T, "A");
    AddNode(T, "A.1");
    AddNode(T, "A.2");
    AddNode(T, "A1.1");
    AddNode(T, "A1.2");
    AddNode(T, "A2.1");
    AddNode(T, "A2.2");
    cout << "Duyet truoc: ";
    PreOrder(T, Root(T));
    cout << "\nDuyet giua: ";
    InOrder(T, Root(T));
    cout << "\nDuyet sau: ";
    PostOrder(T, Root(T));
    return 0;
}