#ifndef QUEUE_H
#define QUEUE_H
#include "Point2D.h"

pPtLink createPointLink(Point2D* point);
void freePointLink(pPtLink pPointLink);
PointList* mallocPointList();
int enqueue(Point2D* newPoint, PointList* pointList);
int dequeue(PointList* pointList);
void peek(PointList* pointList);
void print(PointList* pointList);
void freePointList(PointList* pointList);

#endif
