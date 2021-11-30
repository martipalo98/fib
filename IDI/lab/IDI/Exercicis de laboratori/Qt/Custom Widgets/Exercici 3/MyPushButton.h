#include <QPushButton>

class MyPushButton : public QPushButton {
	Q_OBJECT

	public:
		MyPushButton(QWidget *parent);
		int color_id = rand()%4;

	public slots:
	    void changeColor(int);

};
