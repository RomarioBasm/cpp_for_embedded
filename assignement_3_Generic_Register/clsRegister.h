#ifndef CLS_REGISTER_H
#define CLS_REGISTER_H


enum Permission{
    ReadOnly,
    WriteOnly,
    ReadWrite,
    Reserved
};

enum ErrorState{
    Not_OK,
    OK
};

template<typename T>
class clsReg{
    private: 
        T regData;
        Permission regPermission;
        std::vector<Permission> bitPermission;

    public: 
        clsReg(T data,Permission per):regData(data),regPermission(per){
            int size = sizeof(T)*8;

            /* set pin permissions as a register permission */
            for(int i=0;i<size;i++){
               bitPermission.push_back(regPermission);  
            }
        }

        ErrorState setRegisterValue(T value); 
        T getRegisterValue();

        ErrorState setBit(T bitPos);
        ErrorState clearBit(T bitPos);

        T getBit(T bitPos, ErrorState* getErrorState);
        ErrorState setPermissionReg(Permission regPermission);
        ErrorState setPermissionBit(T bitPos, Permission bitPermission);
};

template<typename T>
ErrorState clsReg<T>::setRegisterValue(T value){
    ErrorState setErrorState = OK;
    if(regPermission == WriteOnly||regPermission == ReadWrite){
        regData = std::move(value);
    }
    else{
        setErrorState = Not_OK;
    }
    return setErrorState;
}

template<typename T>
T clsReg<T>::getRegisterValue(){
    T reg = std::move(regData);
    return reg;
}

template<typename T>
ErrorState clsReg<T>::setBit(T bitPos){
    ErrorState setErrorState = OK;
    int size = sizeof(T)*8;
    if(size>bitPos && (bitPermission.at(bitPos) == WriteOnly || bitPermission.at(bitPos) == ReadWrite)){
        regData = ((regData)|(1<<(bitPos)));
    }
    else{
        setErrorState = Not_OK;
    }
    return setErrorState;
}

template<typename T>
ErrorState clsReg<T>::clearBit(T bitPos){
    ErrorState clearErrorState = OK;
    int size = sizeof(T)*8;
    if(size>bitPos && (bitPermission.at(bitPos) == WriteOnly || bitPermission.at(bitPos) == ReadWrite)){
        regData = ((regData)& ~(1<<(bitPos)));
    }
    else{
        clearErrorState = Not_OK;
    }
    return clearErrorState;
}

template<typename T>
T clsReg<T>::getBit(T bitPos, ErrorState* getErrorState){
    T val = ((regData>>bitPos)&1);
    int size = sizeof(T)*8;
    if(size>bitPos && (bitPermission.at(bitPos) == ReadOnly || bitPermission.at(bitPos) == ReadWrite)){
        *getErrorState = OK;
    }
    else{
        *getErrorState = Not_OK;
    }
    return val;
}

template<typename T>
ErrorState clsReg<T>::setPermissionReg(Permission newRegPermission){
    ErrorState setErrorState = OK;
    if(newRegPermission>=ReadOnly && newRegPermission<=Reserved){
        regPermission = newRegPermission;
    }
    else{
        setErrorState = Not_OK;
    }
    return setErrorState;
}

template<typename T>
ErrorState clsReg<T>::setPermissionBit(T bitPos, Permission newBitPermission){
    ErrorState setErrorState = OK;
    int size = sizeof(T)*8;
    if(newBitPermission>=ReadOnly && newBitPermission<=Reserved && size>=bitPos){
        bitPermission.at(bitPos) = newBitPermission;

    }
    else{
        std::cout<<"size: "<<size<< "  , newBitPermission"<< newBitPermission<<std::endl;
        setErrorState = Not_OK;
    }
    return setErrorState;
}

#endif