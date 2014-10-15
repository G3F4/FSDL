#include "SingletonBase.hpp"

//std::unique_ptr<SingletonBase> SingletonBase::m_instance;
//std::once_flag SingletonBase::m_once_flag;
//
//SingletonBase& SingletonBase::Instance() {
//    std::call_once(m_once_flag, [] {
//        m_instance.reset(new SingletonBase);
//    });
//    return *m_instance.get();
//}