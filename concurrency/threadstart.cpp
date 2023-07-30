#include<iostream>
#include<thread> // include thread 
#include<mutex>// for mutexes 
#include<vector>
#include<atomic>
#include<condition_variable>
#include<future>// for async
#include<chrono>//to sleep- for timming

/* //thread is one mechanism of achiveing concurrency. main thread is where out program starts
//then we may ave additional threads- exeuting blocks of code, functions all while our main thread executes.
//thred has its own stack for local variables, own logical control flow and thead id. 
//shared libraries, run time heap, input/output. 

Two types thread and jthread
s
syntax:  std::thread threadNAme(&addressoffunction, argument list);
important to make the main thread wait for synchronization. 
or else will give error because the main thread amight be done and killl the program while the other threads are continuing


ALSO REMEMBER MAIN THREAD IS ALSO A THREAD. join will make the main thread wait for the other thread to join.
use std::this_thread::sleep_for(1s); to make the thread sleep
*/


 int shared_value=0; // this is for mmultiple threads to read and change
 int shared_value_mutex=0; // this is for mmultiple threads to read and change. but mutex
std::mutex gLock;// mutex

std::condition_variable gConditionVar; // condition varriable 

void func(int x){
    std::cout<<x<<std::endl;
}



void sharedVAlueIncrementMutex(){ // THIS IS NOT EXCEPTIONS SAFE 
    gLock.lock();// LOCKS THE MUTEX, Blocks if mutex not avialble.
        shared_value_mutex=shared_value_mutex+1; // increments the global static variable
    gLock.unlock();// UNLOCKS THE MUTEX
} //THREADS READ THE SHARED VALUE AND UPDATES IT.- data race may occur


void sharedVAlueIncrement(){
    shared_value=shared_value+1; // increments the global static variable
} //THREADS READ THE SHARED VALUE AND UPDATES IT.- data race may occur


void sharedVAlueIncrementLockGuard(){ //USE THIS- THIS IS EXCEPTION SAFE############
    std::lock_guard<std::mutex> lockGuard(gLock);// THIS IS SCOPED AND WHEN IT GOES OUT OF SCOPE. ITS UNLOCKED
    shared_value_mutex=shared_value_mutex+1; // increments the global static variable
} //THREADS READ THE SHARED VALUE AND UPdat

static std::atomic<int> shared_atomic_value=0;// declared as atomic. prevents data races

void sharedVAlueIncrementAtomic(){ //USE THIS too#############
    shared_atomic_value++;// done in atomic. no data races occur
    //REMEMBER USE ONLY ++,-- ++,--, +=val, -=val ETC.   shared_atomic_val=shared_atomic_val+1 WILL NOT WORKKKKK. not ovverloaded
} //THREADS READ THE SHARED VALUE AND UPdate

void reportingfunction(bool& notified, int& result){ //waits on the working thread to finish and reports
    std::unique_lock<std::mutex> UniqLock(gLock);// similar to lock_guard but can test if locked etc.
    if(!notified){// even if this thread executes first, it pauses here as notified is false
        gConditionVar.wait(UniqLock);// blocks the current thread(sleeps) till the conditon variable is woken up- notified
        // no continuous checking as it is blocked- sleeps
    }
    std::cout<<"reporter result: "<<result<<std::endl;// afterr the working thread is done and notofoes, this executes
}

void Workingfunction(bool& notified, int& result){
    std::unique_lock<std::mutex> UniqLock(gLock);// this (glock) LOCK IS SHARED
    result+=1;
    //do the required work
    notified=true;//after work is done.
    std::cout<<"work complete"<<std::endl;
    gConditionVar.notify_one();// make the condition variable notify one of the threads sleeping to wakeup.(hs notify_all too)
}


int backgroundAsyncFunc(int x){// function works in the backgroud asynchronously.

    return x*x; 
}

int bufferedfileLoder(std::string fname){ //returns true when the file is done loading- does it in the background asynchronously
    size_t bytesloaded=0;
    while(bytesloaded<20000){
        std::cout<<"background thread loading..."<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));// aarticifical slow down to simulate work done
        bytesloaded+=1000;
    }

    return 1;
}

void tryLockFunc1(int x){
    if(gLock.try_lock()){//if this funtion manahes to get lock  mutex
        std::cout<<"Function 1 got lock"<<std::endl;
        gLock.unlock();

    }
    else{// ifn it doesnt this section will get executed
        std::cout<<"Function 1 didnt get lock"<<std::endl;
        //do work here
    }

    std::cout<<"Function 1 work done regardless whether we get lock or not"<<std::endl;
}

