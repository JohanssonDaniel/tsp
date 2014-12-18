/* A class representing a circular linked list of Node.
 * Every Node has a Point struct and a pointer to the next Node.
 * danjo732, piehe154
 */

#ifndef TOUR_H
#define TOUR_H

#include "Node.h"
#include "Point.h"

class Tour {
public:
    /**
     * Constructor: Tour
     * Usage: Tour tour;
     * ---------------------------------------
     * Creates a new empty tour, a Node with a null pointer
     */
    Tour();
    /*
     * Destructor: ~Tour();
     * Usage: delete tour;
     */
    ~Tour();
    /*Deletes the Nodes from the Tour
     */
    void clear();
    /*Prints the Points in the list to the console.
     */
    void show();
    /* Draws line between the Points on the canvas.
     */
    void draw(QGraphicsScene* scene);
    /* Returns the size of the list.
     */
    int size();
    /* Returns the distance between to given points.
     */
    double distance();
    /* Inserts a point according to the "Nearest neighbour" heuristic into the list.
     */
    void insertNearest(Point p);
    /* Inserts a point according to the "Smallest increase" heuristic into the list.
     */
    void insertSmallest(Point p);

    void edgeLocalExchangeSearch();

private:
    /* Used to insert a new Node with a specified point at the index.
     */
    void insert(int index, Point point);
    /* Insert the point as a new node after the node pointer
     */
    void insertAfter(Node* node, Point point);
    /* Deletes the Node at the specified index
     */
    void deleteTempNode(int index);
    /* Deletes the the node after the specified node
     */
    void deleteAfterNode(Node* node);
    /* Sets the first Node to be a null pointer
     */
    Node* m_front = nullptr;   // pointer to front node in Tourlist;  nullptr if empty
};

#endif // TOUR_H
