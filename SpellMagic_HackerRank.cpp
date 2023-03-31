#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
//#include <stdio.h>
//#include <cstring>
//#include <cstdarg>
//#include <ctime>
//#include <chrono>
//#include <cstring>
//#include <climits>     // The maximum and minimum size of integral values
//#include <conio.h>     // For getch() and putch()
//#include <sstream>
#include <cmath>
//#include <windows.h>
//#include <fstream>
//#include <typeinfo>
#include <algorithm>
#include <iterator>
//#include <utility>
#include <vector>
//#include <map>
//#include <set>
//#include <bitset>
//#include <queue>
//using namespace std::chrono;
//#include <exception>
//#include <stdexcept>
using namespace std;

class Spell
{
private:
    string scrollName;
public:
    Spell(const string& name = ""): scrollName(name) {}
    virtual ~Spell() {}
    const string& revealScrollName() const
    {
        return scrollName;
    }
};

class Fireball : public Spell
{
private:
    int power;
public:
    Fireball(int power): power(power) {}
    void revealFirepower() const
      {
        cout << "Fireball: " << power << endl;
      }
};

class Frostbite : public Spell
{
private:
    int power;
public:
    Frostbite(int power): power(power) {}
    void revealFrostpower() const
      {
        cout << "Frostbite: " << power << endl;
      }
};

class Thunderstorm : public Spell
{
private:
    int power;
public:
    Thunderstorm(int power): power(power) {}
    void revealThunderpower() const
      {
        cout << "Thunderstorm: " << power << endl;
      }
};

class Waterbolt : public Spell
{
private:
    int power;
public:
    Waterbolt(int power): power(power) {}
    void revealWaterpower() const
    {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal
{
public:
    static string journal;
    static string read()
    {
        return journal;
    }
};

string SpellJournal::journal = "";

void counterspell(Spell *spell)
{
   if (typeid(*spell)  == typeid(Fireball))
    {
       Fireball *f = dynamic_cast<Fireball*>(spell);
       f->revealFirepower();
    }
   else if (typeid(*spell)  == typeid(Frostbite))
    {
        Frostbite *f = dynamic_cast<Frostbite*>(spell);
        f->revealFrostpower();
    }
   else if (typeid(*spell)  == typeid(Waterbolt))
    {
        Waterbolt *f = dynamic_cast<Waterbolt*>(spell);
        f->revealWaterpower();
    }
   else if (typeid(*spell)  == typeid(Thunderstorm))
    {
        Thunderstorm *f = dynamic_cast<Thunderstorm*>(spell);
        f->revealThunderpower();
    }
   else
   {
       string strA = spell->revealScrollName();
       string strB = SpellJournal::read();

       int m = strA.length();
       int n = strB.length();

       vector<vector<int>> vLCSMatrix(m + 1, vector<int>(n + 1));

       for (int i = 1; i <= m; i++)
       {
           for (int j = 1; j <= n; j++)
           {
               if (strA[i - 1] == strB[j - 1])
               {
                   vLCSMatrix[i][j] = 1 + vLCSMatrix[i - 1][j - 1];
               }
               else
               {
                   vLCSMatrix[i][j] = std::max(vLCSMatrix[i - 1][j], vLCSMatrix[i][j - 1]);
               }
           }
       }
       cout << vLCSMatrix[m][n] << std::endl;
   }
}

class Wizard
{
public:
    Spell *cast()
    {
        Spell *spell;
        string s; cin >> s;
        int power; cin >> power;
        if(s == "fire") {
            spell = new Fireball(power);
        }
        else if(s == "frost") {
            spell = new Frostbite(power);
        }
        else if(s == "water") {
            spell = new Waterbolt(power);
        }
        else if(s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main()
{
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--)
    {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
