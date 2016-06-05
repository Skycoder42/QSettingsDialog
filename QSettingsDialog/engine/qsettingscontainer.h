#ifndef QSETTINGSCONTAINER_H
#define QSETTINGSCONTAINER_H

#include "qsettingsdialog_global.h"
#include <QObject>
#include <QScopedPointer>
#include "qsettingsentry.h"
#include "exceptions.h"
class QSettingsDialog;

class QSettingsContainerPrivate;
class QSETTINGSDIALOGSHARED_EXPORT QSettingsContainer : public QObject
{
	Q_OBJECT
	friend class QSettingsContainerPrivate;
public:
	explicit QSettingsContainer(QSettingsDialog *settingsDialog, const QString &containerPath, QObject *parent = nullptr);
	~QSettingsContainer();

	int appendEntry(QSettingsEntry *entry);
	int prependEntry(QSettingsEntry *entry);
	int insertEntry(int index, QSettingsEntry *entry);

	int getEntryIndex(int id) const;
	int getEntryId(int index) const;
	QSettingsEntry *getEntry(int id) const;
	QSettingsEntry *getEntryFromIndex(int index) const;

	bool removeEntry(int id);
	bool removeEntryFromIndex(int index);
	void moveEntry(int indexFrom, int indexTo);

protected:
	QScopedPointer<QSettingsContainerPrivate> d_ptr;
};

class QSETTINGSDIALOGSHARED_EXPORT QAsyncSettingsContainer : public QSettingsContainer
{
public:
	explicit QAsyncSettingsContainer(QSettingsDialog *settingsDialog, const QString &containerPath, QObject *parent = nullptr);
	~QAsyncSettingsContainer();
};

#endif // QSETTINGSCONTAINER_H