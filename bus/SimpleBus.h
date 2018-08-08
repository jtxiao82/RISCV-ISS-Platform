/*****************************************************************************

	The following code is derived, directly or indirectly, from the SystemC
	source code Copyright (c) 1996-2008 by all Contributors.
	All Rights reserved.

	The contents of this file are subject to the restrictions and limitations
	set forth in the SystemC Open Source License Version 3.0 (the "License");
	You may not use this file except in compliance with such restrictions and
	limitations. You may obtain instructions on how to receive a copy of the
	License at http://www.systemc.org/. Software distributed by Contributors
	under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
	ANY KIND, either express or implied. See the License for the specific
	language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************


 *****************************************************************************/

#ifndef SIMPLEBUSLT_H__
#define SIMPLEBUSLT_H__

#include "tlm"

#include "tlm_utils/simple_target_socket.h"
#include "tlm_utils/simple_initiator_socket.h"

#include "SimpleAddressMap.h"


template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
class SimpleBus : public sc_core::sc_module
{
	public:
		typedef tlm::tlm_generic_payload                 transaction_type;
		typedef tlm::tlm_phase                           phase_type;
		typedef tlm::tlm_sync_enum                       sync_enum_type;
		typedef tlm_utils::simple_target_socket_tagged<SimpleBus>    target_socket_type;
		typedef tlm_utils::simple_initiator_socket_tagged<SimpleBus> initiator_socket_type;

	public:
		//2013-10-13 14:37:39, tshsu: NR_OF_INITIATOR_SOCKETS means #. of "target" module == #. of "initiator" sockets of bus.
		target_socket_type target_socket[NR_OF_TARGET_SOCKETS];
		initiator_socket_type initiator_socket[NR_OF_INITIATOR_SOCKETS];

	public:
		SC_HAS_PROCESS(SimpleBus);

		SimpleBus(sc_core::sc_module_name name, double clock_period_in_ps = 1000 );

		void bindTargetSocket(typename initiator_socket_type::base_target_socket_type& target
				,sc_dt::uint64 low
				,sc_dt::uint64 high
				,sc_dt::uint64 mask = 0xffffffffffffffffULL);
		/*
		*/

		void setMemoryMap(unsigned int target_id
				,sc_dt::uint64 low
				,sc_dt::uint64 high
				,sc_dt::uint64 mask = 0xffffffffffffffffULL);

		sc_dt::uint64 getAddressOffset(unsigned int initiator_socket_id);

		sc_dt::uint64 getAddressMask(unsigned int initiator_socket_id);

		unsigned int decode(const sc_dt::uint64& address);

		void set_clock_period( sc_core::sc_time t );

		sc_core::sc_time get_clock_period();

		sc_core::sc_time Delay( transaction_type& trans );

		//
		// interface methods
		//

		//
		// Lt protocol
		// - forward each call to the target/initiator
		//
		void initiatorBTransport(int SocketId,
				transaction_type& trans,
				sc_core::sc_time& t);

		unsigned int transportDebug(int SocketId,
				transaction_type& trans);

		bool limitRange(unsigned int initiator_socket_id, sc_dt::uint64& low, sc_dt::uint64& high);

		bool getDMIPointer(int SocketId,
				transaction_type& trans,
				tlm::tlm_dmi&  dmi_data);

		void invalidateDMIPointers(int port_id,
				sc_dt::uint64 start_range,
				sc_dt::uint64 end_range);

	private:
		SimpleAddressMap m_addrMap; //a pretty simple address map
		std::vector<sc_dt::uint64> m_masks; //address masks for each target
		unsigned int m_target_count;  //number of connected targets (see bindTargetSocket for explanation)
		sc_core::sc_time clock_period;

};

#endif
