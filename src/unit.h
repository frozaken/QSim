#include "statframe.h"
#include <string>
#include "action.h"
#include <list>

using namespace std;

class Unit{
private:
    Statframe stats;
    int is_target_fixed;
    static Unit* DeadTarget;
public:
    Unit* Target;
    string Name;
    Unit();
    //Unit(Stattemplate);
    Unit(string);
    friend ostream& operator << (ostream &stream, const Unit &unt);
    void ProgressTime(double timedelta);
    Action* GetAction();
    void SetFixedTarget( Unit* );
    void PickTarget(list< Unit* >);
}; 