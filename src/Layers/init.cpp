/**
 * @file init.cpp
 * 
 * @brief The code for the init functions
 * 
 * @author DePianoman
 */

#include "init.h"
#include "Types/MenuLayer.h"

/**
 * Initialize the layer hooks
 */
void Layers::init() {
    MenuLayerHook::mem_init();
}