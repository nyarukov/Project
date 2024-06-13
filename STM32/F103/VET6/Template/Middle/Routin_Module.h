#ifndef __ROUTIN_MODULE
#define __ROUTIN_MODULE

#include "bf_middle.h"

typedef struct
{
    int Src;
    int Dst;
    Status (*Send)(int _Src, int _Dst, void * _pBuf, int _Len);
    Status (*Recv)(int _Src, int _Dst, void * _pBuf, int _Len);
    struct bf_list *list;
}Routin_Module;

typedef struct
{
    unsigned char *name;
    void (*init)(void);
    
}s;

Status Routin_Register(Routin_Module *_Routin);


#endif // !__ROUTIN_MODULE
