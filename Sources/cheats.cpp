#include "cheats.hpp"
#define NUM 60
#define NEW_3DS 0x03C00000

namespace CTRPluginFramework
{
	void	No_1(MenuEntry *entry)
	{
		if (Controller::IsKeyDown(Key::A))
		{
			memcpy((u32*)(0x87871C0),(u32*)(0x8790088),0x20);
		}
	}
	
	void	No_2(MenuEntry *entry)
	{
		if (Controller::IsKeyDown(Key::A))
		{
			memcpy((u32*)(0x87871C0 + NEW_3DS),(u32*)(0x8790088 + NEW_3DS),0x20);
		}
	}
	
	void	custom_old(MenuEntry *entry)
	{
		File fp;
		u32 add_off = 0x0865E8A0;
		u16 JP[NUM];
		if(File::Open(fp,"hminer.txt",File::RW) == 0)
		{
			for(int i=0;i<NUM;i++)
			{
				fp.File::Read(&JP[i],0x02);
				Process::Write16(add_off + (i * 0x03),JP[i]);
			}
			fp.File::Close();
		}
	}
	
	void	custom_new(MenuEntry *entry)
	{
		File fp;
		u32 add_off = 0x0865E8A0 + NEW_3DS;
		u16 JP[NUM];
		if(File::Open(fp,"hminer.txt",File::RW) == 0)
		{
			for(int i=0;i<NUM;i++)
			{
				fp.File::Read(&JP[i],0x02);
				Process::Write16(add_off + (i * 0x03),JP[i]);
			}
			fp.File::Close();
		}
	}
}