//
//  LinkList.h
//  src
//  
//  Created by double Z on 2020/09/02 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef SRC_LINKLIST_H
#define SRC_LINKLIST_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Data {
    int year;
    int day;

    Data(){}

    Data(int _year, int _day)
        :year(_year), day(_day) {}

    bool operator ==(const Data& data){
        return (this->year == data.year
                && this->day == data.day);
    }
};

struct Node {
    friend istream& operator>>(istream& is, Node* node);
    friend ostream& operator<<(ostream& os, Node* node);

    Data data;
    Node* next;
};

istream& operator >>(istream& is, Node* node){
    is >> node->data.year >> node->data.day;
    return is;
}

ostream& operator <<(ostream& os, Node* node){
    os << "[" << node->data.year << ", " << node->data.day << "] -> ";
    return os;
}

class LinkList {
public:
    Node* head;

    LinkList(){
        create(0);
    }

    LinkList(int size){
        create(size);
    }

    ~LinkList(){
        Node* save = NULL;
        while(head){
            save = head->next;
            free(head);
            head = save;
        }
    }

    void init(){
        for(Node* move = head->next; move != NULL; move = move->next){
            cout << "请输入节点信息: ";
            cin >> move;
        }
    }

    void output(){
        for(Node* move = head->next; move != NULL; move = move->next){
            cout << move;
        }
        cout << "[^]" << endl;
    }

    void insert_after(int index, const Node& node){
        int counter = 0;
        for(Node* move = head->next; move != NULL; move = move->next){
            if(counter == index){
                Node* fresh = static_cast<Node*>(malloc(sizeof(Node*)));
                fresh->data = node.data;
                fresh->next = move->next;
                move->next = fresh;

                break;
            }
            counter++;
        }
    }

    void insert_before(int index, const Node& node){
        int counter = 0;
        for(Node* move = head; move->next != NULL; move = move->next){
            if(counter == index){
                Node* fresh = static_cast<Node*>(malloc(sizeof(Node*)));
                fresh->data = node.data;
                fresh->next = move->next;
                move->next = fresh;

                break;
            }
            counter++;
        }
    }

    void remove(const Data& data){
        for(Node* move = head; move->next != NULL; move = move->next){
            if(move->next->data == data){
                Node* save = move->next;
                move->next = move->next->next;
                free(save);
                save = NULL;
            }
        }
    }

private:
    void create(int size){
        head = (Node*)malloc(sizeof(Node*));
        head->next = NULL;

        Node* move = head;
        Node* fresh = NULL;

        while(size--){
            fresh = (Node*)malloc(sizeof(Node*));
            fresh->next = NULL;
            move->next = fresh;
            move = move->next;
        }
    }
};

void testLinkList(){
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
}

#endif //SRC_LINKLIST_H
