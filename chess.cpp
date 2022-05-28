/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "board.h"

#include "readFile.h"     // for readFile functions
#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include "unitTests.h"    // for unit tests

#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include <cctype>         // for tolower
using namespace std;

#define YEET 0

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{
   set <int> possible;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Board * board = (Board *)p;

   // call all the top functions (
   board->display(pUI);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   Interface ui("Chess");
   
   ogstream gout;
   ogstream* pGout = &gout;

   // Initialize the game class
   Board board(pGout);
   Board* pBoard = &board;
   
#ifdef _WIN32
 //  int    argc;
 //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
 //  string filename = argv[1];
   if (__argc == 2) ; // TODO: fix and uncomment
//      readFile(__argv[1], board);
#else // !_WIN32
   if (argc == 2) ;
//      readFile(argv[1], board); // TODO: fix and uncomment
#endif // !_WIN32
   
   // run unit tests?
   bool runUnitTests = false;
   if (runUnitTests) ; // add unit test function call here

   // set everything into action
   ui.run(callBack, pBoard);

   return YEET;
}
