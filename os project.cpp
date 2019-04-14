*********************_______________________OPERATING__SYSTEM________________________**************************

NAME: NAVEEN SAI
ROLL NO: 33
SECTION:K17KV
GROUP: 1


*********************************____________________PROJECT______________________*******************************


QUESTION :
             Write a program that implements the least frequently used page replacement algorithm. First, generate 
a random page-reference string where page numbers range from 0 to 9. Apply the random page-reference string to each
algorithm, and record the number of page faults incurred by each algorithm. Implement the replacement algorithm so that
the number of page frames can vary from 1 to 7. Assume that demand paging is used .



INTRODUCTION TO THE PAGE REPLACEMENTS:
                                     A program needs its code and information live in memory before it is executed. Yet,
once in a while the memory estimate can't fit all the code and information of running projects. The arrangement is to cut 
both memory and projects into equivalent measured pages. An OS can undoubtedly swap in the required page of a program from
plate to memory. Paging happens when a page blame happens. A page blame happens when a required page isn't inhabitant in
memory and should be swapped in, conceivably overwriting another page in memory. A page substitution calculation chooses 
which memory page must be paged out (swap out, write to circle) to account for the mentioned page. 
To plan a decent page substitution calculation, we would prefer not to every now and again swap a similar memory page in and
out. So to assess a page substitution calculation, we can run it on a specific string of memory references and decide the
quantity of page blames that happen, the less the better.


Understanding Page Replacement Algorithms :

FIFO: The newly brought-in page will replace the oldest page resident in memory. The idea is that the earliest page brought in 
will be the first one replaced. A detailed demostration of how FIFO page replacement algorithm works can be found in SGG. 
LRU: The Least Recently Used algorithm works on the assumption that pages that are most recently used will most likely to be 
used next. So the idea is to replace the longest-resident page when a new page is brought in. A detailed demostration of how 
the LRU algorithm works can be found in SGG.

DESCRIPITION:
Page number: the page in the disk which will be demanded to swap in the memory. 
Page frame: the page in the computer memory 
page-reference string: a sequence of the pages on the disk that are demanded to swap into the memory.

********************************__________________________C*O*D*E_______________________________*******************************





#include <stdio.h>
#include <stdlib.h>


/**************************************
* The parameters of memory and circle pages 
* PageFrameList: The progressively distributed cluster speaking to memory pages 
* FrameNR: the quantity of page outlines in memory 
* elementCout: Point to the following page to be supplanted 
* ReferenceString: The succession of the requesting pages 
* ReferenceLength: The length of the randomized reference string 
* ReferenceSZ: the page number range in the reference string
*/
#define ReferenceLength 100
typedef struct
{
    int *PageFrameList;
    int elementCount;	
}PageFrame;
int ReferenceSZ, FrameNR;
PageFrame memory;
int *ReferenceString;
/* Test driver sub functions */
void generateReferenceString();
void initializePageFrame();
void printReferenceString();
void printPageFrame();
/* Algorithm Functions */
int FIFO();
int LRU();
/* The possible algorithm subfunctions
int FIFOSearch(int PageNumber);
int FIFOInsert(int PageNumber);
int LRUSearch(int PageNumber);
int LRUInsert(int PageNumber);
void LRUupdatePageTable(int Findindex);
*/
/*******************************
 *
 * The main function is the test driver for FIFO & LRU algorithms
 *
 * 1. Initialize the system parameters
 * 2. Initialize the memory pages 
 * 3. Generate the randomized reference string
 * 4. Apply the FIFO algorithm, calculate the number of page faults
 * 5. Apply the LRU algorithm, calculate the number of page faults
 */
