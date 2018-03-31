#include "Menu.h"

void Menu::drawTitle()
{
	int y = 0;
	for (int i = 0; i < m_title.size(); i++){
		int x = (CONSOLE_WIDTH - m_title[i].length()) / 2;
		GotoXy(28, y + i);
		cout << m_title[i];
	}
}

Menu::Menu()
{
	m_width = MENU_WIDTH;
	m_height = MENU_HEIGHT;
	m_x = CONSOLE_WIDTH / 2 - 4;
}

void Menu::draw()
{
	clrscr();
	ShowConsoleCursor(false);
	string str = "    MAIN MENU    ";
	GotoXy(m_x + (10 - str.length())/2, m_y[0] - 3);
	TextColor(31);  printf("%s", str.c_str()); TextColor(15);
	drawTitle();
	for (int i = 0; i < MAX_CHOICE; i++){
		drawBoard(m_x - 2, m_y[i] - 1, m_x + 10 , m_y[i] + 1);
		GotoXy(m_x, m_y[i]);
		string s = m_list[i];
		printf("%s", s.c_str());
	}
}

int Menu::updateChoice()
{
	int i = 0;
	while (1) {
		//GotoXy(m_x - 1, m_y[i]);
		//printf("%c", 175);
		GotoXy(m_x, m_y[i]);
		TextColor(14);
		printf("%s", m_list[i].c_str());
		switch (_getch()) {
		case KEY_UP: {
			if (i > 0)
			{
				GotoXy(m_x, m_y[i]);
				TextColor(15);
				printf("%s", m_list[i].c_str());
				i--;
			}
			break;
		}
		case KEY_DOWN: {
			if (i < MAX_CHOICE - 1) {
				GotoXy(m_x, m_y[i]);
				TextColor(15);
				printf("%s", m_list[i].c_str());
				i++;
			}
			break;
		}
		case KEY_ENTER: {
			TextColor(15);
			return i;
		}
		default: break;
		}
	}
}

void Menu::drawSettings()
{
	clrscr();
	ShowConsoleCursor(false);
	drawTitle();
	string str = "    SETTINGS    ";
	GotoXy(m_x + (10 - str.length()) / 2, m_y[0] - 3);
	TextColor(31);  printf("%s", str.c_str()); TextColor(15);
	
	drawBoard(m_x - 2, m_y[0] - 1, m_x + 11, m_y[0] + 1);
	GotoXy(m_x, m_y[0]);
	string s = m_settingList[0];
	printf("%s <%d>", s.c_str(), levelStart);

	drawBoard(m_x - 2, m_y[1] - 1, m_x + 11, m_y[1] + 1);
	GotoXy(m_x, m_y[1]);
	s = m_settingList[1];
	printf("%s <%s>", s.c_str(), musicState[music].c_str());
}

void Menu::setting()
{
	drawSettings();
	updateSetting();
}

void Menu::updateSetting()
{
	int i = 0;
	while (1) {
		//GotoXy(m_x - 1, m_y[i]);
		//printf("%c", 175);
		GotoXy(m_x, m_y[i]);
		TextColor(14);
		printf("%s", m_settingList[i].c_str());
		switch (_getch()) {
		case KEY_UP: {
			if (i > 0)
			{
				GotoXy(m_x, m_y[i]);
				TextColor(15);
				printf("%s", m_settingList[i].c_str());
				i--;
			}
			break;
		}
		case KEY_DOWN: {
			if (i < 1) {
				GotoXy(m_x, m_y[i]);
				TextColor(15);
				printf("%s", m_settingList[i].c_str());
				i++;
			}
			break;
		}
		case ESC: {
			TextColor(15);
			return;
		}
		default: break;
		}
	}
}

