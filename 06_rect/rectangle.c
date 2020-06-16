#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b)
    {
    return a;
    }
  else
    {
    return b;
    }
}
int max (int a, int b) {
  if (a > b)
    {
      return a;
    }
  else
    {
      return b;
    }
}

//Declare your rectangle structure here!
typedef struct
{
  int x, y, width, height;
}rectangle;

rectangle canonicalize(rectangle r) {
    if (r.width < 0 &&  r.height < 0)
      {
	//RETURNS (X,Y) AND NEW HEIGHT AND NEW WIDTH
       	r.width =  -1 * r.width; // WIDTH = POSITIVE	
	r.height = -1 * r.height;// HEIGHT = POSITIVE
        r.x = r.x - r.width; // X + (-W) = BOTTOM)
	r.y = r.y - r.height; // Y + (-Y) = BOTTOM 
      }
    else if (r.width < 0)
      {
	// REURNS (X,Y) AND NEW WIDTH (0, 7) (-4, 2)
        r.width = -1 * r.width;;// WIDTH = POSITIVE 
        r.x = r.x - r.width; // X + (-W) = BOTTOM -4;
	
      }
    else if (r.height < 0)
      {
	r.height =  -1* r.height; // MAKES HEIGHT POSITIVE
	r.y = r.y - r.height;
        
      }
  return r;
}
rectangle intersection(rectangle r1, rectangle r2) {
    r1 =  canonicalize(r1);
    r2 =  canonicalize(r2);
    rectangle R;
  if (r1.x + r1.width < r2.x || r1.y + r1.height < r2.y || r2.y + r2.height <r1.y || r2.x+ r2.width < r1.x)
    {
      R.height = 0;
      R.width = 0;
      return R;
    }
    else
      {
	R.x = max(r1.x, r2.x);
	R.y = max(r1.y, r2.y);
	if (r1.width == r2.width || r1.height == r2.height)
	  {
	    R.width = min(r1.width, r2.width)- r1.x;
	    R.height = min (r1.height, r2.height);
	    return R;
	  }
	else
	  {
	    R.width = min(r1.width,  r2.width);
	    R.height = min(r1.height,  r2.height);
	    return R;
          }
  //x canonicalize (R);
}

//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                            r.x + r.width, r.y+r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;              
  r1.y = 3;                     
  r1.width = 5;                
  r1.height = 6;              
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;               
  r2.y = 5;                  
  r2.width = -5;             
  r2.height = -7;            
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;
}