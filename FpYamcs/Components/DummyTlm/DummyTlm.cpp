// ======================================================================
// \title  DummyTlm.cpp
// \author chammard
// \brief  cpp file for DummyTlm component implementation class
// ======================================================================

#include "FpYamcs/Components/DummyTlm/DummyTlm.hpp"

namespace FpYamcs {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

DummyTlm ::DummyTlm(const char* const compName) : DummyTlmComponentBase(compName) {}

DummyTlm ::~DummyTlm() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void DummyTlm ::run_handler(FwIndexType portNum, U32 context) {
    if (this->m_counter % 3 == 0) {
        this->m_sampleStruct.set_x(this->m_sampleStruct.get_x() + 1);
        this->m_sampleStruct.set_y(Fw::On::ON);
    } else {
        this->m_sampleStruct.set_y(Fw::On::OFF);
    }
    this->tlmWrite_DummyCounter(m_counter++);
    this->tlmWrite_DummyStruct(this->m_sampleStruct);
}

void DummyTlm ::DUMMY_COMMAND_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    this->log_ACTIVITY_HI_DummyEvent(0xFF);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace FpYamcs
