#include"StateMachine.h"

int main()
{
	StateMachine* s = new StateMachine;
	s->payFailed();
	cout << "State: " << s->getState() << endl;
	cout << "\n-----------\n";

	s->paySuccess();
	cout << "State: " << s->getState() << endl;
	s->payFailed();
	cout << "State: " << s->getState() << endl;
	cout << "\n-----------\n";

	s->paySuccess();
	cout << "State: " << s->getState() << endl;
	s->paySuccess();
	cout << "State: " << s->getState() << endl;
	s->receiveProduct();
	cout << "State: " << s->getState() << endl;
	cout << "\n-----------\n";
}