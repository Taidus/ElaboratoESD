#include "StateMachine_1.h"
#include <cstring>

#define CHECK_EVENT(in, pos) \
    ( (unsigned int)in & ((unsigned int)1 << pos) )

#define SET_EVENT(out, pos) \
    ( out |= ((unsigned int)1 << pos) )

StateMachine_1::StateMachine_1()
{
    inputSize_ = sizeof(input_);
    outputSize_ = sizeof(output_);
    lVarsSize_ = 0;
}

void StateMachine_1::init()
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
    //Do nothing
}

bool StateMachine_1::dispatch(const StateMachine_1Input* input, int size, int eventsIn)
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
            if ( true  && input_.in_0==1 )
            {
                /* Set current transition */
                transition_.id_ = 2;
                /*Exit from Waiting*/
                ;;
                /*Do Action */
                ;;
                /*Change State to Elaborating */
                state_.id_ = 3;
                /*Entry in Elaborating*/
                ;;
            }
            else
            {
                /*While action for Waiting*/
                ;
            }
        }break;
        case Elaborating:
        {
            if ( true  )
            {
                /* Set current transition */
                transition_.id_ = 3;
                /*Exit from Elaborating*/
                ;;
                /*Do Action */
                output_.out_0=1;;
                /*Change State to Accepting */
                state_.id_ = 4;
                /*Entry in Accepting*/
                ;;
            }
            else
            {
                /*While action for Elaborating*/
                ;
            }
        }break;
        case Accepting:
        {
            if ( true  && input_.in_1==1 )
            {
                /* Set current transition */
                transition_.id_ = 4;
                /*Exit from Accepting*/
                ;;
                /*Do Action */
                ;;
                /*Change State to Serving */
                state_.id_ = 5;
                /*Entry in Serving*/
                ;;
            }
            else
            {
                /*While action for Accepting*/
                ;
            }
        }break;
        case Serving:
        {
            if ( true  && input_.in_2==1 )
            {
                /* Set current transition */
                transition_.id_ = 5;
                /*Exit from Serving*/
                ;;
                /*Do Action */
                output_.out_0=0;;
                /*Change State to Waiting */
                state_.id_ = 1;
                /*Entry in Waiting*/
                ;;
            }
            else
            {
                /*While action for Serving*/
                ;
            }
        }break;
        default:
            std::cerr << "Invalid state, internal error" << std::endl;
            lastError_ = "Invalid state, internal error";
            return false;
        break;
    } // end switch
    return true;
}

const StateMachine_1Input* StateMachine_1::input() const
{
    return &input_;
}

const StateMachine_1Output* StateMachine_1::output() const
{
    return &output_;
}

const StateMachine_1LocalVars* StateMachine_1::localVariables() const
{
    return &local_var_;
}

const SMStateData* StateMachine_1::state() const
{
    return &state_;
}

const SMTransitionData* StateMachine_1::transition() const
{
    return &transition_;
}

int StateMachine_1::eventsInPorts() const
{
    return eventsInPorts_;
}

unsigned int StateMachine_1::eventsOutPorts() const
{
    return eventsOutPorts_;
}

/*Global instance of StateMachine_1*/
StateMachine_1 smInst;


/***** Callbacks *****/
void state_machine_init()
{
    smInst.init();
}

bool state_machine_dispatch(const void* input, int size, int eventsIn)
{
    return smInst.dispatch((StateMachine_1Input*)input, size, eventsIn);
}

const void* state_machine_output(int* size)
{
    *size = smInst.outputSize();
    return (const void*)smInst.output();
}

const void* state_machine_local_variables(int* size)
{
    *size = smInst.lVarsSize();
    return (const void*)smInst.localVariables();
}

const void* state_machine_input(int* size)
{
    *size = smInst.inputSize();
    return (const void*)smInst.input();
}

const void* state_machine_state(int* size)
{
    *size = sizeof(SMStateData);
    return (const void*)smInst.state();
}

const void* state_machine_transition(int* size)
{
    *size = sizeof(SMTransitionData);
    return (const void*)smInst.transition();
}

int state_machine_events_in_ports()
{
    return smInst.eventsInPorts();
}

unsigned int state_machine_events_out_ports()
{
    return smInst.eventsOutPorts();
}

const char* state_machine_last_error()
{
    return smInst.lastError_.c_str();
}

