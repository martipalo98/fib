#include <QPushButton>

class MyPushButton : public QPushButton {
	Q_OBJECT

	public:
		MyPushButton(QWidget *parent);
		bool shift_enabled = 0;

	public slots:
	    void toggleVowels();
		void writeVowel();

	signals:
		void sendVowel(QString);

};
