#ifndef AIRPORT_PACKAGES_TEST_CPP
#define AIRPORT_PACKAGES_TEST_CPP
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
#include <iostream>
#include <sstream>
#include <clocale>
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#include <windows.h>
#endif

#include "memtrace.h"     // After standard headers
#include "gtest_lite.h"
#include "airport_packages.h"

using namespace std;

int main() {
	GTINIT(std::cin);       // Required for C(J)PORTA 

	//System Buildup Declaration
	Controller maincontroller(123456);			///ID=123456

	Node node0(0, NULL, NULL, NULL,"N/A");		///BUD-Input
	Node node1(1, NULL, NULL, NULL,"N/A");		///OverSize/Heavy || Normal
	Node node2(2, NULL, NULL, NULL,"N/A");		///OverSize/Heavy
	Node node3(3, NULL, NULL, NULL,"N/A");			///Europe
	Node node4(4, NULL, NULL, NULL,"N/A");			///Asia
	Node node5(5, NULL, NULL, NULL,"N/A");			///Nort-America
	Node node6(6, NULL, NULL, NULL,"N/A");		///Normal
	Node node7(7, NULL, NULL, NULL,"N/A");			///Europe
	Node node8(8, NULL, NULL, NULL,"CDG");				///Paris - CDG
	Node node9(9, NULL, NULL, NULL,"FCO");				///Rome	- FCO
	Node node10(10, NULL, NULL, NULL,"LHR");			///London-Heathrow - LHR
	Node node11(11, NULL, NULL, NULL,"N/A");		///Asia
	Node node12(12, NULL, NULL, NULL,"HKG");			///Honkong	- HKG
	Node node13(13, NULL, NULL, NULL,"PEK");			///Beijing	- PEK
	Node node14(14, NULL, NULL, NULL,"SVO");			///Moscow	- SVO
	Node node15(15, NULL, NULL, NULL,"N/A");		///North-America
	Node node16(16, NULL, NULL, NULL,"YUL");			///Montreal	- YUL
	Node node17(17, NULL, NULL, NULL,"YFK");			///New York	- JFK
	Node node18(18, NULL, NULL, NULL,"LAX");			///Los Angeles	- LAX

	//Rebuilding Network with declarated varibles int Top-Down Architecture
	node0.setnextNode(&node1, NULL, NULL);
	node1.setnextNode(&node2, &node6, NULL);
	node2.setnextNode(&node3, &node4, &node5);
	node3.setnextNode(NULL, NULL, NULL);
	node4.setnextNode(NULL, NULL, NULL);
	node5.setnextNode(NULL, NULL, NULL);
	node6.setnextNode(&node7, &node11, &node15);
	node7.setnextNode(&node8, &node9, &node10);
	node8.setnextNode(NULL, NULL, NULL);
	node9.setnextNode(NULL, NULL, NULL);
	node10.setnextNode(NULL, NULL, NULL);
	node11.setnextNode(&node12, &node13, &node14);
	node12.setnextNode(NULL, NULL, NULL);
	node13.setnextNode(NULL, NULL, NULL);
	node14.setnextNode(NULL, NULL, NULL);
	node15.setnextNode(&node16, &node17, &node18);
	node16.setnextNode(NULL, NULL, NULL);
	node17.setnextNode(NULL, NULL, NULL);
	node18.setnextNode(NULL, NULL, NULL);

	TEST(Package,correct) {
		Package p1(123, 0, 0, 0, 0, "BUD", "CDG", 50.0, 50.0, 40.0, 15.0, false);
		if (p1.isgoodPackage(p1)) {
			cout << "\nCorrect Input" << endl;
			maincontroller.generateTID_Package(p1);
			int a = p1.getTypeID();
			int b = p1.getRegionID();
			int c = p1.getAirportID();
			cout << "\n TypeID " << a << endl;
			cout << "\n RegionID " << b << endl;
			cout << "\n AirportID " << c << endl;

			maincontroller.makeroutePackage(&node0, p1);

			for (int i = 0; i < 19; i++) {
				int g = p1.getNodeRoute(i);
				int h = p1.getEdgeRoute(i);
				cout << "\n" << i << ". " << g << " " << h << endl;
			}
			if (p1.getKezirakodas()) { SUCCEED() << "\nEND" << endl; };
		}
		if (!p1.isgoodPackage(p1)) {
			FAIL() << "\nWrong Input" << endl;
		}
	}ENDM

	TEST(HeavyPackage, correct) {
		HeavyPackage Hp1(100, 150, 70, 50, "JFK");
		Hp1.setHeight(Hp1.getHPHeight());
		Hp1.setLength(Hp1.getHPLength());
		Hp1.setWidth(Hp1.getHPWidth());
		Hp1.setWeight(Hp1.getHPWeight());

		if (Hp1.isgoodHeavyPackage(Hp1)) {
			cout << "\nCorrect Input" << endl;
			maincontroller.generateTID_HeavyPackage(Hp1);
			int a = Hp1.getTypeID();
			int b = Hp1.getRegionID();
			int c = Hp1.getAirportID();
			cout << "\n TypeID " << a << endl;
			cout << "\n RegionID " << b << endl;
			cout << "\n AirportID " << c << endl;

			maincontroller.makerouteHeavyPackage(&node0, Hp1);

			for (int i = 0; i < 19; i++) {
				int g = Hp1.getNodeRoute(i);
				int h = Hp1.getEdgeRoute(i);
				cout << "\n" << i << ". " << g << " " << h << endl;
			}
			SUCCEED() << "\nEND" << endl;
			if (!Hp1.isgoodHeavyPackage(Hp1)) {
				FAIL() << "\nWrong Input" << endl;
			}
		}
	} ENDM;

	TEST(OverSizePackage, correct) {
		OversizePackage OSp1(150.0, 100.0, 50.0, 40.0, "LAX");
		OSp1.setHeight(OSp1.getOSHeight());
		OSp1.setLength(OSp1.getOSLength());
		OSp1.setWidth(OSp1.getOSWidth());
		OSp1.setWeight(OSp1.getOSWeight());

		if (OSp1.isgoodOversizePackage(OSp1)) {
			cout << "\nCorrect Input" << endl;
			maincontroller.generateTID_OversizePackage(OSp1);
			int a = OSp1.getTypeID();
			int b = OSp1.getRegionID();
			int c = OSp1.getAirportID();
			cout << "\n TypeID " << a << endl;
			cout << "\n RegionID " << b << endl;
			cout << "\n AirportID " << c << endl;

			maincontroller.makerouteOversizePackage(&node0, OSp1);

			for (int i = 0; i < 19; i++) {
				int g = OSp1.getNodeRoute(i);
				int h = OSp1.getEdgeRoute(i);
				cout << "\n" << i << ". " << g << " " << h << endl;
			}
			SUCCEED() << "\nEND" << endl;
		}
		if (!OSp1.isgoodOversizePackage(OSp1)) {
			FAIL() << "\nWrong Input" << endl;
		}
	}ENDM;

	TEST(CarryOnPackage, correct) {
		CarryOnPackage COp1(40, 40, 45, 5, "PEK");
		COp1.setHeight(COp1.getCOPHeight());
		COp1.setLength(COp1.getCOPLength());
		COp1.setWidth(COp1.getCOPWidth());
		COp1.setWeight(COp1.getCOPWeight());
		///
		if (COp1.isgoodCarryonPackage(COp1)) {
			cout << "\nCorrect Input" << endl;
			maincontroller.generateTID_CarryOnPackage(COp1);
			maincontroller.makerouteCarryOnPackage(&node0, COp1);
			SUCCEED() << "\nEND" << endl;
		}
		if (!COp1.isgoodCarryonPackage(COp1)) {
			FAIL() << "\nWrong Input" << endl;
		}
	}ENDM;

	TEST(Package, incorrect){
		Package p1(123, 0, 0, 0, 0, "BUD", "CDG", 50.0, 50.0, 40.0, 15.0, false); //2000->50 to correct ERROR || 50->2000 to make ERROR
		if (p1.isgoodPackage(p1)) {
			cout << "\nCorrect Input" << endl;
			maincontroller.generateTID_Package(p1);
			int a = p1.getTypeID();
			int b = p1.getRegionID();
			int c = p1.getAirportID();
			cout << "\n TypeID " << a << endl;
			cout << "\n RegionID " << b << endl;
			cout << "\n AirportID " << c << endl;

			maincontroller.makeroutePackage(&node0, p1);

			for (int i = 0; i < 19; i++) {
				int g = p1.getNodeRoute(i);
				int h = p1.getEdgeRoute(i);
				cout << "\n" << i << ". " << g << " " << h << endl;
			}
			if (p1.getKezirakodas()) { SUCCEED() << "\nEND" << endl; };
		}
		if (!p1.isgoodPackage(p1)) {
			FAIL() << "\nWrong Input" << endl;
		}
	}ENDM;

	if (gtest_lite::test.fail())
		FAIL() << "\n gtest_lite ERROR!" << std::endl;
	if(!gtest_lite::test.fail())
		std::cout << "\n Test Finished Without any Error" << std::endl;


	GTEND(std::cerr);       // Required for C(J)PORTA 
	return 0;
}
#endif // !AIRPORT_PACKAGES_TEST_CPP

/*
_____________________                              _____________________
`-._:  .:'   `:::  .:\           |\__/|           /::  .:'   `:::  .:.-'
    \      :          \          |:   |          /         :       /    
     \     ::    .     `-_______/ ::   \_______-'   .      ::   . /      
      |  :   :: ::'  :   :: ::'  :   :: ::'      :: ::'  :   :: :|       
      |     ;::         ;::         ;::         ;::         ;::  |       
      |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|       
      /     :           :           :           :           :    \       
     /______::_____     ::    .     ::    .     ::   _____._::____\      
                   `----._:: ::'  :   :: ::'  _.----'                    
                          `--.       ;::  .--'                           
                              `-. .:'  .-'                               
                                 \    / :F_P:                            
                                  \  /                                   
                                   \/ 
*/