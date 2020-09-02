#include <iostream>
#include "LinkList/LinkList.h"

int main() {
    /**
     * craete
     */
    LinkList* linkList = new LinkList(2);

    /**
     * traverse
     */
    linkList->init();
    linkList->output();

    /**
     * insert
     */
    Node* node = new Node;
    cout << "请输入新节点的信息: ";
    cin >> node;
    linkList->insert_before(1, *node);
    linkList->insert_before(1, *node);

    /**
     * delete
     */
    Data data(2000, 1);
    linkList->remove(data);

    linkList->output();

    /**
     * destroy
     */
    delete linkList;

    return 0;
}
