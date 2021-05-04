#pragma once
#pragma once
#include<iostream>
using namespace std;
class GifItem;

class PZ {
public:
	int pztype;
	PZ(int i) {
		pztype = i;
	}
	virtual char* getname() = 0;
	virtual char* getStageName() = 0;
	virtual char* diez() = 0;
	virtual void setpos(pair<int, int> p) = 0;
	virtual int getHP() = 0;
	virtual int getATN() = 0;
	virtual int gettype() { return pztype; }
	virtual int getplantstype() { return 0; }
	virtual int getwaittime() { return 0; }
	virtual bool havestage() { return true; }
	virtual int getoriginalHP() { return 0; }
	virtual double getSPD() { return 0.0; }
	virtual void setSPD(double a) {}
	virtual void setwaittime(int i) {}
	virtual void changeSPD(int i) {}
	virtual void beattacked(int i) {}
	virtual int attack() { return 0; }
	virtual int getCD() { return 0; }
	virtual int effect() { return 0; }
	virtual GifItem *getitem() { return nullptr; }
	virtual int getgiftype() { return 0; }
	virtual void backitem() {}
};

