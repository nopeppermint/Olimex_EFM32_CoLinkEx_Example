Olimex_EFM32_CoLinkEx_Example
=============================

Program Olimex EFM32 Boards with Olimex ARM-JTAG-Coocox (CoLinkEx) with Keil MDK-ARM-Lite:

I like Energymicro Microcontrollers and I found some cheap Olimex Boards with them. 
Then I searched a cheap debugger/programmer, I found the CoLinkEx or similar the 
Olimex ARM-JTAG-COOCOX. And now I program some example for these EFM32 Olimex Boards.


___________________________

You need:

1. Keil MDK-ARM-LITE with CoMDKPlugin or Coocox IDE or EmBlocks, CoLinkEx USB Driver,
2. Olimex ARM-JTAG-COOCOX (or another CoLinkEx) or J-Link
3. an Olimex EFM32 Board 
(at the moment only an example for the EM-32G10F128 and the EFM32G880F128-STK is available)

For more Information and direct Links please read "Program EFM32 with CoLinkEx and Keil.pdf"
___________________________

Version__0.6_______28.07.2013_______
-  add 02_LCD_Example_EM-32G880F128-STK, based on EFM32Gxxx_STK emlcd example f
Energy Micro for EmBlocks and Keil MDK-ARM
-  add J-Link to 02_Basic_Example_EFM32G880F128-STK_CooCox_CoIDE (still emlib 1.3.0)

___________________________

Version__0.5_______29.06.2013_______
- add example for EFM32G880F128-STK with Keil MDK-ARM and emlib 3.20.0
in folder 01_Basic_Example_EFM32G880F128-STK_Keil_MDK_ARM
- add example for EFM32G880F128-STK with CooCox CoIDE and emlib 1.3.0
in folder 02_Basic_Example_EFM32G880F128-STK_CoIDE

It's only a simple example with Systick Delay and Breakpoints in Debug Mode

___________________________

Version__0.4_______19.05.2013_______
- update emlib and EFM32G to new version 3.20.0

___________________________

Version__0.3_______27.03.2013_______

- add some Information about how to flash with CoLinkEx CoFlash Command Line

___________________________

Version__0.2_______06.02.2013_______

- axf to bin convert is not necessary, Sorry for wrong information
- add Ulink2 to Project, you can now switch between CoLinkEx and Ulink2
- correct comments

___________________________

Version__0.1_______05.02.2013_______ 

- Initial Version with one Blinky Example for EM-32G10F128 in 
00_Blinky_Keil_EM-32G10F128-H

___________________________

[![githalytics.com alpha](https://cruel-carlota.pagodabox.com/186d4a7ac27adcbf9b13761e64bb4288 "githalytics.com")](http://githalytics.com/nopeppermint/Olimex_EFM32_CoLinkEx_Example)

[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/nopeppermint/Olimex_EFM32_CoLinkEx_Example/trend.png)](https://bitdeli.com/free "Bitdeli Badge")