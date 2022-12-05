#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "IntersectionSimulationClass.h"
#include "EventClass.h"
#include "random.h"

void IntersectionSimulationClass::readParametersFromFile(
                                  const string &paramFname) {
    bool success = true;;
    ifstream paramF;
    
    paramF.open(paramFname.c_str());

    //Check that the file was able to be opened...
    if (paramF.fail()) {
        success = false;
        cout << "ERROR: Unable to open parameter file: " << paramFname << endl;
    }
    else {
    //Now read in all the params, according to the specified format of
    //the text-based parameter file.
        if (success) {
            paramF >> randomSeedVal;
            if (paramF.fail() || randomSeedVal < 0) {
                success = false;
                cout << "ERROR: Unable to read/set random generatsor seed" 
                     << endl;
            }
        }

        if (success) {
            paramF >> timeToStopSim;
            if (paramF.fail() || timeToStopSim <= 0) {
                success = false;
                cout << "ERROR: Unable to read/set simulation end time" 
                     << endl;
            }
        }

        if (success) {
            paramF >> eastWestGreenTime >> eastWestYellowTime;
            if (paramF.fail() || eastWestGreenTime <= 0 || 
                eastWestYellowTime <= 0) {
                success = false;
                cout << "ERROR: Unable to read/set east-west times" 
                     << endl;
            }
        }

        if (success) {
            paramF >> northSouthGreenTime >> northSouthYellowTime;
            if (paramF.fail() || northSouthGreenTime <= 0 ||
                northSouthYellowTime <= 0) {
                success = false;
                cout << "ERROR: Unable to read/set north-south times" 
                     << endl;
        }
        }

        if (success) {
            paramF >> eastArrivalMean >> eastArrivalStdDev;
            if (paramF.fail() || eastArrivalMean <= 0 ||
                eastArrivalStdDev < 0) {
                success = false;
                cout << "ERROR: Unable to read/set east arrival distribution" 
                    << endl;
            }
        }

        if (success) {
            paramF >> westArrivalMean >> westArrivalStdDev;
            if (paramF.fail() || westArrivalMean <= 0 ||
                westArrivalStdDev < 0) {
                success = false;
                cout << "ERROR: Unable to read/set west arrival distribution" 
                    << endl;
        }
        }

        if (success) {
            paramF >> northArrivalMean >> northArrivalStdDev;
            if (paramF.fail() ||northArrivalMean <= 0 ||
                northArrivalStdDev < 0) {
                success = false;
                cout << "ERROR: Unable to read/set north arrival distribution" 
                    << endl;
            }
        }

        if (success) {
            paramF >> southArrivalMean >> southArrivalStdDev;
            if (paramF.fail() || southArrivalMean <= 0 ||
                southArrivalStdDev < 0) {
                success = false;
                cout << "ERROR: Unable to read/set south arrival distribution" 
                    << endl;
            }
        }

        if (success) {
            paramF >> percentCarsAdvanceOnYellow;
            if (paramF.fail() || percentCarsAdvanceOnYellow < 0 ||
                percentCarsAdvanceOnYellow > 100) {
                success = false;
                cout << "ERROR: Unable to read/set percentage yellow advance" 
                    << endl;
            }

            //Use the specified seed to seed the random number generator
            setSeed(randomSeedVal);
        }

        paramF.close();
    }

  //Let the caller know whether things went well or not by printing the
    if (!success) {
        cout << "ERROR: Parameter file was NOT read in successfully, so the " 
             << "simulation is NOT setup properly!" << endl;
        isSetupProperly = false;
    }
    else {
        cout << "Parameters read in successfully - simulation is ready!" 
             << endl;
        isSetupProperly = true;
    }
}

void IntersectionSimulationClass::printParameters() const {
    cout << "===== Begin Simulation Parameters =====" << endl;
    if (!isSetupProperly)
    {
        cout << "  Simulation is not yet properly setup!" << endl;
    }
    else
    {                                                   
        cout << "  Random generator seed: " << randomSeedVal << endl;
        cout << "  Simulation end time: " << timeToStopSim << endl;

        cout << "  East-West Timing -" <<
                " Green: " << eastWestGreenTime << 
                " Yellow: " << eastWestYellowTime <<
                " Red: " << getEastWestRedTime() << endl;

        cout << "  North-South Timing -" <<
                " Green: " << northSouthGreenTime << 
                " Yellow: " << northSouthYellowTime <<
                " Red: " << getNorthSouthRedTime() << endl;

        cout << "  Arrival Distributions:" << endl;
        cout << "    East - Mean: " << eastArrivalMean << 
                " StdDev: " << eastArrivalStdDev << endl;
        cout << "    West - Mean: " << westArrivalMean << 
                " StdDev: " << westArrivalStdDev << endl;
        cout << "    North - Mean: " << northArrivalMean << 
                " StdDev: " << northArrivalStdDev << endl;
        cout << "    South - Mean: " << southArrivalMean << 
                " StdDev: " << southArrivalStdDev << endl;

        cout << "  Percentage cars advancing through yellow: " <<
                percentCarsAdvanceOnYellow << endl;
    }
    cout << "===== End Simulation Parameters =====" << endl;
}

