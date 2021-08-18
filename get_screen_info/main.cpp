/////////////////////////////////////////////////////
// DEVELOPER: Dibe
// 
// FILE: main.cpp
/////////////////////////////////////////////////////

#include <iostream>
#include <fcntl.h>
#include <string.h>
#include <string>
#include <sys/ioctl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <linux/fb.h>

#define SCREEN_FILE "/dev/fb0"   // device screen to be opened

// Show the menu of the application	
void displayMenu()
{
	std::cout.setf(std::ios::right);
	std::cout.width(25);
	std::cout << "--== SCREEN INFO ==--" << std::endl << std::endl;
	std::cout.unsetf(std::ios::right);
	std::cout << "1. Fixed Screen Info" << std::endl;
	std::cout << "2. Variable Screen Info" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << std::endl;
	std::cout << "ENTER YOUR OPTION: ";
}

// check the menu selection, and base on the choice display the information about available:
// fixed screen(visual, accelerator, capabilities), or 
// variable screen (screen resolution, bits per pixel)
void checkSelection(int& option, const int& fd)
{
	int retVal;

	switch(option){
		case 1:
			std::cout << std::endl << "--== FIXED SCREEN INFORMATION ==--" << std::endl;
			struct fb_fix_screeninfo fixScreen;
			retVal = ioctl(fd, FBIOGET_FSCREENINFO, &fixScreen);
			if(retVal < 0) {
         	std::cout << strerror(errno) << std::endl;
         } else {
				// ARRAYS CONTAINING LISTS OF DESCRIPTIONS ABOUT:
				// - Visual
				// - Accelerator
				// - Capabilities
				std::string visual[7] = {"Monochr. 1=Black 0=White","Monochr. 1=White 0=Black","True color","Pseudo color (like atari)","Direct color","Pseudo color readonly", "Visual identified by a V4L2 FOURCC"};
				std::string accel[100] = {"no hardware accelerator","Atari Blitter","Amiga Blitter","Cybervision64 (S3 Trio64)","RetinaZ3 (NCR 77C32BLT)","Cybervision64/3D (S3 ViRGE)","ATI Mach 64GX family","DEC 21030 TGA","ATI Mach 64CT family","ATI Mach 64CT family VT class","ATI Mach 64CT family GT class","Sun Creator/Creator3D","Sun cg6","Sun leo/zx","IMS Twin Turbo","3Dlabs Permedia 2","Matrox MGA2064W (Millenium)","Matrox MGA1064SG (Mystique)","Matrox MGA2164W (Millenium II)","Matrox MGA2164W (Millenium II)","Matrox G100 (Productiva G100)","Matrox G200 (Myst, Mill, ...)","Sun cgfourteen","Sun bwtwo","Sun cgthree","Sun tcx","Matrox G400","nVidia RIVA 128","nVidia RIVA TNT","nVidia RIVA TNT2","C&T 6555x","3Dfx Banshee","ATI Rage128 family","CyberPro 2000","CyberPro 2010","CyberPro 5000","SiS 300/630/540","3Dlabs Permedia 3","ATI Radeon family","Intel 810/815","SiS 315, 650, 740","SiS 330 (\"Xabre\")","Intel 830M/845G/85x/865G","nVidia Arch 10","nVidia Arch 20","nVidia Arch 30","nVidia Arch 40","XGI Volari V3XT, V5, V8","XGI Volari Z7","TI OMAP16xx","Trident TGUI","Trident 3DImage","Trident Blade3D","Trident BladeXP"};
				std::string cap[2] = {"No Information","Device supports FOURCC-based formats"};
				// -------------------------------------------------
				
				// Display Info
				std::cout << "-> Screen Visual #: " << fixScreen.visual;		// 2
				std::cout << " [" << visual[fixScreen.visual] << "]" << std::endl;
				std::cout << "-> Screen Accelerator: " << fixScreen.accel;  // 0
				std::cout << " [" << accel[fixScreen.accel] << "]" << std::endl;		
				std::cout << "-> Screen Capabilities: " << fixScreen.capabilities; // 0
				std::cout << " [" << cap[fixScreen.capabilities] << "]" << std::endl;	
				std::cout << "---------------------------------" << std::endl;			
			}
	
			break;

		case 2:
			std::cout << std::endl << "--== FIXED SCREEN INFORMATION ==--" << std::endl;
			struct fb_var_screeninfo varScreen;
			retVal = ioctl(fd, FBIOGET_VSCREENINFO, &varScreen);
			if(retVal < 0) {
         	std::cout << strerror(errno) << std::endl;
         } else {
				std::cout << "-> Screen X Resolution: " << varScreen.xres << " pixels" << std::endl; // 880			
				std::cout << "-> Screen Y Resolution: " << varScreen.yres << " pixels" << std::endl; // 480			
				std::cout << "-> Bits Per Pixel: " << varScreen.bits_per_pixel << std::endl; // 32
				std::cout << "---------------------------------" << std::endl;			
			}
			break;

		case 0:
			break;

		default:
			std::cout << "Please, enter one of the options available: ";
	}
}

// clear the remain characters in buffer
// if the user has typed something that is
// not one of the choices of the menu
void clearBuffer()
{
	std::cin.clear();
	std::cin.ignore(100,'\n');
}

// wait the user to enter one of the options from the menu
// and validates if it is a one of the listed choices
void enterOption(const int& fd)
{	
	int option = -1;
	do {
		std::cin >> option;
		if(std::cin.fail())
		{
			clearBuffer();
			option = -1;
		}
		checkSelection(option, fd);
		
		if(option == 1 || option == 2)
		{
			option = -1; // reseting the option
			std::cout << "Now, try another option: ";
		}

	} while(option < 0 || option > 2);
	
}


int main()
{
	bool rc = true;
	int fd;
	int flags = O_RDONLY | O_NONBLOCK; // open file device in read only and non-blocking mode	
	
	system("clear");
	std::cout << std::endl << std::endl;
	std::cout << "==================================" << std::endl;	
	std::cout << "Opening file: " << SCREEN_FILE << std::endl;
	std::cout << "==================================" << std::endl << std::endl;	
	fd = open(SCREEN_FILE, flags); // open the device
	
	// Check if the device could not be opened
	// then display the error message
	if(fd < 0)
	{
		std::cout << "Open Err: " << strerror(errno) << std::endl;
		rc = false;
	}

	// Check if the file could be opened
	// then get then get the info
	if(rc){
		displayMenu();
		enterOption(fd);
	}
	std::cout << std::endl;		
	std::cout << "==================================" << std::endl;	
	std::cout << "Closing file: " << SCREEN_FILE << std::endl;
	std::cout << "==================================" << std::endl;	
	close(fd);

	std::cout << std::endl;
	std::cout << "BYE BYE! =)" << std::endl << std::endl;
}
