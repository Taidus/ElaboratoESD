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
    state_.id_ = 2;
    /*Entry action for Idle */
    output_.out_1=0; local_var_.lvar_0=0;;
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
        case Idle:
        {
            if ( true  && local_var_.lvar_0 > 1 )
            {
                /* Set current transition */
                transition_.id_ = 2;
                /*Exit from Idle*/
                ;;
                /*Do Action */
                output_.out_0=1;;
                /*Change State to Requesting */
                state_.id_ = 3;
                /*Entry in Requesting*/
                ;;
            }
            else
            {
                /*While action for Idle*/
                local_var_.lvar_0++;;
            }
        }break;
        case Requesting:
        {
            if ( true  && input_.in_0==1 )
            {
                /* Set current transition */
                transition_.id_ = 3;
                /*Exit from Requesting*/
                ;;
                /*Do Action */
                output_.out_1=1;;
                /*Change State to Using */
                state_.id_ = 4;
                /*Entry in Using*/
                output_.out_0=0; output_.out_2=0; local_var_.lvar_0=0;;
            }
            else
            {
                /*While action for Requesting*/
                ;
            }
        }break;
        case Using:
        {
            if ( true  && local_var_.lvar_0 > 2 )
            {
                /* Set current transition */
                transition_.id_ = 4;
                /*Exit from Using*/
                ;;
                /*Do Action */
                output_.out_2=1;;
                /*Change State to Idle */
                state_.id_ = 2;
                /*Entry in Idle*/
                output_.out_1=0; local_var_.lvar_0=0;;
            }
            else
            {
                /*While action for Using*/
                local_var_.lvar_0++;;
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

const StateMachine_0Input* StateMachine_0::input() const
{
    return &input_;
}

const StateMachine_0Output* StateMachine_0::output() const
{
    return &output_;
}

const StateMachine_0LocalVars* StateMachine_0::localVariables() const
{
    return &local_var_;
}

const SMStateData* StateMachine_0::state() const
{
    return &state_;
}

const SMTransitionData* StateMachine_0::transition() const
{
    return &transition_;
}

int StateMachine_0::eventsInPorts() const
{
    return eventsInPorts_;
}

unsigned int StateMachine_0::eventsOutPorts() const
{
    return eventsOutPorts_;
}

/*Global instance of StateMachine_0*/
StateMachine_0 smInst;


/***** Callbacks *****/
void state_machine_init()
{
    smInst.init();
}

bool state_machine_dispatch(const void* input, int size, int eventsIn)
{
    return smInst.dispatch((StateMachine_0Input*)input, size, eventsIn);
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

