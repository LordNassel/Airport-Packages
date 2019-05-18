#ifndef AIRPORT_PACKAGES_H
#define AIRPORT_PACKAGES_H
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
// total_hours_wasted_here = 24
//
#include<iostream>
#include<string.h>
#include "memtrace.h"
#ifndef MEMTRACE
#endif //MEMTRACE
//airport_packages.h
using namespace std;

class Node {
	int ID;
	Node* next0;
	Node* next1;
	Node* next2;
	const char* name;
public:
	Node(int ID=0, Node* next0 = NULL, Node* next1 = NULL, Node* next2 = NULL, const char* name = NULL) 
		:ID(ID), next0(), next1(), next2(), name(name) {};

	void setID(int ID) { this->ID = ID; };
	void setnextNode(Node* next0, Node* next1, Node* next2) {
		this->next0 = next0;
		this->next1 = next1;
		this->next2 = next2;
	}

	int getID() const { return ID; };

	Node* getnext0_Node() { return next0; };
	Node* getnext1_Node() { return next1; };
	Node* getnext2_Node() { return next2; };

	virtual ~Node() {};
};

class Edge {
	int ID;
public:
	Edge(int ID=0) :ID(ID) {};

	void setID(int ID) { this->ID = ID; }

	int getID() const { return ID; }

	virtual ~Edge() {};
};

class Package {
	int ID;
	int TypeID;
	int RegionID;
	int AirportID;
	int SystemLevel;
	const char* start;
	const char* goal;
	int noderoute[18] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int edgeroute[18] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //17 in real, but we do not want memory problems
	double height;
	double length;
	double width;
	double weight;
	bool kezirakodas;
public:
	Package(int ID = 0, int TypeID = 0, int RegionID = 0, int AirportID = 0, int SystemLevel = 0, const char* start = "BUD", const char* goal = "N/A", double height = 0, double length = 0, double width = 0, double weight = 0, bool kezirakodas=false)
		:ID(ID), TypeID(TypeID), RegionID(RegionID), AirportID(AirportID), SystemLevel(SystemLevel), start(start), goal(goal), height(height), length(length), width(width), weight(weight), kezirakodas(kezirakodas) {};

	void setID(int ID) { this->ID = ID; };
	void setTypeID(int TypeID) { this->TypeID = TypeID; };
	void setRegionID(int RegionID) { this->RegionID = RegionID; };
	void setAirportID(int AirportID) { this->AirportID = AirportID; };
	void setSystemLevel(int SystemLevel) { this->SystemLevel = SystemLevel; };
	void setStart(char* start) { this->start = start; };
	void setGoal(char* goal) { this->goal = goal; };
	void setNodeRoute(int num, int value) { this->noderoute[num] = value; };
	void setEdgeRoute(int num, int value) { this->edgeroute[num] = value; };
	void setHeight(double height) { this->height = height; };
	void setLength(double length) { this->length = length; };
	void setWidth(double width) { this->width = width; };
	void setWeight(double weight) { this->weight = weight; };
	void setKezirakodas(bool value) { this->kezirakodas = value; };

	int getID() const { return ID; };
	int getTypeID() const { return TypeID; };
	int getRegionID() const { return RegionID; };
	int getAirportID() const { return AirportID; };
	int getSystemLevel() const { return SystemLevel; };
	int getNodeRoute(int num) const { return noderoute[num]; };
	int getEdgeRoute(int num) const { return edgeroute[num]; };
	double getHeight() const { return height; };
	double getLength() const { return length; };
	double getWidth() const	{ return width; };
	double getWeight() const { return weight; };
	const char* getStart() const { return start; };
	const char* getGoal() const { return goal; };
	bool getKezirakodas() const { return kezirakodas; };

	virtual bool isgoodPackage(Package& p1) const {
		if ((p1.getLength() < 22) || (p1.getLength() > 100)) {	//Wrong length
			cout << "\nWrong Length" << endl;
			return false;
		}
		if ((p1.getHeight() < 35) || (p1.getHeight() > 70)) { //Wrong height
			cout << "\nWrong Height" << endl;
			return false;
		}
		if ((p1.getWidth() < 40) || (p1.getWidth() > 60)) { //Wrong width
			cout << "\nWrong Width" << endl;
			return false;
		}
		if ((p1.getWeight() < 10) || (p1.getWeight() > 30)) { //Wrong weight
			cout << "\nWrong Weight" << endl;
			return false;
		}

		const char* check = p1.getGoal();

		if (!(strcmp(check,"CDG"))) {
			return true;
		}
		if (!(strcmp(check, "FCO"))) {
			return true;
		}
		if (!(strcmp(check, "LHR"))) {
			return true;
		}
		if (!(strcmp(check, "HKG"))) {
			return true;
		}
		if (!(strcmp(check, "PEK"))) {
			return true;
		}
		if (!(strcmp(check, "SVO"))) {
			return true;
		}
		if (!(strcmp(check, "YUL"))) {
			return true;
		}
		if (!(strcmp(check, "JFK"))) {
			return true;
		}
		if (!(strcmp(check, "LAX"))) {
			return true;
		}
		else {
			return false;
		}
	}

