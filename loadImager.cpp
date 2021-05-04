//
// Created by sun on 8/26/16.
//

#include "loadImager.h"

LoadImager *gImageCache;

QPixmap LoadImager::load(const QString &path){
	if (pixmaps.find(path) == pixmaps.end())
		pixmaps.insert(path, QPixmap("images/" + path));
	return pixmaps[path];
}