#pragma once
#include<iostream>
#include <random>
using namespace std;
//Bài toán cho thuê phòng khách sạn, nhà nghỉ
class State
{
public:
    virtual void getForm() = 0;//Nhận form đăng ký thuê phòng
    virtual void checkForm() = 0;//Kiểm tra form
    virtual void rentRoom() = 0;//Tiến hành cho thuê phòng
    virtual void dispenseKeys() = 0;//Phát chìa khóa
};

class IRentalRoom {
public:
    virtual void getForm() = 0;
    virtual void checkForm() = 0;
    virtual void setState(State* state) = 0;
    virtual State* getState() = 0;
    virtual State* getWaiting() = 0;
    virtual State* getReceivingForm() = 0;
    virtual State* getRentRoom() = 0;
    virtual State* getFully() = 0;
    virtual int getNumberRooms() = 0;
    virtual void setNumberRooms(int numberOfRooms) = 0;

};
class RentalRoom : public IRentalRoom
{
private:
    State* mCurent;        //State hiện tại
    State* mWaiting;       //State waiting
    State* mReceivingForm; //State nhận form
    State* mRentRoom;      //State cho thuê phòng
    State* mFully;         //State hết phòng
    int numberRooms;       //Số lượng phòng 

public:
    RentalRoom(int numberOfRooms);
    ~RentalRoom();
    void getForm();
    void checkForm();
    void rentRoom();
    void dispenseKeys();
    State* getState();
    void setState(State* state);
    State* getWaiting();
    State* getReceivingForm();
    State* getRentRoom();
    State* getFully();
    int getNumberRooms();
    void setNumberRooms(int numberOfRooms);
};
class WaitingState : public State
{
private:
    IRentalRoom* mRoom;

public:
    WaitingState(IRentalRoom* Room);
    void getForm();
    void checkForm();
    void rentRoom();
    void dispenseKeys();
};

class ReceivingFormState : public State
{
private:
    IRentalRoom* mRoom;
    random_device illustrate; //Biến minh họa dùng cho hàm checkForm

public:
    ReceivingFormState(IRentalRoom* Room);
    void getForm();
    void checkForm();
    void rentRoom();
    void dispenseKeys();
};

class RentRoomState : public State
{
private:
    IRentalRoom* mRoom;

public:
    RentRoomState(IRentalRoom* Room);
    void getForm();
    void checkForm();
    void rentRoom();
    void dispenseKeys();

};

class FullyState : public State
{
private:
    IRentalRoom* mRoom;

public:
    FullyState(IRentalRoom* Room);
    void getForm();
    void checkForm();
    void rentRoom();
    void dispenseKeys();
};
