#include "Pipe.h"
#include "Manager.h"
#include <iostream>
#include <thread>

using namespace std;

void runGraphics()
{
	
//	system("d:\\users\\user-pc\\desktop\\e.exe.lnk");
		

}
int main()
{
//	srand(time_t(NULL));
//
//	thread t(runGraphics);
//	t.detach();
//	Sleep(1000);
//
//	Pipe p;
//	bool isConnect = p.connect();
//
//	string ans;
//	while (!isConnect)
//	{
//		cout << "cant connect to graphics" << endl;
//		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
//		cin >> ans;
//
//		if (ans == "0")
//		{
//			cout << "trying connect again.." << endl;
//			Sleep(5000);
//			isConnect = p.connect();
//		}
//		else
//		{
//			p.close();
//			return 0;
//		}
//	}

//	Manager mgr(p);
//
//	mgr.playGame();
//
//	p.close();

    Player* whitepl = new Player(true);
    Player* blackpl = new Player(false);
    Board* B = new Board(whitepl,blackpl);
    B->print();




//    if (B->tryMove(7, 0, 7, 1))
//    {
//        B->Move(7, 0, 7, 1);
//        B->print();
//    }
    cout << " " << endl;

	return 0;


                                                            ///Knight check
    if (B->tryMove(0,1,2,0)) {
        B->Move(0, 1, 2, 0);
    }
    cout << " " << endl;
    B->print();
    if (B->tryMove(2,0,3,2)) {
        B->Move(2, 0, 3, 2);
    }
    cout << " " << endl;
    B->print();
    if (B->tryMove(3,2,5,1)) {
        B->Move(3, 2, 5, 1);
    }
    cout << " " << endl;
    B->print();
    if (B->tryMove(5,1,7,2)) {
        B->Move(5, 1, 7, 2);
    }
    cout << " " << endl;
    B->print();


                                                            // bishop check
    if (B->tryMove(0,2,5,7)) {
        B->Move(0, 2, 5, 7);
        cout << " " << endl;
        B->print();
    }
    if (B->tryMove(5,7,7,5)) {
        B->Move(5, 7, 7, 5);
        cout << " " << endl;
        B->print();
    }
    if (B->tryMove(7,0,6,0)) {
        B->Move(7, 0, 6, 0);
        B->Move(6, 0, 6, 4);
        cout << " " << endl;
        B->print();
    }
}