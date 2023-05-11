#pragma once

//using state design pattern
#include<iostream>
#include<random>
using namespace std;

//Tạo interface cho các state: IState
//Mỗi state obj đều cần phải có các methods: getForm, checkForm, rentApplication, dispenseKeys
class IState
{
public:
	virtual void getForm() = 0; //nhận form
	virtual void checkForm() = 0;//kiểm form
	virtual void rentApartment() = 0;//thuê căn hộ
	virtual void dispenseKeys() = 0;//nhận chìa khóa
};

//Tạo interface cho rental Robot
class IRentalRobot {
public:
	virtual void getForm() = 0;
	virtual void checkForm() = 0;
	//hàm set, get để change state cho robot
	virtual void setState(IState* state) = 0;
	virtual IState* getState() = 0;
	virtual IState* getWaitingState() = 0;
	virtual IState* getReceivingFormState() = 0;
	virtual IState* getRentApartmentState() = 0;
	virtual IState* getFullyRentedState() = 0;
	//kiểm tra còn căn hộ trống không, vì vậy cần thêm hàm getCount, setCount
	//đểm số lượng căn hộ trống
	virtual int getCount() = 0;
	virtual void setCount(int count) = 0;
};

//Implement cho các class State
//Trạng thái chờ
class WaitingState :public IState {
private:
	IRentalRobot* mRobot;
public:
	//contructor
	WaitingState(IRentalRobot* robot)
	{
		mRobot = robot;
	}
	//override các method từ interface IState
	void getForm()
	{
		//nếu form được gửi sẽ chuyển đến trạng thái receiving form
		mRobot->setState(mRobot->getReceivingFormState());
		cout << "Thanks for the form." << endl;
	}
	//không thể kiểm tra form, thuê căn hộ, nhận chìa khóa khi chưa nhận form thành công
	void checkForm()
	{
		cout << "You have to submit an form." << endl;
	}
	void rentApartment()
	{
		cout << "You have to submit an form." << endl;
	}
	void dispenseKeys()
	{
		cout << "You have to submit an form." << endl;
	}
};

//recivingForm state
//trạng thái đang nhận from đăng kí
class ReceivingFormState :public IState {
private:
	IRentalRobot* mRobot;
	std::random_device mRandomGenerator;
public:
	//contructor
	ReceivingFormState(IRentalRobot* robot)
	{
		mRobot = robot;
	}

	//overide
	//đã nhận được form từ trạng thái chờ
	void getForm()
	{
		cout << "We already got your application." << endl;
	}

	//kiểm tra form đăng kí
	void checkForm()
	{
		// simulate the form checking
		std::uniform_int_distribution<int> int_distribution(0, 9);
		bool isFormOk = (int_distribution(mRandomGenerator) > 5);

		//nếu form đăng kí phù hợp và còn căn hộ thì chuyển đến trạng thái thuê căn hộ
		if (isFormOk && mRobot->getCount() > 0) {
			cout << "Congratulations, you were approved." << endl;
			mRobot->setState(mRobot->getRentApartmentState());
			mRobot->getState()->rentApartment();
		}//còn không sẽ quay về trạng thái chờ 
		else {
			mRobot->setState(mRobot->getWaitingState());
			cout << "Sorry, you were not approved." << endl;
		}
	}

	//không thể thuê căn hộ và nhận chìa khóa khi chưa kiểm tra form
	void rentApartment()
	{
		cout << "You must have your application checked." << endl;
	}

	void dispenseKeys()
	{
		cout << "You must have your application checked." << endl;
	}
};

//rentApartment state
//Trạng thái tiến hành cho thuê 1 căn hộ
class RentApartmentState : public IState
{
private:
	IRentalRobot* mRobot;
public:
	//contructor
	RentApartmentState(IRentalRobot* robot)
	{
		mRobot = robot;
	}

	//đã kiểm tra form từ trạng thái nhận
	void getForm()
	{
		cout << "Hang on, we’re renting you an apartment." << endl;
	}

