#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

//LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void insertionSort(Song mySongArray[], int numSongs);
void reverseBubbleSort(Song mySongArray[], int numSongs);
void quickSort(Song mySongArray[], int left, int right);
int partition(Song mySongArray[], int left, int right);

int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}
	
	while(getline(inFile, temp, '\n') && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	
	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();

	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	reverseBubbleSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quickSort(mySongArray, 0, numSongs - 1);
	
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(Song mySongArray[], int numSongs){
	for (int i = 1; i < numSongs; ++i){
		Song key = mySongArray[i];
		int j = i - 1;

		while (j >= 0 && mySongArray[j].getTitle() > key.getTitle()){
			mySongArray[j + 1] = mySongArray[j];
			--j;
		}
		mySongArray[j + 1] = key;
	}
}

//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void reverseBubbleSort(Song mySongArray[], int numSongs){
	for (int i = 0; i < numSongs - 1; ++i){ 
		for (int j = 0; j < numSongs - i - 1; ++j){
			if (mySongArray[j].getTitle() < mySongArray[j + 1].getTitle()){
				Song temp = mySongArray[j];
				mySongArray[j] = mySongArray[j + 1];
				mySongArray[j + 1] = temp;
			}
		}
	}
}


//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quickSort(Song *mySongArray, int left, int right) {
	if (left < right) {
		int pivotIndex = partition(mySongArray, left, right);
		quickSort(mySongArray, left, pivotIndex - 1);
		quickSort(mySongArray, pivotIndex + 1, right); 
	}
}


//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(Song *mySongArray, int left, int right){
	string pivot = mySongArray[right].getTitle();
	int i = left - 1;

	for (int j = left; j < right; ++j){
		if (mySongArray[j].getTitle() < pivot){
			i++;
			Song temp = mySongArray[i];
			mySongArray[i] = mySongArray[j];
			mySongArray[j] = temp;
		}
	}

	Song temp = mySongArray[i + 1];
	mySongArray[i + 1] = mySongArray[right];
	mySongArray[right] = temp;

	return i + 1;
}