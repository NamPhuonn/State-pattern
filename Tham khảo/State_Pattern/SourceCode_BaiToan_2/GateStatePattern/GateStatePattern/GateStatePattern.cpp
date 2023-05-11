
#include "Gate.h"


int main()
{
    Gate DormitoryGate;
    cout << "State of Gate: " << DormitoryGate.GateName() << endl;
    DormitoryGate.Enter();
    DormitoryGate.CheckIDSuccessed();
    DormitoryGate.SwipingCard();

    cout << "\nState of Gate: " << DormitoryGate.GateName() << endl;
    DormitoryGate.Enter();
    DormitoryGate.CheckIDFailed();
    DormitoryGate.Enter();

    cout << "\nState of Gate: " << DormitoryGate.GateName() << endl;
    DormitoryGate.SwipingCard();
    DormitoryGate.CheckIDSuccessed();
    DormitoryGate.SwipingCard();

    cout << "\nState of Gate: " << DormitoryGate.GateName() << endl;
    DormitoryGate.Enter();
    DormitoryGate.Enter();

    return 0;
}