	void checkForm()
	{
		cout << "Hang on, we’re renting you an apartment." << endl;
	}

	//thuê -> thì số căn hộ giảm đi 1
	void rentApartment()
	{
		mRobot->setCount(mRobot->getCount() - 1);
		cout << "Renting you an apartment...." << endl;
		dispenseKeys();//nhận chia khóa
	}

	void dispenseKeys()
	{
		//nếu số phòng > 0
		if (mRobot->getCount() > 0) {
			//thì quay về trang thài chờ
			mRobot->setState(mRobot->getWaitingState());
		}
		else {
			//ngược lại đến trạng thái đã full căn hộ thuê
			mRobot->setState(mRobot->getFullyRentedState());
		}
		cout << "Here are your keys!" << endl;
	}
};

//FullyRented state
//Trạng thái đã full căn hộ
class FullyRentedState : public IState
{
private:
	IRentalRobot* mRobot;
public:
	//contructor
	FullyRentedState(IRentalRobot* robot)
	{
		mRobot = robot;
	}

	//thuê căn hộ nhưng căn hộ đã đầy
	void getForm()
	{
		cout << "Sorry, we’re fully rented." << endl;
	}

	void checkForm()
	{
		cout << "Sorry, we’re fully rented." << endl;
	}

	void rentApartment()
	{
		cout << "Sorry, we’re fully rented." << endl;
	}

	void dispenseKeys()
	{
		cout << "Sorry, we’re fully rented." << endl;
	}
};


//implement class RentalRobot
class RentalRobot : public IRentalRobot
{
private:
	//gồm các trạng thái (trạng thái hiện tại, chờ, nhận, thuê, đầy)
	IState* mCurentState;

	IState* mWaitingState;
	IState* mReceivingFormState;
	IState* mRentApartmentState;
	IState* mFullyRentedState;
	//số phòng còn trống
	int mCount;
public:
	//contructor: khởi tạo với số căn hộ mặc định
	RentalRobot(int count)
	{
		mCount = count;
		//new ra các trạng thái của robot
		mWaitingState = new WaitingState(this);
		mReceivingFormState = new ReceivingFormState(this);
		mRentApartmentState = new RentApartmentState(this);
		mFullyRentedState = new FullyRentedState(this);
		mCurentState = mWaitingState; //trạng thái ban đầu là trạng thái chờ
	}
	//detructor
	~RentalRobot()
	{
		if (mWaitingState != nullptr) {
			delete mWaitingState;
			mWaitingState = nullptr;
		}

		if (mReceivingFormState != nullptr) {
			delete mReceivingFormState;
			mReceivingFormState = nullptr;
		}

		if (mRentApartmentState != nullptr) {
			delete mRentApartmentState;
			mRentApartmentState = nullptr;
		}

		if (mFullyRentedState != nullptr) {
			delete mFullyRentedState;
			mFullyRentedState = nullptr;
		}

		mCurentState = nullptr;
	}

	//các method nhận, kiểm tra, thuê của trạng thái hiện tại
	void getForm()
	{
		mCurentState->getForm();
	}

	void checkForm()
	{
		mCurentState->checkForm();
	}

	void rentApartment()
	{
		mCurentState->rentApartment();
	}
	//set trạng thái hiện tại
	void setState(IState* state)
	{
		mCurentState = state;
	}

	//get trạng thái hiện tại
	IState* getState()
	{
		return mCurentState;
	}

	//get các trạng thái chờ, nhận, thuê, đầy của robot
	IState* getWaitingState()
	{
		return mWaitingState;
	}

	IState* getReceivingFormState()
	{
		return mReceivingFormState;
	}

	IState* getRentApartmentState()
	{
		return mRentApartmentState;
	}

	IState* getFullyRentedState()
	{
		return mFullyRentedState;
	}

	//lấy ra số căn hộ còn tróng
	int getCount()
	{
		return mCount;
	}

	//set số căn hộ còn trống
	void setCount(int count)
	{
		mCount = count;
	}
};