	virtual ~Package() {};
};

class OversizePackage: public Package {
	double OSheight;
	double OSlength;
	double OSwidth;
	double OSweight; //OS = Oversize
	const char* OSgoal;
public:
	OversizePackage(double OSheight=0, double OSlength=0, double OSwidth=0, double OSweight=0, const char* OSgoal="N/A") 
		:OSheight(OSheight), OSlength(OSlength), OSwidth(OSwidth), OSweight(OSweight), OSgoal(OSgoal) {};

	void setOSHeight(double height) { this->OSheight = height; };
	void setOSLength(double length) { this->OSlength = length; };
	void setOSWidth(double width) { this->OSwidth = width; };
	void setOSWeight(double weight) { this->OSweight = weight; }
	void setOSGoal(char* goal) { this->OSgoal = goal; };

	double getOSHeight() const { return OSheight; };
	double getOSLength() const { return OSlength; };
	double getOSWidth() const { return OSwidth; };
	double getOSWeight() const { return OSweight; };
	const char* getGoal() const { return OSgoal; };

	virtual bool isgoodOversizePackage(OversizePackage& p1) const {
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
		const char* check = p1.getGoal();

		if (!(strcmp(check, "CDG"))) {
			return true;
		}
		if (!(strcmp(check, "FCO"))) {
			return true;
		}
		if (!(strcmp(check, "LHR"))) {
			return true;
		}
		if (!(strcmp(check, "HKG"))) {
			return true;
		}
		if (!(strcmp(check, "PEK"))) {
			return true;
		}
		if (!(strcmp(check, "SVO"))) {
			return true;
		}
		if (!(strcmp(check, "YUL"))) {
			return true;
		}
		if (!(strcmp(check, "JFK"))) {
			return true;
		}
		if (!(strcmp(check, "LAX"))) {
			return true;
		}
		else {
			return false;
		}
	}

	virtual ~OversizePackage() {};
};

class HeavyPackage: public Package {
	double HPheight;
	double HPlength;
	double HPwidth;
	double HPweight; //OS = Oversize
	const char* HPgoal;
public:
	HeavyPackage(double HPheight = 0, double HPlength = 0, double HPwidth = 0, double HPweight = 0, const char* HPgoal = "N/A")
		:HPheight(HPheight), HPlength(HPlength), HPwidth(HPwidth), HPweight(HPweight), HPgoal(HPgoal) {};

	void setHPHeight(double height) { this->HPheight = height; };
	void setHPLength(double length) { this->HPlength = length; };
	void setHPWidth(double width) { this->HPwidth = width; };
	void setHPWeight(double weight) { this->HPweight = weight; }
	void setHPGoal(char* goal) { this->HPgoal = goal; };

	double getHPHeight() const { return HPheight; };
	double getHPLength() const { return HPlength; };
	double getHPWidth() const { return HPwidth; };
	double getHPWeight() const { return HPweight; };
	const char* getGoal() const { return HPgoal; };

	virtual bool isgoodHeavyPackage(HeavyPackage& p1) const {
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
		const char* check = p1.getGoal();

		if (!(strcmp(check, "CDG"))) {
			return true;
		}
		if (!(strcmp(check, "FCO"))) {
			return true;
		}
		if (!(strcmp(check, "LHR"))) {
			return true;
		}
		if (!(strcmp(check, "HKG"))) {
			return true;
		}
		if (!(strcmp(check, "PEK"))) {
			return true;
		}
		if (!(strcmp(check, "SVO"))) {
			return true;
		}
		if (!(strcmp(check, "YUL"))) {
			return true;
		}
		if (!(strcmp(check, "JFK"))) {
			return true;
		}
		if (!(strcmp(check, "LAX"))) {
			return true;
		}
		else {
			return false;
		}
	}

	virtual ~HeavyPackage() {};
};