void tryLockFunc2(int x){
    if(gLock.try_lock()){//if this funtion manages to get lock mutex
        std::cout<<"Function 2 got lock"<<std::endl;
        gLock.unlock();
    }
    else{// ifn it doesnt this section will get executed
        std::cout<<"Function 2 didnt get lock"<<std::endl;
        //do work here
    }

    std::cout<<"Function 2 work done regardless whether we get lock or not"<<std::endl;

}

//###############################################################3






int main(){

    auto lambda=[](int x){
        std::cout<<"hello from lambda function on thread: val is :"<<x<<'\n';
    };
    std::thread worker1(&func,100); //pass in adress of the fucntion and the ardument list
   
    worker1.join();// make the main thread wait till the this thread is done. or elsee will terminate while this thread goes on,
    std::thread worker2(lambda,200);// pass in lambda function
    worker2.join();


    //working with MULTIPLE threads- generally we ues a vector of threads

    std::vector<std::thread> threadVector;// threas will run one after the other
    for(int i=0;i<10;i++){
        threadVector.push_back(std::thread(&func,i+100));// remember
        threadVector[i].join(); // we immediately join each thread, here it will execute sequentially
    }

    std::vector<std::thread> threadVector2;// threads will run together(concurrently). results will be jumbled.
    for(int i=0;i<10;i++){
        threadVector2.push_back(std::thread(&func,i+100));// remember
    }
    for(int i=0;i<10;i++){
        threadVector2[i].join(); // join the threads running together.
    }


    //jthread(c++ 20)- auto joining. USES RAII,  has a destructor that joins. dont need to explicitly join.
   // USE g++ -std=c++20 threadstart.cpp  OR WONT WORK.
   
    std::vector<std::jthread> JthreadVector;// threads will run together(concurrently). results will be jumbled.
    for(int i=0;i<10;i++){
        JthreadVector.push_back(std::jthread(&func,i));// remember
    }
    // NO NEED TO EXPLICITLY JOIN. BUT CAN JOIN. USES RAII- DESTRUCTOR JOINS
    for(int i=0;i<10;i++){ 
       JthreadVector[i].join(); // join the threads running together.
    }


// SHARED RESOURCES-mutex and preventing data races

// function sharedValueIncrement reads the shared value increments the static varible by 1
//when it mutiple threads read and increment the same shared value. data races occur and result is not deterministic.

//MUTEXES- mutually exlusive - protects shared resources being acccessed by multiple threads
//use std::mutex gLock; and place the gLock.lock() and gLock.unlock() between the critical section -region where data race may occur.
// NOT EXCEPTION SAFE.

std::vector<std::thread> threadVectorShared;// 
    for(int i=0;i<10;i++){
        threadVectorShared.push_back(std::thread(&sharedVAlueIncrementMutex));
    }
    for(int i=0;i<10;i++){
        threadVectorShared[i].join(); // join the threads running together.
    }

    std::cout<<"Shared value:"<<shared_value_mutex<<std::endl;

// DEADLOCK- if we forget to unlock, it becomes stuck there. this is deadlock. all threads are blocked there.
// if an exxeception is thrown inside the lock and unlock. it will cause deadlock as unlock isnt called

// lock_guard is a mutex wrapper that provides RAII for ownership duration of a scoped block
std::vector<std::thread> threadVectorSharedLockGuard;// 
    for(int i=0;i<10;i++){
        threadVectorSharedLockGuard.push_back(std::thread(&sharedVAlueIncrementLockGuard));
    }
    for(int i=0;i<10;i++){
        threadVectorSharedLockGuard[i].join(); // join the threads running together.
    }

    std::cout<<"Shared value:"<<shared_value_mutex<<std::endl;


// ATOMIC to update shared variables. Easier when it comes to a variable being accessed by
//multiple threads declare it as atomic.

//HOWEVER IT DOES NOT SUPPORT atomicVar=atomicVar+1;  only ++,--, +=val, -=val etc are overloaded. 
//itll cause issues if used.
//this is generally for simpler operations like +1, +10 etc. use  lockguard for others.

std::vector<std::thread> threadVectorSharedAtomic;// 
    for(int i=0;i<10;i++){
        threadVectorSharedAtomic.push_back(std::thread(&sharedVAlueIncrementAtomic));
    }
    for(int i=0;i<10;i++){
        threadVectorSharedAtomic[i].join(); // join the threads running together.
    }

    std::cout<<"Shared value:"<<shared_atomic_value<<std::endl;

// CONDITION VARIABLE- when a thread is accesing a critical section where it is locked. all other threads
///continously check if it is locked or unlocked. this is exepensive.
//CONDITION varible will block other threads untill the thread modifies the shared resource and
// notifies the condition variable
// we use unique_lock here.- its a mutex ownership wrapper- better than lock_guard. can test is locked or not etc
//we use two threads here- working thread and a reporting thread

//DIDNT WORK TRY AGAIN
  /*   int result=0;
    bool notified=false; 
    std::thread workerX(&Workingfunction,notified,result);
    std::thread reporter(&reportingfunction, notified,result);
    

    workerX.join();
    reporter.join();
    std::cout<<"hello from main thread \n"; */


     //TRY_LOCK ... TRIES to lock the mutex. returns immediately. on sucess returns true, when it manages to lock- when other threads arent locking it
     //retunrs false when it fails to lock- some other thread is already locking it
    //if fails to acquire the lock, that section is skipped and the rest is run. no waiting like normal lock


        std::thread tryLockthread1(&tryLockFunc1,1);
        std::thread tryLockthread2(&tryLockFunc2,1);
        
        tryLockthread1.join();
        tryLockthread2.join();// here both inside try locks may get executed if first thead gets unlocked before t
        //the second thread's try_lock is checked. however if any of the threads faill to get lock. the critical part will be
        //skipped and rest of the function will get executed.

//std::async - WIHTOUT SYNCHRONIZATION- runs in the background- need #include<future>
//syntax  std::future<function return type> asyncFunc=std::async(std::launch::async,&function address, parameter list);
// use asyncfunction.get() to get the value of the function
// asyncfunction.get() WAITS till future object has a VALID result.
 // launch policyies - std::launch::async- a new thread is launched to execute the task asynchronously
 //std::launch::deffered- task is executed on the calling thread the first time its result is requested- lazy evaluation
 
 // we can use this to asynchronously load data

 std::future<int> asynchronouslyRunFunction= std::async(std::launch::async, &backgroundAsyncFunc,19);// future object stores the interger
 //result of the function.
 int a =asynchronouslyRunFunction.get();// waits till the future obect has a valid value. essentially does a wait(). USING WAIT_FOR AND GETTING THE STATUS IS BETTER- THIS PAUSES THE WORK TILL THE BACKGROUNDTHREAD IS DONE
 // program wont proceed till future object has completed.
 //also dont call asynchronouslyRunFunction.get() twice. error
 std::cout<<"async val: "<<a<<std::endl;
//###########################

//another async

    std::future<int> backGroundFileLoaderThread= std::async(std::launch::async, &bufferedfileLoder,"filename.txt");// launch type is async. creates new thread that runs in the background
     // background thread that loads the file in the background
     std::future_status Fstatus;// whether our task is computed- ready means done, timeout, deffered are other possibilieties


     //#######main program
     // HERE WE CHECK IF THE BACKGROUND THREAD DATA IS DONE FROM TIME TIME TO TIME WOITHOUT PAUSING THE THREAD TILL RESULTS ARE AVIALABLE. WE UE WAIT_FOR AND FUTURE_STATUS FOR THIS
     while(true){
        std::cout<<"main program running"<<std::endl;
        //artifcial sleep- simmulate work being done
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); //sleep this thread for 50 ms
        Fstatus=backGroundFileLoaderThread.wait_for(std::chrono::milliseconds(1));//(op: ready, timeout,deffered) waits for result, returns if not available for the speciified timeout duration
   //BLOCKs till the result is available or time out. whatever comes first
     // if the background thread data is ready- thread complete
        if(Fstatus==std::future_status::ready){// remember.. if completedd the backgroud thread
            std::cout<<"data ready: "<<backGroundFileLoaderThread.get()<<std::endl;// can use get to take the value of the function in the future object
            break;
        }
     }

    return 0;
}




//PROGRAM TO CONTINOUSLLY PRINT HELLO UNTILL I PRESS A KEY
/*
static bool isFinished=false;// mark as atomic? static std::atomic<bool>

    void printFucn(){//contiuosly prints hello
    while(!isFinished){// untill isFinished is true
            std::cout<<"hello\n";
            std::this_thread::sleep_for(1s);//will sleep for 1 second- sometimes threads causse 100% cpu usage. this waits avoid that
    }
    }
int main()
{
    using namespace std::literals::chrono_literals;
    
    std::thread printerThread(printFucn); //continously prints hello
    std::cin.get();// waits for keyboard press
    isFinished=true; //stops the print function from printing
    printerThread.join();// 
    return 0;
}
*/