#include "../include/ProductionWorker.h"
#include "../include/Date.h"
#include <iostream>

int main(void){
    //Creating Workers
    ProductionWorker uninit_worker(Date(12, 4, 2014));
    ProductionWorker init_worker(Date(4, 7, 2008), 2, 15.98);

    //Printing worker details
    std::cout << uninit_worker << std::endl;
    std::cout << init_worker << std::endl;

    //Using setters
    uninit_worker.setRate(39.99);
    uninit_worker.setShift(1);

    //Printing again
    std::cout << uninit_worker << std::endl;

}