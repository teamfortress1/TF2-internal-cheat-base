#include "netvars.h"

#include "../../valve/interfaces/interfaces.h"
#include "../win32/console.h"
#include <ctype.h>
#include <format>
#include <iostream>
#include <fstream>
void Netvars::SetupNetvars()
{
	for (auto clientClass = interfaces::client->getClientAllClass(); clientClass; clientClass = clientClass->next)
		if (clientClass->recvTable)
			Dump(clientClass->networkName, clientClass->recvTable);
}

void Dump(const char* baseClass, RecvTable* table, std::uint32_t offset)
{
	//std::fstream netvarfile;
	for (auto i = 0; i < table->propsCount; ++i)
	{
		const auto prop = &table->props[i];

		if (!prop || isdigit(prop->varName[0]))
			continue;

		if (fnv::Hash(prop->varName) == fnv::HashConst("baseclass"))
			continue;

		if (prop->recvType == SendPropType::DATATABLE &&
			prop->dataTable &&
			prop->dataTable->tableName[0] == 'D')
			Dump(baseClass, prop->dataTable, offset + prop->offset);

		const auto netvarName = std::format("{}->{}", baseClass, prop->varName);

		netvars[fnv::Hash(netvarName.c_str())] = offset + prop->offset;

		console::color(clr.red);
		/*std::cout << "[NETVAR] found netvar " << netvarName << " in class " << baseClass << "\n";

		netvarfile.open("netvars.txt", std::ios::out | std::ios::in | std::ios::app);

		if (netvarfile.is_open() == true)
		{
			netvarfile << "[NETVAR] " << netvarName << " found in class " << baseClass << "\n";
			netvarfile.close();
		}
		netvarfile.close();*/
	}
}