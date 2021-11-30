#include <QLineEdit>

class MyLineEdit : public QLineEdit {
	Q_OBJECT

	public:
		MyLineEdit(QWidget *parent);
		int allowederrors = 5;
		QString word = "DICCIONARI";
		QString visibleword = "**********";
		//QStringList used_chars;

	public slots:
	    void checkLetter(QString);
		void resetGame();

	signals:
		void updateVisibleWord(const QString &);
		void updateErrorCount(const int &);
};
