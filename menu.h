#pragma once
//
// Created by sun on 8/25/16.

#include <QtWidgets>

class GifItem;
class MyPixItem;

class MenuScene : public QGraphicsScene
{
	Q_OBJECT
public:
	MenuScene();
	
private:
	GifItem *Dave;
	QGraphicsPixmapItem *background;
	MyPixItem *adventureButton;
	
};

