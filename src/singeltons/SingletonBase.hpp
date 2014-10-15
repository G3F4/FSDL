#ifndef SINGLETONBASE_HPP_DEFINE
#define SINGLETONBASE_HPP_DEFINE

#include <mutex>
#include <memory>

template < typename Class >
class SingletonBase {

public:
    static Class& Instance(void){
        std::call_once(m_once_flag, [] {
            m_instance.reset(new Class);
        });
        return *m_instance.get();
    }
    virtual ~SingletonBase(void) {}

protected:
    SingletonBase(void) {};
    static std::unique_ptr<Class> m_instance;
    static std::once_flag m_once_flag;

};

template <typename T>
std::unique_ptr<T> SingletonBase<T>::m_instance;
//std::unique_ptr<SingletonBase> SingletonBase::m_instance;
template <typename T>
std::once_flag SingletonBase<T>::m_once_flag;

//
//SingletonBase& SingletonBase::Instance() {
//    std::call_once(m_once_flag, [] {
//        m_instance.reset(new SingletonBase);
//    });
//    return *m_instance.get();
//}
#endif /* SINGLETONBASE_HPP_DEFINE */