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
    this->tlmWrite_DummyCounter(m_counter++);
}

}  // namespace FpYamcs