class CarryOnPackage: public Package {
	double COPheight;
	double COPlength;
	double COPwidth;
	double COPweight; //COP=Carry-on Package
	const char* COPgoal;
public:
	CarryOnPackage(double COPheight=0, double COPlength=0, double COPwidth=0, double COPweight=0, const char* COPgoal="N/A") 
		:COPheight(COPheight), COPlength(COPlength), COPwidth(COPwidth), COPweight(COPweight), COPgoal(COPgoal){};

	void setCOPHeight(double height) { this->COPheight = height; };
	void setCOPLength(double length) { this->COPlength = length; };
	void setCOPWidth(double width) { this->COPwidth = width; };
	void setCOPWeight(double weight) { this->COPweight = weight; }
	void setCOPGoal(char* goal) { this->COPgoal = goal; };

	double getCOPHeight() const { return COPheight; };
	double getCOPLength() const { return COPlength; };
	double getCOPWidth() const { return COPwidth; };
	double getCOPWeight() const { return COPweight; };
	const char* getCOPGoal() const { return COPgoal; };

	virtual bool isgoodCarryonPackage(CarryOnPackage& p1) const {
		if ((p1.getLength() < 22) || (p1.getLength() > 100)) {	//Wrong length
			cout << "\nWrong Length" << endl;
			return false;
		}
		if ((p1.getHeight() < 35) || (p1.getHeight() > 70)) { //Wrong height
			cout << "\nWrong Height" << endl;
			return false;
		}
		if ((p1.getWidth() < 40) || (p1.getWidth() > 50)) { //Wrong width
			cout << "\nWrong Width" << endl;
			return false;
		}
		if ((p1.getWeight() < 1) || (p1.getWeight() > 10)) { //Wrong weight
			cout << "\nWrong Weight" << endl;
			return false;
		}
		const char* check = p1.getCOPGoal();

		if (!(strcmp(check, "CDG"))) {
			return true;
		}
		if (!(strcmp(check, "FCO"))) {
			return true;
		}
		if (!(strcmp(check, "LHR"))) {
			return true;
		}
		if (!(strcmp(check, "HKG"))) {
			return true;
		}
		if (!(strcmp(check, "PEK"))) {
			return true;
		}
		if (!(strcmp(check, "SVO"))) {
			return true;
		}
		if (!(strcmp(check, "YUL"))) {
			return true;
		}
		if (!(strcmp(check, "JFK"))) {
			return true;
		}
		if (!(strcmp(check, "LAX"))) {
			return true;
		}
		else {
			return false;
		}
	}

	virtual ~CarryOnPackage() {};
};

