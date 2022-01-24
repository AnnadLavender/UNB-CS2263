#ifndef POINT2D_H
#define POINT2D_H

typedef struct point2D
{
  double x;
  double y;
}
Point2D;

typedef struct pt2link
{
  Point2D* payload;
  struct pt2link* next;
}
PtLink, *pPtLink;

typedef struct pointList
{
  pPtLink head;
  pPtLink tail;
  pPtLink iterator; /* not implemented */
  int nLinks;
}PointList;

Point2D* mallocPoint2D();
Point2D* createPoint2D(double x, double y);
void freePoint2D(Point2D* pThis);
double getXPoint2D(Point2D* pThis);
double getYPoint2D(Point2D* pThis);
void setPoint2D(Point2D* pPt, double x, double y);
double getDistancePoint2D(Point2D* pThis, Point2D* pThat);

#endif
