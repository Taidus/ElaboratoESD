#ifndef STATEMACHINE_1_H
#define STATEMACHINE_1_H
#include <string>
#include <iostream>

#if defined(_MSC_VER) && _MSC_VER < 1600 
    typedef __int32 int32_t;
    typedef __int16 int16_t;
    typedef __int8 int8_t;
#else
    #error "Compiler not supported"
#endif
#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_)
#define EXPORT_SHARED_LIB __declspec(dllexport)
#else
#define EXPORT_SHARED_LIB
#endif


#pragma pack(push, 1)
/*Input data structure*/
struct StateMachine_1Input
{
    int32_t in_0;
    int32_t in_1;
};

/*Output data structure*/
struct StateMachine_1Output
{
    int32_t out_0;
    int32_t out_1;
    int32_t out_2;
};

/*Local variables data structure*/
struct StateMachine_1LocalVars
{
    int8_t lvar_0;
};

/*Events Input definition*/
enum
{
};

/*Events Output definition*/
enum
{
};

/*State data structure*/
struct SMStateData
{
    int id_;
};

/*Transition data structure*/
struct SMTransitionData
{
    int id_;
};
#pragma pack(pop)

/*States*/
enum StateType
{
    Idle = 2,
    Requesting = 3,
    Using = 4
};

/*State machine class*/
class StateMachine_1
{
public:
/* public methods */
    StateMachine_1();
    void init();
    bool dispatch(const StateMachine_1Input* input, int size, int eventsIn);
    const StateMachine_1Input* input() const;
    const StateMachine_1Output* output() const;
    const StateMachine_1LocalVars* localVariables() const;
    const SMStateData* state() const;
    const SMTransitionData* transition() const;
    int eventsInPorts() const;
    unsigned int eventsOutPorts() const;
    int inputSize() const { return inputSize_; }
    int outputSize() const { return outputSize_; }
    int lVarsSize() const { return lVarsSize_; }
    std::string lastError_;

private:
/* Attributes */
    StateMachine_1Input input_;
    StateMachine_1Output output_;
    StateMachine_1LocalVars local_var_;
    SMStateData state_;
    SMTransitionData transition_;
    int eventsInPorts_;
    unsigned int eventsOutPorts_;
    int inputSize_;
    int outputSize_;
    int lVarsSize_;
}; /*StateMachine_1*/

extern StateMachine_1 smInst;


/***** Callbacks *****/
/*Trigger first transition*/
extern "C" EXPORT_SHARED_LIB void state_machine_init();
/*Submit input*/
extern "C" EXPORT_SHARED_LIB bool state_machine_dispatch(const void* input, int size, int eventsIn);
/*Get current output*/
extern "C" EXPORT_SHARED_LIB const void* state_machine_output(int* size);
/*Get current local variables*/
extern "C" EXPORT_SHARED_LIB const void* state_machine_local_variables(int* size);
/*Get current input*/
extern "C" EXPORT_SHARED_LIB const void* state_machine_input(int* size);
/*Get current state*/
extern "C" EXPORT_SHARED_LIB const void* state_machine_state(int* size);
/*Get current transition*/
extern "C" EXPORT_SHARED_LIB const void* state_machine_transition(int* size);
/*Get current events input ports*/
extern "C" EXPORT_SHARED_LIB int state_machine_events_in_ports();
/*Get current events output ports*/
extern "C" EXPORT_SHARED_LIB unsigned int state_machine_events_out_ports();
/*Get last error*/
extern "C" EXPORT_SHARED_LIB const char* state_machine_last_error();


#endif

