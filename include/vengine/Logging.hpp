/// @file

#pragma once

void VENGLOG(const char *asMsg, ...);
void VENGERR(const char *asMsg, ...);
void VENGWARN(const char *asMsg, ...);

#ifdef VENGINE_DEBUG
void VENGLOG(const char *asMsg, ...)
{
};

void VENGERR(const char *asMsg, ...)
{
};

void VENGWARN(const char *asMsg, ...)
{
};
#else
void VENGLOG(const char *asMsg, ...){}
void VENGERR(const char *asMsg, ...){}
void VENGWARN(const char *asMsg, ...){}
#endif