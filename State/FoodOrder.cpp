#include"FoodOrder.h"
#include"FoodOrderState.h"

FoodOrder::FoodOrder() 
{
    mWaitingOrderState = new WaitingOrderState(this);
    mOrderPlacedState = new OrderPlacedState(this);
    mFoodPreparationState = new FoodPreparationState(this);
    mOutForDeliveryState = new OutForDeliveryState(this);
    mDeliveredState = new DeliveredState(this);
    
    //Trạng thái ban đầu là trạng thái chờ nhận đơn hàng
    currentState = mWaitingOrderState; 
}

void FoodOrder::setState(FoodOrderState* state) 
{
    currentState = state;
}

FoodOrderState* FoodOrder::getCurrentState() 
{
    return currentState;
}

FoodOrderState* FoodOrder::getWaitingOrderState()
{
    return mWaitingOrderState;
}

FoodOrderState* FoodOrder::getOrderPlacedState()
{
    return mOrderPlacedState;
}

FoodOrderState* FoodOrder::getFoodPreparationState()
{
    return mFoodPreparationState;
}

FoodOrderState* FoodOrder::getOutForDeliveryState()
{
    return mOutForDeliveryState;
}

FoodOrderState* FoodOrder::getDeliveredState()
{
    return mDeliveredState;
}

void FoodOrder::getOrder() 
{
    currentState->getOrder();
}

void FoodOrder::checkOrder() 
{
    currentState->checkOrder();
}

void FoodOrder::cancelOrder() 
{
    currentState->cancelOrder();
}

void FoodOrder::showStatus() 
{
    currentState->showStatus();
}

void FoodOrder::markAsOutForDelivery() 
{
    currentState->markAsOutForDelivery();
}

void FoodOrder::markAsDelivered() 
{
    currentState->markAsDelivered();
}

FoodOrder::~FoodOrder() 
{
    if (mWaitingOrderState != nullptr)
    {
        delete mWaitingOrderState;
        mWaitingOrderState = nullptr;
    }
    if (mOrderPlacedState != nullptr)
    {
        delete mOrderPlacedState;
        mOrderPlacedState = nullptr;
    }
    if (mFoodPreparationState != nullptr)
    {
        delete mFoodPreparationState;
        mFoodPreparationState = nullptr;
    }
    if (mOutForDeliveryState != nullptr)
    {
        delete mOutForDeliveryState;
        mOutForDeliveryState = nullptr;
    }
    if (mDeliveredState != nullptr)
    {
        delete mDeliveredState;
        mDeliveredState = nullptr;
    }
}
