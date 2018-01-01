#include "NetClient.hpp"

CNetClient::CNetClient() = default;
CNetClient::~CNetClient() = default;

bool CNetClient::Connect(const char *hostname)
{
	return false;
};

void CNetClient::Disconnect(const char *reason, ...)
{
};

bool CNetClient::IsConnected() const
{
	return false;
};