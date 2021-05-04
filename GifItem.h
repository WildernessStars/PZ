#pragma once
#include <QtWidgets>
extern int sum_sunshine;
class GifItem :public QObject, public QGraphicsItem {
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:

public:
	QMovie* gifitem;
	GifItem(const QString & path, QGraphicsItem *parent = nullptr);
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	virtual QRectF boundingRect()const;

signals:
	void finished();
};

class myPixmap : public QObject, public QGraphicsPixmapItem{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:
	
public:
	myPixmap(const QPixmap &image){
		setPixmap(image);
	}
};

class MyPixItem :public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	MyPixItem(const QPixmap & image, QGraphicsPixmapItem *parent = nullptr) {
		if (image.height() > 100)
			setPixmap(image.copy(0, image.height() / 2, image.width(), image.height() / 2));
		else
			setPixmap(image);
		connect(this, &MyPixItem::clicked, [this] { emit selected(); });
		//connect(this, &MyPixItem::reled, [this] { emit backnow(); });
	}
	void mousePressEvent(QGraphicsSceneMouseEvent *event) {
		emit clicked(event);
	}
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
		emit reled(event);
	}
signals:
	//void backnow();
	void selected();
	void clicked(QGraphicsSceneMouseEvent *event);
	void reled(QGraphicsSceneMouseEvent *event);
};

class SunShine :public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	SunShine(const QPixmap & image, QGraphicsPixmapItem *parent = nullptr);
	void mousePressEvent(QGraphicsSceneMouseEvent *event) {
		emit clicked(event);
	}
signals:
	void clicked(QGraphicsSceneMouseEvent *event);
};