//MY CODE: schedule the arrival, sorted with sortedListClass
void IntersectionSimulationClass::scheduleArrival(const string &travelDir) {
    int arrivalTime = 0, eventTime = 0;
    EventClass singleEvent;
    if(travelDir == EAST_DIRECTION){
        arrivalTime = getPositiveNormal(eastArrivalMean, eastArrivalStdDev);
        eventTime = currentTime + arrivalTime;
        singleEvent = EventClass(eventTime, EVENT_ARRIVE_EAST); 
        eventList.insertValue(singleEvent);
        cout << "Time: " << currentTime 
             << " Scheduled " << singleEvent << endl;
    }
    else if(travelDir == WEST_DIRECTION){
        arrivalTime = getPositiveNormal(westArrivalMean, westArrivalStdDev);
        eventTime = currentTime + arrivalTime;
        singleEvent = EventClass(eventTime, EVENT_ARRIVE_WEST);
        eventList.insertValue(singleEvent);
        cout << "Time: " << currentTime 
             << " Scheduled " << singleEvent << endl;
    }
    else if(travelDir == NORTH_DIRECTION){
        arrivalTime = getPositiveNormal(northArrivalMean, northArrivalStdDev);
        eventTime = currentTime + arrivalTime;
        singleEvent = EventClass(eventTime, EVENT_ARRIVE_NORTH);
        eventList.insertValue(singleEvent);
        cout << "Time: " << currentTime 
             << " Scheduled " << singleEvent << endl;
    }
    else if(travelDir == SOUTH_DIRECTION){
        arrivalTime = getPositiveNormal(southArrivalMean, southArrivalStdDev);
        eventTime = currentTime + arrivalTime;
        singleEvent = EventClass(eventTime, EVENT_ARRIVE_SOUTH);
        eventList.insertValue(singleEvent);
        cout << "Time: " << currentTime 
             << " Scheduled " << singleEvent << endl;
    }
}

//MY CODE: add the next event to eventList when have
void IntersectionSimulationClass::scheduleLightChange() {
    int eventTime = 0; 
    EventClass singleEvent;
    if(currentLight == LIGHT_GREEN_EW){
        eventTime = currentTime + eastWestGreenTime;
        singleEvent = EventClass(eventTime, EVENT_CHANGE_YELLOW_EW); 
        eventList.insertValue(singleEvent);
        cout << "Time: " << currentTime 
             << " Scheduled " << singleEvent << endl;
    }
    else if(currentLight == LIGHT_YELLOW_EW){
        eventTime = currentTime + eastWestYellowTime;
        singleEvent = EventClass(eventTime, EVENT_CHANGE_GREEN_NS);
        eventList.insertValue(singleEvent);
        cout << "Time: " << currentTime 
             << " Scheduled " << singleEvent << endl;
    }
    else if(currentLight == LIGHT_GREEN_NS){
        eventTime = currentTime + northSouthGreenTime;
        singleEvent = EventClass(eventTime, EVENT_CHANGE_YELLOW_NS);
        eventList.insertValue(singleEvent);
        cout << "Time: " << currentTime 
             << " Scheduled " << singleEvent << endl;
    }
    else if(currentLight == LIGHT_YELLOW_NS){
        eventTime = currentTime + northSouthYellowTime;
        singleEvent = EventClass(eventTime, EVENT_CHANGE_GREEN_EW);
        eventList.insertValue(singleEvent);
        cout << "Time: " << currentTime 
             << " Scheduled " << singleEvent << endl;
    }
}

