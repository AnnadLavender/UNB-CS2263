#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point2D.h"

Point2D* mallocPoint2D()
{
  Point2D* pPtThis;
  pPtThis = (Point2D*) malloc(sizeof(Point2D));
  return pPtThis;
}

Point2D* createPoint2D(float x, float y)
{
  Point2D* pPtThis;
  pPtThis = mallocPoint2D();
  if(pPtThis == NULL)
  {
    return pPtThis;
  }
  pPtThis->x = x;
  pPtThis->y = y;
  return pPtThis;
}

void freePoint2D(Point2D* pThis)
{
  free(pThis);
}

double getXPoint2D(Point2D* pThis)
{
  return pThis->x;
}

double getYPoint2D(Point2D* pThis)
{
  return pThis->y;
}

void setPoint2D(Point2D* pPt, double x, double y)
{
  pPt->x = x;
  pPt->y = y;
  return;
}

double getDistancePoint2D(Point2D* pThis, Point2D* pThat)
{
  return sqrt(pow((getXPoint2D(pThis) - getXPoint2D(pThat)), 2)
   + pow((getYPoint2D(pThis) - getYPoint2D(pThat)), 2));
}
