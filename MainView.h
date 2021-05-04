//
// Created by sun on 8/25/16.
//


#include <QtWidgets>

class MenuScene;
class GameScene;
class MainWindow;

class MainView : public QGraphicsView{
	Q_OBJECT
public:
	MainView();
	~MainView();
	void switchToMenuScene();
	void switchToGameScene();
private:
	MenuScene *menuScene;
	GameScene *gameScene;
};

class MainWindow : public QMainWindow{
	Q_OBJECT
public:
	MainWindow();
private:
	QGraphicsView *mainView;
};

extern MainView *gMainView;

