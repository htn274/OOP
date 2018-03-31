#include "CGAME.h"

CGAME::CGAME()
{
	m_level = 0;
	m_numObj = { 0, 0, 0, 0 };
}

CGAME::CGAME(int level)
{
	this->CGAME::CGAME();
	m_level = level;
	CObject* x = new CPeople();
	m_obj.push_back(x);

	int numEachType = MIN_SO_LUONG + (m_level - 1);
	//Sinh làn xe hơi
	srand(time(NULL));
	int d;
	x = new CAR(YCAR);
	m_obj.push_back(x);
	int s = m_obj.size() - 1;
	for (int i = 1; i < numEachType; i++) {
		x = new CAR();
		m_obj.push_back(x);
		d = MIN_DISTANCE + rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + (MAX_DISTANCE - m_level);
		m_obj[s + i]->init(m_obj[s + i - 1], d, CREATE_RIGHT);
		if (m_obj[s + i]->isFull(m_obj[s])) {
			delete m_obj[s + i];
			m_obj.erase(m_obj.end() - 1);
			numEachType = i;
			break;
		}
	}
	m_numObj[0] = numEachType;

	//Sinh làn xe tải
	srand(time(NULL));
	x = new TRUCK(YTRUCK);
	m_obj.push_back(x);
	s = m_obj.size() - 1;
	numEachType = MIN_SO_LUONG + (m_level - 1);
	for (int i = 1; i < numEachType; i++) {
		x = new TRUCK();
		m_obj.push_back(x);
		d = MIN_DISTANCE + rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + (MAX_DISTANCE - m_level);
		m_obj[s + i]->init(m_obj[s + i - 1], d, CREATE_RIGHT);
		if (m_obj[s + i]->isFull(m_obj[s])) {
			delete m_obj[s + i];
			m_obj.erase(m_obj.end() - 1);
			numEachType = i;
			break;
		}
	}
	m_numObj[1] = numEachType;

	//Sinh làn khủng long
	srand(time(NULL));
	x = new DINOSAUR(YDINOSAUR);
	m_obj.push_back(x);
	s = m_obj.size() - 1;
	numEachType = MIN_SO_LUONG + (m_level - 1);
	for (int i = 1; i < numEachType; i++) {
		x = new DINOSAUR();
		m_obj.push_back(x);
		d = MIN_DISTANCE + rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + (MAX_DISTANCE - m_level);
		m_obj[s + i]->init(m_obj[s + i - 1], d, CREATE_RIGHT);
		if (m_obj[s + i]->isFull(m_obj[s])) {
			delete m_obj[s + i];
			m_obj.erase(m_obj.end() - 1);
			numEachType = i;
			break;
		}
	}
	m_numObj[2] = numEachType;

	//Sinh chim
	createBird(YCAR - 3);
	createBird(YTRUCK - 4);
	createBird(YDINOSAUR - 4);
	//for (int i = 0; i < 4; i++) cout << m_numObj[i] << " ";
}

CGAME::CGAME(CGAME && game)
{
	this->~CGAME();
	this->m_level = game.m_level;
	this->m_numObj = game.m_numObj;

	this->m_obj = game.m_obj;

	game.m_obj.clear();
}

CGAME::~CGAME()
{
	m_level = 0;
	for (int i = 0; i < m_obj.size(); i++)
		delete[]m_obj[i];
}

void CGAME::drawLoad()
{
	char ch = 177;
	int x = CONSOLE_WIDTH / 2 - 10, y = CONSOLE_HEIGHT / 2;
	GotoXy(x, y);
	cout << "Loading...";
	TextColor(11);
	GotoXy(x, y + 2);
	for (int r = 1; r <= 20; r++)
	{
		for (int q = 0; q <= 100000000; q++); //to display the character slowly
		cout << ch;
	}
	TextColor(15);
}

void CGAME::drawScence()
{
	drawBoard(BOARD_STARTX, BOARD_STARTY, BOARD_ENDX, BOARD_ENDY);

	int y = BOARD_STARTY + 1;
	while (y < BOARD_ENDY) {
		drawDaiPhanCach(y);
		y += 8;
	}
}

void CGAME::drawGame()
{
	clrscr();
	string str = "LEVEL: " + to_string(m_level);
	GotoXy((BOARD_ENDX- str.length()) / 2, 0);
	printf("%s", str.c_str());
	drawScence();
	drawObject();
	
	//draw Instruction
	int x = BOARD_ENDX + 5;
	int y = BOARD_STARTY + 10;
	TextColor(14);
	drawBoard(x - 1, y - 2, x + 15, y + 9);
	GotoXy(x, y - 2); printf("INSTRUCTION");
	string instruct[8] = {"A  : Move left ", 
						  "D  : Move right", 
						  "W  : Move up   ", 
						  "S  : Move down ", 
		                  "L  : Save game ", 
						  "T  : Load game ", 
						  "P  : Pause game", 
						  "ESC: Main menu "};
	for (int i = 0; i < 8; i++) {
		GotoXy(x, y + i);
		printf("%s\n", instruct[i].c_str());
	}
	TextColor(15);
}

void CGAME::startGame()
{
	clrscr();
	drawLoad();
	ShowConsoleCursor(false);
	int tmp = m_level;
	this->~CGAME();
	if (tmp == MAX_LEVEL) tmp = 0;
	new (this) CGAME(tmp + 1);
	drawGame();
}

