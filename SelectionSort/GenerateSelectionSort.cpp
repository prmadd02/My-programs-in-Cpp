// Generate and Selection Sort Random Numbers
// Paul Maddox

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>


using namespace std;
int tmp;
int x = 0;
int randomNumber;
int array [10000] = {};



int main()
{
	
cout << "Press Enter to Generate Numbers." << endl;
cin.ignore();	
	
ofstream myfile;
myfile.open ("integers.txt");

srand (time(NULL));
for (x = 0; x < 10000; x++)
{			
		randomNumber = rand() % 10000 + 1;
        array[x] = randomNumber;
        cout << randomNumber << endl;
        myfile << array[x] << endl;
}

cout << "\nRandom Numbers generated and placed into integer.txt file. Press Enter to Sort by Selection." << endl;

cin.ignore();

ofstream myfile2;
myfile2.open ("sorted.txt");

for (int i = 0; i < 10000 -1; i++)
{
		for (int j = i+1; j < 10000; j++)

			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}

	cout << array[i] << endl;    
    myfile2 << array[i] << endl;
    	
	}
cout << "Random Numbers sorted and placed into sorted.txt file. Press Enter to Exit." << endl;

cin.ignore();

return 0;
}
