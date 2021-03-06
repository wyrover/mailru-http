/*! \file mutex.h
     
    Simple mutex wrapper
*/
#pragma once
#include <uv.h>

namespace sys
{

/*! \class Mutex
    
    A simple non-recursive mutex, which can block execution, when other thread locks on it,
    or unblock it, when other thread is done working with it
*/
class Mutex
{
public:
    /*! Creates new non-locked mutex
     */
    Mutex();
    /*! Releases system resources, taken by mutex
     */
    ~Mutex();
    /*! Locks a mutex, blocking  execution of code in other threads
     */
    void lock();
    /*! Unlocks a mutex, allowing execution of code in other threads
     */
    void unlock();
protected:
    uv_mutex_t m_mtx;
private:
    /*! Cannot be copied, so this is disabled and not implemented
        \param[in] o other mutex
     */
    Mutex(const sys::Mutex& o);
    /*! Cannot be copied, so this is disabled and not implemented
        \param[in] o other mutex
        \return self-reference
     */	
    sys::Mutex& operator=(const sys::Mutex& o);
};

}
