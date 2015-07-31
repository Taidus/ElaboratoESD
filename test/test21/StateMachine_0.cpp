#include "StateMachine_0.h"
#include <cstring>

#define CHECK_EVENT(in, pos) \
    ( (unsigned int)in & ((unsigned int)1 << pos) )

#define SET_EVENT(out, pos) \
    ( out |= ((unsigned int)1 << pos) )

StateMachine_0::StateMachine_0()
{
    inputSize_ = sizeof(input_);
    outputSize_ = sizeof(output_);
    lVarsSize_ = sizeof(local_var_);
}

void StateMachine_0::init()
{
    /* Clear */
    memset((void*)&input_, 0, sizeof(input_));
    memset((void*)&output_, 0, sizeof(output_));
    memset((void*)&state_, 0, sizeof(state_));
    memset((void*)&transition_, 0, sizeof(transition_));
    eventsInPorts_ = 0;
    eventsOutPorts_ = 0;
    /*Set inial transition*/
    transition_.id_ = 1;
    /*Change State*/
    state_.id_ = 1;
    /*Entry action for Waiting */
    local_var_.lvar_0=0;;
}

bool StateMachine_0::dispatch(const StateMachine_0Input* input, int size, int eventsIn)
{
    /*Check for input size*/
    if ( size && size != sizeof(input_) )
    {
        std::cerr << "input size mismatch cannot evaluate the input" << std::endl;
        lastError_ = "input size mismatch";
        return false;
    }
    /*Save current input*/
    input_ = *input;
    /*Save current events input*/
    eventsInPorts_ = eventsIn;
    /*Clear events output*/
    eventsOutPorts_ = 0;
    switch((StateType)state_.id_)
    {
        case Waiting:
        {
