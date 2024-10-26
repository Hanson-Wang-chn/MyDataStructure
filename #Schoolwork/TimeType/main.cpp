#include "TimeType.h"

int main() {
    TimeType currentTime;
    TimeType endTime;
    bool done = false;
    currentTime.Set (15, 20, 0);
    endTime. Set (18, 30, 0);
    while (!done) {
        currentTime.Increment();
        currentTime.Write();
        if (currentTime.Equal(endTime)) {
            done = true;
        }
    }
    return 0;
}