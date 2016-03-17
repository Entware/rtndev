	/*
Copyright (c) 2012, SgE
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the SgE nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL SgE BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//--------------------------------------------------------------------------------

MP709 control http://www.masterkit.ru/main/set.php?code_id=579540

to compile: gcc mp709.c -o mp709_sge_mips -lusb-1.0 -lpthread
*/

#include <libusb-1.0/libusb.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DEV_VID 0x16C0
#define DEV_PID 0x05DF
#define DEV_NAME "MP709"
#define DEV_CONFIG 1
#define DEV_INTF 0

unsigned char COMMAND_1[8] = {0xE7,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char COMMAND_2[8] = {0xE7,0x19,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char COMMAND_3[8] = {0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int main(int argc, char * argv[])
{
	if (argc != 2 
	||  argc == 2 && (strcasecmp(argv[1], "off") != 0) && (strcasecmp(argv[1], "on") != 0) && (strcasecmp(argv[1], "get") != 0))
		goto usage;

	libusb_device_handle *handle;
	libusb_device *device;
	int ret;
	unsigned char buf[8];
	unsigned char description[8];
	struct libusb_device_descriptor desc;

	ret = libusb_init(NULL);

	if (ret < 0) {
		printf("failed to initialize libusb!\n");
		goto exit;
	}

	libusb_set_debug(NULL, 3);
	handle = libusb_open_device_with_vid_pid(NULL, DEV_VID, DEV_PID);

	if (handle == NULL) {
		printf("no connected " DEV_NAME " found!\n");
		libusb_exit(NULL);
		goto exit;
	}

	if (libusb_kernel_driver_active(handle,DEV_INTF))
		libusb_detach_kernel_driver(handle, DEV_INTF);

	if ((ret = libusb_set_configuration(handle, DEV_CONFIG)) < 0) {
		printf(DEV_NAME "configuration failed!\n");

		goto done;
	}

	if (libusb_claim_interface(handle,  DEV_INTF) < 0) {
		printf(DEV_NAME " interface claim error!\n");

		goto finish;
	}

	device = libusb_get_device(handle);

	ret = libusb_get_device_descriptor(device, &desc);
	if (ret < 0)
	{
		printf("failed to get " DEV_NAME " descriptor\n");
		goto finish;
	} else {
		if (libusb_get_string_descriptor_ascii(handle, desc.iProduct, description, 8-1) <= 0 || strcmp(DEV_NAME, description) != 0 ) {
			printf("%s instead of " DEV_NAME " found!\n", description);
			ret = -1;
			goto finish;
		}
	}

	if (strcasecmp(argv[1], "on") == 0) 
	{
		ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_1, 8, 1000);
		if (ret > 0)
			printf("OK\n");
		else
			printf("FAIL\n");
	}

	if (strcasecmp(argv[1], "off") == 0) 
	{
		ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_2, 8, 1000);
		if (ret > 0)
			printf("OK\n");
		else
			printf("FAIL\n");
	}

	if (strcasecmp(argv[1], "get") == 0) {
		ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_3, 8, 1000);
		ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_IN, 0x1, 0x300, 0, COMMAND_3, 8, 1000);

		if (ret > 0)
			printf("%d\n", COMMAND_3[1] == 0x19 ? 0 : 1);
		else
			printf("FAIL\n");
	}

finish:
	libusb_attach_kernel_driver(handle, DEV_INTF);

done:
	libusb_close(handle);
	libusb_exit(NULL);

	if (ret > 0)
		exit(0);
	else
		goto exit;

usage:
	printf("Invalid parameters!\n");
	printf("Usage: mp709 <on|off|get>\n\n");
exit:
	exit(1);
}