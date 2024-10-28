#pragma once
#include <vector>
#include "directhook.h"

namespace directhook
{
	class MethodTable
	{
	public:
		MethodTable() {}

		template<typename D3DInterfaceT>
		void AddVTableEntries(D3DInterfaceT* d3dInterface, uint32 vtableEntriesCount)
		{
			methods.reserve(methods.size() + vtableEntriesCount);
			void** vTableBase = *reinterpret_cast<void***>(d3dInterface);
			for (uint32 i = 0; i < vtableEntriesCount; ++i)
			{
				methods.push_back(vTableBase[i]);
			}
		}

		void* operator[](uint32 i) const
		{
			return (void*)methods[i];
		}

	private:
		std::vector<void*> methods;
	};
}