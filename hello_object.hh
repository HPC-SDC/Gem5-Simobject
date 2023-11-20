#ifndef __LEARNING_GEM5_HELLO_OBJECT_HH__
#define __LEARNING_GEM5_HELLO_OBJECT_HH__

#include "params/MyObject.hh"
#include "sim/sim_object.hh"
#include "learning_gem5/goodbye_object.hh"

/*
namespace gem5
{

    class MyObject : public SimObject
    {

    private:
        void processEvent();

        EventFunctionWrapper event;

        const std::string myName;

        Tick latency;

        int timesLeft;


    public:
        MyObject(const MyObjectParams& p);

        void startup() override;

    };

} // namespace gem5
*/

class MyObject : public SimObject
{
private:
    void processEvent();

    EventWrapper event;

    /// Pointer to the corresponding GoodbyeObject. Set via Python
    GoodbyeObject* goodbye;

    /// The name of this object in the Python config file
    const std::string myName;

    /// Latency between calling the event (in ticks)
    const Tick latency;

    /// Number of times left to fire the event before goodbye
    int timesLeft;

public:
    MyObject(const MyObjectParams& p);

    void startup() override;
};



#endif // __LEARNING_GEM5_HELLO_OBJECT_HH__
