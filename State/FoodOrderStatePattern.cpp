#include"FoodOrder.h"

int main() 
{
    IFoodOrder* order = new FoodOrder();
    
    // WaitingOrderState;
    order->getOrder();
    cout << endl;

    // OrderPlacedState
    order->showStatus();
    order->checkOrder();
    cout << endl;

    // FoodPreparationState
    order->showStatus();
    order->markAsOutForDelivery();
    cout << endl;

    // OutForDeliveryState
    order->showStatus();
    order->markAsDelivered();
    cout << endl;

    // DeliveredState
    order->showStatus();

    return 0;
}
