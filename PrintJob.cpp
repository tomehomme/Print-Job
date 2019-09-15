#include "PrintJob.h"

PrintJob::PrintJob ( int setP /*, int setJ, int numP*/ ):priority(setP){}//, jobNumber(setJ), numPages(numP){}
int PrintJob::getPriority ( ){
    return priority;
}

// int PrintJob::getJobNumber ( ){
//     return jobNumber;
// }

// int PrintJob::getPages ( ){
//     return numPages;
// }

void PrintJob::setPriority (int priority){ //changes the priority
    this->priority = priority;
} 


//   void PrintJob::setJobNumber (int jobNumber){ //changes the job number
//       this->jobNumber = jobNumber;
// } 