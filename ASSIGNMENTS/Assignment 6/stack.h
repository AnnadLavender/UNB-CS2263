#ifndef STACK_H
#define STACK_H

pPtLink createPointLink(Point2D* point);
void freePointLink(pPtLink pPointLink);
PointList* mallocPointList();
int push(Point2D* newPoint, PointList* pointList);
int pop(PointList* pointList);
void peek(PointList* pointList);
void print(PointList* pointList);
void freePointList(PointList* pointList);

#endif
