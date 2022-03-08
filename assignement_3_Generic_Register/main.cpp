
#include <iostream>
#include <vector>
#include "clsRegister.h"
using namespace std;

int main(){
    clsReg<char> register1(0,ReadWrite);
    int regValue = 0;

    ErrorState errorState;
    
    /* set a bit register */
    std::cout<< " setting a bit number 3" << endl;
    errorState = register1.setBit(3);
    regValue = register1.getRegisterValue();
    if(errorState == ErrorState::OK){
        std::cout<<" The data in the register : "<< regValue <<std::endl;
    }
    else{
        std::cout<<" there's an error ! " <<std::endl;
    }
    std::cout<< " ************************** " << endl;
    std::cout<< " writing on the register 25" << endl;

    /* set a value to a register */
    errorState = register1.setRegisterValue(25);
    regValue = register1.getRegisterValue();
    if(errorState == OK){
        std::cout<<" The data in the register : "<< regValue <<std::endl;
    }
    else{
        std::cout<<" there's an error ! " <<std::endl;
    }
    std::cout<< " ************************** " << endl;

    /* change register permission */
    errorState = register1.setPermissionReg(ReadOnly);
    if(errorState == OK){
        std::cout<<" The permission of the register has been changed truly" <<std::endl;
    }
    else{
        std::cout<< "There's an error !" << std::endl;
    }
    std::cout<< " ************************** " << endl;
    std::cout<< " trying to write on the register when the permission is read only " << endl;

    /* Try to write on the register when the permission is read only */
    errorState = register1.setRegisterValue(100);
    if(errorState == OK){
        std::cout<<" The data in the register : "<< regValue <<std::endl;
    }
    else{
        std::cout<<" the permission of the register is read only !" <<std::endl;
    }
    std::cout<< " ************************** " << endl;
    std::cout<< " Changing the bit permission to write on it " << endl;

    /* change bit permission */
    errorState = register1.setPermissionBit(6, WriteOnly);
    if(errorState == OK){
        std::cout<<"  The permission of the bit has been changed truly " <<std::endl;
    }
    else{
        std::cout<<" There's an error ! " <<std::endl;
    }

    std::cout<< " ************************** " << endl;
    std::cout<< " Set the bit " << endl;

    /* Try to write on the bit */
    errorState = register1.setBit(6);
    if(errorState == OK){
        std::cout<<" The bit has been changed truly" <<std::endl;
    }
    else{
        std::cout<<" There's an error ! " <<std::endl;
    }
    
    /* checking the value */

    regValue = register1.getRegisterValue();
    if(errorState == OK){
        std::cout<<" The data in the register : "<< regValue <<std::endl;
    }
    else{
        std::cout<<" there's an error ! " <<std::endl;
    }

    return 0;
}