int main(int argc, char* argv[])
{
if( argc != 3 )
{
printf("Command format: Test <reference string size> <number of page frames>");
}
ReferenceSZ = atoi(argv[1]);
FrameNR = atoi(argv[2]);
generateReferenceString();
initializePageFrame();
printf("page fault of FIFO: %d\n",FIFO());
free(memory.PageFrameList);
printf("\n");
printf("\n");
printReferenceString();
initializePageFrame();
printf("page fault of LRU: %d\n",LRU());
free(memory.PageFrameList);
free(ReferenceString);
return 0;
}
/*
The test driver functions implmentation details
*/
void generateReferenceString()
{
int i;
srand(time(0));
ReferenceString = (int *)malloc( sizeof(int) * ReferenceLength );
printf("The randomized Reference String: ");
for(i=0; i< ReferenceLength; i++)
{
ReferenceString[i] = rand() % ReferenceSZ;
printf("%d ", ReferenceString[i]);       
}
printf("\n");
}
void initializePageFrame()
{
int i;
memory.PageFrameList = (int *)malloc( sizeof(int)* FrameNR );
memory.elementCount =0;    
for(i=0; i< FrameNR; i++)
{
memory.PageFrameList[i] = -1;       
}
}
void printPageFrame()
{
int i;
for(i=0; i< FrameNR; i++)
{
printf("%2d ",memory.PageFrameList[i]);       
}
printf("\n");
}
void printReferenceString()
{
int i;
printf("The Same Reference String: ");
for(i=0; i< ReferenceLength; i++)
{
printf("%d ", ReferenceString[i]);       
}
printf("\n");
}
/*
 * The skeleton code for FIFO & LRU algs
 NOTE: you are not required to follow the skeleton code here you can also write on your own,
 even different data structure BUT make sure your algorithm is correct!!!!!! It is strongly recommended 
to print out the PageFrames so that you can follow how the algorithm works and double check it
 */
int FIFO()
{
int PagefaultCount=0;
int i;
for( i=0; i<ReferenceLength; i++ ) 
{
PagefaultCount+=FIFOInsert(ReferenceString[i]);
printPageFrame();
}
return PagefaultCount;
}
/*  Some hints you can follow
int FIFOSearch(int PageNumber)
{

}
int FIFOInsert(int PageNumber)
{
int Pagefault=0;
if( 0==FIFOSearch(PageNumber) )
{
//Replace the page HERE
}
return Pagefault;      
}
*/
int LRU()
{
int PagefaultCount=0;
int i;
for( i=0; i<ReferenceLength; i++ ) 
{
PagefaultCount+=LRUInsert(ReferenceString[i]);
printPageFrame();
}
return PagefaultCount;
}
/*  Some hints you can follow
int LRUSearch(int PageNumber)
{


}
int LRUInsert(int PageNumber)
{
int PageFault=0;
int Findindex = -1;
Findindex = LRUSearch(PageNumber);
if ( -1 == Findindex ) 
{         
//Replace the page HERE
}
else
{
LRUupdatePageTable(Findindex);
return PageFault;
}
void LRUupdatePageTable(int Findindex)
{

}
*/


SAMPLE CODE:



The code will take two arguments: one is the reference range, the other is the number of page frames in memory.

The displayed information looks as below:

The randomized Reference String: 5 2 2 0 4 6 4 4 1 3 4 5 0 4 5 6 2 0 0 1 
 5 -1 -1 
 5  2 -1 
 5  2 -1 
 5  2  0 
 4  2  0 
    .
    .
    .
 0  6  2 
 1  6  2 
page fault of FIFO: 13                    
The Same Reference String: 5 2 2 0 4 6 4 4 1 3 4 5 0 4 5 6 2 0 0 1 
 5 -1 -1 
 5  2 -1 
 5  2 -1 
 5  2  0 
 4  2  0 
    .
    .
    .
 6  2  0 
 1  2  0 
page fault of LRU: 13 


The test pilot will create an irregular page-reference string and consider both the two calculation works, every one of which will print out its number of page deficiencies. 
The page outlines are spoken to by a progressively dispensed whole number exhibit; the variable lementCount will follow which is the nextpage edge to be supplanted . 
In every calculation, it will mimic the paging procedure to take in the page-reference string and after that choose which page in the page casings will be paged out each time.

GITHUB LINKS: 

