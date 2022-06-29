#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    if(argc<2){
        exit(1);
    }

    int frameLength = atoi(argv[1]);
    int frame[frameLength];

    int queue[frameLength];
    int firstQuIdx = 0;
    int lastQuIdx = 0;

    int i;
    for(i=0; i<frameLength; i++){
        frame[i]=-1;
        queue[i]=-1;
    }

    // 2^12 = 4096
    // 2^20 = 1048576

    unsigned short pageTable[1048576];
    char valid[1048576];
    char clean[1048576];
    char swaped[1048576];

    for(i=0; i<1048576; i++){
        pageTable[i]=0;
        valid[i] = 'i'; // invalid
        clean[i] = 'c'; // clean
        swaped[i] = 'x';
    }
    // variables setting

    int minFault=0;
    int majFault=0;
    int hit=0;
    int swapData=0;
    // Variables setting

    char temp[500];
    while(fgets(temp, 500, stdin) != NULL){
        char ch;
        long logicalAddress;
        sscanf(temp, "%c %ld", &ch, &logicalAddress);
        // Take inputs

        if(!(ch=='w' || ch=='r')){
            exit(1);
        }
        
        int offSet = logicalAddress%4096; // 12 bits
        int pageNum = logicalAddress/4096; // 20 bits
        // Claculate offset and page number

        // if page is valid
        if(valid[pageNum]=='v'){
            hit++;
            if(ch=='w'){
                clean[pageNum] = 'd';
            }

            long p = pageTable[pageNum]*4096+offSet;
            printf("%ld\n", p);

        } else{

            // if page is invalid 
            int emptyFrameIdx = -1;
            for(i=0; i<frameLength; i++){
                if(frame[i]==-1){
                    emptyFrameIdx = i;
                    break;
                }
            }

            // if there is empty frame
            if(emptyFrameIdx != -1){
                minFault++;

                pageTable[pageNum] = emptyFrameIdx;
                frame[emptyFrameIdx] = pageNum;
                valid[pageNum] = 'v'; // set table, frame and valid bit

                queue[lastQuIdx++] = emptyFrameIdx;
                lastQuIdx = lastQuIdx%frameLength; // add frame number in queue for FIFO

                if(ch=='w'){
                    clean[pageNum] = 'd';
                }// if it's writing, set it dirty

                long p = pageTable[pageNum]*4096+offSet;
                printf("%ld\n", p);

            } else{
                // if there is no empty frame
                int removedIdx = queue[firstQuIdx++];
                int removedPageNum = frame[removedIdx];
                firstQuIdx = firstQuIdx%frameLength; // get 'first in' index from queue
                queue[lastQuIdx++] = removedIdx;
                lastQuIdx = lastQuIdx%frameLength; // set that index as the last in queue

                valid[frame[removedIdx]] ='i'; // set removed page invalid

                pageTable[pageNum] = removedIdx;
                frame[removedIdx] = pageNum;
                valid[pageNum] = 'v'; // set table, frame and valid bit

                if(clean[frame[removedIdx]]=='c'){
                    // if the page removed is clean
                    minFault++;

                } else{
                    // if the page removed is dirty
                    majFault++;
                    if(swaped[removedPageNum]=='x'){
                        // if the removed page hasn't been stored
                        swaped[removedPageNum] = 'o';
                        swapData++; // copy page from frame to disk
                    }
                }

                if(ch=='w'){
                    clean[pageNum] = 'd';
                } else{
                    clean[pageNum] = 'c';
                }

                long p = pageTable[pageNum]*4096+offSet;
                printf("%ld\n", p);
            }

        }
        
    }
    printf("%d\n", minFault); // # of minor page faults
    printf("%d\n", majFault); // # of major page faults
    printf("%d\n", hit); // # of hits
    printf("%d\n", swapData); // # of stored page
}