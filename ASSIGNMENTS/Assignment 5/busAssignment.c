#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Strings.h"
#include "Point2D.h"

typedef struct student
{
  Point2D* point;
  String name;
}
Student;

typedef struct line
{
  int size;
  String label;
  Point2D* points[];
}
Line;

void freeLineList(Line* lineList[])
{
  int size = (sizeof(lineList) / sizeof(lineList[0]));
  int i,j;
  for(i = 0; i < size; i++)
  {
    freeString(lineList[i]->label);
    for(j = 0; j < lineList[i]->size; j++)
    {
      freePoint2D(lineList[i]->points[j]);
    }
    free(lineList[i]->points);
    free(lineList[i]);
  }
  free(lineList);
}

Line* fscanfBusRoute(FILE* file, Line* line)
{
  int size;
  fscanf(file,"%d", &size);
  String s = mallocString(50);
  line = malloc(sizeof(Line*) + size*sizeof(Point2D*));
  line->label = mallocString(50);
  line->size = size;
  int j = 0;
  double x,y;
  while(j < line->size)
  {
    fscanf(file,"%lf %lf ",&x,&y);
    line->points[j] = createPoint2D(x,y);
    j++;
  }
  fgets(s,50,file);
  line->label = duplicateString(s);
  freeString(s);
  return line;
}

int main(int argc, char const *argv[])
{
  FILE* studentsFile = stdin;
  FILE* busRouteFile = fopen(argv[1], "r");

  if(studentsFile == (FILE*)NULL)
  {
    fprintf(stderr, "Unable to open file %s\n", stdin);
    return EXIT_FAILURE;
  }
  if(busRouteFile == (FILE*)NULL)
  {
    fprintf(stderr, "Unable to open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  int i = 0,j;
  int numberOfRoutes;
  fscanf(busRouteFile,"%d", &numberOfRoutes);
  Line* lineList[numberOfRoutes];
  String studentName = mallocString(50);
  String nearestRoute = mallocString(60);

  while( i < numberOfRoutes)
  {
    lineList[i] = fscanfBusRoute(busRouteFile,lineList[i]);
    i++;
  }

  double x = 0,y=0;
  double nearestDistance;
  double distance = 0;
  Point2D* nearestLocation = createPoint2D(x,y);
  Point2D* studentLocation = createPoint2D(x,y);
  while(fscanf(studentsFile,"%lf %lf ",&x,&y)==2)
  {
    distance = 0;
    fgets(studentName,50,studentsFile);
    printf("----------------\n%s", studentName);//for each student
    setPoint2D(studentLocation,x,y);
    printf("Location: %.2lf %.2lf\n", getXPoint2D(studentLocation),
    getYPoint2D(studentLocation));
    i=0;
    setPoint2D(nearestLocation, getXPoint2D(studentLocation),
    getYPoint2D(studentLocation));
    nearestDistance = 1000000;
    while(i < numberOfRoutes)//for each route
    {
      j = 0;
      while(j < lineList[i]->size)//for each bus stop
      {
        distance = getDistancePoint2D(studentLocation, lineList[i]->points[j]);
        if(nearestDistance >= distance)
        {
          nearestDistance = distance;
          setPoint2D(nearestLocation, getXPoint2D(lineList[i]->points[j]),
          getYPoint2D(lineList[i]->points[j]));
          nearestRoute = duplicateString(lineList[i]->label);
        }
        j++;
      }
      i++;
    }
    printf("Nearest route: %s",nearestRoute);
    printf("Nearest stop: %.2lf %.2lf\n", getXPoint2D(nearestLocation),
    getYPoint2D(nearestLocation));
  }

  freeString(studentName);
  freeString(nearestRoute);
  freePoint2D(nearestLocation);
  freePoint2D(studentLocation);

  freeLineList(lineList);

  fclose(busRouteFile);
  fclose(studentsFile);
  return 0;
}
