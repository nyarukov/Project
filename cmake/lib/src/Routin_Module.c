/**
 * @file Routin_Module.c
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Routin_Module.h"

Routin_Module *root;

Status Routin_Register(int _Src, int _Dst, 
                        Status (*Sned)(int _Src, ...), 
                        Status (*Recv)(int _Src, ...))
{
    // Routin_Module *Node = bf_new_node(Routin_Module);

    // bf_get_elem(Node, Routin_Module)->Src = _Src;
    // bf_get_elem(Node, Routin_Module)->Dst = _Dst;
    // bf_get_elem(Node, Routin_Module)->Send = Sned;
    // bf_get_elem(Node, Routin_Module)->Recv = Recv;
    
    // bf_list_insert_later(root, Node);
}
