# LG 32UN880 Monitor Brightness control

The target of this project is to find a way to control the brightness of the monitor per USB.

## Related Work

Some monitors of the "ultrafine" line are already supported by operating systems like Windows and MaxOsX. The tool [LG-Ultrafine-Brightness 2](https://github.com/Willian-Zhang/LG-Ultrafine-Brightness-2) alredy implemented such a control. The [implementation](https://github.com/Willian-Zhang/LG-Ultrafine-Brightness-2/blob/master/LG-Ultrafine-Brightness/LGUltraFine.cpp) use the [library libhid](https://github.com/signal11/hidapi/blob/master/libusb/hid.c) using [library libusb](https://libusb.info/) as most tools do.

# Todos
- [x] find Lib to access the usb an interface at all
- [x] access the monitor interface
- [ ] read out current brightness
- [ ] change monitor brightness

# Log
## 2022-06-25 bring the project online

## Future Work