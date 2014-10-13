// This is the .h file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own, as well as on the members.
// TODO: remove this comment header

#ifndef TOUR_H
#define TOUR_H

#include "Node.h"
#include "Point.h"

class Tour {
public:

    Tour();
    void Tour2(Point p, Point p1, Point p2, Point p3);
    ~Tour();
    void show();
    void draw(QGraphicsScene* scene);
    int size();
    double distance();
    void insertNearest(Point p);
    void insertSmallest(Point p);

private:
    void insert(int index, Point point);
    void deleteTempNode(int index);
    Node* m_front = nullptr;   // pointer to front node in Tourlist;  nullptr if empty
};

#endif // TOUR_H
