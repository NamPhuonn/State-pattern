#include"FoodOrder.h"

int main(){
    FoodOrder* order = new FoodOrder();
    // WaitingOrderState;
    order->getOrder();
    cout << endl;

    // OrderPlacedStatus
    order->showStatus();
    order->checkOrder();
    cout << endl;

    // FoodPreparationState
    order->showStatus();
    order->checkOrder();
    cout << endl;

    // OutForDeliveryState
    order->showStatus();
    order->checkOrder();
    cout << endl;
    // DeliveredState
    order->showStatus();
    return 0;
}