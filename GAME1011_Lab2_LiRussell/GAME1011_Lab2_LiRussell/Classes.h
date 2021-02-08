#pragma once
#include <string>
#include <iostream>
using namespace std;

// Weapon class
class Weapon
{
public:
	string wname;
	string description;
	int damage;
	string ability[3];
	int id;
public:
	// Default constructor
	Weapon()
	{
		SetWName("BYUG^&YHF^%&*(I");
		SetWDes("none");
		SetWDam(0);
		SetWId(0);
		for (int i = 0; i < 3; i++)
		{
			ability[i] = "none";
		}
	}
	Weapon(int wId,string weaponName, string d, int wd, string ab[])
	{
		SetWId(wId);
		SetWName(weaponName);
		SetWDes(d);
		SetWDam(wd);
		for (int i = 0; i < 3; i++)
		{
			ability[i] = ab[i];
		}
	}
	string WeaponInfo()
	{
		string wares = "\nWeapon ID Number ===> " + to_string(GetWId());
		wares += "\nWeapon Name ========> " + GetWName();
		wares += "\nWeapon Description ========> " + GetWDes();
		wares += "\nWeapon Damage ========> " + to_string(GetWDam());
		for (int i = 0; i < 3; i++)
		{
			wares += "\nWeapon Ability =======> " + ability[i] + "\n";
		}
		wares += "\n";
		return wares;
	}

	// Getters and Setters
	void SetWName(string n)
	{
		this->wname = n;
	}
	virtual string GetWName() const
	{
		return wname;
	}

	void SetWId(int i)
	{
		this->id = i;
	}
	virtual int GetWId() const
	{
		return id;
	}

	void SetWDes(string d)
	{
		this->description = d;
	}
	virtual string GetWDes() const
	{
		return description;
	}

	void SetWDam(int da)
	{
		this->damage = da;
	}
	virtual int GetWDam() const
	{
		return damage;
	}
};

// Character class
class Character
{
protected:
	string name;
	int health;
	Weapon weap;
public:
	virtual void DisplayInfo() const = 0; // Pure virtual function
	// Default constructor
	Character()
	{
		SetCName("JOHUR^%hng76&Y");
		SetCHealth(0);
		weap.id = 0;
		weap.wname = "Nyug7&*Hre4$%E456";
		weap.description = "Plain old fists";
		weap.damage = 1;
		for (int i = 0; i < 3; i++)
		{
			weap.ability[i] = "Nothing";
		}

	}
	Character(string n, int h, Weapon w)
	{
		SetCName(n);
		SetCHealth(h);
		weap.id = w.id;
		weap.wname = w.wname;
		weap.description = w.description;
		weap.damage = w.damage;
		for (int i = 0; i < 3; i++)
		{
			weap.ability[i] = w.ability[i];
		}
	}

	// Getters and Setters
	void SetCName(string n)
	{
		this->name = n;
	}
	virtual string GetCName() const
	{
		return name;
	}

	void SetCHealth(int h)
	{
		this->health = h;
	}
	virtual int GetCHealth() const
	{
		return health;
	}
};

// Human class
class Human : public Character
{
protected:
	string songName;
	Weapon h_Weap;
public:
	// Default constructor
	Human()
	{
		SetSong("FTFD%^G&Hr543e546VG");
		h_Weap.SetWId(0);
		h_Weap.SetWName("None");
		h_Weap.SetWDes("None");
		h_Weap.SetWDam(0);
		for (int i = 0; i < 3; i++)
		{
			h_Weap.ability[i] = "none";
		}
	}

	Human(string n, int h, Weapon w, string sn) : Character(n, h, w)
	{
		SetSong(sn);
		h_Weap.SetWId(w.GetWId());
		h_Weap.SetWName(w.GetWName());
		h_Weap.SetWDes(w.GetWDes());
		h_Weap.SetWDam(w.GetWDam());
		for (int i = 0; i < 3; i++)
		{
			h_Weap.ability[i] = w.ability[i];
		}
	}

	// Getters and Setters
	void SetSong(string s)
	{
		this->songName = s;
	}
	virtual string GetSong() const
	{
		return songName;
	}

	virtual void DisplayInfo() const
	{
		string wares = "\n\nName: " + GetCName();
		wares += "\nSinger of " + GetSong();
		wares += "\nHealth: " + to_string(GetCHealth());
		wares += "\nWeapon: " + h_Weap.GetWName();
		wares += "\n";
		cout << wares;
	}
};

// Bearman class
class Bearman : public Character
{
protected:
	string preName;
	Weapon b_Weap;
public:
	// Default constructor
	Bearman()
	{
		SetpreN("78y76TGTYGUBUH5");
		b_Weap.SetWId(0);
		b_Weap.SetWName("None");
		b_Weap.SetWDes("None");
		b_Weap.SetWDam(0);
		for (int i = 0; i < 3; i++)
		{
			b_Weap.ability[i] = "none";
		}
	}
	Bearman(string n, int h, Weapon w, string pn) : Character(n, h, w)
	{
		SetpreN(pn);
		b_Weap.SetWId(w.GetWId());
		b_Weap.SetWName(w.GetWName());
		b_Weap.SetWDes(w.GetWDes());
		b_Weap.SetWDam(w.GetWDam());
		for (int i = 0; i < 3; i++)
		{
			b_Weap.ability[i] = w.ability[i];
		}
	}

	// Getters and Setters
	void SetpreN(string p)
	{
		this->preName = p;
	}
	virtual string GetpreN() const
	{
		return preName;
	}

	virtual void DisplayInfo() const
	{
		string wares = "\n\nName: '" + GetpreN() + "' " + GetCName();
		wares += "\nHealth: " + to_string(GetCHealth());
		wares += "\nWeapon: " + b_Weap.GetWName();
		wares += "\n";
		cout << wares;
	}
};

// Xada class
class Xada : public Character 
{
protected:
	int hpMod;
	Weapon x_Weap;
public:
	// Default constructor
	Xada()
	{
		SetMod(0);
		x_Weap.SetWId(0);
		x_Weap.SetWName("None");
		x_Weap.SetWDes("None");
		x_Weap.SetWDam(0);
		for (int i = 0; i < 3; i++)
		{
			x_Weap.ability[i] = "none";
		}
	}
	Xada(string n, int h, Weapon w, int pn) : Character(n, h, w)
	{
		SetMod(pn);
		x_Weap.SetWId(w.GetWId());
		x_Weap.SetWName(w.GetWName());
		x_Weap.SetWDes(w.GetWDes());
		x_Weap.SetWDam(w.GetWDam());
		for (int i = 0; i < 3; i++)
		{
			x_Weap.ability[i] = w.ability[i];
		}
	}

	// Getters and Setters
	void SetMod(int p)
	{
		this->hpMod = p;
	}
	virtual int GetMod() const
	{
		return hpMod;
	}

	virtual void DisplayInfo() const
	{
		string wares = "\n\nName: "+ GetCName();
		wares += "\nHealth: " + to_string(GetCHealth());
		wares += "\nHP Mod: +" + to_string(GetMod());
		wares += "\nWeapon: " + x_Weap.GetWName();
		wares += "\n";
		cout << wares;
	}
};