#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap(){
    numItems = 0;
}

void Heap::enqueue (PrintJob* job){ //inserts to the back and then bubbles up
    if (numItems != MAX_HEAP_SIZE){
        arr[numItems] = job;
        numItems++;
        bubbleUp(numItems-1); //index of the new job is numItems-1
    }
}

 PrintJob* Heap::highest ( ){
    // if (!isEmpty()){
    //     return arr[0];
    //  }
     return arr[0];
 }
 
bool Heap::isEmpty() const{
    return numItems==0;
}

void Heap::bubbleUp(int currIndex){
    if (currIndex == 0 || arr[currIndex]->getPriority()<=arr[currIndex/2]->getPriority()){
        return;
    }
    swap(arr[currIndex],arr[currIndex/2]); //swap the parent and the child if child>=parent
    bubbleUp(currIndex/2); //recursively bubble up with parent's index
}

void Heap::print() {
    if (!isEmpty()){
        for (int i = 0; i<numItems; i++){
         cout << "Priority: " << arr[i]->getPriority() << endl;
        }
        //  << ", Job Number: " << arr[0]->getJobNumber()
        //  << ", Number of Pages: " << arr[0]->getPages()
        //  << endl;
    }
   
}

 void Heap::dequeue ( ){
     if (!isEmpty()){
         swap(arr[0],arr[numItems-1]);
         numItems--;
         trickleDown(1); //trickle down starting at root 
     }
 }

 void Heap::trickleDown(int currIndex){
     if (currIndex*2+1 >= numItems){
        return;
    }
    if(arr[currIndex]->getPriority() >= arr[currIndex*2]->getPriority() && arr[currIndex]->getPriority() >= arr[currIndex*2+1]->getPriority()){ //if it is greater than both children, stop
        return;
    }
    if (arr[currIndex*2]->getPriority() >= arr[currIndex*2+1]->getPriority()){ //go with the bigger path
        swap(arr[currIndex],arr[currIndex*2]);
        trickleDown(currIndex*2); //recursive with next child's index
    }
    else{
        swap(arr[currIndex],arr[currIndex*2+1]); //swap the parent and the child if parent>child
        trickleDown(currIndex*2+1); //recursively trickle down with child's index
    }
 }