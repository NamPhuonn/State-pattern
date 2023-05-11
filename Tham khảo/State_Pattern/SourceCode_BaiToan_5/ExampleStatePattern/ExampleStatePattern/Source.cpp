#include"Header.h"
RentalRoom::RentalRoom(int numberOfRooms) {
        numberRooms = numberOfRooms;
        mWaiting = new WaitingState(this);
        mReceivingForm = new ReceivingFormState(this);
        mRentRoom= new RentRoomState(this);
        mFully= new FullyState(this);
        mCurent = mWaiting;
}
RentalRoom::~RentalRoom()
{
    if (mWaiting!= NULL) {
        delete mWaiting;
        mWaiting = NULL;
    }

    if (mReceivingForm != NULL) {
        delete mReceivingForm;
        mReceivingForm = NULL;
    }

    if (mRentRoom != NULL) {
        delete mRentRoom;
        mRentRoom= NULL;
    }

    if (mFully!= NULL) {
        delete mFully;
        mFully = NULL;
    }
    mCurent = NULL;
}

void RentalRoom::getForm()
{
    mCurent->getForm();
}

void RentalRoom::checkForm()
{
    mCurent->checkForm();
}

State* RentalRoom::getState()
{
    return mCurent;
}
void RentalRoom::setState(State* state)
{
    mCurent = state;
}

void RentalRoom::rentRoom(){
    mCurent->rentRoom();
}
void RentalRoom::dispenseKeys(){
    mCurent->dispenseKeys();
}

State* RentalRoom::getWaiting()
{
    return mWaiting;
}

State* RentalRoom::getReceivingForm()
{
    return mReceivingForm;
}

State* RentalRoom::getRentRoom()
{
    return mRentRoom;
}

State* RentalRoom::getFully()
{
    return mFully;
}

int RentalRoom::getNumberRooms()
{
    return numberRooms;
}

void RentalRoom::setNumberRooms(int numberOfRooms)
{
    numberRooms = numberOfRooms;
}
WaitingState::WaitingState(IRentalRoom* Room)
{
    mRoom = Room;
}

void WaitingState::getForm()
{
    mRoom->setState(mRoom->getReceivingForm());//Chuyển tới state tiếp theo, tức nhận form
    cout << "Cam on thong tin cua ban." << endl;
}

void WaitingState::checkForm()
{
    cout << "Ban phai nop lai form." << endl;
    //Ở waiting state k thể checkform, phải submit form
}

void WaitingState::rentRoom()
{
    cout << "Ban phai nop lai form." << endl;
    //Ở waiting state k thể rentRoom, phải submit form
}

void WaitingState::dispenseKeys()
{
    cout << "Ban phai nop lai form." << endl;
    //Ở waiting state k thể dispenseKeys, phải submit form
}

ReceivingFormState::ReceivingFormState(IRentalRoom* Room)
{
    mRoom = Room;
}

void ReceivingFormState::getForm()
{
    cout << "Da nhan duoc form." << endl;
    //Nhận được form
}

void ReceivingFormState::checkForm()
{
    //Do chúng ta không biết cụ thể điều kiện form như thế nào là đúng nên ta sẽ random, ở đây chỉ mang tính tượng trưng
    uniform_int_distribution<int> int_distribution(0, 1);
    bool isFormOk = (int_distribution(illustrate) == 1 );
    if (isFormOk && mRoom->getNumberRooms() > 0) {
        cout << "Dang ky thanh cong!" << endl;//Form được chấp nhận
        mRoom->setState(mRoom->getRentRoom());//Chuyển sang state tiến hành cho thuê phòng
        mRoom->getState()->rentRoom();//Gọi hàm cho thuê phòng
       
    }
    else {
        mRoom->setState(mRoom->getWaiting());//Do form không được chấp nhận=>chuyển về state chờ form
        cout << "Form bi loi, dang ky that bai!" << endl;
    }
}

void ReceivingFormState::rentRoom()
{
    cout << "Thong tin cua ban chua duoc kiem tra." << endl;
    //Ở state nhận form chưa thể gọi đến cho thuê được, phải vượt qua check
}

void ReceivingFormState::dispenseKeys()
{
    cout << "Thong tin cua ban chua duoc kiem tra." << endl;
    ////Ở state nhận form chưa thể gọi đến cho thuê được, phải vượt qua check và tiến hành cho thuê
}


RentRoomState::RentRoomState(IRentalRoom* Room)
{
    mRoom = Room;
}

void RentRoomState::getForm()
{
    cout << "Dang xu ly thue phong." << endl;
    //Ở trạng thái đang tiến hành cho thuê, không thể getForm
}

void RentRoomState::RentRoomState::checkForm()
{
    cout << "Dang xu ly thue phong." << endl;
    //Ở trạng thái đang tiến hành cho thuê, không thể checkForm

}

void RentRoomState::rentRoom()
{
    //Ở trạng thái đang tiến hành cho thuê, gọi hàm cho thuê và trừ số phòng trống trừ đi 1
    mRoom->setNumberRooms(mRoom->getNumberRooms() - 1);
    cout << "Dang lay phong...." << endl;
    dispenseKeys();//Chuyển đến hàm phát chìa khóa
}

void RentRoomState::dispenseKeys()
{
    if (mRoom->getNumberRooms() > 0) //Nếu còn phòng về trạng thái chờ
        mRoom->setState(mRoom->getWaiting());
    else   //Hết phòng chuyển về trạng thái hết phòng
        mRoom->setState(mRoom->getFully());    
    cout << "Moi lay chia khoa cua ban!" << endl;
    //Phát chìa khóa
}


FullyState::FullyState(IRentalRoom* Room)
{
    mRoom = Room;
}

void FullyState::getForm()
{
    cout << "Xin loi, chung toi da het phong" << endl;
    //Hết phòng, không nhận form nữa
}

void FullyState::checkForm()
{
    cout << "Xin loi, chung toi da het phong." << endl;
    //Hết phòng, không check form nữa
}

void FullyState::rentRoom()
{
    cout << "Xin loi, chung toi da het phong." << endl;
    //Hết phòng, không cho thuê nữa
}

void FullyState::dispenseKeys()
{
    cout << "Xin loi, chung toi da het phong." << endl;
    //Hết phòng, không phát chìa khóa nữa
}