#pragma once
#include <iostream>
#include <random>
using namespace std;

class RentalRobot
{
private:
    enum eState //tạo các trạng thái mặc định của robot
    {
        STATE_WAITING = 0,  //chờ khách thuê nhà
        STATE_RECEIVING_FORM, //đang nhận form đăng ký
        STATE_RENT_APARTMENT, //tiến hành cho thuê 1 căn hộ
        STATE_FULL_RENTED    //Đã hết phòng
    };

    int mNumberOfApartments;  //số lượng phòng có thể cho thuê
    int mState;  //trạng thái hiện tại của robot

public:
    RentalRobot(int numberOfApartments)
    {
        mNumberOfApartments = numberOfApartments;
        mState = STATE_WAITING;
    }
    // nhận form, hàm này sẽ được gọi khi khách điền đầy đủ thông tin và bấm submit 
    void getForm() 
    {
        switch (mState)
        {
        case STATE_WAITING:
            mState = STATE_RECEIVING_FORM;
            printf("Thanks for the form.\n");
            break;
        case STATE_RECEIVING_FORM:
            printf("We already got your form.\n");
            break;
        case STATE_RENT_APARTMENT:
            printf("Hang on, we’re renting you an apartment.\n");
            break;
        case STATE_FULL_RENTED:
            printf("Sorry, we're fully rented.\n");
            break;
        default:
            break;
        }
    }

    void checkForm()  //kiểm tra form và kiểm tra luôn phòng trống
    {
        switch (mState)
        {
        case STATE_WAITING:
            printf("You have to submit an form.\n");
            break;
        case STATE_RECEIVING_FORM:
        {
            // mô phỏng việc kiểm tra biểu mẫu
            random_device mRandomGenerator;  //tạo số random
            uniform_int_distribution<int> int_distribution(0, 9);  //tạo số ngẫu nhiên từ 0->9
            bool isFormOk = int_distribution(mRandomGenerator) > 5;

            // check result
            if (isFormOk) {
                printf("Congratulations, you were approved.\n");
                mState = STATE_RENT_APARTMENT;
                rentApartment();
            }
            else {
                printf("Sorry, you were not approved.\n");
                mState = STATE_WAITING;
            }
            break;
        }
        case STATE_RENT_APARTMENT:
            printf("Hang on, we’re renting you an apartment.\n");
            break;
        case STATE_FULL_RENTED:
            printf("Sorry, we're fully rented.\n");
            break;
        default:
            break;
        }
    }

    void rentApartment()  //tiến hành cho thuê
    {
        switch (mState)
        {
        case STATE_WAITING:
            mState = STATE_RECEIVING_FORM;
            printf("Thanks for the form.\n");
            break;
        case STATE_RECEIVING_FORM:
            printf("You must have your form checked.\n");
            break;
        case STATE_RENT_APARTMENT:
            printf("Renting you an apartment....\n");
            mNumberOfApartments--;
            dispenseKeys(); //đưa chìa khóa cho khách
            break;
        case STATE_FULL_RENTED:
            printf("Sorry, we're fully rented.\n");
            break;
        default:
            break;
        }
    }

    void dispenseKeys()
    {
        switch (mState)
        {
        case STATE_WAITING:
            printf("You have to submit an form.\n");
            break;
        case STATE_RECEIVING_FORM:
            printf("You must have your form checked.\n");
            break;
        case STATE_RENT_APARTMENT:
            printf("Here are your keys!\n");
            if (mNumberOfApartments > 0) {
                mState = STATE_WAITING;
            }
            else {
                mState = STATE_FULL_RENTED;
            }
            break;
        case STATE_FULL_RENTED:
            printf("Sorry, we're fully rented.\n");
            break;
        default:
            break;
        }
    }
};