#ifndef AIRPORT_PACKAGES_CPP
#define AIRPORT_PACKAGES_CPP
// Dear programmer:
// When I wrote this code, only God and
// I knew hot it worked.
// Now, only God knos it!
//
// Therefore, if you are trying to optimize
// this routine and it fails (most surely),
// please increase this counter as a 
// warning for the next person:
//
// total_hours_wasted_here = 0
//
#include "airport_packages.h"

#ifdef _MSC_VER
// Handling MSC error messages
#define _CRT_SECURE_NO_WARNINGS
#endif
using namespace std;

void printID_Node(Package& workload);
void givetoEdge_Node(Package& workload);

void printID_Edge(Package& workload);
void givetoNode_Edge(Package& workload);

///ERROR1--ERROR2: already defined in airport_packages.obj
/*
bool Package::isgoodPackage(Package& p1)const {
	if ((p1.getLength() < 22) || (p1.getLength() > 100)) {	//Wrong length
		cout << "\nWrong Length" << endl;
		return false;
	}
	if ((p1.getHeight() < 35) || (p1.getHeight() > 70)) { //Wrong height
		cout << "\nWrong Height" << endl;
		return false;
	}
	if ((p1.getWidth() < 56) || (p1.getWidth() > 50)) { //Wrong width
		cout << "\nWrong Width" << endl;
		return false;
	}
	if ((p1.getWeight() < 10) || (p1.getWeight() > 30)) { //Wrong weight
		cout << "\nWrong Weight" << endl;
		return false;
	}
	if ((p1.getGoal() == "CDG") || (p1.getGoal() == "FCO") || (p1.getGoal() == "LHR") || (p1.getGoal() == "HKG") || (p1.getGoal() == "PEK") || (p1.getGoal() == "SVO") || (p1.getGoal() == "YUL") || (p1.getGoal() == "JFK") || (p1.getGoal() == "LAX")) { //Wrong destination
		cout << "\nWrong Destination" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool CarryOnPackage::isgoodCarryonPackage(CarryOnPackage& p1) const {
	if ((p1.getLength() < 22) || (p1.getLength() > 100)) {	//Wrong length
		cout << "\nWrong Length" << endl;
		return false;
	}
	if ((p1.getHeight() < 35) || (p1.getHeight() > 70)) { //Wrong height
		cout << "\nWrong Height" << endl;
		return false;
	}
	if ((p1.getWidth() < 56) || (p1.getWidth() > 50)) { //Wrong width
		cout << "\nWrong Width" << endl;
		return false;
	}
	if ((p1.getWeight() < 1) || (p1.getWeight() > 10)) { //Wrong weight
		cout << "\nWrong Weight" << endl;
		return false;
	}
	if ((p1.getGoal() == "CDG") || (p1.getGoal() == "FCO") || (p1.getGoal() == "LHR") || (p1.getGoal() == "HKG") || (p1.getGoal() == "PEK") || (p1.getGoal() == "SVO") || (p1.getGoal() == "YUL") || (p1.getGoal() == "JFK") || (p1.getGoal() == "LAX")) { //Wrong destination
		cout << "\nWrong Destination" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool HeavyPackage::isgoodHeavyPackage(HeavyPackage& p1) const {
	if ((p1.getLength() < 100) || (p1.getLength() > 200)) {	//Wrong length
		cout << "\nWrong Length" << endl;
		return false;
	}
	if ((p1.getHeight() < 70) || (p1.getHeight() > 150)) { //Wrong height
		cout << "\nWrong Height" << endl;
		return false;
	}
	if ((p1.getWidth() < 50)) { //Wrong width
		cout << "\nWrong Width" << endl;
		return false;
	}
	if ((p1.getWeight() < 30) || (p1.getWeight() > 100)) { //Wrong weight
		cout << "\nWrong Weight" << endl;
		return false;
	}
	if ((p1.getGoal() == "CDG") || (p1.getGoal() == "FCO") || (p1.getGoal() == "LHR") || (p1.getGoal() == "HKG") || (p1.getGoal() == "PEK") || (p1.getGoal() == "SVO") || (p1.getGoal() == "YUL") || (p1.getGoal() == "JFK") || (p1.getGoal() == "LAX")) { //Wrong destination
		cout << "\nWrong Destination" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool OversizePackage::isgoodOversizePackage(OversizePackage& p1) const {
	if ((p1.getLength() < 100) || (p1.getLength() > 200)) {	//Wrong length
		cout << "\nWrong Length" << endl;
		return false;
	}
	if ((p1.getHeight() < 70) || (p1.getHeight() > 150)) { //Wrong height
		cout << "\nWrong Height" << endl;
		return false;
	}
	if ((p1.getWidth() < 50) || (p1.getWidth() > 50)) { //Wrong width
		cout << "\nWrong Width" << endl;
		return false;
	}
	if ((p1.getWeight() < 30) || (p1.getWeight() > 100)) { //Wrong weight
		cout << "\nWrong Weight" << endl;
		return false;
	}
	if ((p1.getGoal() == "CDG") || (p1.getGoal() == "FCO") || (p1.getGoal() == "LHR") || (p1.getGoal() == "HKG") || (p1.getGoal() == "PEK") || (p1.getGoal() == "SVO") || (p1.getGoal() == "YUL") || (p1.getGoal() == "JFK") || (p1.getGoal() == "LAX")) { //Wrong destination
		cout << "\nWrong Destination" << endl;
		return false;
	}
	else {
		return true;
	}
}*/
#endif // !AIRPORT_PACKAGES_CPP

/*
.___                   .___                          _____                 
|   | _____    _____   |   |______  ____   ____     /     \ _____    ____  
|   | \__  \  /     \  |   \_  __ \/  _ \ /    \   /  \ /  \\__  \  /    \ 
|   |  / __ \|  Y Y  \ |   ||  | \(  <_> )   |  \ /    Y    \/ __ \|   |  \
|___| (____  /__|_|  / |___||__|   \____/|___|  / \____|__  (____  /___|  /
           \/      \/                         \/          \/     \/     \/ 
*/