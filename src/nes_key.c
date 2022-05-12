#include "nes_key.h"


static bool nes_keys[9];

void nes_set_key(int key){

	nes_keys[key] = true;
}

int nes_get_key(int key){
    switch (key)
	{
        case 0: // On / Off
            return 1;
        case 1: // A
            return GetKey(37);//K
        case 2: // B
            return GetKey(36);;//J
        case 3: // SELECT
            return GetKey(22);//U
        case 4: // START
            return GetKey(23);//I
        case 5: // UP
            return GetKey(17);//W
        case 6: // DOWN
            return GetKey(31);//S
        case 7: // LEFT
            return GetKey(30);//A
        case 8: // RIGHT
            return GetKey(32);//D
        default:
            return 1;
    }
}
