#pragma once
class Automobil
{
public:
	void vozi();
	void skreni(int); // skreni prima kut skretanja, -0 do -100 je lijevo, 0 do 180 je desno
	void koci();
	void upali_motor();
};


// funkcije za pozvat kroz klasu idu na public a ostalo private