void CGAME::updatePosObject(char direct)
{
	m_obj[0]->updatePos(direct);
	//Cập nhật vị trí xe va dinosaur
	for (int i = 1; i < m_obj.size() - m_numObj[3]; i++) {
		m_obj[i]->updatePos(LEFT);
	}
	
	//Cập nhật vị trí chim
	for (int i = m_obj.size() - m_numObj[3]; i < m_obj.size(); i++)
		m_obj[i]->updatePos(RIGHT);
}

bool CGAME::isOver()
{
	return m_obj[0]->isDead();
}

bool CGAME::isCrash()
{
	for (int i = 1; i < m_obj.size(); i++)
		if (m_obj[0]->isImpact(m_obj[i])) return true;
	return false;
}

void CGAME::Over()
{
	//clrscr();
	m_obj[0]->Die();
	m_level = 0;
	//pauseGame();
	TextColor(31);
	string str = "Game over!:( Try one more time!";
	GotoXy((BOARD_ENDX - str.length()) / 2, CONSOLE_HEIGHT / 2);
	cout << str;
	TextColor(15);
}

bool CGAME::isFinish()
{
	return m_obj[0]->isWin();
}

void CGAME::afterFinish()
{
	startGame();
}

void CGAME::saveGame()
{
	clrscr();
	char dir[100];
	dir[0] = '\0';
	string str = "Enter file name: ";
	int x = (CONSOLE_WIDTH - str.length())/ 2;
	int y = CONSOLE_HEIGHT / 2;
	strcat(dir, getFileName(str, x, y));

	if (writeFile(dir)) {
		GotoXy(x, y + 1);
		printf("Save successful! Press Enter to continue");
		char ch = 'A';
		do {
			ch = _getch();
			if (ch == KEY_ENTER) {
				clrscr();
				this->drawGame();
				//this->resumeGame();
				break;
			}
		} while (ch != 'Y' && ch !='N');
	}
}

bool CGAME::writeFile(char* fileName)
{
	FILE* f = fopen(fileName, "w");
	if (f) {
		fprintf(f, "%d\n", this->m_level);
		for (int i = 0; i < m_numObj.size(); i++)
			fprintf(f, "%d ", m_numObj[i]);
		for (int i = 0; i < m_obj.size(); i++) {
			m_obj[i]->writeToFile(f);
		}
	}
	else return false;
	fclose(f);
	return true;
}

bool CGAME::loadGame()
{
	//this->pauseGame();
	bool checkReadFile = false;
	char ch = 'A';
	do {
		clrscr();
		char dir[100]; dir[0] = '\0';
		string str = "Enter file name: ";
		int x = 10;
		int y = CONSOLE_HEIGHT / 2;
		strcat(dir, getFileName(str, x, y));
		checkReadFile = readFile(dir);
		if (checkReadFile) {
			clrscr();
			this->drawGame();
			//this->resumeGame();
			return true;
		}
		else {
			string str1 = "Can not open file! Do you want to continue load game? (Y/N)";
			GotoXy(x, y + 1);
			printf("%s", str1.c_str());
			ch = toupper(_getch());
		}
	} while ((ch == 'Y'));
	return false;
}

bool CGAME::readFile(char * fileName)
{
	FILE *f = fopen(fileName, "r");
	if (f) {
		CGAME newGame;
		fscanf(f, "%d", &newGame.m_level);
		for (int i = 0; i < 4; i++)
			fscanf(f, "%d", &newGame.m_numObj[i]);
		
		int totalNum = 1;
		for (int i = 0; i < 4; i++) totalNum += newGame.m_numObj[i];

		CObject *x;
		int t;
		for (int i = 0; i < totalNum; i++) {
			fscanf(f, "%d", &t);
			x = ObjectFactory::createObject(t);
			x->readFromFile(f);
			newGame.m_obj.push_back(x);
		}

		this->CGAME::CGAME(std::forward<CGAME>(newGame));
	}
	else return false;
	fclose(f);
	return true;
}

int CGAME::getLevel()
{
	return this->m_level;
}


void CGAME::drawDaiPhanCach(int y)
{
	const char c = 176;
	for (int x = BOARD_STARTX + 1; x < BOARD_ENDX; x++) 
	if (!m_obj[0]->Thuoc(x,y)){
		GotoXy(x, y); cout << c;
	}
		//m_map[y][x] = c;
}

void CGAME::drawObject()
{
	m_obj[0]->draw(193);
	for (int i = 1; i < m_obj.size() - m_numObj[3]; i++) {
		m_obj[i]->draw(219);
		m_obj[i]->drawTrafficLight();
	}
	for (int i = m_obj.size() - m_numObj[3]; i < m_obj.size(); i++)
		m_obj[i]->draw(254);
}

void CGAME::createBird(int yBird)
{
	
	CObject* x = new BIRD(yBird);
	m_obj.push_back(x);
	int s = m_obj.size() - 1;
	int num = MIN_SO_LUONG + (m_level - 1) * 3;
	for (int i = 1; i < num; i++) {
		x = new BIRD();
		m_obj.push_back(x);
		srand(time(NULL));
		int d = MIN_DISTANCE + rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + (MAX_DISTANCE - m_level);
		m_obj[s + i]->init(m_obj[s + i - 1], d, CREATE_LEFT);
		if (m_obj[s + i]->isFull(m_obj[s])) {
			delete m_obj[s + i];
			m_obj.erase(m_obj.end() - 1);
			num = i;
			break;
		}
	}
	m_numObj[3] += num;
}

char * CGAME::getFileName(string str, int x, int y)
{
	char dir[100];
	GotoXy(x, y);
	printf("%s", str.c_str());
	ShowConsoleCursor(true);
	scanf("\n");
	gets_s(dir);
	ShowConsoleCursor(false);
	return dir;
}