class Controller {
	int ID;
public:
	Controller(int ID) :ID(123456) {};
	void setID(int ID) { this->ID = ID; }
	int getID() const { return ID; }

//TravelID Table:
//	Heavy|OverSize|Normal|CarryOn --- Region --- Airport Code
//		1			2		3		  1-2-3			1-9
	void generateTID_Package(Package& workload) {
		///Normal
		const char* goal = workload.getGoal();
		int TypeID = 2;
		workload.setTypeID(TypeID);
		int RegionID = 0;
		int AirportID = 0;
		if (!(strcmp(goal, "CDG")) || !(strcmp(goal, "FCO")) || !(strcmp(goal, "LHR"))) {
			RegionID = 1;
			workload.setRegionID(RegionID);
			if (!(strcmp(goal, "CDG"))) AirportID = 1;
			if (!(strcmp(goal, "FCO"))) AirportID = 2;
			if (!(strcmp(goal, "LHR"))) AirportID = 3;
			workload.setAirportID(AirportID);
		}
		if (!(strcmp(goal, "HKG"))|| !(strcmp(goal, "PEK")) || !(strcmp(goal, "SVO"))) {
			RegionID = 2;
			workload.setRegionID(RegionID);
			if (!(strcmp(goal, "HKG"))) AirportID = 4;
			if (!(strcmp(goal, "PEK"))) AirportID = 5;
			if (!(strcmp(goal, "SVO"))) AirportID = 6;
			workload.setAirportID(AirportID);
		}
		if (!(strcmp(goal, "YUL"))|| !(strcmp(goal, "JFK"))|| !(strcmp(goal, "LAX"))) {
			RegionID = 3;
			workload.setRegionID(RegionID);
			if (!(strcmp(goal, "YUL"))) AirportID = 7;
			if (!(strcmp(goal, "JFK"))) AirportID = 8;
			if (!(strcmp(goal, "LAX"))) AirportID = 9;
			workload.setAirportID(AirportID);
		}
	}
	void generateTID_CarryOnPackage(CarryOnPackage& workload) {
		///CarryOnPackage
		const char* goal = workload.getGoal();
		int TypeID = 3;
		int RegionID = 0;
		int AirportID = 0;
		if (!(strcmp(goal, "CDG"))|| !(strcmp(goal, "FCO"))|| !(strcmp(goal, "FCO"))) {
			RegionID = 1;
			if (!(strcmp(goal, "CDG"))) AirportID = 1;
			if (!(strcmp(goal, "FCO"))) AirportID = 2;
			if (!(strcmp(goal, "LHR"))) AirportID = 3;
		}
		if (!(strcmp(goal, "HKG"))|| !(strcmp(goal, "PEK"))|| !(strcmp(goal, "SVO"))) {
			RegionID = 2;
			if (!(strcmp(goal, "HKG"))) AirportID = 4;
			if (!(strcmp(goal, "PEK"))) AirportID = 5;
			if (!(strcmp(goal, "SVO"))) AirportID = 6;
		}
		if (!(strcmp(goal, "YUL")) || !(strcmp(goal, "JFK"))|| !(strcmp(goal, "LAX"))) {
			RegionID = 3;
			if (!(strcmp(goal, "YUL"))) AirportID = 7;
			if (!(strcmp(goal, "JFK"))) AirportID = 8;
			if (!(strcmp(goal, "LAX"))) AirportID = 9;
		}
		workload.setTypeID(TypeID);
		workload.setRegionID(RegionID);
		workload.setAirportID(AirportID);
	}
	void generateTID_OversizePackage(OversizePackage& workload) {
		///OversizePackage
		const char* goal = workload.getGoal();
		int TypeID = 1;
		int RegionID = 0;
		int AirportID = 0;
		if (!(strcmp(goal, "CDG")) || !(strcmp(goal, "FCO")) || !(strcmp(goal, "FCO"))) {
			RegionID = 1;
			if (!(strcmp(goal, "CDG"))) AirportID = 1;
			if (!(strcmp(goal, "FCO"))) AirportID = 2;
			if (!(strcmp(goal, "LHR"))) AirportID = 3;
		}
		if (!(strcmp(goal, "HKG")) || !(strcmp(goal, "PEK")) || !(strcmp(goal, "SVO"))) {
			RegionID = 2;
			if (!(strcmp(goal, "HKG"))) AirportID = 4;
			if (!(strcmp(goal, "PEK"))) AirportID = 5;
			if (!(strcmp(goal, "SVO"))) AirportID = 6;
		}
		if (!(strcmp(goal, "YUL")) || !(strcmp(goal, "JFK")) || !(strcmp(goal, "LAX"))) {
			RegionID = 3;
			if (!(strcmp(goal, "YUL"))) AirportID = 7;
			if (!(strcmp(goal, "JFK"))) AirportID = 8;
			if (!(strcmp(goal, "LAX"))) AirportID = 9;
		}
		workload.setTypeID(TypeID);
		workload.setRegionID(RegionID);
		workload.setAirportID(AirportID);
	}
	void generateTID_HeavyPackage(HeavyPackage& workload) {
		///HeavyPackage
		const char* goal = workload.getGoal();
		int TypeID = 1;
		int RegionID = 0;
		int AirportID = 0;
		if (!(strcmp(goal, "CDG")) || !(strcmp(goal, "FCO")) || !(strcmp(goal, "FCO"))) {
			RegionID = 1;
			if (!(strcmp(goal, "CDG"))) AirportID = 1;
			if (!(strcmp(goal, "FCO"))) AirportID = 2;
			if (!(strcmp(goal, "LHR"))) AirportID = 3;
		}
		if (!(strcmp(goal, "HKG")) || !(strcmp(goal, "PEK")) || !(strcmp(goal, "SVO"))) {
			RegionID = 2;
			if (!(strcmp(goal, "HKG"))) AirportID = 4;
			if (!(strcmp(goal, "PEK"))) AirportID = 5;
			if (!(strcmp(goal, "SVO"))) AirportID = 6;
		}
		if (!(strcmp(goal, "YUL")) || !(strcmp(goal, "JFK")) || !(strcmp(goal, "LAX"))) {
			RegionID = 3;
			if (!(strcmp(goal, "YUL"))) AirportID = 7;
			if (!(strcmp(goal, "JFK"))) AirportID = 8;
			if (!(strcmp(goal, "LAX"))) AirportID = 9;
		}
		workload.setTypeID(TypeID);
		workload.setRegionID(RegionID);
		workload.setAirportID(AirportID);
	}



