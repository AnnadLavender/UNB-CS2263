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

double getXPoint2D(Point2D* pThis)
{
  return pThis->x;
}

double getYPoint2D(Point2D* pThis)
{
  return pThis->y;
}

void freePoint2D(Point2D* pThis)
{
  free(pThis);
}

int main(int argc, char **argv[])
{
  Point2D* pointA;
  double xA,yA;

  printf("Input x and y of point A: ");
  int iErrA = scanf("%lf%lf",&xA,&yA);
  while(iErrA != 2)
  {
    printf("Input x and y of point A again: ");
    iErrA = scanf("%lf%lf",&xA,&yA);
  }
  pointA = createPoint2D(xA, yA);

  printf("Point A: (%.2lf,%.2lf)\n",getXPoint2D(pointA), getYPoint2D(pointA));

  freePoint2D(pointA);
  return EXIT_SUCCESS;
}
