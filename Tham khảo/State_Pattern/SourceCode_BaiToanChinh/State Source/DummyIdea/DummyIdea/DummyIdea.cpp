#include"Header.h"

int main()
{
	DummyState* s = new DummyState;
	s->payFailed();
	cout << "State: " << s->getState() << endl;
	cout << "\n-----------\n";

	s->payFailed();
	s->receiveProduct();
	cout << "State: " << s->getState() << endl;
	cout << "\n-----------\n";

	s->paySuccess();
	s->receiveProduct();
	cout << "State: " << s->getState() << endl;
	cout << "\n-----------\n";

	s->paySuccess();
	s->paySuccess();
	s->receiveProduct();
	cout << "State: " << s->getState() << endl;
	cout << "\n-----------\n";

}