#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"
#include "queue.h"
// Other supported functions
pPtLink createPointLink(Point2D* point)
{
  pPtLink pPointLink = (pPtLink) malloc(sizeof(PtLink));
  if(pPointLink == (pPtLink)NULL)
  {
    return pPointLink;
  }
  pPointLink->payload = point;
  return pPointLink;
}

void freePointLink(pPtLink pPointLink)
{
    free(pPointLink);
    return;
}

// queue creation
PointList* mallocPointList()
{
  PointList* pointListThis = (PointList*) malloc(sizeof(PointList));
  if(pointListThis == (PointList*)NULL )
  {
    return pointListThis;
  }
  pointListThis->head = (pPtLink)NULL;
  pointListThis->tail = (pPtLink)NULL;
  pointListThis->iterator = (pPtLink)NULL;
  pointListThis->nLinks = 0;
  return pointListThis;
}

// enqueue
int enqueue(Point2D* newPoint, PointList* pointList)
{
  pPtLink pPointLink = createPointLink(newPoint);
  if(pPointLink == (pPtLink)NULL)
  {
    return 1;
  }
  if(pointList->nLinks)
  {
    pointList->tail->next = pPointLink;
  }
  else
  {
    pointList->head = pPointLink;
  }
  pointList->tail = pPointLink;
  pointList->nLinks++;
  return 0; //success
}
// dequeuing
int dequeue(PointList* pointList)
{
  if(!pointList->nLinks)
  {
    return EOF;
  }
  pPtLink temp = pointList->head;
  Point2D* tempPoint = temp->payload;
  pointList->head = temp->next;
  printf("Dequeued point: (%.1lf, %.1lf)\n", getXPoint2D(tempPoint), getYPoint2D(tempPoint));
  free(temp);
  pointList->nLinks--;
  return 0;//success
}

// peek (look at the next value to be dequeued)
void peek(PointList* pointList)
{
  if(pointList->head == (pPtLink)NULL)
  {
    printf("The list is empty, unable to peek the point\n");
  }
  else
  {
    Point2D* point = pointList->head->payload;
    printf("Peeked point: (%.1lf, %.1lf)\n", getXPoint2D(point), getYPoint2D(point));
  }
}

// reporting the queue contents
void print(PointList* pointList)
{
  pPtLink current = pointList->head;
  int i = 0;
  if(i == pointList->nLinks)
  {
    printf("The list is empty\n");
    return;
  }

  while(i < pointList->nLinks)
  {
    printf("Point %d: (%.1lf, %.1lf)\n", i, getXPoint2D(current->payload), getYPoint2D(current->payload));
    printf("Address:\n");
    printf("- PtLink: %p\n", current);
    printf("- payload: %p\n", current->payload);
    printf("- next: %p\n\n", current->next);
    i++;
    current = current->next;
  }
}

// and queue destruction
void freePointList(PointList* pointList)
{
  pPtLink current = pointList->head;
  while(pointList->head != (pPtLink)NULL)
  {
    current = pointList->head->next;
    freePointLink(pointList->head);
    pointList->head = current;
  }
  free(pointList);
  return;
}
