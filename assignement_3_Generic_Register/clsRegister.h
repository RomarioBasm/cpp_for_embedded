#ifndef CLS_REGISTER_H
#define CLS_REGISTER_H

enum Permission{
    ReadOnly,
    WriteOnly,
    ReadWrite,
    Reserved
};

enum ErrorState{
    Ok,
    Not_OK
};

template<typename T>
class clsReg{
    private: 
        T regData;
        enum regPermission;
        vector<Permission> bitPermission;
    public: 
        clsReg(T data,Permission per):regData(data),regPermission(per);

        ErrorState setRegisterValue(T value); 
        T getRegisterValue();

        ErrorState setBit(T bitPos);
        ErrorState clearBit(T bitPos);

        T getBit(T bitPos);
        ErrorState setPermissionReg(Permission regPermission);
        ErrorState setPermissionBit(T bitPos, Permission bitPermission);
};

template<typename T>
ErrorState clsReg<T>::setRegisterValue(T value){
    ErrorState setErrorState = Ok;
    if(regPermission == WriteOnly||regPermission == ReadWrite){
        regData = std::move(value);
    }
    else{
        setErrorState = Not_OK;
    }
    return ErrorState;
}

template<typename T>
T clsReg<T>::getRegisterValue(){
    T reg = std::move(regData);
    return reg;
}

template<typename T>
ErrorState clsReg<T>::setBit(T bitPos){
    ErrorState setErrorState = Ok;
    int size = sizeof(T);
    if(size>bitPos){
        regData = ((regData)|(1<<(bitPos)));
    }
    else{
        setErrorState = Not_OK;
    }
    return setErrorState;
}

template<typename T>
ErrorState clsReg<T>::clearBit(T bitPos){
    regData = ((regData)& ~(1<<(bitPos)));
    return state;
}

template<typename T>
T clsReg<T>::getBit(T bitPos){
    T val = ((regData>>bitPos)&1);
    return val;
}

template<typename T>
ErrorState clsReg<T>::setPermissionReg(Permission regPermission){

}

template<typename T>
ErrorState clsReg<T>::setPermissionBit(T bitPos, Permission bitPermission){

}

#endif