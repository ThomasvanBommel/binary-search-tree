/**
 * Thomas vanBommel
 * Feb 27. '21 - Created
 * */

#include <iostream>
#include <chrono>

using namespace std;

class Timer{
public:
    // Create a new timer
    Timer(bool startImmediately){
        if(startImmediately) start();
    }

    // Start the timer
    void start(){
        start_ = chrono::high_resolution_clock::now();
    }

    // Get elapsed time (ms) without stopping
    double time(){
        return chrono::duration_cast<chrono::milliseconds>(
            chrono::high_resolution_clock::now() - start_
        ).count();
    }

private:
    chrono::time_point<chrono::high_resolution_clock> start_;
};