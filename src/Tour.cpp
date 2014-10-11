// This is the .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <iostream>
#include "Tour.h"
#include "Node.h"
#include "Point.h"

Tour::Tour()
{
}

Tour::~Tour()
{
    // TODO: write this member
}


void Tour::Tour2(Point a, Point b, Point c, Point d)
{
    m_front = new Node(a,new Node(b, new Node(c, new Node(d, nullptr))));
    m_front->next->next->next->next = m_front;
}

void Tour::show()
{   bool hasNotLooped = true;
    if(m_front != nullptr){
        Node* current = m_front;
        while(hasNotLooped && current->next != nullptr){
            cout << current->toString() << endl;
            current = current->next;
            if(current == m_front){
                hasNotLooped = false;
            }
        }
    }
}

void Tour::draw(QGraphicsScene *scene)
{   bool hasNotLooped = true;
    if(m_front != nullptr){
        Node* current = m_front;
        while (hasNotLooped && current->next != nullptr){
            current->point.drawTo(current->next->point, scene);
            current = current->next;
            if(current == m_front){
                hasNotLooped = false;
            }
        }
    }
}

int Tour::size()
{   int tourSize = 0;
    bool hasNotLooped = true;
    if(m_front != nullptr){
        Node* current = m_front;
        while (hasNotLooped && current->next != nullptr) {
            tourSize++;
            current = current->next;
            if(current == m_front){
                hasNotLooped = false;
            }
        }
    }
    return tourSize;
}

double Tour::distance()
{
    double tourDistance = 0;
    bool hasNotLooped = true;
    if(m_front != nullptr){
        Node* current = m_front;
        while(hasNotLooped){
            tourDistance += current->point.distanceTo(current->next->point);

            current = current->next;
            if(current == m_front){
                hasNotLooped = false;
            }
        }
    }
    return tourDistance;
}

void Tour::insertNearest(Point p)
{
    double nearestDistance = -1;
    int index = 0;
    int closestIndex = 0;
    bool hasNotLooped = true;
    if(m_front == nullptr){
        m_front = new Node(p, m_front);
    }
    else{
        Node* current = m_front;
        while(hasNotLooped && current != nullptr){
            double tempNearestDistance = p.distanceTo(current->point);
            index++;
            if(nearestDistance == -1){
                closestIndex = index;
                nearestDistance = tempNearestDistance;
            }
            else if(tempNearestDistance < nearestDistance){
                closestIndex = index;
                nearestDistance = tempNearestDistance;
            }
            current = current->next;
            if(current == m_front){
                hasNotLooped = false;
            }
        }
        insert(closestIndex, p);
    }
}

void Tour::insertSmallest(Point p)
{
    double increasedDistance = -1;
    for(int i = 0; i < size(); ++i){

        Tour tempTour = this;
        Node* tempCurrent = tempTour.m_front;

        for(int j; j < i; ++j){
            tempCurrent = tempCurrent->next;
        }

        Node* temp = tempCurrent->next;
        tempCurrent->next = new Node(p, temp);
        double tempIncreasedDistance = tempTour.distance();

        if(increasedDistance = -1){
            increasedDistance = tempIncreasedDistance;
        }
        else if(tempIncreasedDistance < increasedDistance){
            increasedDistance = tempIncreasedDistance;
            this = tempTour;
        }
    }
}

void Tour::insert(int index, Point point){
    if (index == 0) {
        Node* temp = m_front;
        m_front = new Node(point, temp);
    }
    else {
        Node* current = m_front;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        if(index > size()-1){
            current->next = new Node(point, m_front);
        }
        else{
            Node* temp = current->next;
            current->next = new Node(point, temp);
        }
    }
}
