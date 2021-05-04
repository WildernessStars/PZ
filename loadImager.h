#pragma once
//
// Created by sun on 8/26/16.
//

#include <QtGui>

class LoadImager{
	QMap<QString, QPixmap> pixmaps;
public:
	QPixmap load(const QString &path);
};

extern LoadImager *gImageCache;

