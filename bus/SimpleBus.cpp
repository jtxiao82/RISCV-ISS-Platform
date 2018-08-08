#include "SimpleBus.h"

template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::SimpleBus(sc_core::sc_module_name name, double clock_period_in_ps) :
			sc_core::sc_module(name), 
			m_masks( NR_OF_INITIATOR_SOCKETS, 0xffffffffffffffffULL ),
			m_target_count(0),
			clock_period( clock_period_in_ps, sc_core::SC_PS )
	{
		for (unsigned int i = 0; i < NR_OF_TARGET_SOCKETS; ++i) {
			target_socket[i].register_b_transport(this, &SimpleBus::initiatorBTransport, i);
			target_socket[i].register_transport_dbg(this, &SimpleBus::transportDebug, i);
			target_socket[i].register_get_direct_mem_ptr(this, &SimpleBus::getDMIPointer, i);
		}
		for (unsigned int i = 0; i < NR_OF_INITIATOR_SOCKETS; ++i) {
			initiator_socket[i].register_invalidate_direct_mem_ptr(this, &SimpleBus::invalidateDMIPointers, i);
		}

	}


template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
void SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::bindTargetSocket(typename initiator_socket_type::base_target_socket_type& target
				,sc_dt::uint64 low
				,sc_dt::uint64 high
				,sc_dt::uint64 mask){
			initiator_socket[m_target_count](target); //bind sockets
			//insert into address map and increase target count
			// (we have to count the targets manually, because target_socket.size() is only reliable during simulation
			//  as it gets evaluated during end_of_elaboration)
			setMemoryMap( m_target_count++, low, high, mask );
		}

template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
void SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::setMemoryMap(unsigned int target_id
				,sc_dt::uint64 low
				,sc_dt::uint64 high
				,sc_dt::uint64 mask) {
			assert( target_id < NR_OF_INITIATOR_SOCKETS );
			//insert into address map and increase target count
			// (we have to count the targets manually, because target_socket.size() is only reliable during simulation
			//  as it gets evaluated during end_of_elaboration)
			m_addrMap.insert(low, high, target_id);
			m_masks[target_id] = mask; //add the mask for this target
		}

template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
sc_dt::uint64 SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::getAddressOffset(unsigned int initiator_socket_id)
		{
			return m_addrMap.getBaseAddress( initiator_socket_id );
		}

template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
sc_dt::uint64 SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::getAddressMask(unsigned int initiator_socket_id)
		{
			return m_masks[initiator_socket_id];
		}


template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
unsigned int SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::decode(const sc_dt::uint64& address)
		{
			return m_addrMap.decode(address);
		}


template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
void SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::set_clock_period( sc_core::sc_time t )
		{
			clock_period = t;
		}


template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
sc_core::sc_time SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::get_clock_period()
		{
			return clock_period;
		}


template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
sc_core::sc_time SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::Delay( transaction_type& trans )
		{
			//Note that 4 means bus width is 4 bytes; not good enough coding.
			return (1 +  trans.get_data_length() / 4 )*clock_period;
		}



template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
void SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::initiatorBTransport(int SocketId,
				transaction_type& trans,
				sc_core::sc_time& t)
		{
			initiator_socket_type* decodeSocket;
			unsigned int initiator_socket_id = decode(trans.get_address());
			assert(initiator_socket_id < NR_OF_INITIATOR_SOCKETS);
			decodeSocket = &initiator_socket[initiator_socket_id];
			trans.set_address(trans.get_address() & getAddressMask(initiator_socket_id));

            
			t += Delay( trans );

			(*decodeSocket)->b_transport(trans, t);
		}


template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
unsigned int SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::transportDebug(int SocketId,
				transaction_type& trans)
		{
			unsigned int initiator_socket_id = decode(trans.get_address());
			assert(initiator_socket_id < NR_OF_INITIATOR_SOCKETS);
			initiator_socket_type* decodeSocket = &initiator_socket[initiator_socket_id];
			trans.set_address( trans.get_address() & getAddressMask(initiator_socket_id) );

			return (*decodeSocket)->transport_dbg(trans);
		}



template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
bool SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::limitRange(unsigned int initiator_socket_id, sc_dt::uint64& low, sc_dt::uint64& high)
		{
			sc_dt::uint64 addressOffset = getAddressOffset(initiator_socket_id);
			sc_dt::uint64 addressMask = getAddressMask(initiator_socket_id);

			if (low > addressMask) {
				// Range does not overlap with addressrange for this target
				return false;
			}

			low += addressOffset;
			if (high > addressMask) {
				high = addressOffset + addressMask;

			} else {
				high += addressOffset;
			}
			return true;
		}



template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
bool SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::getDMIPointer(int SocketId,
				transaction_type& trans,
				tlm::tlm_dmi&  dmi_data)
		{
			sc_dt::uint64 address = trans.get_address();

			unsigned int initiator_socket_id = decode(address);
			assert(initiator_socket_id < NR_OF_INITIATOR_SOCKETS);
			initiator_socket_type* decodeSocket = &initiator_socket[initiator_socket_id];
			sc_dt::uint64 maskedAddress = address & getAddressMask(initiator_socket_id);

			trans.set_address(maskedAddress);

			bool result =
				(*decodeSocket)->get_direct_mem_ptr(trans, dmi_data);

			if (result)
			{
				// Range must contain address
				assert(dmi_data.get_start_address() <= maskedAddress);
				assert(dmi_data.get_end_address() >= maskedAddress);
			}

			// Should always succeed
			sc_dt::uint64 start, end;
			start = dmi_data.get_start_address();
			end = dmi_data.get_end_address();

			limitRange(initiator_socket_id, start, end);

			dmi_data.set_start_address(start);
			dmi_data.set_end_address(end);

			return result;
		}



template <int NR_OF_TARGET_SOCKETS, int NR_OF_INITIATOR_SOCKETS>
void SimpleBus<NR_OF_TARGET_SOCKETS, NR_OF_INITIATOR_SOCKETS>::invalidateDMIPointers(int port_id,
				sc_dt::uint64 start_range,
				sc_dt::uint64 end_range)
		{
			// FIXME: probably faster to always invalidate everything?

			if (!limitRange(port_id, start_range, end_range)) {
				// Range does not fall into address range of target
				return;
			}

			for (unsigned int i = 0; i < NR_OF_TARGET_SOCKETS; ++i) {
				(target_socket[i])->invalidate_direct_mem_ptr(start_range, end_range);
			}
		}








template class SimpleBus<1, 1>;
