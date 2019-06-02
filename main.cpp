#include <iostream>
#include <cstdlib>
#include <memory>
#include "BoardingStatus.hpp"
#include "Passenger.hpp"

using namespace std;

int main() {
    BoardingStatus aBoardingStatus;

    //Lets create 3 passengers for demo
    std::unique_ptr<Passenger> passenger1 = std::make_unique<Passenger>("Azad");
    std::unique_ptr<Passenger> passenger2 = std::make_unique<Passenger>("Michael");
    std::unique_ptr<Passenger> passenger3 = std::make_unique<Passenger>("William");

    aBoardingStatus.registerObserver(passenger1.get());
    aBoardingStatus.registerObserver(passenger2.get());
    aBoardingStatus.registerObserver(passenger3.get());

    //Case-1 :: BoardingStatus is updated to false
    //It will NOT send Boarding Alert message to passengers as Boarding Gate is not opened yet
    bool isBoardingOpen = false;
    aBoardingStatus.setBoardingStatus(isBoardingOpen);

    //Case-2 :: BoardingStatus is updated to true - Open Boarding Gate
    //It will send Boarding Alert message to all 3 passengers as Boarding Gate is not opened yet
    isBoardingOpen = true;
    cout<<"\n<-------------First alert to passengers when Boarding Gate is opened ------> " << endl << endl;
    aBoardingStatus.setBoardingStatus(isBoardingOpen);

    //Passenger2 is boarded after first Boarding alert
    //De-register passenger-2 from further alert
    aBoardingStatus.deregisterObserver(passenger2.get());


    //Case-3 :: ..... After 30 min, some passengers are still not boarded.......
    //Send 2nd alert to those who are still not boarded
    //It will not re-open boarding gate but just to send alert to remaining passengers who are not boarded yet
    //It will send Boarding Alert message to 2 remaining passengers only
    cout<<"\n<---After 30 min: Second alert to those passengers who are not yet boarded----> " << endl << endl;
    aBoardingStatus.setBoardingStatus(isBoardingOpen);

    return EXIT_SUCCESS;
}
