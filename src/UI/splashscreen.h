#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QWidget>
#include <QTimer>

class SplashScreen : public QWidget
{
	Q_OBJECT

public:
	explicit SplashScreen(QWidget *parent = nullptr);

signals:
	void splashFinished(void);

private slots:
	void onTimeout(void);

private:
	QTimer *timer;
};

#endif /* SPLASHSCREEN_H */
