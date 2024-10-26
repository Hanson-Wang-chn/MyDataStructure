#include "Random.h"
#include "Runway.h"
#include <thread> // 使用 sleep_for
#include <chrono> // 使用 milliseconds

int main()
{
    int end_time;
    int queue_limit;
    int flight_number = 0;
    double arrival_rate, departure_rate;

    initialize(end_time, queue_limit, arrival_rate, departure_rate);

    Random variable;
    Runway small_airport(queue_limit);

    for (int current_time = 0; current_time < end_time; current_time++) {
        int number_arrivals = variable.poisson(arrival_rate);
        for (int i = 0; i < number_arrivals; i++) {
            Plane current_plane(flight_number++, current_time, arriving);
            if (small_airport.can_land(current_plane) != success)
                current_plane.refuse();
        }

        int number_departures = variable.poisson(departure_rate);
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (small_airport.can_depart(current_plane) != success)
                current_plane.refuse();
        }

        Plane moving_plane;
        switch (small_airport.activity(current_time, moving_plane)) {
            case land:
                moving_plane.land(current_time);
                break;
            case takeoffs:
                moving_plane.fly(current_time);
                break;
            case idle:
                run_idle(current_time);
        }

        cout << endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    small_airport.shut_down(end_time);

    return 0;
}