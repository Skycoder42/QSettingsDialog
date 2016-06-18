#ifndef QSETTINGSLOADERENTRY_H
#define QSETTINGSLOADERENTRY_H

#include "qsettingsdialog_global.h"
#include "qsettingsentry.h"
#include "qsettingsloader.h"

class QSettingsLoaderEntry : public QSettingsEntry, public QSimpleSettingsLoader
{
public:
	QSettingsLoader *getLoader() final {
		return this;
	}
	void freeLoader(QSettingsLoader *) final {}
};

#endif // QSETTINGSLOADERENTRY_H