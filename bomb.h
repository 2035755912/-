#ifndef BOMB_H
#define BOMB_H

#include <QWidget>
#include<QIcon>
#include<QTimer>
#include<QPainter>
#include<QVector>
class bomb
{
public:
    bomb();
    QVector<QPixmap>m_pixarr;

    void updateinfo();

    int m_x;
    int m_y;
    bool m_free;

    int m_recorder;

    int m_index;




};

#endif // BOMB_H
