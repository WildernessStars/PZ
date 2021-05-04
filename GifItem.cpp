#include "GifItem.h"
#include "store.h"
int sum_sunshine=50;
SunShine::SunShine(const QPixmap & image, QGraphicsPixmapItem *parent) {
	setPixmap(image);
	connect(this, &SunShine::clicked, [this] {
		sum_sunshine += 50;
		delete this;
	});
}