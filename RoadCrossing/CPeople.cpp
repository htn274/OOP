#include "CPeople.h"

CPeople::CPeople()
{
	m_width = 1;
	m_height = 2;
	m_y = BOARD_ENDY - 1;
	m_x = BOARD_ENDX / 2;
	m_state = true;
	m_type = 0;
}

void CPeople::draw(char ch)
{
	GotoXy(m_x, m_y);
	printf("%c", ch);
	GotoXy(m_x, m_y - 1);
	printf("%c", char(254));
}

void CPeople::updatePos(char direct)
{
	GotoXy(m_x, m_y);
	printf(" ");
	GotoXy(m_x, m_y - 1);
	printf(" ");
	switch (direct) {
	case UP: Up(); break;
	case KEY_UP: Up(); break;
	case DOWN: Down(); break;
	case KEY_DOWN: {
		Down(); break;
	}
	case LEFT: Left(); break;
	case KEY_LEFT: Left(); break;
	case RIGHT: Right(); break;
	case KEY_RIGHT: Right(); break;
	}
	this->draw(193);
}

bool CPeople::isDead()
{
	return !m_state;
}

bool CPeople::isImpact(CObject * obj)
{
	for (int i = 0; i < m_width; i++)
		for (int j = 0; j < m_height; j++)
			if (obj->Thuoc(m_x + i, m_y - j)) return true;
	return false;
}

void CPeople::Die()
{
	m_state = false;
}

bool CPeople::isWin()
{
	return (m_y - m_height == BOARD_STARTY);
}


