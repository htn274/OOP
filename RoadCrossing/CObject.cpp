#include "CObject.h"

void CObject::init(int y)
{
	m_width = 3;
	m_height = 3;
	m_x = (BOARD_ENDX/2) - 20;
	m_y = y;
}

void CObject::init(const CObject *obj, int d, int direct)
{
	this->m_x = obj->m_x + d * direct;
	this->m_y = obj->m_y;
	this->m_width = obj->m_width;
	this->m_height = obj->m_height;
}

void CObject::Up()
{
	if (m_y > BOARD_STARTY + 1) m_y--;
}

void CObject::Left()
{
	if (m_x > BOARD_STARTX + 1) m_x--;
}

void CObject::Right()
{
	if (m_x < BOARD_ENDX - 1) m_x++;
}

void CObject::Down()
{
	if (m_y < BOARD_ENDY - 1) m_y++;
}

bool CObject::Thuoc(int x, int y)
{
	for (int i = 0; i < m_width; i++)
		for (int j = 0; j < m_height; j++)
			if (x == m_x + i && y == m_y - j)
				return true;
	return false;
}

bool CObject::IsHitBoard()
{
	return (m_x == BOARD_STARTX + 1|| m_x + m_width == BOARD_ENDX);
}

bool CObject::isOutBoard()
{
	return (m_x < BOARD_STARTX + 1 || m_x + m_width > BOARD_ENDX);
}

bool CObject::shouldCreateNext(CObject * x)
{
	if (abs(this->m_x - x->m_x) > BOARD_ENDX - m_width) return false;
	return true;
}

void CObject::updatePos(char direct)
{
	switch (direct) {
	case LEFT: Left(); break;
	case RIGHT: Right(); break;
	case UP: Up(); break;
	case DOWN: Down(); break;
	}
}

bool CObject::isDead()
{
	return false;
}

bool CObject::isImpact(CObject *)
{
	return false;
}

bool CObject::isWin()
{
	return false;
}

void CObject::writeToFile(FILE * f)
{
	fprintf(f, "\n%d %d %d", m_type, m_x, m_y);
}

void CObject::readFromFile(FILE * f)
{
	fscanf(f, "%d %d", &this->m_x, &this->m_y);
}

bool CObject::isFull(CObject *obj)
{
	return abs(this->m_x - obj->m_x) > (BOARD_ENDX - m_width);
}

