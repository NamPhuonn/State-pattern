#include"FoodOrder.h"
#include"FoodOrderState.h"

// Cài đặt lại các phương thức khi hệ thống ở trạng thái "Chờ nhận đơn hàng"
WaitingOrderState::WaitingOrderState(IFoodOrder* _order)
{
    order = _order;
}

void WaitingOrderState::getOrder() 
{
    order->setState(order->getOrderPlacedState());
    cout << "Order received, it will be placed soon." << endl;
}

void WaitingOrderState::checkOrder() 
{
    cout << "There's no order received." << endl;
}

void WaitingOrderState::cancelOrder() 
{
    cout << "There's no order received." << endl;
}

void WaitingOrderState::showStatus() 
{
    cout << "Waiting for getting an order." << endl;
}

void WaitingOrderState::markAsOutForDelivery() 
{
    cout << "There's no order received." << endl;
}

void WaitingOrderState::markAsDelivered() 
{
    cout << "There's no order received." << endl;
}

// Cài đặt lại các phương thức khi hệ thống ở trạng thái "Đơn đã được đặt"
OrderPlacedState::OrderPlacedState(IFoodOrder* _order)
{
    order = _order;
}

void OrderPlacedState::getOrder() 
{
    cout << "Order is already placed, please wait for it to be checked." << endl;
}

void OrderPlacedState::checkOrder() 
{
    order->setState(order->getFoodPreparationState());
    cout << "Order is already checked, please wait for it to be prepared" << endl;
}

void OrderPlacedState::cancelOrder() 
{
    order->setState(order->getWaitingOrderState());
    cout << "Order cancelled." << endl;
}

void OrderPlacedState::showStatus() 
{
    cout << "Order placed, waiting for it to be checked." << endl;
}

void OrderPlacedState::markAsOutForDelivery() 
{
    cout << "Order is waiting to be checked." << endl;
}

void OrderPlacedState::markAsDelivered() 
{
    cout << "Order is waiting to be checked." << endl;
}

// Cài đặt lại các phương thức khi hệ thống ở trạng thái "Chuẩn bị đơn hàng"
FoodPreparationState::FoodPreparationState(IFoodOrder* _order) 
{
    order = _order;
}

void FoodPreparationState::getOrder() 
{
    cout << "Order is being prepared, please wait." << endl;
}

void FoodPreparationState::checkOrder() 
{
    cout << "Order is being prepared, please wait." << endl;
}

void FoodPreparationState::cancelOrder() 
{
    cout << "Can't cancel after placing." << endl;
}

void FoodPreparationState::showStatus() 
{
    cout << "Order is being prepared." << endl;
}

void FoodPreparationState::markAsOutForDelivery() 
{
    order->setState(order->getOutForDeliveryState());
    cout << "Order is ready to be delivered" << endl;
}

void FoodPreparationState::markAsDelivered() 
{
    cout << "Order is being delivered, please wait." << endl;
}

// Cài đặt lại các phương thức cho trạng thái "Đang vận chuyển đơn hàng"
OutForDeliveryState::OutForDeliveryState(IFoodOrder* _order) 
{
    order = _order;
}

void OutForDeliveryState::getOrder() 
{
    cout << "Order is out for delivery, please wait." << endl;
}

void OutForDeliveryState::checkOrder() 
{
    cout << "Order is out for delivery, please wait." << endl;
}

void OutForDeliveryState::cancelOrder() 
{
    cout << "Can't cancel after placing." << endl;
}

void OutForDeliveryState::showStatus() 
{
    cout << "Order is out for delivery." << endl;
}

void OutForDeliveryState::markAsOutForDelivery() 
{
    cout << "Order is out for delivery." << endl;
}

void OutForDeliveryState::markAsDelivered()
{
    order->setState(order->getDeliveredState());
    cout << "Order is marked as delivered" << endl;
}

// Cài đặt lại các phương thức cho trạng thái "Đã vận chuyển đến nơi"
DeliveredState::DeliveredState(IFoodOrder* _order) 
{
    order = _order;
}

void DeliveredState::getOrder() 
{
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

void DeliveredState::checkOrder() 
{
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

void DeliveredState::cancelOrder() 
{
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

void DeliveredState::showStatus() 
{
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

void  DeliveredState::markAsOutForDelivery() 
{
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

void DeliveredState::markAsDelivered() 
{
    order->setState(order->getWaitingOrderState()); // Quay lại trạng thái ban đầu
    cout << "Order has been delivered, enjoy your meal !" << endl;
}
