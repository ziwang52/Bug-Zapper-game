//zi Wang
//Lab 3 out
//bug zappper 


#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
void initDisplay();
int getNoBugs();
int* getXCoords(int no_bugs);
int* getYCoords(int no_bugs);
int* displayObjects(int* x_coords, int* y_coords, int no_objects);
// add *x_coords *y_coords to compare location
int zapBugs(int* x, int* y, int* x_coords, int* y_coords, int* objects, int no_bugs);


int main()
{
  //Variable Declaration/Initialization
  int no_bugs = 0;
  int* x_coords = NULL;
  int* y_coords = NULL;
  int* objects=NULL;
  int*x = NULL;
  int*y= NULL;
  int no_objects = 0;
  char repeat = 'y';


  //Display graphics
  displayGraphics();
  //Initialize random # generator
  srand(time(0));
 
do
 {
   initDisplay();
  no_bugs = getNoBugs();
  //Set x-coord
  x_coords = getXCoords(no_bugs);
  //Set y-coord
  y_coords = getYCoords(no_bugs);
  //Display objects
  no_objects=no_bugs;
  objects=displayObjects(x_coords, y_coords,  no_objects);
  x = new int[no_objects];
  y = new int[no_objects];
 
 // zap bugs
  zapBugs( x, y, x_coords, y_coords,objects, no_bugs);
  delete[] x_coords;
  delete[] y_coords;
  delete[] x;
  delete[] y;
  delete[] objects;

  cout << "Repeat Again? y/n :";
  cin >> repeat;

  //Cleanup memory
  clearGraphics();
  system("cls");
} while (repeat == 'y' || repeat == 'Y');



  return 0;
}

//Implement functions below
void initDisplay()
{
  //Variable declaration/initialization
int rect = 0;
displayPNG("Grass.png", 0, 0);
//draw rect 
rect= drawRect(250,0,200,40);
// display scores and shots
gout<<setColor(0,0,0)<<setPos(285,20)<<"Score: "<<endg;
gout<< setColor(0, 0, 0) <<setPos(363,20)<<"Shots: "<<endg;
  
}

int getNoBugs() 
{  
  //Variable declaration/initialization
  int no_bugs=0;
  do
  {
    //Prompt for # bugs – should be between 5 and 20 inclusive
    cout << "Enter # of Bugs to Display <between 5 and 20>: ";
    cin >> no_bugs;
     
  } while (no_bugs < 5 || no_bugs>20);

  return no_bugs;

}

int* getXCoords(int no_bugs)
{  //Variable Declaration/Intitialization
  int i = 0;
  //Dynamically allocate the arrays
 int * x_coords = new int[no_bugs];

  //Set the x coord for the targets
  for (i = 0; i < no_bugs; i++)
  {
    //Set x/y coordinates
    x_coords[i] = (rand() % 576);
  }


  return(x_coords);
}

int* getYCoords(int no_bugs)
 {
  //Variable declaration/initialization
  int i = 0;

  //Dynamically allocate the array for y-coords
  int* y_coords = new int[no_bugs];
  //Generates y-coords for each object randomly
  for (i = 0; i < no_bugs; i++)
  {
    y_coords[i] = (rand() % 336);
  }
  return y_coords;
  }
 int* displayObjects(int* x_coords, int* y_coords, int no_objects)
{
   //Variable Declaration/Initialization
    int i = 0;
    
    int* objects= new int[no_objects];
  
   for (i = 0; i < no_objects; i++)
   {
     //Set the image    
   objects[i]=displayPNG("bugs.png", x_coords[i], y_coords[i]);
   }
   return objects;
}
int zapBugs(int* x, int* y, int* x_coords, int* y_coords, int* objects, int no_bugs)
{ 
  
  int i =0; 
  int k =0;
  int j =0;
  int circle=0;
  int score =0;
  int shots=0;

    for (int i = 0; i < 2*no_bugs; i++)
    {
      cout << "Please enter x/y coordinate: ";
      cin >> x[i] >> y[i];
      shots++;
      

      for (int k = 0; k <  no_bugs; k++)
       {
           //compare player x/y coords and counting scores
          if ((x_coords[k] < x[i]) && (x[i] < (x_coords[k] + 64)) && (y_coords[k] < y[i]) && (y[i] < (y_coords[k] + 64)))
            {
             score++;
             circle=drawCircle(10, x[i], y[i]);
             setColor(circle, 0, 0, 0);
            // display png for 1 second
              
             Sleep(1000);
             removeObject(objects[k]);
              
             }
          // draw a black circle         
          for (j = 0; j < 10; j++)
          {
            circle = drawCircle(j, x[i], y[i]);
            setColor(circle, 0, 0, 0);
          }
          
           // show scores and shots
          gout << setColor(0, 0, 0) << setPos(340, 20) << score << endg;
          gout << setColor(0, 0, 0) << setPos(420, 20) << shots << endg;
          //show game resluts
          if (score == no_bugs)
          {
            drawRect(250, 0, 200, 40);
            gout << setColor(0, 0, 0) << setPos(330, 20) << " Winner " << endg;
          }
          if ((score != no_bugs)&&(shots==2*no_bugs))
          {
            drawRect(250, 0, 200, 40);
            gout << setColor(0, 0, 0) << setPos(330, 20) << "Game Over " << endg;
          }
     
         
       }      
        
    }
   
   
return score;
}


