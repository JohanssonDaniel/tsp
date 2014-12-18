/*
 * Tour.cpp implements the Tour class behavior declared in Tour.h
 * Borrows the insert(), delete() and clear() functions from the 9:th lecture code
 *
 * danjo732, piehe154
 * The task was to implement the functions and their behavior, specified in the lab instruction
 * Is mainly focusing on adding Points to the Tour according to the Nearest neighbour or Smallest increase heuristic
 */

#include <iostream>
#include "Tour.h"
#include "Node.h"
#include "Point.h"

Tour::Tour()
{
}

Tour::~Tour()
{
    clear();
}
/*
 * Clears the Tour by getting the next Node and deleting it.
 * Loops until it has reached the front
 */
void Tour::clear() {
    Node* current = m_front;
    if(m_front != nullptr){
        do{
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        while(current != m_front);
    }
    m_front = nullptr;
}
/* Prints out each Nodes Point to the console by looping through the list and calling the Points ->toString() method
 * Stops looping when current == m_front.
 */
void Tour::show()
{
    if(m_front != nullptr){
        Node* current = m_front;
        do{
            cout << current->toString() << endl;
            current = current->next;
        }while(current != m_front);
    }
}
/* Draws line between the current and current->next point by calling the point.drawTo() method.
 * Stops looping when current == m_front.
 */
void Tour::draw(QGraphicsScene *scene){
    if(m_front != nullptr){
        Node* current = m_front;
        do{
            current->point.drawTo(current->next->point, scene);
            current = current->next;
        }while(current != m_front);
    }
}
/* Returns the size of the Tour.
 * Loops through the list and increasing the index until current == m_front.
 */
int Tour::size()
{   int tourSize = 0;
    if(m_front != nullptr){
        Node* current = m_front;
        do{

            tourSize++;
            current = current->next;
        }while (current != m_front);
    }
    return tourSize;
}
/* Returns the total distance between all the line between the points of the list
 * by calling the distanceTo method and adding that distance to tourDistance.
 * Stops looping when current == m_front.
 */
double Tour::distance()
{
    double tourDistance = 0;
    if(m_front != nullptr){
        Node* current = m_front;
        do{

            tourDistance += current->point.distanceTo(current->next->point);

            current = current->next;
        }while(current != m_front);
        return tourDistance;
    }
}

/* Inserts a given point into the Tour according to the "Nearest neighbour" heuristic.
 * Tries the distance between the given point and all the points in the Tour and saves the index of the
 * Point which has the closest distance to the new Point.
 * Calls the insert() function to add the new Point at the saved index.
 * Usage: tour.insertNearest(p);
 */
void Tour::insertNearest(Point p)
{
    double nearestDistance = -1;
    Node* smallestNode = m_front;
    if(m_front == nullptr){                 //If this is the first Node
        m_front = new Node(p, m_front);     //Create a new Node which points to itself and has the Point p as element
        m_front->next = m_front;
    }
    else{
        Node* current = m_front;            //Initialize current as the first Node of the list
        do{
            double tempNearestDistance = p.distanceTo(current->point); //Save the distance between the current and new point
            if(nearestDistance == -1 || tempNearestDistance < nearestDistance){ //Check whether we have updated nearest distance or we have a smaller distance
                nearestDistance = tempNearestDistance;
                smallestNode = current;
            }

            current = current->next;                                            //Point to next Node
        }while(current != m_front);
        insertAfter(smallestNode, p);
    }
}
/* Inserts a given point into the Tour according to the "Smallest increase" heuristic.
 * Inserts the given point with the insert() function, into the Tour and calls the distance() function to check the total distance of the tour.
 * Saves the index where the increase is the smallest and calls the insert() function to add the Point as a Node to the Tour.
 * Usage: tour.insertSmallest(p);
 */
void Tour::insertSmallest(Point p)
{
    double increasedDistance = -1;
    Node* smallestNode = m_front;

    if (m_front == nullptr){                //If this is the first Node
        m_front = new Node(p, m_front);     //Create a new Node which points to itself and has the Point p as element
    }
    else{
        Node* current = m_front;            //Initialize current as the first Node of the list
        do{

            insertAfter(current, p);
            double tempIncreasedDistance = distance();                      //Save the new total distance

            if(increasedDistance == -1 ||tempIncreasedDistance < increasedDistance){ //Check whether we have updated smallest total distance or we have a smaller total distance
                increasedDistance = tempIncreasedDistance;                           //Update increasedDistance
                smallestNode = current;
            }
            deleteAfterNode(current);

            current = current->next;
        }while(current != m_front);

        insertAfter(smallestNode, p);
    }
}

void Tour::edgeLocalExchangeSearch(){
    Node* current = m_front;
    double dist = distance();
    do{
        Node* current2 = current->next;
        Node* current3 = current2->next;
        Node* current4 = current3->next;

        //Efter byten 1-3-2-4
        current->next = current3;
        current3->next = current2;
        current2->next = current4;

        if(distance() > dist){
            //Byt tillbaka till 1-2-3-4
            current->next = current2;
            current2->next = current3;
            current3->next = current4;
        }
        //Välj nästa nod
        current = current->next;
    }while(current != m_front);
}
/*
 * Insert the specified point after the node by setting the nodes next pointer to point at the a new node with the point as value and
 * The previous node next->next pointer as next pointer
 */
void Tour::insertAfter(Node* node, Point point){

    if(node->next == nullptr){
        node->next = new Node(point, m_front);
    }
    else{
        node->next = new Node(point, node->next);
    }

}

void Tour::deleteAfterNode(Node *node){
    node->next = node->next->next;
}

