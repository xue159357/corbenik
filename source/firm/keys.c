#include <common.h>

#include <ctr9/aes.h>
#include <ctr9/sha.h>

#define FIRM_INTERNAL_CODE
#include <firm/internal.h>

int set_N11_K9L(uint32_t index) {
	static uint8_t ss_keyn[2][16] = {
        { 0 }, // 9.5
        { 0 }, // 9.6+
    };

    if (ss_keyn[0][0] == 0) {
        ss_keyn[0][0] = 1;
        FILE* key = fopen(PATH_SLOT0X11KEY95, "r");
        if (key) {
            fread(ss_keyn[0], 1, AES_BLOCK_SIZE, key);
            fclose(key);
        }
    }

    if (ss_keyn[1][0] == 0) {
        ss_keyn[1][0] = 1;
        FILE* key = fopen(PATH_SLOT0X11KEY96, "r");
        if (key) {
            fread(ss_keyn[1], 1, AES_BLOCK_SIZE, key);
            fclose(key);
        }
    }

    setup_aeskey(0x11, (void*) ss_keyn[index]);

	use_aeskey(0x11);

	return 0;
}

int set_Y3D_cetk(uint32_t index) {
	// From https://github.com/profi200/Project_CTR/blob/master/makerom/pki/prod.h#L19
	static uint8_t common_keyy[6][16] = {
		{0xD0, 0x7B, 0x33, 0x7F, 0x9C, 0xA4, 0x38, 0x59, 0x32, 0xA2, 0xE2, 0x57, 0x23, 0x23, 0x2E, 0xB9} , // 0 - eShop Titles
		{0x0C, 0x76, 0x72, 0x30, 0xF0, 0x99, 0x8F, 0x1C, 0x46, 0x82, 0x82, 0x02, 0xFA, 0xAC, 0xBE, 0x4C} , // 1 - System Titles
		{0xC4, 0x75, 0xCB, 0x3A, 0xB8, 0xC7, 0x88, 0xBB, 0x57, 0x5E, 0x12, 0xA1, 0x09, 0x07, 0xB8, 0xA4} , // 2
		{0xE4, 0x86, 0xEE, 0xE3, 0xD0, 0xC0, 0x9C, 0x90, 0x2F, 0x66, 0x86, 0xD4, 0xC0, 0x6F, 0x64, 0x9F} , // 3
		{0xED, 0x31, 0xBA, 0x9C, 0x04, 0xB0, 0x67, 0x50, 0x6C, 0x44, 0x97, 0xA3, 0x5B, 0x78, 0x04, 0xFC} , // 4
		{0x5E, 0x66, 0x99, 0x8A, 0xB4, 0xE8, 0x93, 0x16, 0x06, 0x85, 0x0F, 0xD7, 0xA1, 0x6D, 0xD7, 0x55} , // 5
	};

	setup_aeskeyY(0x3D, (void*) common_keyy[index]);

	use_aeskey(0x3D);

	return 0;
}
