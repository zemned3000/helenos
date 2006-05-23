#ifndef _libc_ASYNC_H_
#define _libc_ASYNC_H_

#include <ipc/ipc.h>
#include <psthread.h>

int async_manager(void);
void async_create_manager(void);
void async_destroy_manager(void);
int _async_init(void);
ipc_callid_t async_get_call(ipc_call_t *data);

/* Should be defined by application */
pstid_t async_new_connection(ipc_callid_t callid, ipc_call_t *call,
			     void (*cthread)(ipc_callid_t,ipc_call_t *));
void client_connection(ipc_callid_t callid, ipc_call_t *call) __attribute__((weak));

#endif
