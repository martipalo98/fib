#include <QLabel>

class MyLabel : public QLabel {
	Q_OBJECT

	public:
		MyLabel(QWidget *parent);
		QString name = "";
		QString surname = "";
		QString dni = "";
		QString result = "";

	public slots:
		void setName(QString);
		void setSurname(QString);
		void setDNI(QString);
	    void showResult();
};
