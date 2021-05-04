#pragma once
//
// Created by sun on 8/27/16.
//

#include <QtWidgets>
#include"GifItem.h"

class Plants;

class PlantCardItem : public QGraphicsPixmapItem {

public:
	PlantCardItem(const QPixmap & image, QGraphicsItem *parent = nullptr) {
		setPixmap(image.copy(0, image.height() / 2, image.width(), image.height() / 2));
	}
};
class PlantCardAvalible : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	int plantkind;
	int percent;
	QPixmap imagecard;
	PlantCardAvalible (int a,int per,const QPixmap & image, QGraphicsItem *parent = nullptr) {
		plantkind = a;
		percent = per;
		imagecard=image;
		//qDebug() <<'*'<< image.width();
		setPixmap(image.copy(0, 0, image.width()*per/100, image.height() / 2));
		connect(this, &PlantCardAvalible::clicked, [this] { emit selected(); });
	}
	void UpdateCard(int per,bool afford) {
		percent = per;
		//qDebug() << ' '<<imagecard.width();
		if(afford)
			setPixmap(imagecard.copy(0, 0, (imagecard.width()/100)*per, imagecard.height() / 2));
		else
			setPixmap(imagecard.copy(0, 0, (imagecard.width() / 100)*5, imagecard.height() / 2));
	}
	void mousePressEvent(QGraphicsSceneMouseEvent *event) {
		emit clicked(event);
	}
signals:
	void selected();
	void clicked(QGraphicsSceneMouseEvent *event);
};
