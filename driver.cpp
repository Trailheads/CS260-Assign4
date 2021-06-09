#include "Linked_List.cpp"
#include "Node.cpp"
#include <iostream>

int main() {
    Linked_List<int> LL;
    int value = 0;
    
    //Test add function
    for(int i = 0; i < 10; i++) {
        LL.add(value, i);
        value += 10;
    }


    //Test get function
    for(int i = 0; i < 10; i++) {
        //Expect return values of: 0,10,20,30,40,50,60,70,80,90
        std::cout << "Position: " << i << " has a value of: " << LL.get(i) << std::endl;
    }

    //Test remove function
    std::cout << "\nRemoving 5th node...\n" << std::endl;
    LL.remove(5); 

    for(int i = 0; i < LL.get_size(); i++) {
        //expect return values of: 0,10,20,40,50,60,70,80,90
        std::cout << "Position: " << i << " has a value of: " << LL.get(i) << std::endl;
    }
    
    return 0;
}