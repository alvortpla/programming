// ball1.cpp
// Simulates a bouncing ball
// ---------------------------------------------------
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
#define DELAY 10000000L // Output delay
#define CLS (cout << "\033[2J") // Clear screen
#define LOCATE(z,s) (cout <<"\033["<< z <<';'<< s <<'H')
#define COLOR( f, b) (cout << "\033[1;3"<< (f) \
<<";4"<< (b) <<'m' << flush)
// Position the cursor in row z and column s
int main()
{
int x = 2, y = 3, dx = 1, speed = 0;
string floor(79, '-'),
header = "**** JUMPING BALL ****";
CLS;
LOCATE(1,25); cout << header;
LOCATE(25,1); cout << floor;
COLOR(7,4);

bool flag;
flag=true;


while(flag=true) // Let the ball "always" bounce
{ // Terminate by interrupt key (^C)

int c;
if(kbhit() != 0) // Key was pressed?
{
c = getch(); // Yes -> Get character
if( c == 27 ) // character == Esc?
flag=false;
else if (c == '+')
speed+=1;
else if (c == '-')
speed-=1;

// . . .
}



LOCATE(y,x); cout << 'o' << endl; // Show the ball
for( long wait = 0; wait < DELAY; ++wait)
;
if(x == 1 || x == 79) dx = -dx; // Bounce off
// a wall?
if( y == 24 ) // On the floor?
{
speed = - speed;
if( speed == 0 ) speed = -7; // Restart
}
speed += 1; // Acceleration = 1
LOCATE(y,x); cout << ' '; // Clear output
y += speed; x += dx; // New Position
}
return 0;
}