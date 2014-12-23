// Paul Maddox
//Ordered Collection

#include <iostream>
#include <stdlib.h>

template<class Comparable>
class OrderedCollection { 
    private:
        Comparable* arr;
        int arraySize;

    public:
        OrderedCollection() {
            arr = new Comparable[0];
            arraySize = 0;
        }

		void makeEmpty() { // Deletes entire array
            delete arr;
            arr = new Comparable[0];
            arraySize = 0;
        }

        bool isEmpty() {   // Checks to see if its empty
            if(arraySize == 0) {
                return true; 
            } else {
                return false; 
            }
        }
        
        

        void insert(Comparable newElement) {   // inserts element into array
            Comparable* newArr = new Comparable[arraySize + 1];
            for(int i = 0; i < arraySize; i++) {
                newArr[i] = arr[i];
            }
            newArr[arraySize] = newElement;
            delete[] arr;
            arr = newArr;
            arraySize++;
        }

        void remove(Comparable removeElement) {  // removes element from array
            Comparable *newArr;
            bool Found = false;
            for(int i = 0; i < arraySize; i++) {
                if(arr[i] == removeElement) {
                    newArr = new Comparable[arraySize - 1]; 
                    for(int j = 0; j < arraySize; j++) {
                        if(i == j) {
                            Found = true;
                            continue;
                        } else if(i != j && Found) {
                            newArr[j - 1] = arr[j];
                        } else {
                            newArr[j] = arr[j];
                        }
                    }
                    
                }
            }
            delete[] arr;
            arr = newArr;
            arraySize--;
        }

        Comparable findMin() { //finds minimum element
            int minElement = 0; 
            for(unsigned int i = 0; i < arraySize; i++) {
                if(arr[i] < arr[minElement]) {
                    minElement = i; 
                }
            }

            return arr[minElement];
        }

        Comparable findMax() {  //finds maximum element
            int maxElement = 0; 
            for(int i = 0; i < arraySize; i++) {
                if(arr[i] > arr[maxElement]) {
                    maxElement = i; 
                }
            }

            return arr[maxElement];
        }

        int getSize() { //returns array size
            return arraySize; 
        }

        void printArray() { //prints the array
            for(int i = 0; i < arraySize; i++) {
                std::cout << arr[i] << std::endl; 
            }
        }
};

int main()
{
    OrderedCollection<int> oc;
	int arr [10];
	std::cout << "Populating Ordered Collection with random integers..."<< std::endl;
	
	if (oc.isEmpty())
	{
	
		for(int i = 0; i < 10; i++)
		{
			int ri=rand() % 100 + 1;
			arr[i]=ri;
			oc.insert(ri);
		
		}
		oc.printArray();
	
	system ("PAUSE");
	
		std::cout << "    Min: "<<oc.findMin()<< std::endl;
	
		std::cout << "    Max: "<<oc.findMax()<< std::endl;
	
	system ("PAUSE");
	
		std::cout << "Deleting Max and Min..." << std::endl;
	
	oc.remove(1); //removes min
	oc.remove(79); //removes max
	
		oc.printArray();
	
	system ("PAUSE");
	
		std::cout << "    Min: "<<oc.findMin()<< std::endl;
	
		std::cout << "    Max: "<<oc.findMax()<< std::endl;
	
	return 0;
	
	}
	else
	{	
		std::cout <<"Array is empty, unable to find Min and Max." << std::endl;
	}
