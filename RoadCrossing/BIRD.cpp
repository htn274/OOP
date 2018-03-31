#include "BIRD.h"

BIRD::BIRD()
{
	m_type = 4;
	m_width = 3;
	m_height = 2;
}

BIRD::BIRD(int y)
{
	this->init(y);
	this->BIRD::BIRD();
	m_x = (BOARD_ENDX/2) + 20;
}

void BIRD::draw(char ch)
{
	if (isOutBoard() || IsHitBoard()) return;
	GotoXy(m_x, m_y - 1); printf("%c", ch);
	GotoXy(m_x + 2, m_y - 1); printf("%c", ch);
	GotoXy(m_x + 1, m_y); printf("%c", 219);
}

void BIRD::updatePos(char direct)
{
	if (isOutBoard()) {
		CObject::updatePos(direct);
		return;
	}
	switch (direct) {
	case RIGHT: {
		draw(' ');
		GotoXy(m_x + 1, m_y); printf(" ");
		Right();
		if (IsHitBoard()) {
			//GotoXy(m_x, m_y - 1); printf(" ");
			m_x = BOARD_STARTX + 1;
		}
		//GotoXy(m_x + 1, m_y - 1); printf("%c", 219);
		//GotoXy(m_x + 2, m_y); printf("%c", 219);
		draw(254);
	}
	}
}
