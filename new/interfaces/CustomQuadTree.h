//
// Created by Darshan Shetty on 16-03-2017.
//

#ifndef UNTITLED_CUSTOMQUADTREE_H
#define UNTITLED_CUSTOMQUADTREE_H
#include<iostream>
#include <cstdlib>
#include <queue>
#include "Point.h"

using namespace std;

struct Node	{
    double x;
    double y;
    struct Node* NW;
    struct Node* NE;
    struct Node* SE;
    struct Node* SW;
} ;
struct Node* root=NULL;

struct Node* makeNode(double x, double y)	{
    struct Node* temp = new Node;
    temp->x = x;
    temp->y = y;
    temp->NW = NULL;
    temp->NE = NULL;
    temp->SE = NULL;
    temp->SW = NULL;
    return temp;
}
void deleteNode(Node s)
{
    delete s;
}


class PointQuadtree	{
public:

    //check to see if two Node structs are equal
    bool equalCoordinates(struct Node* temp, struct Node* toBeInserted)	{
        if(temp->x == toBeInserted->x && temp->y == toBeInserted->y)	{
            return true;
        }
        else	{
            return false;
        }
    }

    //return the successive quadrant where toBeInserted will be further inserted
    struct Node* getQuadrant(struct Node* temp, struct Node* toBeInserted)	{
        if(temp->x < toBeInserted->x)	{
            if(temp->y < toBeInserted->y)	{
                return temp->SW;
            }
            else	{
                return temp->NW;
            }
        }

        else if(temp->y < toBeInserted->y)	{
            return temp->SE;
        }
        else	{
            return temp->NE;
        }
    }

    //insert into the final quadrant found
    struct Node* insertPointInFinalQuadrant(struct Node* temp, struct Node* toBeInserted)	{
        if(temp->x < toBeInserted->x)	{
            if(temp->y < toBeInserted->y)	{
                temp->SW = toBeInserted;
            }
            else	{
                temp->NW = toBeInserted;
            }
        }

        else if(temp->y < toBeInserted->y)	{
            temp->SE = toBeInserted;
        }
        else	{
            temp->NE = toBeInserted;
        }
    }

    //insert: @return true for successful search, false for unsuccessful search
    bool insert(struct Node* toBeInserted)	{
        if(root == NULL)	{
            root = toBeInserted;
            return true;
        }

        struct Node *temp = root;
        while(temp != NULL && !equalCoordinates(temp, toBeInserted))	{
            struct Node* quadrant = getQuadrant(temp, toBeInserted);
            if(quadrant == NULL)    {
                insertPointInFinalQuadrant(temp, toBeInserted);
                temp = NULL;
                return true;
            }
            else    {
                temp = quadrant;
            }
        }

        return false;
    }

    bool insert(Point p)	{
        struct Node* temp = makeNode(p.getCoordinates()[0],p.getCoordinates()[1]);
        return insert(temp);
    }

    //insert: @return true for successful search, false for unsuccessful search
    bool insert(double x, double y)	{
        struct Node* temp = makeNode(x,y);
        return insert(temp);
    }

    //searching: @return true for successful search, false for unsuccessful search
    bool search(struct Node* toBeSearched) {
        if(root == NULL)	{
            return false;
        }

        if(equalCoordinates(root, toBeSearched))    {
            return true;
        }

        struct Node *temp = root;
        while(temp != NULL) {
            if(equalCoordinates(temp, toBeSearched))    {
                return true;
            }
            else    {
                temp = getQuadrant(temp, toBeSearched);
            }
        }
        return false;
    }

    //searching: @return true for successful search, false for unsuccessful search
    bool search(double x, double y) {
        struct Node* temp = makeNode(x,y);
        return search(temp);
    }

    bool search(Point p) {
        struct Node* temp = makeNode(p.getCoordinates()[0],p.getCoordinates()[1]);
        return search(temp);
    }

    //function for level order traversal using BFS
    void levelOrderTraversal(struct Node* temp) {
        queue<struct Node*> q;
        if(q.empty())
            q.push(temp);

        while(!q.empty())   {
            struct Node* popped = q.front();
            q.pop();
            cout << "(" << popped->x <<", " << popped->y << ") ";
            if(popped->NW != NULL)
                q.push(popped->NW);
            if(popped->NE != NULL)
                q.push(popped->NE);
            if(popped->SE != NULL)
                q.push(popped->SE);
            if(popped->SW != NULL)
                q.push(popped->SW);
        }
    }
    void destroyTree(Node* root) {
        if(root == NULL) return;
        if(root->NE == NULL && root->NW == NULL && root->SE == NULL && root->SW == NULL) delete root;
        destroyTree(root->NE);
        destroyTree(root->NW);
        destroyTree(root->SE);
        destroyTree(root->SW);
        delete root;
    }
    void deleteTree()
    {
        destroyTree(root);
    }
};
#endif //UNTITLED_CUSTOMQUADTREE_H
