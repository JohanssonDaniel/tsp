/*
 * TDDD86 TSP
 * This client program uses your Tour class and contains the 'main'
 * function to open the input file and set up the program's primitive GUI.
 */

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Point.h"
#include "Tour.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    string filename = "tsp10.txt";
    ifstream input;
    input.open(filename);

    // get dimensions
    int width;
    int height;
    input >> width;
    input >> height;

    // setup graphical window
    QGraphicsView *view = new QGraphicsView();
    QGraphicsScene *scene = new QGraphicsScene();
    view->setScene(scene);
    view->scale(1, -1); //screen y-axis is inverted
    view->setSceneRect(0, 0, width, height);
    view->show();

    // run insertion heuristic
    /*Point p(100,100);
    Point p1(500,100);
    Point p2(500,500);
    Point p3(100,500);*/
    Tour tour;


    /*Tour tour(p, p1, p2, p3);
    tour.show();
    cout << tour.size() << endl;
    cout << "Distance: " << tour.distance() << endl;*/

    double x;
    double y;
    while (input >> x >> y) {
        Point p(x, y);
        tour.insertNearest(p);
        //uncomment the 4 lines below to animate
        //tour.draw(scene);
        //std::chrono::milliseconds dura(500);
        //std::this_thread::sleep_for(dura);
        //a.processEvents();
    }/*
    input.close();
    Point p(110, 225);
    Point p1(161, 280);
    Point p2(157, 443);
    Point p3(283, 379);
    tour.insertNearest(p);
    tour.insertNearest(p1);
    tour.insertNearest(p2);
    tour.insertNearest(p3);
*/
    // print tour to standard output
    cout << "Tour distance: " << std::fixed << std::setprecision(4)
         << std::showpoint << tour.distance() << endl;
    cout << "Number of points: " << tour.size() << endl;
    tour.show();

    // draw tour
    tour.draw(scene);
    return a.exec(); // start Qt event loop
}