//MY CODE: handle the next event 
bool IntersectionSimulationClass::handleNextEvent() {
    EventClass eventToHandle;
    eventList.removeFront(eventToHandle);
    currentTime = eventToHandle.getTimeOccurs();
    if(currentTime <= timeToStopSim) {
        cout << endl;
        cout << "Handling " << eventToHandle << endl;

        //Handling Event
        //Arrivals - enqueue CarClass objects for different directions 
        if(eventToHandle.getType() == EVENT_ARRIVE_EAST) {
            CarClass eastCar = CarClass(EAST_DIRECTION, currentTime);
            eastQueue.enqueue(eastCar);
            //print out the details
            cout << "Time: " << currentTime << " Car #" << eastCar.getId() 
                 << " arrives east-bound - queue length: " 
                 << eastQueue.getNumElems() << endl;
            //schedule next arrival
            scheduleArrival(EAST_DIRECTION);
            //record the maximum queue length
            if(eastQueue.getNumElems() > maxEastQueueLength) {
                maxEastQueueLength = eastQueue.getNumElems();
            }
        }
        else if(eventToHandle.getType() == EVENT_ARRIVE_WEST) {
            CarClass westCar = CarClass(WEST_DIRECTION, currentTime);
            westQueue.enqueue(westCar);
            cout << "Time: " << currentTime << " Car #" << westCar.getId() 
                 << " arrives west-bound - queue length: " 
                 << westQueue.getNumElems() << endl;
            scheduleArrival(WEST_DIRECTION);
            if(westQueue.getNumElems() > maxWestQueueLength) {
                maxWestQueueLength = westQueue.getNumElems();
            }
        }
        else if(eventToHandle.getType() == EVENT_ARRIVE_NORTH) {
            CarClass northCar = CarClass(NORTH_DIRECTION, currentTime);
            northQueue.enqueue(northCar);
            cout << "Time: " << currentTime << " Car #" << northCar.getId() 
                 << " arrives north-bound - queue length: " 
                 << northQueue.getNumElems() << endl;
            scheduleArrival(NORTH_DIRECTION);
            if(northQueue.getNumElems() > maxNorthQueueLength) {
                maxNorthQueueLength = northQueue.getNumElems();
            }
        }
        else if(eventToHandle.getType() == EVENT_ARRIVE_SOUTH) {
            CarClass southCar = CarClass(SOUTH_DIRECTION, currentTime);
            southQueue.enqueue(southCar);
            cout << "Time: " << currentTime << " Car #" << southCar.getId() 
                 << " arrives south-bound - queue length: " 
                 << southQueue.getNumElems() << endl;
            scheduleArrival(SOUTH_DIRECTION);
            if(southQueue.getNumElems() > maxSouthQueueLength) {
                maxSouthQueueLength = southQueue.getNumElems();
            }
        }
        
        //Light change
        //handle east-west traffic when yellow light
        else if(eventToHandle.getType() == EVENT_CHANGE_YELLOW_EW){
            int numCarsAdvancedEast = 0, numCarsAdvancedWest = 0;
            cout << "Advancing cars on east-west green" << endl;
            //print out the east first
            while((eastQueue.getNumElems() != EMPTY_QUEUE) && 
                  (numCarsAdvancedEast < eastWestGreenTime)) {
                CarClass advancedCar;
                eastQueue.dequeue(advancedCar);
                numCarsAdvancedEast += 1;
                cout << "  Car #" << advancedCar.getId() 
                     << " advances east-bound" << endl;
            }
            //print out the west next
            while((westQueue.getNumElems() != EMPTY_QUEUE) && 
                  (numCarsAdvancedWest < eastWestGreenTime)) { 
                CarClass advancedCar;
                westQueue.dequeue(advancedCar);
                numCarsAdvancedWest += 1;
                cout << "  Car #" << advancedCar.getId() 
                     << " advances west-bound" << endl;
            }
            //record the EW total advanced cars
            numTotalAdvancedEast += numCarsAdvancedEast;
            numTotalAdvancedWest += numCarsAdvancedWest;
            //print out the EW remaining queue
            cout << "East-bound cars advanced on green: " 
                 << numCarsAdvancedEast 
                 << " Remaining queue: " << eastQueue.getNumElems() << endl;
            cout << "West-bound cars advanced on green: " 
                 << numCarsAdvancedWest 
                 << " Remaining queue: " << westQueue.getNumElems() << endl;
            //change the light
            currentLight = LIGHT_YELLOW_EW;
            scheduleLightChange();
        }
        //handle north-south traffic when yellow light
        else if(eventToHandle.getType() == EVENT_CHANGE_YELLOW_NS){
            int numCarsAdvancedNorth = 0, numCarsAdvancedSouth = 0;
            cout << "Advancing cars on north-south green" << endl;
            while((northQueue.getNumElems() != EMPTY_QUEUE) && 
                  (numCarsAdvancedNorth < northSouthGreenTime)){
                CarClass advancedCar;
                northQueue.dequeue(advancedCar);
                numCarsAdvancedNorth += 1;
                cout << "  Car #" << advancedCar.getId() 
                     << " advances north-bound" << endl;
            }
            while((southQueue.getNumElems() != EMPTY_QUEUE) && 
                  (numCarsAdvancedSouth < northSouthGreenTime)){
                CarClass advancedCar;
                southQueue.dequeue(advancedCar);
                numCarsAdvancedSouth += 1;
                cout << "  Car #" << advancedCar.getId() 
                     << " advances south-bound" << endl;
            }
            //record the NS total advanced cars
            numTotalAdvancedNorth += numCarsAdvancedNorth;
            numTotalAdvancedSouth += numCarsAdvancedSouth;
            //print out the NS remaining queue
            cout << "North-bound cars advanced on green: " 
                 << numCarsAdvancedNorth 
                 << " Remaining queue: " << northQueue.getNumElems() << endl;
            cout << "South-bound cars advanced on green: " 
                 << numCarsAdvancedSouth 
                 << " Remaining queue: " << southQueue.getNumElems() << endl;
            //change the light
            currentLight = LIGHT_YELLOW_NS;
            scheduleLightChange();
        }
        //handle north-south traffic through green light 
        else if(eventToHandle.getType() == EVENT_CHANGE_GREEN_EW){
            int numCarsAdvancedNorth = 0, numCarsAdvancedSouth = 0;
            bool ifStopAtYellowNorth = NOT_STOP_AT_YELLOW;
            bool ifStopAtYellowSouth = NOT_STOP_AT_YELLOW;
            cout << "Advancing cars on north-south yellow" << endl;
            //North queue
            while((northQueue.getNumElems() != EMPTY_QUEUE) && 
                (numCarsAdvancedNorth < northSouthYellowTime) && 
                (ifStopAtYellowNorth == NOT_STOP_AT_YELLOW)){
                int passValue = getUniform(INCLUSIVE_MIN, INCLUSIVE_MAX);
                if(passValue > percentCarsAdvanceOnYellow){
                    cout << "  Next north-bound car will NOT advance on yellow"
                        << endl;
                    ifStopAtYellowNorth = STOP_AT_YELLOW;
                } 
                //advance on yelllow
                else{
                    CarClass advancedCar;
                    northQueue.dequeue(advancedCar);
                    numCarsAdvancedNorth += 1;
                    cout << "  Next north-bound car will advance on yellow" 
                        << endl;
                    cout << "  Car #" << advancedCar.getId() 
                        << " advances north-bound" << endl;
                }
            }
            if(northQueue.getNumElems() == EMPTY_QUEUE){
                cout << "  No north-bound cars waiting to advance on yellow" 
                    << endl;
            }
            
            //South queue
            while((southQueue.getNumElems() != EMPTY_QUEUE) && 
                (numCarsAdvancedSouth < northSouthYellowTime) && 
                (ifStopAtYellowSouth == NOT_STOP_AT_YELLOW)){  
                int passValue = getUniform(INCLUSIVE_MIN, INCLUSIVE_MAX);
                if(passValue > percentCarsAdvanceOnYellow){
                    cout << "  Next south-bound car will NOT advance on yellow"
                        << endl;
                    ifStopAtYellowSouth = STOP_AT_YELLOW;
                }
                //advance on yelllow
                else{
                    CarClass advancedCar;
                    southQueue.dequeue(advancedCar);
                    numCarsAdvancedSouth += 1;
                    cout << "  Next south-bound car will advance on yellow" 
                        << endl;
                    cout << "  Car #" << advancedCar.getId() 
                        << " advances south-bound" << endl;
                }
            }
            if(southQueue.getNumElems() == EMPTY_QUEUE){
                cout << "  No south-bound cars waiting to advance on yellow" 
                     << endl;
            }
            numTotalAdvancedNorth += numCarsAdvancedNorth;
            numTotalAdvancedSouth += numCarsAdvancedSouth;
            cout << "North-bound cars advanced on yellow: " 
                 << numCarsAdvancedNorth
                 << " Remaining queue: " << northQueue.getNumElems() << endl;
            cout << "South-bound cars advanced on yellow: " 
                 << numCarsAdvancedSouth
                 << " Remaining queue: " << southQueue.getNumElems() << endl;
            currentLight = LIGHT_GREEN_EW;
            scheduleLightChange();
        }
        //handle east-west traffic through yellow light
        else if(eventToHandle.getType() == EVENT_CHANGE_GREEN_NS){
            int numCarsAdvancedEast = 0, numCarsAdvancedWest = 0;
            bool ifStopAtYellowEast = NOT_STOP_AT_YELLOW;
            bool ifStopAtYellowWest = NOT_STOP_AT_YELLOW;
            cout << "Advancing cars on east-west yellow" << endl;
            //East queue
            while((eastQueue.getNumElems() != EMPTY_QUEUE) && 
                  (numCarsAdvancedEast < eastWestYellowTime) && 
                  (ifStopAtYellowEast == NOT_STOP_AT_YELLOW)){
                int passValue = getUniform(INCLUSIVE_MIN, INCLUSIVE_MAX);
                if(passValue >= percentCarsAdvanceOnYellow){
                    cout << "  Next east-bound car will NOT advance on yellow"
                         << endl;
                    ifStopAtYellowEast = STOP_AT_YELLOW;
                } 
                //advance on yelllow
                else{
                    CarClass advancedCar;
                    eastQueue.dequeue(advancedCar);
                    numCarsAdvancedEast += 1;
                    cout << "  Next east-bound car will advance on yellow"
                         << endl;
                    cout << "  Car #" << advancedCar.getId() 
                         << " advances east-bound" << endl;
                }
            }
            if(eastQueue.getNumElems() == EMPTY_QUEUE){
                cout << "  No east-bound cars waiting to advance on yellow"
                     << endl;
            }
            //West queue
            while((westQueue.getNumElems() != EMPTY_QUEUE) && 
                  (numCarsAdvancedWest < eastWestYellowTime) && 
                  (ifStopAtYellowWest == NOT_STOP_AT_YELLOW)){  
                int passValue = getUniform(INCLUSIVE_MIN, INCLUSIVE_MAX);
                if(passValue >= percentCarsAdvanceOnYellow){
                    cout << "  Next west-bound car will NOT advance on yellow"
                         << endl;
                    ifStopAtYellowWest = STOP_AT_YELLOW;
                }
                //advance on yelllow
                else{
                    CarClass advancedCar;
                    westQueue.dequeue(advancedCar);
                    numCarsAdvancedWest += 1;
                    cout << "  Next west-bound car will advance on yellow"
                         << endl;
                    cout << "  Car #" << advancedCar.getId()
                         << " advances west-bound" << endl;
                }
            }
            if(westQueue.getNumElems() == EMPTY_QUEUE){
                cout << "  No west-bound cars waiting to advance on yellow"
                     << endl;
            }
            numTotalAdvancedEast += numCarsAdvancedEast;
            numTotalAdvancedWest += numCarsAdvancedWest;
            cout << "East-bound cars advanced on yellow: "
                 << numCarsAdvancedEast
                 << " Remaining queue: " << eastQueue.getNumElems() << endl;
            cout << "West-bound cars advanced on yellow: "
                 << numCarsAdvancedWest
                 << " Remaining queue: " << westQueue.getNumElems() << endl;
            currentLight = LIGHT_GREEN_NS;
            scheduleLightChange();
        }
        return true;
    }
    cout << endl;
    cout << "Next event occurs AFTER the simulation end time "
         << "(" << eventToHandle << ")!" << endl;
    return false;
}

void IntersectionSimulationClass::printStatistics() const {
    cout << "===== Begin Simulation Statistics =====" << endl;
    cout << "  Longest east-bound queue: " << maxEastQueueLength << endl;
    cout << "  Longest west-bound queue: " << maxWestQueueLength << endl;
    cout << "  Longest north-bound queue: " << maxNorthQueueLength << endl;
    cout << "  Longest south-bound queue: " << maxSouthQueueLength << endl;
    cout << "  Total cars advanced east-bound: " <<
            numTotalAdvancedEast << endl;
    cout << "  Total cars advanced west-bound: " <<
            numTotalAdvancedWest << endl;
    cout << "  Total cars advanced north-bound: " <<
            numTotalAdvancedNorth << endl;
    cout << "  Total cars advanced south-bound: " <<
            numTotalAdvancedSouth << endl;
    cout << "===== End Simulation Statistics =====" << endl;
}