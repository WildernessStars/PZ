//#include "PVZ_Qt.h"
#include <QtWidgets/QApplication>
#include <QtCore>
#include <QtWidgets>
#include "MainView.h"
#include "LoadImager.h"

int main(int argc, char * *argv){
	QApplication a(argc, argv);
	QCoreApplication::setApplicationName("Plants vs Zombies");
	gImageCache = new LoadImager;
	MainWindow mainWindow;
	gMainView->switchToMenuScene();
	mainWindow.show();
	a.exec();
	delete gImageCache;
	return 0;
}
