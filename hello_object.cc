#include "learning_gem5/hello_object.hh"
#include "base/trace.hh"
#include "debug/Hello.hh"

#include <iostream>

namespace gem5
{
    /*
    MyObject::MyObject(const MyObjectParams& params) :
        SimObject(params), 
        //event(*this),
        event([this] {processEvent(); }, name()),
        myName(params.name),
        latency(params.time_to_wait),
        timesLeft(params.number_of_fires)
    {
        DPRINTF(Hello, "Created the hello object\n");
        //std::cout << "Hello World! From a SimObject!" << std::endl;
    }
    */

    MyObject::MyObject(MyObjectParams& params) :
        SimObject(params),
        event(*this),
        goodbye(params.goodbye_object),
        myName(params.name),
        latency(params.time_to_wait),
        timesLeft(params.number_of_fires)
    {
        DPRINTF(Hello, "Created the hello object with the name %s\n", myName);
        panic_if(!goodbye, "HelloObject must have a non-null GoodbyeObject");
    }


    void MyObject::processEvent()
    {
        timesLeft--;
        DPRINTF(Hello, "Hello world! Processing the event! %d left\n", timesLeft);

        if (timesLeft <= 0) {
            DPRINTF(Hello, "Done firing!\n");
            goodbye->sayGoodbye(myName);
        }
        else {
            schedule(event, curTick() + latency);
        }
    }

    void MyObject::startup()
    {
        schedule(event, latency);
    }

} // namespace gem5
