#include <iostream>

#include "Heap.h"

using namespace std;

Heap::Heap(){
	numItems = 0;
}

void Heap::enqueue(PrintJob* Job){

	if(numItems < MAX_HEAP_SIZE){
		int i = 0;

		arr[numItems] = Job;

		i = numItems;
		numItems++;

		while((i != 0) && (arr[getParent(i)]->getPriority() < arr[i]->getPriority())){
			perlocate(getParent(i), i);
			i = getParent(i);
		}
	}
}

void Heap::dequeue(){

	if(numItems > 0){
		PrintJob* temp = arr[0];
		arr[0] = arr[numItems - 1];
		delete temp;
		trickleDown(0);
		numItems--;
	}
	
}

PrintJob* Heap::highest(){

	if(numItems > 0){
		return arr[0];
	}
	else{
		return nullptr;
	}
	
}

void Heap::print(){
	if(numItems > 0){
		cout << "Priority: " << arr[0]->getPriority() << ", ";
		cout << "Job Number: " << arr[0]->getJobNumber() << ", ";
		cout << "Number of Pages: " << arr[0]->getPages();
		cout << endl;
	}

	else{
		cout << "error";
	}

}

void Heap::trickleDown(int x){
	int y = getLeft(x);
	int z = getRight(x);

	int largest = x;

	if((y < numItems) && arr[y]->getPriority() > arr[largest]->getPriority()){
		largest = y;
	}

	if((z < numItems) && arr[z]->getPriority() > arr[largest]->getPriority()){
		largest = z;
	}

	if(x != largest){
		perlocate(x ,largest);
		trickleDown(largest);
	}


}

int Heap::getParent(int num){
	return ((num -1) / 2);
}

int Heap::getRight(int num){
	return ((2 * num) + 2);
}

int Heap::getLeft(int num){
	return ((2 * num) + 1);
}

void Heap::perlocate(int x, int y){
	PrintJob* temp = arr[y];
	arr[y] = arr[x];
	arr[x] = temp;
}