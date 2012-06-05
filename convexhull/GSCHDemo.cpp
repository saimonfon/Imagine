/*
 **************************************************************************
 * Convex Hull (Graham Scan) Demo                                         *
 * By Arash Partow - 2001                                                 *
 * URL: http://www.partow.net                                             *
 *                                                                        *
 * Copyright Notice:                                                      *
 * Free use of this library is permitted under the guidelines and         *
 * in accordance with the most current version of the Common Public       *
 * License.                                                               *
 * http://www.opensource.org/licenses/cpl.php                             *
 *                                                                        *
 **************************************************************************
*/


#include <time.h>
#include <vector>

#include "ConvexHull.h"
#include "GrahamScanConvexHull.h"
#include "ConvexHullEPSWriter.h"

void gen_rand_points(double x1, double y1, double x2, double y2, std::vector<point2d>& point, unsigned int count);


int main1(int argc, char* argv[])
{
   std::vector<point2d> point;
   std::vector<point2d> convex_hull;

   char* file_name = "convexhull.eps";

   if (argc == 7)
   {
     /*
        usage:
        ./GSCHDemo 50 50 550 550 300 convexhull.eps
     */
     double x1 = atoi(argv[1]);
     double y1 = atoi(argv[2]);
     double x2 = atoi(argv[3]);
     double y2 = atoi(argv[4]);
     unsigned pntcnt    = atoi(argv[5]);
              file_name = argv[6];

     gen_rand_points(x1,y1,x2,y2,point,pntcnt);


   }
   else
     gen_rand_points(50,50,500,500,point,1000);

   /*
   Alternate method of instantiation:
   ConvexHull* hull_generator = new GrahamScanConvexHull();
   (*hull_generator)(point, convex_hull);
   delete hull_generator;
   */
   GrahamScanConvexHull()(point, convex_hull);

   ConvexHullEPSWriter()(file_name,point,convex_hull);

   return true;
}


void gen_rand_points(double x1, double y1, double x2, double y2, std::vector<point2d>& point, unsigned int count)
{
   point.clear();
   point.reserve(count);

   double dx = fabs(x2 - x1) - 1.0;
   double dy = fabs(y2 - y1) - 1.0;

   srand (static_cast<unsigned int>(time(NULL)));

   for (unsigned int i = 0; i < count; i++)
   {
      point2d tmp_pnt;

      tmp_pnt.x = x1 + (dx * rand() / RAND_MAX) + (rand() / RAND_MAX);
      tmp_pnt.y = y1 + (dy * rand() / RAND_MAX) + (rand() / RAND_MAX);

      point.push_back(tmp_pnt);
   }
}

