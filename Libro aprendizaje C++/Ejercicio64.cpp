#include <iostream>
#include <iomanip>
#include <cstdlib>

#include <time.h> // Prototype of time()


using namespace std;

int main()
{
long sec;
time( &sec ); // Take the number of seconds and
srand( (unsigned)sec ); // use it to initialize.

char play='Y';


while (play=='Y')
{

int true_number, my_number, counter=0, diff;
true_number=rand() % 15 + 1;

while (counter < 3) {


cout << "Enter a number: " << endl;

cin >> my_number;
diff=my_number-true_number;



if (diff == 0) {
    cout << "You guessed it!" << endl;
    break; }

else if (diff>0) {
    cout << "You have gone up!" << endl;
    ++counter;
}

else if (diff<0) {
    cout << "You have gone down!" << endl;
    ++counter;
}



    
}
cout <<"The true number is " << true_number << endl;
cout << "Do you want to play again? (Y/N)"<<endl;
do {
cin.get(play);
}
while( play != 'Y' && play != 'N');

}


/*cout << "My number: " << my_number << "\t\t" << "True number: " << true_number << endl;*/


return 0;
}