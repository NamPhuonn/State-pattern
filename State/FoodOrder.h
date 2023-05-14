#pragma once
#include<iostream>
using namespace std;

class FoodOrderState;
class IFoodOrder 
{
public:
    virtual FoodOrderState* getWaitingOrderState() = 0;
    virtual FoodOrderState* getOrderPlacedState() = 0;
    virtual FoodOrderState* getFoodPreparationState() = 0;
    virtual FoodOrderState* getOutForDeliveryState() = 0;
    virtual FoodOrderState* getDeliveredState() = 0;
    virtual FoodOrderState* getCurrentState() = 0;
    virtual void setState(FoodOrderState* state) = 0;
    virtual void getOrder() = 0;
    virtual void checkOrder() = 0;
    virtual void cancelOrder() = 0;
    virtual void showStatus() = 0;
    virtual void markAsOutForDelivery() = 0;
    virtual void markAsDelivered() = 0;
    virtual ~IFoodOrder(){};
};

class FoodOrder : public IFoodOrder {
private:
    FoodOrderState* mWaitingOrderState;
    FoodOrderState* mOrderPlacedState;
    FoodOrderState* mFoodPreparationState;
    FoodOrderState* mOutForDeliveryState;
    FoodOrderState* mDeliveredState;
    FoodOrderState* currentState;
    static int orderNum;
public:
    FoodOrder();
    ~FoodOrder();
    FoodOrderState* getWaitingOrderState();
    FoodOrderState* getOrderPlacedState();
    FoodOrderState* getFoodPreparationState();
    FoodOrderState* getOutForDeliveryState();
    FoodOrderState* getDeliveredState();
    FoodOrderState* getCurrentState();
    void setState(FoodOrderState* state);
    void getOrder();
    void checkOrder();
    void cancelOrder();
    void showStatus();
    void markAsOutForDelivery();
    void markAsDelivered();
};
