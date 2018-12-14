//
// Created by gideon on 14/12/18.
//

#include "Interpreter.h"


Interpreter::Interpreter(){
    fileLoaded = false;
}

Interpreter::Interpreter(fstream flightCode){
    fileLoaded = false;

}

void Interpreter::loadFileData(fstream *dataFile, bool *isLoaded) {
    vector <string> lineFilds;
    string line;
    dataFile->open(fileName);
    if (!dataFile->is_open()) {
        dataFile->open(fileName, fstream::out);
        if (!dataFile->is_open()) {
            throw "ERROR: CAN'T OPEN THE FILE";
        }
        dataFile->close();
        return;
    }
    if (!*isLoaded) {
        while (getline(*dataFile, line)) {
            lineFilds = lineParser(line, " | ");
            enterObjData(lineFilds, section);
        }
        if (section == PLANE) {
            this->generator.setPlanes(static_cast<int>(companyFleet.size()));
        } else if (section == EMPLOYEE) {
            this->generator.setEmployees(static_cast<int>(employeeMap.size()));
            for (int i = 1; i <= employeeMap.size(); i++) {
                employeeMap[to_string(i)]->setEmployer(employeeMap[to_string(i)]);
            }
        } else if (section == FLIGHT) {
            this->generator.setFlights(static_cast<int>(FlightsMap.size()));
        }
        //mark the files as readed
        *isLoaded = true;
    }
    dataFile->close();
    if (section == SCHEDUALE) {
        for (int i = 1; i <= fleetSchedule.size(); i++) {
            if (fleetSchedule[to_string(i)] == "") {
                continue;
            }
            companyFleet[fleetSchedule[to_string(i)]]->
                    setOccupiedDatesList(FlightsMap[to_string(i)]->getDate());
        }
    } else if (section == EMPLOYEE_SCHEDULE) {
        if (FlightsMap.size() != 0 && crewSchedule.size() != 0) {
            tempCrewSchedule = crewSchedule;
            for (int i = 1; i <= FlightsMap.size(); i++) {
                while (tempCrewSchedule.find(to_string(i)) != tempCrewSchedule.end()) {
                    FlightsMap[to_string(i)]->setAssignedCrew(
                            employeeMap[tempCrewSchedule.find(to_string(i))->second]);
                    employeeMap[tempCrewSchedule.find(to_string(i))->second]->setOccupiedDatesList(
                            FlightsMap[to_string(i)]->getDate());
                    tempCrewSchedule.erase(tempCrewSchedule.find(to_string(i)));
                }
            }
        }
    }
}
