#include "Time2.h"

int main() {
    Time2 currentTime;
    Time2 endTime;
    bool done = false;
    currentTime.Set(2, 0, 0);
    endTime.Set(6, 0, 0);
    while (!done) {
        currentTime.Increment();
        currentTime.Write();
        if (currentTime.Equal(endTime)) {
            done = true;
        }
    }
    return 0;
}
