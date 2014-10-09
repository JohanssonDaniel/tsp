// This is the .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <iostream>
#include "Tour.h"
#include "Node.h"
#include "Point.h"

Tour::Tour(Point a, Point b, Point c, Point d)
{
    m_front = new Node(a,new Node(b, new Node(c, new Node(d, nullptr))));
    m_front->next->next->next->next = m_front;
}

Tour::~Tour()
{
    // TODO: write this member
}

void Tour::show()
{   if(m_front != nullptr){
        Node* current = m_front;
        while(current->next != m_front){
            cout << current->toString() << endl;
            current = current->next;
        }
        cout << current->toString() << endl;
    }
}

void Tour::draw(QGraphicsScene *scene)
{
    // TODO: write this member
}

int Tour::size()
{
    // TODO: write this member
}

double Tour::distance()
{
    // TODO: write this member
}

void Tour::insertNearest(Point p)
{
    // TODO: write this member
}

void Tour::insertSmallest(Point p)
{
    // TODO: write this member
}
