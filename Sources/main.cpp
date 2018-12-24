#include "cheats.hpp"

namespace CTRPluginFramework
{
	void	PatchProcess(FwkSettings &settings) { }

	int	main()
	{
		PluginMenu *menu = new PluginMenu("たこPlugin", 0, 0, 1);
		menu->SynchronizeWithFrame(true);


		MenuFolder *folder = nullptr, *subfolder = nullptr, *subsubfolder = nullptr;
		
		menu->Append(new MenuEntry("カスタムキーボード(ひらがなOLD3DS専用)",custom_old));
		menu->Append(new MenuEntry("カスタムキーボード(ひらがなNEW3DS専用)",custom_new));
		menu->Append(new MenuEntry("プロフの文字列をプレイヤー名にする(OLD3DS専用(Aボタン))",No_1));
		menu->Append(new MenuEntry("プロフの文字列をプレイヤー名にする(NEW3DS専用(Aボタン))",No_2));

		menu->Run();
		return 0;
	}
}