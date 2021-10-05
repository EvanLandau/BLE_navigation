#include <pthread.h>
#include <string.h>

//UUIDs of BLE beacons
const char UUID1[36] = "";
const char UUID2[36] = "";
const char UUID3[36] = "";

struct scanArg //Holds information to pass to threads
{
    int thread_id;
    //Bluetooth info
    char UUID[36];
    float* s;
    unsigned int* t;
}

double scanSignal(void *threadarg) //Scans for an individual signal strength
{
    //Get struct with information about needed scan
    struct scanArg *args;
    args = (struct scanArg *) threadarg;
    //Scan for it
}

pthread_t* scanSetup(float *s1, float *s2, float *s3, unsigned int* t1, unsigned int* t2, unsigned int* t3) 
{
    //Setup
    pthread_t threads[3];
    scanArg threadData[3];
    //TODO: Add actual scan

    //Create threads for each BLE scanner
    //1
    threadData[0].thread_id = 1;
    std::strcpy(threadData[0].UUID, UUID1);
    threadData[0].s = s1;
    threadData[0].t = t1;
    //2
    threadData[1].thread_id = 2;
    std::strcpy(threadData[1].UUID, UUID2);
    threadData[1].s = s2;
    threadData[1].t = t2;
    //3
    threadData[2].thread_id = 3;
    std::strcpy(threadData[2].UUID, UUID3);
    threadData[2].s = s3;
    threadData[2].t = t3;
    //Start threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, scanSignal, (void *) &threadData);
    }
}