	void makeroutePackage(Node* worknode, Package& workload) {
		///maincontroller.makeroutePackage(node0, p1);
		int SystemLevel = workload.getSystemLevel();

		Node* next0 = worknode->getnext0_Node();
		Node* next1 = worknode->getnext1_Node(); 
		Node* next2 = worknode->getnext2_Node();
		if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); } //New Feature
		int WorkNodeID = worknode->getID();
		cout << "\n" << WorkNodeID << endl;

		if ((WorkNodeID == 0) && (SystemLevel == 0)) {
			workload.setNodeRoute(WorkNodeID, 1);		//Node writes its ID to Package
			workload.setEdgeRoute(0, 1);				//Connencting Edge writes its ID to Package
			SystemLevel++;
			workload.setSystemLevel(SystemLevel); 
			makeroutePackage(next0, workload); //0->1
		}
		if ((WorkNodeID == 1) && (SystemLevel == 1)) {
			workload.setNodeRoute(WorkNodeID, 1);
			workload.setEdgeRoute(5,1);
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			makeroutePackage(next1, workload); //1->6
		}
		if ((WorkNodeID == 6) && (SystemLevel == 2)) {
			workload.setNodeRoute(WorkNodeID, 1);
			SystemLevel++; 
			workload.setSystemLevel(SystemLevel);
			if (workload.getRegionID() == 1) { workload.setEdgeRoute(6, 1); makeroutePackage(next0, workload); }	//6->7
			if (workload.getRegionID() == 2) { workload.setEdgeRoute(10, 1); makeroutePackage(next1, workload); }	//6->11
			if (workload.getRegionID() == 3) { workload.setEdgeRoute(14, 1); makeroutePackage(next2, workload); }	//6->15
		}
		if ((WorkNodeID == 7) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			if (workload.getAirportID() == 1) { workload.setEdgeRoute(7, 1); makeroutePackage(next0, workload); }	//7->8
			if (workload.getAirportID() == 2) { workload.setEdgeRoute(8, 1); makeroutePackage(next1, workload); }	//7->9
			if (workload.getAirportID() == 3) { workload.setEdgeRoute(9, 1); makeroutePackage(next2, workload); }	//7->10

		}
		if ((WorkNodeID == 8) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
		if ((WorkNodeID == 9) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
		if ((WorkNodeID == 10) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
		if ((WorkNodeID == 11) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			workload.setKezirakodas(true);
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			if (workload.getAirportID() == 4) { workload.setEdgeRoute(11, 1); makeroutePackage(next0, workload); }	//11->12
			if (workload.getAirportID() == 5) { workload.setEdgeRoute(12, 1); makeroutePackage(next1, workload); }	//11->13
			if (workload.getAirportID() == 6) { workload.setEdgeRoute(13, 1); makeroutePackage(next2, workload); }	//11->14
		}
		if ((WorkNodeID == 12) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
		if ((WorkNodeID == 13) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
		if ((WorkNodeID == 14) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
		if ((WorkNodeID == 15) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			if (workload.getAirportID() == 7) { workload.setEdgeRoute(15, 1); makeroutePackage(next0, workload); }	//15->16
			if (workload.getAirportID() == 8) { workload.setEdgeRoute(16, 1); makeroutePackage(next1, workload); }	//15->17
			if (workload.getAirportID() == 9) { workload.setEdgeRoute(17, 1); makeroutePackage(next2, workload); }	//15->18
		}
		if ((WorkNodeID == 16) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
		if ((WorkNodeID == 17) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			workload.setKezirakodas(true);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			//STOP
		}
		if ((WorkNodeID == 18) && (SystemLevel == 4)) {
			workload.setNodeRoute(WorkNodeID, 1);
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
	}

	void makerouteCarryOnPackage(Node* worknode, CarryOnPackage& workload) { cout << " - NOT IN SYSTEM" << endl; };

	void makerouteOversizePackage(Node* worknode, OversizePackage& workload){
		///maincontroller.makerouteOversizePackage(node0, p1);
		int SystemLevel = workload.getSystemLevel();

		Node* next0 = worknode->getnext0_Node();
		Node* next1 = worknode->getnext1_Node(); 
		Node* next2 = worknode->getnext2_Node();
		int WorkNodeID = worknode->getID();
		//cout << "\n" << WorkNodeID << endl;									//Test

		if ((WorkNodeID == 0) && (SystemLevel == 0)) {
			workload.setNodeRoute(WorkNodeID, 1);		//Node writes its ID to Package
			workload.setEdgeRoute(0, 1);				//Connencting Edge writes its ID to Package
			SystemLevel++;
			workload.setSystemLevel(SystemLevel); 
			makerouteOversizePackage(next0, workload); //0->1
		}
		if ((WorkNodeID == 1) && (SystemLevel == 1)) {
			workload.setNodeRoute(WorkNodeID, 1);
			workload.setEdgeRoute(1,1);
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			makerouteOversizePackage(next0, workload); //1->2
		}
		if ((WorkNodeID == 2) && (SystemLevel == 2)) {
			workload.setNodeRoute(WorkNodeID, 1);
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			if (workload.getRegionID() == 1) { workload.setEdgeRoute(2, 1); makerouteOversizePackage(next0, workload); }	//2->3
			if (workload.getRegionID() == 2) { workload.setEdgeRoute(3, 1); makerouteOversizePackage(next1, workload); }	//2->4
			if (workload.getRegionID() == 3) { workload.setEdgeRoute(4, 1); makerouteOversizePackage(next2, workload); }	//2->5
		}if ((WorkNodeID == 3) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}if ((WorkNodeID == 4) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}if ((WorkNodeID == 5) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}


	}

	void makerouteHeavyPackage(Node* worknode, HeavyPackage& workload) {
		///makerouteHeavyPackage(&node0,Hp1);
		int SystemLevel = workload.getSystemLevel();

		Node* next0 = worknode->getnext0_Node();
		Node* next1 = worknode->getnext1_Node();
		Node* next2 = worknode->getnext2_Node();
		int WorkNodeID = worknode->getID();
		//cout << "\n" << WorkNodeID << endl;

		if ((WorkNodeID == 0) && (SystemLevel == 0)) {
			workload.setNodeRoute(WorkNodeID, 1); //Node writes its ID to Package
			workload.setEdgeRoute(0, 1);				//Connencting Edge writes its ID to Package
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			makerouteHeavyPackage(next0, workload); //0->1
		}
		if ((WorkNodeID == 1) && (SystemLevel == 1)) {
			workload.setNodeRoute(WorkNodeID, 1);
			workload.setEdgeRoute(1, 1);
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			makerouteHeavyPackage(next0, workload); //1->2
		}
		if ((WorkNodeID == 2) && (SystemLevel == 2)) {
			workload.setNodeRoute(WorkNodeID, 1);
			SystemLevel++;
			workload.setSystemLevel(SystemLevel);
			if (workload.getRegionID() == 1) { workload.setEdgeRoute(2, 1); makerouteHeavyPackage(next0, workload); }	//2->3
			if (workload.getRegionID() == 2) { workload.setEdgeRoute(3, 1); makerouteHeavyPackage(next1, workload); }	//2->4
			if (workload.getRegionID() == 3) { workload.setEdgeRoute(4, 1); makerouteHeavyPackage(next2, workload); }	//2->5
		}if ((WorkNodeID == 3) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}if ((WorkNodeID == 4) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}if ((WorkNodeID == 5) && (SystemLevel == 3)) {
			workload.setNodeRoute(WorkNodeID, 1);
			if (workload.getNodeRoute(18) == 1) { workload.setNodeRoute(18, 0); }	//New Feature
			workload.setEdgeRoute(0, 1);											//New Feature
			workload.setKezirakodas(true);
			//STOP
		}
	}

	virtual ~Controller() {};
};
#endif // !AIRPORT_PACKAGES_H

/*
           .            .                     .
                  _        .                          .            (
                 (_)        .       .                                     .
  .        ____.--^.
   .      /:  /    |                               +           .         .
         /:  `--=--'   .                                                .
  LS    /: __[\==`-.___          *           .
       /__|\ _~~~~~~   ~~--..__            .             .
       \   \|::::|-----.....___|~--.                                 .
        \ _\_~~~~~-----:|:::______//---...___
    .   [\  \  __  --     \       ~  \_      ~~~===------==-...____
        [============================================================-
        /         __/__   --  /__    --       /____....----''''~~~~      .
  *    /  /   ==           ____....=---='''~~~~ .
      /____....--=-''':~~~~                      .                .
      .       ~--~         Kuat Drive Yard's Imperial-class Star Destroyer
                     .                                   .           .
                          .                      .             +
        .     +              .                                       <=>
                                               .                .      .
   .                 *                 .                *                ` -
   */