#include "TRAFFIC_LIGHT.h"

TRAFFIC_LIGHT::TRAFFIC_LIGHT()
{
	m_width = 1;
	m_height = 2;
	m_state = COLOR::green;
	m_time = 0;
	m_x = BOARD_STARTX + 1;
}

TRAFFIC_LIGHT::TRAFFIC_LIGHT(int y)
{
	this->TRAFFIC_LIGHT::TRAFFIC_LIGHT();
	m_y = y;
}

void TRAFFIC_LIGHT::incTime()
{
	m_time++;
	if (m_time > TIME_TRAFFIC_LIGHT) {
		updateState(254);
		m_time = 0;
	}
}

void TRAFFIC_LIGHT::draw(char ch)
{
	TextColor(GREY);
	GotoXy(m_x, m_y); printf("%c", ch);
	GotoXy(m_x, m_y - 1); printf("%c", ch);
	if (m_state == COLOR::red) {
		TextColor(RED);
		GotoXy(m_x, m_y - 1); printf("%c", ch);
	}
	else {
		TextColor(GREEN);
		GotoXy(m_x, m_y); printf("%c", ch);
	}
	TextColor(15);
}

void TRAFFIC_LIGHT::updateState(char ch)
{
	if (m_state == COLOR::green) {
		//TextColor(GREY);
		//GotoXy(m_x, m_y); printf("%c", ch);
		m_state = COLOR::red;
		this->draw(ch);
		//TextColor(RED);
		//GotoXy(m_x, m_y - 1); printf("%c", ch);
	}
	else {
		//TextColor(GREY);
		m_state = COLOR::green;
		this->draw(ch);
	}
	TextColor(15);
}

bool TRAFFIC_LIGHT::isRed()
{
	return (m_state == COLOR::red);
}

void TRAFFIC_LIGHT::writeToFile(FILE * f)
{
	fprintf(f, "\n%d %d %d %d", m_x, m_y, m_state, m_time);
}

void TRAFFIC_LIGHT::readFromFile(FILE * f)
{
	fscanf(f, "%d %d %d %d", &m_x, &m_y, &m_state, &m_time);
}
