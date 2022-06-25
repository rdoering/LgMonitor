#include <stdio.h>
#include <wchar.h>
#include <assert.h>

#include <hidapi_darwin.h>

#define MAX_STR 255

int main(int argc, char *argv[])
{
	int res;
	unsigned char buf[65];
	wchar_t wstr[MAX_STR];
	hid_device *handle;
	int i;

	assert(hid_init() == 0);

	handle = hid_open(0x043e, 0x9a39, NULL);
	assert(handle != NULL);

    uint8_t data[7] = { 0 };
	res = hid_get_feature_report(handle, data, sizeof(data));
	printf("hid_get_feature_report: %d\n", res);
	if(res < 0) {
		wprintf(L"hid_get_feature_report failed: %ls\n", hid_error(handle));
	}


	// Read the Manufacturer String
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	wprintf(L"Manufacturer String: %ls\n", wstr);

	// Read the Product String
	res = hid_get_product_string(handle, wstr, MAX_STR);
	wprintf(L"Product String: %ls\n", wstr);

	// Read the Serial Number String
	res = hid_get_serial_number_string(handle, wstr, MAX_STR);
	wprintf(L"Serial Number String: (%d) %ls\n", wstr[0], wstr);

	// Read Indexed String 1
	res = hid_get_indexed_string(handle, 1, wstr, MAX_STR);
	wprintf(L"Indexed String 1: %ls\n", wstr);

	// Toggle LED (cmd 0x80). The first byte is the report number (0x0).
	buf[0] = 0x0;
	buf[1] = 0x80;
	res = hid_write(handle, buf, 65);

	// Request state (cmd 0x81). The first byte is the report number (0x0).
	buf[0] = 0x0;
	buf[1] = 0x81;
	res = hid_write(handle, buf, 65);

	// Read requested state
	res = hid_read(handle, buf, 65);

	// Print out the returned buffer.
	for (i = 0; i < 4; i++)
		printf("buf[%d]: %d\n", i, buf[i]);

    
	hid_close(handle);

	// Finalize the hidapi library
	res = hid_exit();

	return 0;
}