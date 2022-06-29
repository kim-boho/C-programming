#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

//MaxNumOfJobs = 1000;
int numOfCPU;
int numOfJobs;
char arrName[1000][100];
char arrProcess[1000][100];
int arrNums[1000][3];
int startTime;
int totalDuration;
int lastDoneTime[1000];
int currentTime;
int assignedIndex[1000];
int count=0;
int preProcessIndex;
int prePriority;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* run(){
    while(totalDuration > 0){
        // Processing time string

        pthread_mutex_lock(&lock);
        int i;
        if(count==0){
            printf("%d", currentTime);
            for(i=0; i<numOfCPU; i++){
                assignedIndex[i] = -1;
            }
        }

        // To make result string, add process name or - to string
        int j = count;

        // Initialize index of process to add
        preProcessIndex = -1;
        prePriority = -1;

        // Check all jobs and find process that can be added and has the most highest priority
        for(i=0; i<numOfJobs; i++){
                // If the process is already added, skip it.
                int isAlreadyAssigned = 0;
                int k;
                for(k=0; k<j; k++){
                    if(assignedIndex[k]==i){
                        isAlreadyAssigned = 1;
                        break;
                    }
                }

                // If the process is not added, check if the process is possible to be added to cpu
                if(isAlreadyAssigned == 0){
                    int arri = arrNums[i][0];
                    int dur = arrNums[i][1];
                    int pri = arrNums[i][2];

                if(arri <= currentTime && dur > 0){
                    if(preProcessIndex==-1 || prePriority > pri){
                        preProcessIndex = i;
                        prePriority = pri;
                    } else if(prePriority == pri){
                        int preArrival = arrNums[preProcessIndex][0];
                        if(preArrival > arri){
                            preProcessIndex = i;
                            prePriority = pri;
                        }
                    }
                }
            }
        }
        char temp[1000];
        // If we found process that can be added, add it to cpu and print
        if(preProcessIndex != -1){

            assignedIndex[j] = preProcessIndex;

            // Assign job to CPU
            strcat(temp,"\t");
            strcat(temp, arrProcess[preProcessIndex]);
            printf("%s", temp);
            temp[0] = '\0';
            
            // Decrease duration
            arrNums[preProcessIndex][1]--;
            totalDuration--;

            // If the job is done, check if for the second table
            if(arrNums[preProcessIndex][1] == 0){
                lastDoneTime[preProcessIndex] = currentTime + 1;
            }
            // If we could not find process to add, add -
        } else{
            strcat(temp, "\t");
            strcat(temp, "-");
            printf("%s", temp);
            temp[0] = '\0';
        }
        // Print the cpu status if there is any assgined cpu
        count++;
        preProcessIndex = -1;
        prePriority = -1;
        // if all CPU were used
        if(count==numOfCPU){
            printf("\n");
            currentTime++;
            count = 0;
            sleep(1); // one time unit is done
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(int argc, char* argv[]){

    // Take the number of cpu in command line
    sscanf(argv[1], "%d", &numOfCPU);

    // To store inputs by each line
    char temp[100];

    numOfJobs = 0;
    totalDuration = 0;

    // Take header and ignore
    if(fgets(temp, 300, stdin) != NULL){

        // Take job information
        while(fgets(temp, 300, stdin) != NULL){
            sscanf(temp, "%s\t%s\t%d\t%d\t%d", arrName[numOfJobs], arrProcess[numOfJobs], &arrNums[numOfJobs][0], &arrNums[numOfJobs][1], &arrNums[numOfJobs][2]);
            int duration = arrNums[numOfJobs][1];
            totalDuration += duration;
            int arrivalTime = arrNums[numOfJobs][0];
            if(numOfJobs == 0){
                startTime = arrivalTime;
            } else{
                if(startTime > arrivalTime){
                    startTime = arrivalTime;
                }
            }
            numOfJobs++;
        }
    }
    int i;

    // Table header string
    for(i=1; i<=numOfCPU; i++){
        if(i==1){
            printf("Time\tCPU%d",i);
        } else{
            printf("\tCPU%d",i);
        }
    }
    printf("\n");


    // For summary table
    for(i=0; i<numOfJobs; i++){
        lastDoneTime[i] = -1;
    }



    // Start from the ealiest time
    currentTime = startTime;


    pthread_t threads[numOfCPU];
    for(i=0; i<numOfCPU; i++){
        pthread_create(&threads[i], NULL, &run, NULL);
    } // create threads

    for(i=0; i<numOfCPU; i++){
        pthread_join(threads[i], NULL);
    } // join threads
    

    // print processes using thread//


    // All jobs were done and print idle string
    char idleString[1000];
    idleString[0] = '\0';
    char time[10];
    sprintf(time, "%d", currentTime);
    strcat(idleString, time);
    strcat(idleString, "\tIDLE\n\n");
    printf("%s", idleString);


    // The second table
    printf("Summary\n");

    // To check the user is already printed or not
    int arrivalOrderedIndex[numOfJobs];
    for(int i=0; i<numOfJobs; i++){
        arrivalOrderedIndex[i] = -1;
    }

    // To check if the all users were checked
    int isAllUsersChecked = 0;

    // Check each process and find the user who has the ealiest arrived job to print, and print it
    while(isAllUsersChecked==0){
        int ealiestArrivalProcess = -1;
        int lastFinishedTime;
        for(int j=0; j<numOfJobs; j++){
            if(arrivalOrderedIndex[j] == -1){
                int currentArr = arrNums[j][0];
                if(ealiestArrivalProcess == -1){
                    ealiestArrivalProcess = j;
                    lastFinishedTime = lastDoneTime[j];
                } else{
                    if(arrNums[ealiestArrivalProcess][0]>currentArr){
                        ealiestArrivalProcess = j;
                        lastFinishedTime = lastDoneTime[j];
                    }
                }
            }
        }
        

        // Check the same user names
        for(i=0; i<numOfJobs; i++){
            if(ealiestArrivalProcess != i && strcmp(arrName[ealiestArrivalProcess], arrName[i])==0){
                if(lastDoneTime[ealiestArrivalProcess]<lastDoneTime[i]){
                    lastFinishedTime = lastDoneTime[i];
                }
                arrivalOrderedIndex[i] = 0;
            }
        }

        printf("%s\t%d\n", arrName[ealiestArrivalProcess], lastFinishedTime);
        arrivalOrderedIndex[ealiestArrivalProcess] = 0;

        // To check if all users were checked
        for(i=0; i<numOfJobs; i++){
            if(arrivalOrderedIndex[i]==0){
                isAllUsersChecked = 1;
            } else{
                isAllUsersChecked = 0;
                break;
            }
        }
    }


    return 0;
}