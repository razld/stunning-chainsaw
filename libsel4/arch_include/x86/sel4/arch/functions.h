/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef __LIBSEL4_ARCH_FUNCTIONS_H
#define __LIBSEL4_ARCH_FUNCTIONS_H

#include <sel4/types.h>
#include <sel4/sel4_arch/functions.h>

static inline seL4_Word
seL4_GetMR(int i)
{
    seL4_Word mr;
    SEL4_GET_IPCBUF_SCALE(msg, i, mr);
    return mr;
}

static inline void
seL4_SetMR(int i, seL4_Word mr)
{
    SEL4_SET_IPCBUF_SCALE(msg, i, mr);
}

static inline seL4_Word
seL4_GetUserData(void)
{
    seL4_Word data;
    SEL4_GET_IPCBUF(userData, data);
    return data;
}

static inline void
seL4_SetUserData(seL4_Word data)
{
    SEL4_SET_IPCBUF(userData, data);
}

static inline seL4_CapData_t
seL4_GetBadge(int i)
{
    seL4_CapData_t badge;
    SEL4_GET_IPCBUF_SCALE(caps_or_badges, i, badge.words[0]);
    return badge;
}

static inline seL4_CPtr
seL4_GetCap(int i)
{
    seL4_CPtr cap;
    SEL4_GET_IPCBUF_SCALE(caps_or_badges, i, cap);
    return cap;
}

static inline void
seL4_SetCap(int i, seL4_CPtr cptr)
{
    SEL4_SET_IPCBUF_SCALE(caps_or_badges, i, cptr);
}

static inline void
seL4_GetCapReceivePath(seL4_CPtr* receiveCNode, seL4_CPtr* receiveIndex, seL4_Word* receiveDepth)
{
    if (receiveCNode != seL4_Null) {
        SEL4_GET_IPCBUF(receiveCNode, *receiveCNode);
    }

    if (receiveIndex != seL4_Null) {
        SEL4_GET_IPCBUF(receiveIndex, *receiveIndex);
    }

    if (receiveDepth != seL4_Null) {
        SEL4_GET_IPCBUF(receiveDepth, *receiveDepth);
    }
}

static inline void
seL4_SetCapReceivePath(seL4_CPtr receiveCNode, seL4_CPtr receiveIndex, seL4_Word receiveDepth)
{
    SEL4_SET_IPCBUF(receiveCNode, receiveCNode);
    SEL4_SET_IPCBUF(receiveIndex, receiveIndex);
    SEL4_SET_IPCBUF(receiveDepth, receiveDepth);
}

static inline seL4_IPCBuffer*
seL4_GetIPCBuffer(void)
{
    /* Assume that the address of our IPC buffer is in the user data word. Our
     * parent (or seL4_InitBootInfo in the case of the root task) should have
     * ensured this is true. The user is free to overwrite this data with
     * something else, but should then be aware they lose the functionality of
     * this function.
     */
    return (seL4_IPCBuffer*)seL4_GetUserData();
}

#endif
